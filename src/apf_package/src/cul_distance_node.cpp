#include <memory>
#include "tf2/LinearMath/Quaternion.h"

#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/string.hpp"
#include "nav_msgs/msg/odometry.hpp"
#include "apf_interfaces/msg/distance.hpp"

using std::placeholders::_1;

class cul_distance_node : public rclcpp::Node
{
  public:
    cul_distance_node()
    : Node("cul_distance_node")
    {
      subscription_ = this->create_subscription<nav_msgs::msg::Odometry>(
      "/odom", 10, std::bind(&cul_distance_node::topic_callback, this, _1));
      distance_publisher_ = this->create_publisher<apf_interfaces::msg::Distance>("/distance", 10);
    }
    //원하는 x,y,z 좌표 전달, 뒤에 3개는 오일러 각도.
    double goal_points[6] = {-0.3, -0.4, 0.8, 0.5, 0.5, 0.5};
    double cartisian_distance = 0;
    double cartisian_vector[3]= {0, 0, 0};

  private:
    //odom에서 값이 들어오면, distance 계산해서 값을 출력한다. - 일단 이거의 주기가 얼마인지는 설정하지 않았다.
    void topic_callback(const nav_msgs::msg::Odometry & msg)
    {
      //odom에서 받은 데이터를 받아서 저장하기.
      double position[3] = {msg.pose.pose.position.x, msg.pose.pose.position.y, msg.pose.pose.position.z};
      double Quater[4] = {msg.pose.pose.orientation.x, msg.pose.pose.orientation.y, msg.pose.pose.orientation.z, msg.pose.pose.orientation.w};

      //RCLCPP_INFO(this->get_logger(), "Position: x:'%.2f', y:'%.2f', z:'%.2f'\n", position[0], position[1], position[2]);
      //RCLCPP_INFO(this->get_logger(), "Quater: x:'%.2f', y:'%.2f', z:'%.2f, w:%.2f'\n", Quater[0], Quater[1], Quater[2], Quater[3]);
      //RCLCPP_INFO(this->get_logger(), "Position_diff: x:'%.2f', y:'%.2f', z:'%.2f'\n", (goal_points[0] - position[0]), (goal_points[1] - position[1]), (goal_points[2] - position[2]));

      //목표 roll pitch yaw 쿼터니안으로 변환해서 저장하고, 현재 값도 쿼터니안으로 변환해서 저장하기
      tf2::Quaternion target_Quater, cur_Quater;
      target_Quater.setRPY(goal_points[3], goal_points[4], goal_points[5]);
      cur_Quater.setValue(Quater[0], Quater[1], Quater[2], Quater[3]);
      
      //쿼터니안 값 개별로 출력해 보기
      /*
      RCLCPP_INFO(this->get_logger(), "%f %f %f %f",
            cur_Quater.x(), cur_Quater.y(), cur_Quater.z(), cur_Quater.w());
      */
      //직교 좌표계에서 차이를 구하기
      cartisian_distance = sqrt(pow(goal_points[0] - position[0],2) + pow(goal_points[1] - position[1],2) + pow(goal_points[2] - position[2],2));

      //쿼터니언에서 차이를 구하기 - 이러면 차이가 구해진다.
      tf2::Quaternion q_error = target_Quater*cur_Quater.inverse();
      //차이애서 축 성분과 회전량을 출력한다.
      tf2::Vector3 axis = q_error.getAxis();
      double angle = q_error.getAngle();
      tf2::Vector3 angle_distance = axis*angle;

      for(int i = 0; i < 3; i++){
        cartisian_vector[i] = (goal_points[i] - position[i])/cartisian_distance;
      }

      RCLCPP_INFO(this->get_logger(), "cartisian_distance:'%.4f', cartisian_vector : (%.4f,%.4f,%.4f)", cartisian_distance, cartisian_vector[0],cartisian_vector[1],cartisian_vector[2]);
      
      RCLCPP_INFO(this->get_logger(), "Quaternion_distance: : (%.4f,%.4f,%.4f)", angle_distance.x(), angle_distance.y(), angle_distance.z() );

      //보낼 거리 데이터 저장하기
      auto pub_distance = apf_interfaces::msg::Distance();
      
      //목표점 입력
      pub_distance.target_point.x = goal_points[0];
      pub_distance.target_point.y = goal_points[1];
      pub_distance.target_point.z = goal_points[2];
      //end_effector의 좌표 입력
      pub_distance.end_point.x = position[0];
      pub_distance.end_point.y = position[1];
      pub_distance.end_point.z = position[2];

      //end_effector의 직교 좌표계 차이
      pub_distance.end_distance = cartisian_distance;
      //end_effector의 힘 방향 벡터
      pub_distance.direction_vector.x = cartisian_vector[0];
      pub_distance.direction_vector.y = cartisian_vector[1];
      pub_distance.direction_vector.z = cartisian_vector[2];
      //end_effector의 각도 차이
      pub_distance.end_angle_distance.x = angle_distance.x();
      pub_distance.end_angle_distance.y = angle_distance.y();
      pub_distance.end_angle_distance.z = angle_distance.z();

      distance_publisher_->publish(pub_distance);
    }

    rclcpp::Subscription<nav_msgs::msg::Odometry>::SharedPtr subscription_;
    rclcpp::Publisher<apf_interfaces::msg::Distance>::SharedPtr distance_publisher_;
};

int main(int argc, char * argv[])
{
  rclcpp::init(argc, argv);
  rclcpp::spin(std::make_shared<cul_distance_node>());
  rclcpp::shutdown();
  return 0;
}