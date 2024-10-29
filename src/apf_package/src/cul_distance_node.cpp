#include <memory>

#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/string.hpp"
#include "std_msgs/msg/float64_multi_array.hpp"
using std::placeholders::_1;

class cul_distance_node : public rclcpp::Node
{
  public:
    cul_distance_node()
    : Node("cul_distance_node")
    {
      subscription_ = this->create_subscription<std_msgs::msg::Float64MultiArray>(
      "/link_pose", 10, std::bind(&cul_distance_node::topic_callback, this, _1));
    }

  private:
    void topic_callback(const std_msgs::msg::Float64MultiArray & msg) const
    {
      RCLCPP_INFO(this->get_logger(), "I heard: '%f'", msg.data[0]);
    }
    rclcpp::Subscription<std_msgs::msg::Float64MultiArray>::SharedPtr subscription_;
};

int main(int argc, char * argv[])
{
  rclcpp::init(argc, argv);
  rclcpp::spin(std::make_shared<cul_distance_node>());
  rclcpp::shutdown();
  return 0;
}