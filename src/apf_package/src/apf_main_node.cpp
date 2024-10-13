#include <memory>

#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/string.hpp"
using std::placeholders::_1;

class apf_main_node : public rclcpp::Node
{
  public:
    apf_main_node()
    : Node("apf_main_node")
    {
      subscription_ = this->create_subscription<std_msgs::msg::String>(
      "/jacobian", 10, std::bind(&apf_main_node::topic_callback, this, _1));
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
  rclcpp::spin(std::make_shared<apf_main_node>());
  rclcpp::shutdown();
  return 0;
}