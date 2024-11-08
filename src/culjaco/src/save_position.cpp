#include <memory>
#include <vector>
#include <chrono>
#include <functional>
#include <string>

#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/string.hpp"
#include "sensor_msgs/msg/joint_state.hpp"
#include "std_msgs/msg/float64_multi_array.hpp"
#include "apf_interfaces/msg/jacobian.hpp"
#include <Eigen/Dense>
#include "nav_msgs/msg/odometry.hpp"

#include <fstream>


//지금 이게 최종 자코비안을 보내는 내가 만들어 놓은 노드이다.

using namespace std::chrono_literals;

using std::placeholders::_1;

class jaco_node : public rclcpp::Node
{
  public:
    //노드에서 돌려쓸 변수
    std::vector<double> joint_position;
    int position_size = 7;
    double joint_array[7];
    //joint 개수
    const int joint_EA = 7;

    //DH파라미터 저장할 배열 전역 변수로 선언
    //a | alpha | d | theta 순으로 배열 되었다.
    //0.34,0.4,0.4,0.126 - 이게 메인 DH
    double d_params[4] = {0.36,0.42,0.4,0.154};
    double theta[7] = {0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0};

    double DH_params[7][4] = {
      {0,   -M_PI/2,  d_params[0], theta[0]},
      {0,   M_PI/2,   0,           theta[1]},
      {0,   M_PI/2,   d_params[1], theta[2]},
      {0,   -M_PI/2,  0,           theta[3]},
      {0,   -M_PI/2,  d_params[2], theta[4]},
      {0,   M_PI/2,   0,           theta[5]},
      {0,   0     ,   d_params[3], theta[6]},
    };
    double position[3] = {0,0,0};
    //노드 구성 파트
    jaco_node()
    : Node("jaco_node")
    {
        //joint의 현재 상태를 받아오는 topic subscriber
        subscription_jointstate = this->create_subscription<sensor_msgs::msg::JointState>(
        "/joint_states", 10, std::bind(&jaco_node::joint_state_callback, this, _1));

        //자코비안을 계산하는 publisher
        publisher_jacobian = this->create_publisher<apf_interfaces::msg::Jacobian>("/jacobian", 5);
        
        //끝단 링크의 위치와 속도를 얻어오기 위해서 플러그인을 구독해서 쓴다.
        subscription_ = this->create_subscription<nav_msgs::msg::Odometry>(
        "/odom", 10, std::bind(&jaco_node::topic_callback, this, _1));

        //링크들의 현재 위치를 보내는 publisher
        publisher_link_pose = this->create_publisher<std_msgs::msg::Float64MultiArray>("/link_pose", 10);
        timer = this->create_wall_timer(
        std::chrono::milliseconds(500), std::bind(&jaco_node::timer_callback, this));

        // 파일 열기
        file_.open("cul_pos.csv", std::ios::out | std::ios::trunc);
        file2_.open("real_pos.csv", std::ios::out | std::ios::trunc);
    }

    ~jaco_node() {
        if (file_.is_open()) file_.close();
        if (file2_.is_open()) file2_.close();
    }

  private:

    //변환행렬 계산 함수
    Eigen::MatrixXd transpose(double a, double alpha,double d,double theta)
    {
        double cos_alpha = 0.0;
        //cos에 alpha 넣은 것은 미리 계산해 놓자. - 계산할 때, pi/2가 완벽하게 pi의 반이 아니라서, 0이 안나오니, 기분나쁘니까 0으로 만들어 버리기
        if (cos(alpha) < 0.01) cos_alpha = 0;
        else cos_alpha = cos(alpha);

        Eigen:: MatrixXd T(4,4);
        T << cos(theta), -sin(theta)*cos_alpha, sin(theta)*sin(alpha), a*cos(theta),
            sin(theta), cos(theta)*cos_alpha, -cos(theta)*sin(alpha), a*sin(theta),
            0,          sin(alpha),             cos_alpha,            d,
            0,          0,                     0,                      1;

        return T;
    }
    
    //odom에서 값이 들어오면, distance 계산해서 값을 출력한다. - 일단 이거의 주기가 얼마인지는 설정하지 않았다.
    void topic_callback(const nav_msgs::msg::Odometry & msg)
    {
      //odom에서 받은 데이터를 받아서 저장하기.
      position[0] = msg.pose.pose.position.x;
      position[1] = msg.pose.pose.position.y;
      position[2] = msg.pose.pose.position.z;
    }


    //받아와서 출력하는 함수
    void joint_state_callback(const sensor_msgs::msg::JointState & msg) 
    {   
        //받은 데이터를 배열로 변환해서 넣자. - 이렇게 받은 것이 앞에서 부터 joint 1부터 시작한다.
        std::string positions; 
        for (int i = 0; i < position_size; i++) {
            joint_array[i] = msg.position[i];
        } 
        //출력하려고 하나씩 전부 변환한 것
        for (size_t i = 0; i < msg.position.size(); ++i) {
            positions += std::to_string(joint_array[i]) + " ";
        }
        RCLCPP_INFO(this->get_logger(), "Joint positions: '%s'", positions.c_str());   

        ///////trannsformation matrix 계산!
        //Trandpose하면서 나오는 모든 행렬을 이 배열에 저장해 놓을 것이다.ㅇ
        Eigen::MatrixXd mat_arry[8];
        for(int i = 0; i < 8; i++){
            mat_arry[i] = Eigen::MatrixXd::Identity(4,4);
        }
        //이건 최종 행렬은 여기에 저장을 한다.
        Eigen::MatrixXd forward_mat(4,4);
        forward_mat = Eigen::MatrixXd::Identity(4,4);

        //mat_arr의 index가 1일때, T 행렬 0->1로의 변환이다. 그냥 0은 월드 좌표계 0을 의미한다.
        for (int i=0; i < 7; i++){
            Eigen::MatrixXd t(4,4);
            t = transpose(DH_params[i][0],DH_params[i][1],DH_params[i][2],joint_array[i]);
            forward_mat = forward_mat*t;
            mat_arry[i+1] = forward_mat;
        }

        ///////jacobian 계산!
        Eigen::Vector3d Z_mat[7];
        Eigen::Vector3d O_mat[7];

        //Z 매트릭스랑 O 매트릭스 잘라서 써야 한다. 필요한 것은 zi와 t7, ti이다.
        for(int i = 0; i < 7; i++){
        //먼저 z0부터 계산. 마지막 z7이 아니라, z6까지가 필요하다. 
        Z_mat[i] = mat_arry[i].block<3,1>(0,2);
        //지금 O도 구하기 얘도 z랑 같다.
        Eigen::Vector3d cur_O(3,1);
        cur_O = mat_arry[i].block<3,1>(0,3);
        //마지막 매트릭스는 이거 하나만 필요하다.
        Eigen::Vector3d final_O(3,1);
        final_O = mat_arry[7].block<3,1>(0,3);
        
        //최종적으로 Zi cross(O최종 - Oi가 필요하다)
        O_mat[i] = Z_mat[i].cross(final_O-cur_O);
        }

        //위아래로 합치기
        Eigen::MatrixXd jacobian_mat(6,7);
        jacobian_mat << O_mat[0], O_mat[1], O_mat[2], O_mat[3], O_mat[4], O_mat[5], O_mat[6],
                        Z_mat[0], Z_mat[1], Z_mat[2], Z_mat[3], Z_mat[4], Z_mat[5], Z_mat[6];
                
        //자코비안 테스트용 각속도
        Eigen::MatrixXd angle_vel(7,1);
        angle_vel << 0.0, 0.1, 0.1, 0.1, 0.1, 0.1, 0.1;
        //자코비안 계산 결과 직교 좌표계 속도
        Eigen::MatrixXd result_vel(7,1);
        result_vel = jacobian_mat*angle_vel;

        ///////그냥 출력하는 파트
        //행렬 형식에 맞게 행렬을 출력한다.
        Eigen:: IOFormat ros2_format(Eigen::StreamPrecision, 0, ", ", ";\n", "[", "]", "[", "]");
        std::stringstream output_mat;
        output_mat << mat_arry[6].format(ros2_format);

        RCLCPP_INFO(this->get_logger(), "Publishing: \n'%s'\n", output_mat.str().c_str());

        // 4번째 열의 첫 번째, 두 번째, 세 번째 요소를 파일에 저장
        if (file_.is_open()) {
            file_ << "x: " << mat_arry[7](0, 3) << ", y: " << mat_arry[7](1, 3) << ", z: " << mat_arry[7](2, 3) << "\n";
        }
        // 측정 데이터 값 저장
        if (file2_.is_open()) {
            file2_ << "x: " << position[0] << ", y: " << position[1] << ", z: " << position[2] << "\n";
        }

        auto link_pose_msg = std_msgs::msg::Float64MultiArray();
        link_pose_msg.data.clear();
        link_pose_msg.data.push_back(1.1);
        link_pose_msg.data.push_back(1.1);

        //실제로 노드들로 publish 하는 파트
        // 데이터 채우기
        //jacobian 메세지 넣기 - 먼저 우리는 가변 배열이니까 크기를 지정해 주기
        auto jaco_msg = apf_interfaces::msg::Jacobian();
        jaco_msg.flat_jacobian.resize(6*joint_EA);

        //데이터 보내주기
        std::vector<double> flat_data(jacobian_mat.data(), jacobian_mat.data() + jacobian_mat.size());
        std::copy(flat_data.begin(), flat_data.end(), jaco_msg.flat_jacobian.begin());

        jaco_msg.col_num = joint_EA;
        publisher_jacobian->publish(jaco_msg);
        publisher_link_pose->publish(link_pose_msg);

    }
    //일정 시간마다 callback함수 호출
    void timer_callback()
    {
        
    }
    rclcpp::Subscription<nav_msgs::msg::Odometry>::SharedPtr subscription_;
    rclcpp::Subscription<sensor_msgs::msg::JointState>::SharedPtr subscription_jointstate;
    rclcpp::TimerBase::SharedPtr timer;
    rclcpp::Publisher<apf_interfaces::msg::Jacobian>::SharedPtr publisher_jacobian;
    rclcpp::Publisher<std_msgs::msg::Float64MultiArray>::SharedPtr publisher_link_pose;
    std::ofstream file_;
    std::ofstream file2_;
};

int main(int argc, char * argv[])
{
  rclcpp::init(argc, argv);
  rclcpp::spin(std::make_shared<jaco_node>());
  rclcpp::shutdown();
  return 0;
}
