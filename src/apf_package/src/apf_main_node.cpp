#include <chrono>
#include <memory>
#include <functional>
#include <Eigen/Dense>
#include <string>

#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/string.hpp"
#include "apf_interfaces/msg/jacobian.hpp"
#include "apf_interfaces/msg/distance.hpp"
#include "sensor_msgs/msg/joint_state.hpp"

#include "visualization_msgs/msg/marker.hpp"
#include "geometry_msgs/msg/point.hpp"

#include "trajectory_msgs/msg/joint_trajectory.hpp"
#include "trajectory_msgs/msg/joint_trajectory_point.hpp"

using std::placeholders::_1;
using namespace std::chrono_literals;

struct distance_data{
      double distance = 0;
      double dir[3] = {0,};
      double angle_distance[3] = {0,};
    } typedef distance_data;

struct obstacle_distance_data{
      double distance = 0;
      double dir[3] = {0,};
    } typedef obstacle_distance_data;

class apf_main_node : public rclcpp::Node
{
  public:
    //거리 값들은 저장하기 - 플래그를 나중에 넣어 줘야 한다.
    
    distance_data end_data;
    std::vector<obstacle_distance_data> obstacle_data;

    double joint_state[7] = {0,};
    Eigen::VectorXd joint_vel;
    //장애물 개수와 링크 개수 정의
    int obstacle_count = 0;
    int link_count = 0;
    int count_for_rviz = 0;
    //먼저 거리 계산 플래그가 들어오면, 계산 수행하기
    int distance_callback_flag = 0;

    apf_main_node()
    : Node("apf_main_node"), count_(0)
    {
      //자코비안을 받아 온다
      subscription_ = this->create_subscription<apf_interfaces::msg::Jacobian>(
      "/jacobian", 10, std::bind(&apf_main_node::topic_callback, this, _1));

      //거리 데이터를 받아온다.
      distnace_subscription_ = this->create_subscription<apf_interfaces::msg::Distance>(
      "/distance", 10, std::bind(&apf_main_node::distance_callback, this, _1));
      //현재 joint 값을 받는다.
      jointstate_subscription_ = this->create_subscription<sensor_msgs::msg::JointState>(
        "/joint_states", 10, std::bind(&apf_main_node::joint_state_callback, this, _1));

      joint_value_publisher_ = this->create_publisher<trajectory_msgs::msg::JointTrajectory>("iiwa_arm_controller/joint_trajectory", 10);
      timer_ = this->create_wall_timer(1ms, std::bind(&apf_main_node::timer_callback, this));
      
      //rviz에 출력하는 파트
      marker_publisher_ = this->create_publisher<visualization_msgs::msg::Marker>("vector_marker", 10);


      //파라미터 설정
      this->declare_parameter<std::vector<double>>("attractive_gain", std::vector<double>{60.0, 15.0}); //attractive_gain
      this->declare_parameter<std::vector<double>>("attractive_range", std::vector<double>{0.2, 0.1}); //attractive_range

      this->declare_parameter<std::vector<double>>("repulsive_gain", std::vector<double>{0.001, 0.00001}); //repulsive_gain
      this->declare_parameter<std::vector<double>>("repulsive_range", std::vector<double>{0.15, 0.1}); //repulsive_range

      //시간 계산을 위한 변수
      last_msg_time_ = this->now();  // 초기값 설정
    }

  private:
    //여기에서 출력 데이터를 계산하고, 매니퓰레이터를 조정하는 부분에 값을 대입한다.
    void topic_callback(const apf_interfaces::msg::Jacobian & msg) 
    {
      if (distance_callback_flag == 1) {

        int rows = 6;
        int cols = msg.col_num;
        //jaco_mat이라는 이름으로 받은 1차원 벡터를 자코비안 행렬로 변환하기 
        Eigen::Map<const Eigen::Matrix<double, Eigen::Dynamic, Eigen::Dynamic, Eigen::ColMajor>> jaco_mat(msg.flat_jacobian.data(), rows, cols);
        //jaco_mat5 5link까지의 자코비안 구하기
        Eigen::Map<const Eigen::Matrix<double, Eigen::Dynamic, Eigen::Dynamic, Eigen::ColMajor>> jaco_mat5(msg.flat_jacobian5.data(), rows, msg.col_num5);
        //jaco_mat3 3link까지의 자코비안 구하기 
        Eigen::Map<const Eigen::Matrix<double, Eigen::Dynamic, Eigen::Dynamic, Eigen::ColMajor>> jaco_mat3(msg.flat_jacobian3.data(), rows, msg.col_num3);

        ///////그냥 출력하는 파트
        //행렬 형식에 맞게 행렬을 출력한다.

  /*
        Eigen:: IOFormat ros2_format(Eigen::StreamPrecision, 0, ", ", ";\n", "[", "]", "[", "]");
        std::stringstream output_mat;
        output_mat << jaco_mat3.format(ros2_format);

        RCLCPP_INFO(this->get_logger(), "Publishing: \n'%s'\n", output_mat.str().c_str());
  */

        ///////그냥 자코비안 값을 출력하는 파트
        //행렬 형식에 맞게 행렬을 출력한다.
        /*
        Eigen:: IOFormat ros2_format(Eigen::StreamPrecision, 0, ", ", ";\n", "[", "]", "[", "]");
        std::stringstream output_mat;
        output_mat << jaco_mat.format(ros2_format);

        RCLCPP_INFO(this->get_logger(), "Publishing: \n'%s'\n", output_mat.str().c_str());
        */

        //목표 지점과의 차이를 이용한 거리 비례 힘 생성 파트
        //먼저 gain 관련 파라미터들 가져오기
        std::vector<double> att_gain;
        this->get_parameter("attractive_gain", att_gain);  
        std::vector<double> att_range;
        this->get_parameter("attractive_range", att_range);

        //////////////////
        //댐핑계수와 필드 계수를 곱한 att_gain 적용시키기
        //////////////////
        Eigen::VectorXd att_force(6);
        for(int i = 0; i < 3; i++){
          //만약 범위 내일 경우에 해당하는 식과 범위가 아닌 경우에 해당하는 식을 분리한다.
          if (end_data.distance < att_range[0]) att_force[i] = att_gain[0]*end_data.distance * end_data.dir[i];
          else att_force[i] = att_range[0] * att_gain[0] * (end_data.distance / fabs(end_data.distance))* end_data.dir[i];
        }
        for(int i = 3; i < 6; i++){
          if (end_data.angle_distance[i-3]< att_range[1]) att_force[i] = att_gain[1]*end_data.angle_distance[i-3];
          else att_force[i] = att_range[1] * att_gain[1] * end_data.angle_distance[i-3] / fabs(end_data.angle_distance[i-3]);
        }

        /////////////////
        //장애물에 의한 repulsive force적용하기
        /////////////////
        //먼저 파라미터들 가져오기
        std::vector<double> rep_gain;
        this->get_parameter("repulsive_gain", rep_gain);
        std::vector<double> rep_range;
        this->get_parameter("repulsive_range", rep_range);

        std::vector<Eigen::VectorXd> rep_force_arr;

        //링크 개수 만큼 반복한다. 지금은 링크 3 - 5 - 7 순임
        for (int k = 0; k < link_count; k++){
          //먼저 각 링크에 발생하는 rep_force 계산할 배열 만들기
          Eigen::VectorXd rep_force = Eigen::VectorXd::Zero(6);

          //각 링크당 장애물 개수만큼 반복해서 계산한다.
          //지금은 k = 0일 때, 0, 1 => k = 1일 때, 2, 3 이래 된다.
          for(int j = k * obstacle_count; j < (k + 1) * obstacle_count; j++ ){

            //장애물 마다 계산해서 넣는다.
            for(int i = 0; i < 3; i++){
              //만약 범위 내일 경우에 해당하는 식과 범위가 아닌 경우에 해당하는 식을 분리한다.
              if (obstacle_data[j].distance < rep_range[0]) rep_force[i] += rep_gain[0] * ((1/obstacle_data[j].distance) - (1/rep_range[0])) * pow((1/obstacle_data[j].distance),2) * obstacle_data[j].dir[i];
              else rep_force[i] += 0;
            }
          }

          //장애물마다 링크에 해당하는 값들 계산해서 넣은 후, 전체 저장 배열에 넣기
          rep_force_arr.push_back(rep_force);
        }
        
        //jaco_mat과 att_force 곱하기, 
        joint_vel = Eigen::Transpose(jaco_mat) * att_force;
        //RCLCPP_INFO(this->get_logger(), "joint_vel_1 %lf, %lf, %lf, %lf, %lf, %lf", joint_vel[0],joint_vel[1],joint_vel[2],joint_vel[3],joint_vel[4],joint_vel[5]);
        
        //jaco_mat과 rep_force 곱해서 넣기
        //이거는 방해하는 힘이니까 방향이 반대다
        if ((int)rep_force_arr.size() == 3){
          joint_vel -= Eigen::Transpose(jaco_mat3) * rep_force_arr[0];
          joint_vel -= Eigen::Transpose(jaco_mat5) * rep_force_arr[1];
          joint_vel -= Eigen::Transpose(jaco_mat) * rep_force_arr[2];
        }
        

        //최종 joint 속도 클리핑하기
        for (int i = 0; i < joint_vel.size(); i++){
          if (joint_vel[i]> 0.8) joint_vel[i] = 0.8;
          else if (joint_vel[i] < -0.8) joint_vel[i] = -0.8;
        }

        RCLCPP_INFO(this->get_logger(), "joint_vel_final %lf, %lf, %lf, %lf, %lf, %lf", joint_vel[0],joint_vel[1],joint_vel[2],joint_vel[3],joint_vel[4],joint_vel[5]);

        // 결과 출력
        //Eigen::IOFormat ros2_format(Eigen::StreamPrecision, 0, ", ", ";\n", "[", "]", "[", "]");
        //std::stringstream output_mat;
        //output_mat << joint_vel.format(ros2_format);
        //RCLCPP_INFO(this->get_logger(), "joint_vel of jaco_mat * att_force: \n'%s'\n", output_mat.str().c_str());

        //힘의 방향 표시하기
        //publish_direction_vector(distance.end_point.x, distance.end_point.y, distance.end_point.z, att_force[0], att_force[1], att_force[2] ,distance.target_point.x,distance.target_point.y, distance.target_point.z);
      }
    }

    //거리 값이 들어왔을 경우의 반응
    void distance_callback(const apf_interfaces::msg::Distance & distance) 
    {
      //RCLCPP_INFO(this->get_logger(), "Distance: %f, Distance_vector: (%f, %f,%f)", distance.end_distance, distance.direction_vector.x, distance.direction_vector.y, distance.direction_vector.z);
      //end_effector의 직교 좌표값을 대입하기
      end_data.distance = distance.end_distance;
      end_data.dir[0] = distance.direction_vector.x;
      end_data.dir[1] = distance.direction_vector.y;
      end_data.dir[2] = distance.direction_vector.z;
      //end_effector의 좌표 차이 값을 대입하기
      end_data.angle_distance[0] = distance.end_angle_distance.x;
      end_data.angle_distance[1] = distance.end_angle_distance.y;
      end_data.angle_distance[2] = distance.end_angle_distance.z;
      
      //장애물 관련 저장하는 파트
      //장애물 개수 저장 및 배열 상에서의 위치 저장할 변수 선언
      obstacle_count = distance.obstacle_count;
      link_count = distance.link_count;

      int value_count = 0;
      obstacle_data.clear();
      //지금은 링크 3부터 시작하고 5, 7 순으로 3개 저장되는데.
      for (int i = 0; i < link_count; i++){
        //배열의 처음부터 -> link3과 장애물의 개수만큼 거리데이터 -> link5와 장애물의 개수만큼 거리데이터 
        for (int j = 0; j < obstacle_count; j++){
          obstacle_distance_data d;
          d.distance = distance.obstacle_distance[value_count];
          d.dir[0] = distance.obstacle_direction_vector[value_count].x;
          d.dir[1] = distance.obstacle_direction_vector[value_count].y;
          d.dir[2] = distance.obstacle_direction_vector[value_count].z;

          obstacle_data.push_back(d);
          
          value_count = value_count+1;
        }
      }
      //RCLCPP_INFO(this->get_logger(), "%d" , value_count);

      //RCLCPP_INFO(this->get_logger(), "%d" , (int)obstacle_data.size());
      //RCLCPP_INFO(this->get_logger(), "%lf, %lf, %lf, %lf" , obstacle_data[0].distance, obstacle_data[1].distance, obstacle_data[2].distance, obstacle_data[3].distance);

      //방향 표시하기 - 동시에 너무 많이 보내서 과부하가 생김
      if(count_for_rviz > 80){
        count_for_rviz++;
      }
      else{
        count_for_rviz = 0;
        publish_direction_vector(distance.end_point.x, distance.end_point.y, distance.end_point.z, distance.direction_vector.x, distance.direction_vector.y, distance.direction_vector.z, distance.target_point.x,distance.target_point.y, distance.target_point.z);
      }
      //값이 들어오면 플래그 on 해주기
      distance_callback_flag = 1;
    }

    void joint_state_callback(const sensor_msgs::msg::JointState & msg) 
    {
      for(int i = 0; i < 7; i++){
        joint_state[i] = msg.position[i];
      }
    }
    //제어 주기마다 실행
    void timer_callback()
    {
      //플래그가 들어오면 실행하자
      if (distance_callback_flag ==1){
        double sampling_time = 0.001;
        auto target_point = trajectory_msgs::msg::JointTrajectory();
        std::vector<std::string> my_joint_names = {"joint_a1", "joint_a2", "joint_a3", "joint_a4", "joint_a5", "joint_a6", "joint_a7"};
        target_point.joint_names = my_joint_names;
        
        //push할 Point 변수를 입력
        auto point = trajectory_msgs::msg::JointTrajectoryPoint();
        //이거 sampling_time보다 더 길면 좀 느려지기는 하지만, 좀 더 부드럽게 이동한다 
        point.time_from_start.sec = sampling_time;

        //내가 입력할 joint_vel에 맞게 Postion vector의 크기를 저장하고, 값을 입력한다. 
        std::stringstream ss;
        //joint position 출력하기
        point.positions.resize(joint_vel.size());
        for(int i = 0; i < joint_vel.size();i++){
          //중력을 z축 방향으로 보상해주자
          if(i == 2) joint_vel[i] += 9.8*sampling_time;
          //최종 값 입력하기  
          point.positions[i] = joint_state[i] + (joint_vel[i]*sampling_time);
          ss << joint_vel[i] << ",";
        }
        //RCLCPP_INFO(this->get_logger(), ss.str().c_str());
        //값을 다 넣은 point 메세지 타입을 push_back 해줘서 넣기.
        target_point.points.push_back(point);

        // 결과 출력
        /*
        Eigen::IOFormat ros2_format(Eigen::StreamPrecision, 0, ", ", ";\n", "[", "]", "[", "]");
        std::stringstream output_mat;
        output_mat << (joint_vel*sampling_time).format(ros2_format);
        RCLCPP_INFO(this->get_logger(), "joint_vel of jaco_mat * att_force: \n'%s'\n", output_mat.str().c_str());
        */


        //최종적으로 메세지 보내기
        joint_value_publisher_->publish(target_point);
      }
    }






    //이 함수는 Rviz에서 힘의 방향을 표시하려고 만든 함수이다.
    void publish_direction_vector(double start_x, double start_y, double start_z, double dir_x, double dir_y, double dir_z, double target_x, double target_y, double target_z) 
    {
      //이거는 화살표 만드는 파트
      auto marker = visualization_msgs::msg::Marker();
      marker.header.frame_id = "world";  // RViz에서 사용하는 기준 프레임
      marker.header.stamp = this->get_clock()->now();
      
      marker.ns = "vector";
      marker.id = 0;
      marker.type = visualization_msgs::msg::Marker::ARROW;  // 화살표를 사용하여 벡터를 표시
      marker.action = visualization_msgs::msg::Marker::ADD;
      
      // 시작점 (start_x, start_y, start_z)
      geometry_msgs::msg::Point start;
      start.x = start_x;
      start.y = start_y;
      start.z = start_z;
      
      // 끝점 (dir_x, dir_y, dir_z 방향으로 벡터 길이를 설정해 이동) - 크기를 1/10으로 줄이기
      geometry_msgs::msg::Point end;
      end.x = start_x + (dir_x)/5;
      end.y = start_y + (dir_y)/5;
      end.z = start_z + (dir_z)/5;

      //점 2개 만들기
      marker.points.resize(2);
      marker.points[0]=(start);
      marker.points[1]=(end);

      // 색상과 크기 설정
      marker.scale.x = 0.025;  // 화살표의 두께
      marker.scale.y = 0.05;   // 화살표의 길이
      marker.color.a = 1.0;   // 투명도
      marker.color.r = 1.0;   // 빨간색

      ////////////여기는 목표 점을 만드는 파트
      auto target_marker = visualization_msgs::msg::Marker();
      target_marker.header.frame_id = "world";  // RViz에서 사용하는 기준 프레임
      target_marker.header.stamp = this->get_clock()->now();
      
      target_marker.ns = "point";
      target_marker.id = 1; //마커 아이디는 다르게 한다.
      target_marker.type = visualization_msgs::msg::Marker::SPHERE;  // 점으로 목표 지점을 표시
      target_marker.action = visualization_msgs::msg::Marker::ADD;
      
      // 시작점 (start_x, start_y, start_z)
      geometry_msgs::msg::Point target_point;
      target_point.x = target_x;
      target_point.y = target_y;
      target_point.z = target_z;

      //점 2개 만들기
      target_marker.points.resize(1);
      target_marker.pose.position = target_point;

      // 색상과 크기 설정
      target_marker.scale.x = 0.1;
      target_marker.scale.y = 0.1;
      target_marker.scale.z = 0.1;
      target_marker.color.a = 1.0;   // 투명도
      target_marker.color.r = 1.0;   // 빨간색
      
      
      marker_publisher_->publish(marker);
      marker_publisher_->publish(target_marker);
    }

    rclcpp::Subscription<apf_interfaces::msg::Jacobian>::SharedPtr subscription_;
    rclcpp::Subscription<apf_interfaces::msg::Distance>::SharedPtr distnace_subscription_;
    rclcpp::Publisher<visualization_msgs::msg::Marker>::SharedPtr marker_publisher_;
    rclcpp::Subscription<sensor_msgs::msg::JointState>::SharedPtr jointstate_subscription_;
    rclcpp::Time last_msg_time_;  // 마지막 메시지의 수신 시각
    rclcpp::TimerBase::SharedPtr timer_;  //이거는 타이머
    rclcpp::Publisher<trajectory_msgs::msg::JointTrajectory>::SharedPtr joint_value_publisher_;
    size_t count_;
};

int main(int argc, char * argv[])
{
  rclcpp::init(argc, argv);
  rclcpp::spin(std::make_shared<apf_main_node>());
  rclcpp::shutdown();
  return 0;
}