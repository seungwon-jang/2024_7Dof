#include <memory>
#include <vector>
#include <chrono>
#include <functional>
#include <string>

#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/string.hpp"
#include "sensor_msgs/msg/joint_state.hpp"
using std::placeholders::_1;

class jaco_node : public rclcpp::Node
{
  public:
    //노드에서 돌려쓸 변수
    std::vector<double> joint_position;
    int position_size = 7;
    double joint_array[7];

    jaco_node()
    : Node("jaco_node")
    {
        //joint의 현재 상태를 받아오는 topic subscriber
        subscription_jointstate = this->create_subscription<sensor_msgs::msg::JointState>(
        "/joint_states", 10, std::bind(&jaco_node::joint_state_callback, this, _1));

        //자코비안을 계산하는 publisher
        publisher_jacobian = this->create_publisher<std_msgs::msg::String>("/jacobian", 10);
        publisher_link_pose = this->create_publisher<std_msgs::msg::String>("/link_pose", 10);
        timer = this->create_wall_timer(
        std::chrono::milliseconds(500), std::bind(&jaco_node::timer_callback, this));
    }

  private:
    //받아와서 출력하는 함수
    void joint_state_callback(const sensor_msgs::msg::JointState & msg) 
    {
        /*
        //받은 데이터를 배열로 변환해서 넣자.
        std::string positions; 
        for (int i = 0; i < position_size; i++) {
            joint_array[i] = msg.position[i];
        } 
        for (size_t i = 0; i < msg.position.size(); ++i) {
            positions += std::to_string(joint_array[i]) + " ";
        }
        RCLCPP_INFO(this->get_logger(), "Joint positions: '%s'", positions.c_str());
        */

        //받은 데이터 저장하기
        for (int i = 0; i < position_size; i++) {
            joint_array[i] = msg.position[i];
        } 
    }
    //일정 시간마다 callback함수 호출
    void timer_callback()
    {
      auto message = std_msgs::msg::String();
      message.data = "Hello, world! " + std::to_string(5);
      RCLCPP_INFO(this->get_logger(), "Publishing: '%s'", message.data.c_str());
      publisher_jacobian->publish(message);
      publisher_link_pose->publish(message);
    }


    rclcpp::Subscription<sensor_msgs::msg::JointState>::SharedPtr subscription_jointstate;
    rclcpp::TimerBase::SharedPtr timer;
    rclcpp::Publisher<std_msgs::msg::String>::SharedPtr publisher_jacobian;
    rclcpp::Publisher<std_msgs::msg::String>::SharedPtr publisher_link_pose;
};

int main(int argc, char * argv[])
{
  rclcpp::init(argc, argv);
  rclcpp::spin(std::make_shared<jaco_node>());
  rclcpp::shutdown();
  return 0;
}