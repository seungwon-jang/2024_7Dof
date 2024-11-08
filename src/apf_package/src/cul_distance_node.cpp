#include <memory>
#include "tf2/LinearMath/Quaternion.h"
#include "tf2_ros/transform_listener.h"
#include "tf2_ros/buffer.h"

#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/string.hpp"
#include "nav_msgs/msg/odometry.hpp"
#include "apf_interfaces/msg/distance.hpp"

#include "fcl/fcl.h"

using std::placeholders::_1;

struct distance_struct{
  double distance_vector;
  double direction_vector;
  int obstacle_num;
}distnace_data;


class cul_distance_node : public rclcpp::Node
{
  public:
    cul_distance_node()
    : Node("cul_distance_node"),
    tf_buffer_(std::make_shared<rclcpp::Clock>(RCL_ROS_TIME)),
    tf_listener_(tf_buffer_)
    {
      //끝단 링크의 위치와 속도를 얻어오기 위해서 플러그인을 구독해서 쓴다.
      subscription_ = this->create_subscription<nav_msgs::msg::Odometry>(
      "/odom", 10, std::bind(&cul_distance_node::topic_callback, this, _1));
      distance_publisher_ = this->create_publisher<apf_interfaces::msg::Distance>("/distance", 10);
      //FCL link와 기본 장애물 설정
      set_fcl();
    }

    //원하는 x,y,z 좌표 전달, 뒤에 3개는 오일러 각도.
    double goal_points[6] = {0.4, 0.4, 0.4, 1.0, 0.5, 2.0};
    double cartisian_distance = 0;
    double cartisian_vector[3]= {0, 0, 0};

    // 장애물과 링크의 위치를 저장할 변수 - fcl에서 사용
    fcl::Transform3d obstacle_transform_;
    fcl::Transform3d obstacle_transform_2;
    fcl::Transform3d test_Transformation;
    fcl::Transform3d link3_Transformation;
    fcl::Transform3d link5_Transformation;
    fcl::Transform3d link7_Transformation;

    fcl::Transform3d obstacle_transform_arr[10];
    fcl::Transform3d link_Transformation_arr[10];
    //링크들을 여기에 모아서 배열로 만든다.
    std::vector<fcl::CollisionObjectd> obstacle;
    std::vector<fcl::CollisionObjectd> link;

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


      //FCL라이브러리 파트
      //link 3,5,7의 회전을 보는 파트
      //world link에서 각 링크로의 위치와 회전을 본다.
      geometry_msgs::msg::TransformStamped transform_link3 = tf_buffer_.lookupTransform("link_0", "link_3", tf2::TimePointZero);
      geometry_msgs::msg::TransformStamped transform_link5 = tf_buffer_.lookupTransform("link_0", "link_5", tf2::TimePointZero);
      geometry_msgs::msg::TransformStamped transform_link7 = tf_buffer_.lookupTransform("link_0", "link_7", tf2::TimePointZero);

      //각 장애물들의 위치는 여기에서 한다.
      Eigen::Translation3d obstacle_trans(0,0,0);
      Eigen::Translation3d obstacle_trans2(0.3,0,0);
      Eigen::Translation3d trans_test(0, 0, 0);


      //각 링크들의 직교 좌표계 이동 저장
      Eigen::Translation3d trans_link3(transform_link3.transform.translation.x,transform_link3.transform.translation.y,transform_link3.transform.translation.z);
      Eigen::Translation3d trans_link5(transform_link5.transform.translation.x,transform_link5.transform.translation.y,transform_link5.transform.translation.z);
      Eigen::Translation3d trans_link7(transform_link7.transform.translation.x,transform_link7.transform.translation.y,transform_link7.transform.translation.z);
      //각 링크들의 회전 쿼터니언 저장
      Eigen::Quaterniond link3_q(transform_link3.transform.rotation.x, transform_link3.transform.rotation.y, transform_link3.transform.rotation.z, transform_link3.transform.rotation.w);
      Eigen::Quaterniond link5_q(transform_link5.transform.rotation.x, transform_link5.transform.rotation.y, transform_link5.transform.rotation.z, transform_link5.transform.rotation.w);
      Eigen::Quaterniond link7_q(transform_link7.transform.rotation.x, transform_link7.transform.rotation.y, transform_link7.transform.rotation.z, transform_link7.transform.rotation.w);
      //얘네들 끼리 곱해서 회전 매트릭스 만들기
      obstacle_transform_arr[0] = obstacle_trans;
      obstacle_transform_arr[1] = obstacle_trans2;
      test_Transformation = trans_test;
      //2개 곱하면 4*4변환행렬로 알아서 만들어 준다.
      link3_Transformation = trans_link3 * link3_q;
      link5_Transformation = trans_link5 * link5_q;
      link7_Transformation = link7_q * trans_link7;
      //그런데 tf3에서는 link의 시작단에 좌표계가 부착되어 있는데, FCL에서 캡슐을 만들때는 중앙에 만든다. - 이 offset 고려해주기.
      Eigen::Translation3d half_length_link3(0,0,0.21);
      Eigen::Translation3d half_length_link5(0,0,0.20);
      Eigen::Translation3d half_length_link7(0,0,0.078);
      Eigen::Quaterniond I_trans(1,0,0,0);
      //transformation을 해준 뒤에 그 좌표계에서 z축 방향으로 절반 이동한 좌표계를 잡아서 밑동이 같은데를 가르키게 변경해준다. 
      link_Transformation_arr[0] = link3_Transformation * (I_trans * half_length_link3);
      link_Transformation_arr[1] = link5_Transformation * (I_trans * half_length_link5);
      link_Transformation_arr[2] = link7_Transformation * (I_trans * half_length_link7);

      RCLCPP_INFO(this->get_logger(), "[%f, %f, %f]", transform_link3.transform.rotation.x, transform_link3.transform.translation.y, transform_link3.transform.translation.z);
      RCLCPP_INFO(this->get_logger(), "[%f, %f, %f]", transform_link5.transform.rotation.x, transform_link5.transform.translation.y, transform_link5.transform.translation.z);
      RCLCPP_INFO(this->get_logger(), "[%f, %f, %f]", transform_link7.transform.rotation.x, transform_link7.transform.translation.y, transform_link7.transform.translation.z);
      //충돌을 감지할 물체들을 정의한다.

      //장애물들 위치 이동시키기
      for (int i = 0 ; i < (int)obstacle.size(); i++){
        obstacle[i].setTransform(obstacle_transform_arr[i]);
      }

      for (int i = 0 ; i < (int)link.size(); i++){
        link[i].setTransform(link_Transformation_arr[i]);
      }
      

      fcl::DistanceRequestd request;
      fcl::DistanceResultd result;
      //장애물의 방향벡터와 거리를 저장하는 배열, 장애물 개수 저장
      std::vector<double> obstacle_distance;
      std::vector<geometry_msgs/Point> obstacle_dirc;
      int obstacle_count = (int)obstacle.size();
      
      // 링크 하나씩 
      for (int i = 0; i < (int)link.size();i++){
        // 각 링크마다 장애물 다 확인하기
        for (int j = 0; j < obstacle_count; j++){
        // 링크와 장애물 간의 거리 계산 시 매번 결과를 초기화
        result.clear();  // 이전 계산의 잔여 값 초기화
        //거리 계산
        fcl::distance(&link[i], &obstacle[j], request, result);
        //최근접 점
        Eigen::Vector3d direction_vector = result.nearest_points[1] - result.nearest_points[0];
        direction_vector.normalize();
        RCLCPP_INFO(this->get_logger(), "Distance between link and obstacle: %f, => [%f, %f, %f]", result.min_distance, direction_vector[0], direction_vector[1], direction_vector[2]);
        }
      }


      //거리 데이터 보내기
      distance_publisher_->publish(pub_distance);
    }

    //fcl에 사용하는 장애물과 링크를 정의하는 파트
    //장애물을 추가로 넣을 경우 다른 함수나 뭐시기를 만들어서 넣어주면 될 것 같다.
    void set_fcl(){

      // FCL 충돌 감지 및 거리 계산 - 이거 된다. 이거 기반으로 뭘 해보면 될듯
      //장애물 정의 - 일단 임시 장애물
      fcl::Sphered obstacle_Sphered(0.1);
      Eigen::Translation3d obstacle_trans(0,0,0);

      //장애물2 
      fcl::Sphered obstacle_Sphered2(0.1);
      Eigen::Translation3d obstacle_trans2(0,0,1.0);

      //거리 테스트할 캡슐 링크 정의하기
      fcl::Capsuled test_capsule(0.1, 0.5);
      Eigen::Translation3d trans_test(0, 0, 0);

      //각 링크에 해당하는 캡슐 만들기
      fcl::Capsuled link3_capsule(0.1, 0.42);
      fcl::Capsuled link5_capsule(0.1, 0.40);
      fcl::Capsuled link7_capsule(0.1, 0.156);

      //각 링크들의 직교 좌표계 이동 저장
      Eigen::Translation3d trans_link3(0,0,0);
      Eigen::Translation3d trans_link5(0,0,0);
      Eigen::Translation3d trans_link7(0,0,0);

      //초기치니까 그냥 대충 넣기
      link3_Transformation = trans_link3;
      link5_Transformation = trans_link3;
      link7_Transformation = trans_link3;

      fcl::CollisionObjectd obstacle_object(std::make_shared<fcl::Sphered>(obstacle_Sphered), obstacle_transform_);
      fcl::CollisionObjectd obstacle_object2(std::make_shared<fcl::Sphered>(obstacle_Sphered2), obstacle_transform_2);
      fcl::CollisionObjectd test_object(std::make_shared<fcl::Capsuled>(test_capsule), test_Transformation);

      fcl::CollisionObjectd link3_object(std::make_shared<fcl::Capsuled>(link3_capsule), link3_Transformation);
      fcl::CollisionObjectd link5_object(std::make_shared<fcl::Capsuled>(link5_capsule), link5_Transformation);
      fcl::CollisionObjectd link7_object(std::make_shared<fcl::Capsuled>(link7_capsule), link7_Transformation);

      //장애물과 링크 배열 정의하기
      obstacle.push_back(obstacle_object);
      obstacle.push_back(obstacle_object2);
      link.push_back(link3_object);
      link.push_back(link5_object);
      link.push_back(link7_object);
    }

    rclcpp::Subscription<nav_msgs::msg::Odometry>::SharedPtr subscription_;
    rclcpp::Publisher<apf_interfaces::msg::Distance>::SharedPtr distance_publisher_;
    tf2_ros::Buffer tf_buffer_;
    tf2_ros::TransformListener tf_listener_;
};

int main(int argc, char * argv[])
{
  rclcpp::init(argc, argv);
  rclcpp::spin(std::make_shared<cul_distance_node>());
  rclcpp::shutdown();
  return 0;
}