#include <memory>

#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/string.hpp"
using std::placeholders::_1;

class cul_distance_node : public rclcpp::Node
{
  public:
    cul_distance_node()
    : Node("cul_distance_node")
    {
      subscription_ = this->create_subscription<std_msgs::msg::String>(
      "/link_pose", 10, std::bind(&cul_distance_node::topic_callback, this, _1));
    }

  private:
    void topic_callback(const std_msgs::msg::String & msg) const
    {
      RCLCPP_INFO(this->get_logger(), "I heard: '%s'", msg.data.c_str());
    }
    rclcpp::Subscription<std_msgs::msg::String>::SharedPtr subscription_;
};

int main(int argc, char * argv[])
{
  rclcpp::init(argc, argv);
  rclcpp::spin(std::make_shared<cul_distance_node>());
  rclcpp::shutdown();
  return 0;
}