#include <chrono>
#include <functional>
#include <memory>
#include <string>
#include <math.h>

#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/string.hpp"
#include <Eigen/Dense>
#define pi 3.14

using namespace std::chrono_literals;

class forward_node : public rclcpp::Node
{
public:
  //DH파라미터 저장할 배열 전역 변수로 선언
  //a | alpha | d | theta 순으로 배열 되었다.
  //0.34,0.4,0.4,0.126 - 이게 메인 DH
    double d_params[4] = {0.34,0.4,0.4,0};
    double theta[7] = {-1.5, 1.0, 0.0, -1.5, 0.0, 1.5, 0.0};

    double DH_params[7][4] = {
      {0,   -M_PI/2,  d_params[0], theta[0]},
      {0,   M_PI/2,   0,           theta[1]},
      {0,   M_PI/2,   d_params[1], theta[2]},
      {0,   -M_PI/2,  0,           theta[3]},
      {0,   -M_PI/2,  d_params[2], theta[4]},
      {0,   M_PI/2,   0,           theta[5]},
      {0,   M_PI/2,   d_params[3], theta[6]},
    };

  //노드 관련 선언
  forward_node()
  : Node("minimal_publisher"), count_(0)
  {
    publisher_ = this->create_publisher<std_msgs::msg::String>("topic", 10);
    timer_ = this->create_wall_timer(
      5s, std::bind(&forward_node::timer_callback, this));
  }

private:

  //변환행렬 계산 함수
  Eigen::MatrixXd transpose(double a, double alpha,double d,double theta)
  {
    double cos_alpha = 0.0;
    //cos에 alpha 넣은 것은 미리 계산해 놓자. - 계산할 때, pi/2가 완벽하게 pi의 반이 아니라서, 0이 안나오니, 기분나쁘니까 0으로 만들어 버리기
    if (cos(alpha) < 0.001) cos_alpha = 0;
    else cos_alpha = cos(alpha);

    Eigen:: MatrixXd T(4,4);
    T << cos(theta), -sin(theta)*cos_alpha, sin(theta)*sin(alpha), a*cos(theta),
         sin(theta), cos(theta)*cos_alpha, -cos(theta)*sin(alpha), a*sin(theta),
         0,          sin(alpha),             cos_alpha,            d,
         0,          0,                     0,                      1;

    return T;
  }

  //timer_callback함수
  void timer_callback()
  {
    auto message = std_msgs::msg::String();
    message.data = "Hello, world! " + std::to_string(count_++);
    //RCLCPP_INFO(this->get_logger(), "Publishing: '%s'", message.data.c_str());

    ///////trannsformation matrix 계산!
    //Trandpose하면서 나오는 모든 행렬을 이 배열에 저장해 놓을 것이다.ㅇ
    Eigen::MatrixXd mat_arry[7];
    for(int i = 0; i < 7; i++){
      mat_arry[i] = Eigen::MatrixXd::Identity(4,4);
    }
    //이건 최종 행렬은 여기에 저장을 한다.
    Eigen::MatrixXd forward_mat(4,4);
    forward_mat = Eigen::MatrixXd::Identity(4,4);

    //좀 혼동이 올 수도 있는게, mat_arr의 index가 0일때, T 행렬 0->1로의 변환이다.
    for (int i=0; i < 7; i++){
      Eigen::MatrixXd t(4,4);
      t = transpose(DH_params[i][0],DH_params[i][1],DH_params[i][2],DH_params[i][3]);
      forward_mat = forward_mat*t;
      mat_arry[i] = forward_mat;
    }

    ///////jacobian 계산!
    Eigen::MatrixXd Z_mat[7];
    Eigen::MatrixXd O_mat[7];

    //Z 매트릭스랑 O 매트릭스 잘라서 저장하기.
    for(int i = 0; i < 7; i++){
      Z_mat[i] = mat_arry[i].block<3,1>(0,2);
      O_mat[i] = mat_arry[i].block<3,1>(0,3);
    }

    //위아래로 합치기
    Eigen::MatrixXd test(6,7);
    test << Z_mat[0], Z_mat[1], Z_mat[2], Z_mat[3], Z_mat[4], Z_mat[5], Z_mat[6],
            O_mat[0], O_mat[1], O_mat[2], O_mat[3], O_mat[4], O_mat[5], O_mat[6];

    ///////그냥 출력하는 파트
    //행렬 형식에 맞게 행렬을 출력한다.
    Eigen:: IOFormat ros2_format(Eigen::StreamPrecision, 0, ", ", ";\n", "[", "]", "[", "]");
    std::stringstream output_mat;
    output_mat << test.format(ros2_format);

    RCLCPP_INFO(this->get_logger(), "Publishing: \n'%s'\n", output_mat.str().c_str());


    publisher_->publish(message);
  }
  rclcpp::TimerBase::SharedPtr timer_;
  rclcpp::Publisher<std_msgs::msg::String>::SharedPtr publisher_;
  size_t count_;
};

int main(int argc, char * argv[])
{

  rclcpp::init(argc, argv);
  rclcpp::spin(std::make_shared<forward_node>());
  rclcpp::shutdown();
  return 0;
}
