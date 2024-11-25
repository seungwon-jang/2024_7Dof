#include <chrono>
#include <memory>
#include <Eigen/Dense>
#include "tf2/LinearMath/Quaternion.h"
#include "tf2_ros/transform_listener.h"
#include "tf2_ros/buffer.h"

#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/string.hpp"
#include "nav_msgs/msg/odometry.hpp"
#include "apf_interfaces/msg/distance.hpp"
#include "apf_interfaces/srv/rrts_points.hpp"

#include "visualization_msgs/msg/marker.hpp"

#include "fcl/fcl.h"

using std::placeholders::_1;
using namespace std::chrono_literals;

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
    tf_listener_(tf_buffer_),
    count_(0)
    {
      //끝단 링크의 위치와 속도를 얻어오기 위해서 플러그인을 구독해서 쓴다.
      subscription_ = this->create_subscription<nav_msgs::msg::Odometry>(
      "/odom", 10, std::bind(&cul_distance_node::topic_callback, this, _1));
      distance_publisher_ = this->create_publisher<apf_interfaces::msg::Distance>("/distance", 10);
      
      //rviz에 출력하는 파트
      marker_publisher_ = this->create_publisher<visualization_msgs::msg::Marker>("vector_marker", 10);

      //RRT 실행시키는 service client
      rrt_client_ = this->create_client<apf_interfaces::srv::RRTSPoints>("rrt_points");

      timer_ = this->create_wall_timer(10ms, std::bind(&cul_distance_node::timer_callback1, this));
      timer2_ = this->create_wall_timer(5000ms, std::bind(&cul_distance_node::timer_callback2, this));
      //FCL link와 기본 장애물 설정
      set_fcl();
      //초기에 설정할 것들 실행
      set_init();
    }

    //원하는 x,y,z 좌표 전달, 뒤에 3개는 오일러 각도.
    double goal_points[6] = {-0.3, -0.5, 0.5, 1.0, 0.5, 2.0};
    //진짜 목표지점의 점
    double init_goal_points[6] = {0.3, 0.5, 0.5, 1.0, 0.5, 2.0};
    //RRTs로 만들어진 점들을 저장할 부분
    std::vector<std::array<double,7>> rrt_result_points;
    double cartisian_distance = 0;
    double cartisian_vector[3]= {0, 0, 0};
    //현재 위치와 회전 성분 저장 - 일단 바로 세워놓은 경우를 초기값으로 넣어 주었다.
    double position[3] = {0.0, 0.0, 1.179};
    double Quater[4] = {-0.001411, -0.001409, 0.706824, 0.707387};

    //장애물 크기
    double obstacle_radidus = 0.15;

    // 장애물과 링크의 위치를 저장할 변수 - fcl에서 사용
    fcl::Transform3d obstacle_transform_;
    fcl::Transform3d obstacle_transform_2;
    fcl::Transform3d test_Transformation;
    fcl::Transform3d link3_Transformation;
    fcl::Transform3d link5_Transformation;
    fcl::Transform3d link7_Transformation;
    //장애물들의 위치를 저장할 변수
    fcl::Transform3d obstacle_transform_arr[10];
    fcl::Transform3d link_Transformation_arr[10];
    //일단 gazebo에 띄워서 움직이는 것을 해보기 전에, Rviz 상에서 먼저 해야하는데, 일단 그거 위치를 아래 변수에 저장해서 넣어줄거다
    double ob1_pose[6] = {0.3,0.3,0.8,0,0,0}; //순서대로 x,y,z, x,y,z방향 들어감(1이면 증가 방향, -1이면 감소 방향, 0아면 정지)
    double ob2_pose[6] = {-0.3,-0.3,0.8,0,0,0};
    int cur_obstacle_count = 0;

    int count_for_rviz = 0;


    int RRT_current_point = 0;

    //링크들을 여기에 모아서 배열로 만든다.
    std::vector<fcl::CollisionObjectd> obstacle;
    std::vector<fcl::CollisionObjectd> link;

  private:
    //odom에서 값이 들어오면, distance 계산해서 값을 출력한다. - 일단 이거의 주기가 얼마인지는 설정하지 않았다.
    void topic_callback(const nav_msgs::msg::Odometry & msg)
    {
      //odom에서 받은 데이터를 받아서 저장하기.
      position[0] = msg.pose.pose.position.x; 
      position[1] = msg.pose.pose.position.y;
      position[2] = msg.pose.pose.position.z;
      Quater[0] = msg.pose.pose.orientation.x;
      Quater[1] = msg.pose.pose.orientation.y;
      Quater[2] = msg.pose.pose.orientation.z;
      Quater[3] = msg.pose.pose.orientation.w;

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
      //목표지점과의 거리 벡터 
      for(int i = 0; i < 3; i++){
        cartisian_vector[i] = (goal_points[i] - position[i])/cartisian_distance;
      }

      //거리가 일정 이상 가까워지면 다음 점으로 옮기기
      if(cartisian_distance < 0.15){
        RRT_current_point++;
        if(RRT_current_point >= (int)rrt_result_points.size())
          RRT_current_point = (int)rrt_result_points.size() - 1; 
        for(int i = 0; i < 7; i++){
          goal_points[i] = rrt_result_points[RRT_current_point][i];
        }
      }

      //RCLCPP_INFO(this->get_logger(), "RRT_point_time_count %d", RRT_current_point);
      //RCLCPP_INFO(this->get_logger(), "(int)rrt_result_points.size() %d", (int)rrt_result_points.size());
      //RCLCPP_INFO(this->get_logger(), "%f, %f, %f", rrt_result_points[RRT_current_point][0], rrt_result_points[RRT_current_point][1], rrt_result_points[RRT_current_point][2]);
      
      //각 좌표계의 거리 측정
      //RCLCPP_INFO(this->get_logger(), "cartisian_distance:'%.4f', cartisian_vector : (%.4f,%.4f,%.4f)", cartisian_distance, cartisian_vector[0],cartisian_vector[1],cartisian_vector[2]);
      
      //RCLCPP_INFO(this->get_logger(), "Quaternion_distance: : (%.4f,%.4f,%.4f)", angle_distance.x(), angle_distance.y(), angle_distance.z() );

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
      Eigen::Translation3d obstacle_trans(ob1_pose[0],ob1_pose[1],ob1_pose[2]);
      Eigen::Translation3d obstacle_trans2(ob2_pose[0],ob2_pose[1],ob2_pose[2]);
      Eigen::Translation3d trans_test(0, 0, 0);


      //각 링크들의 직교 좌표계 이동 저장
      Eigen::Translation3d trans_link3(transform_link3.transform.translation.x,transform_link3.transform.translation.y,transform_link3.transform.translation.z);
      Eigen::Translation3d trans_link5(transform_link5.transform.translation.x,transform_link5.transform.translation.y,transform_link5.transform.translation.z);
      Eigen::Translation3d trans_link7(transform_link7.transform.translation.x,transform_link7.transform.translation.y,transform_link7.transform.translation.z);
      //각 링크들의 회전 쿼터니언 저장
      //Eigen::Quaterniond link3_q(transform_link3.transform.rotation.x, transform_link3.transform.rotation.y, transform_link3.transform.rotation.z, transform_link3.transform.rotation.w);
      //Eigen::Quaterniond link5_q(transform_link5.transform.rotation.x, transform_link5.transform.rotation.y, transform_link5.transform.rotation.z, transform_link5.transform.rotation.w);
      //Eigen::Quaterniond link7_q(transform_link7.transform.rotation.x, transform_link7.transform.rotation.y, transform_link7.transform.rotation.z, transform_link7.transform.rotation.w);
      // 쿼터니언이 이렇게 들어가는 것이 맞는 것 같다 - 위의 방법이 아닌듯
      Eigen::Quaterniond link3_q(transform_link3.transform.rotation.w, transform_link3.transform.rotation.x, transform_link3.transform.rotation.y, transform_link3.transform.rotation.z);
      Eigen::Quaterniond link5_q(transform_link5.transform.rotation.w, transform_link5.transform.rotation.x, transform_link5.transform.rotation.y, transform_link5.transform.rotation.z);
      Eigen::Quaterniond link7_q(transform_link7.transform.rotation.w, transform_link7.transform.rotation.x, transform_link7.transform.rotation.y, transform_link7.transform.rotation.z);

      //회전 행렬로 변환
      Eigen::Matrix3d rotation_matrix3 = link3_q.toRotationMatrix();  // 회전 행렬로 변환
      Eigen::Matrix3d rotation_matrix5 = link5_q.toRotationMatrix();  // 회전 행렬로 변환
      Eigen::Matrix3d rotation_matrix7 = link7_q.toRotationMatrix();  // 회전 행렬로 변환

      //얘네들 끼리 곱해서 회전 매트릭스 만들기
      obstacle_transform_arr[0] = obstacle_trans;
      obstacle_transform_arr[1] = obstacle_trans2;
      test_Transformation = trans_test;

      // 회전을 설정하는 부분
      link3_Transformation.linear() = rotation_matrix3;
      link5_Transformation.linear() = rotation_matrix5;
      link7_Transformation.linear() = rotation_matrix7;

      // 변환을 설정하는 부분
      link3_Transformation.translation() = trans_link3.vector();
      link5_Transformation.translation() = trans_link5.vector();
      link7_Transformation.translation() = trans_link7.vector();

      //transformation을 해준 뒤에 그 좌표계에서 z축 방향으로 절반 이동한 좌표계를 잡아서 밑동이 같은데를 가르키게 변경해준다. 
      link_Transformation_arr[0] = link3_Transformation;
      link_Transformation_arr[1] = link5_Transformation;
      link_Transformation_arr[2] = link7_Transformation;


      //그런데 tf3에서는 link의 시작단에 좌표계가 부착되어 있는데, FCL에서 캡슐을 만들때는 중앙에 만든다. - 이 offset 고려해주기.
      Eigen::Translation3d half_length_link3(0,0,0.21);
      Eigen::Translation3d half_length_link5(0,0,0.20);
      Eigen::Translation3d half_length_link7(0,0,0.078);
      Eigen::Quaterniond I_trans(0,0,0,1);
      //transformation을 해준 뒤에 그 좌표계에서 z축 방향으로 절반 이동한 좌표계를 잡아서 밑동이 같은데를 가르키게 변경해준다. 
      link_Transformation_arr[0] = link3_Transformation * (I_trans * half_length_link3);
      link_Transformation_arr[1] = link5_Transformation * (I_trans * half_length_link5);
      link_Transformation_arr[2] = link7_Transformation * (I_trans * half_length_link7);

      //RCLCPP_INFO(this->get_logger(), "[%f, %f, %f], [%f, %f, %f, %f]",trans_link3.x() ,trans_link3.y() ,trans_link3.z() , transform_link3.transform.rotation.x, transform_link3.transform.rotation.y, transform_link3.transform.rotation.z, transform_link7.transform.rotation.w);
      //RCLCPP_INFO(this->get_logger(), "[%f, %f, %f], [%f, %f, %f, %f]",trans_link5.x() ,trans_link5.y() ,trans_link5.z() , transform_link5.transform.rotation.x, transform_link5.transform.rotation.y, transform_link5.transform.rotation.z, transform_link7.transform.rotation.w);
      //RCLCPP_INFO(this->get_logger(), "[%f, %f, %f], [%f, %f, %f, %f]",trans_link7.x() ,trans_link7.y() ,trans_link7.z() , transform_link7.transform.rotation.x, transform_link7.transform.rotation.y, transform_link7.transform.rotation.z, transform_link7.transform.rotation.w);
      //충돌을 감지할 물체들을 정의한다.

      // 사용 예시 - callback이나 main 함수에서 link3_Transformation 출력
      printTransform3d(link5_Transformation, this->get_logger());


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
      std::vector<geometry_msgs::msg::Point> obstacle_dirc;
      int obstacle_count = (int)obstacle.size();
      int link_count = (int)link.size();

      // 링크 하나씩 
      for (int i = 0; i < link_count ;i++){
        // 각 링크마다 장애물 다 확인하기
        for (int j = 0; j < obstacle_count; j++){
        // 링크와 장애물 간의 거리 계산 시 매번 결과를 초기화
        result.clear();  // 이전 계산의 잔여 값 초기화
        //거리 계산
        fcl::distance(&link[i], &obstacle[j], request, result);
        //최근접 점의 방향 벡터 (링크에서 장애물 방향)
        Eigen::Vector3d direction_vector = result.nearest_points[1] - result.nearest_points[0];
        direction_vector.normalize();
        //구한 값들 대입하기
        obstacle_distance.push_back(result.min_distance);
        geometry_msgs::msg::Point p;
        p.x = direction_vector[0];
        p.y = direction_vector[1];
        p.z = direction_vector[2];

        obstacle_dirc.push_back(p);

        //RCLCPP_INFO(this->get_logger(), "Distance between link%d and obstacle%d: %f, => [%f, %f, %f]", 1+ (i+1)*2, j,result.min_distance, direction_vector[0], direction_vector[1], direction_vector[2]);
        }
      }

      pub_distance.obstacle_distance = obstacle_distance;
      pub_distance.obstacle_direction_vector = obstacle_dirc;
      pub_distance.obstacle_count = obstacle_count;
      pub_distance.link_count = link_count;


      //rviz가 너무 많이 받아 정신을 못차리는 것 같아서 이래함 - 동시에 이래 보내면 문제가 생긴다.
      if(count_for_rviz < 20){
        count_for_rviz++;
      }
      else{
        count_for_rviz = 0;
        publish_obstacle(obstacle_trans.x(), obstacle_trans.y(), obstacle_trans.z(), obstacle_radidus, "obstacle1", 2);
      }
      if(count_for_rviz == 10)
        publish_obstacle(obstacle_trans2.x(), obstacle_trans2.y(), obstacle_trans2.z(), obstacle_radidus, "obstacle2", 3);

      //거리 데이터 보내기
      distance_publisher_->publish(pub_distance);
    }

    void printTransform3d(const fcl::Transform3d& transform, rclcpp::Logger logger) {
    // 변환 행렬을 Eigen 형식으로 변환하고 포맷 지정
    Eigen::IOFormat format(Eigen::StreamPrecision, Eigen::DontAlignCols, ", ", "\n", "[", "]", "[", "]");
    std::stringstream ss;
    ss << transform.matrix().format(format);  // fcl::Transform3d의 행렬 부분을 문자열로 변환

    // ROS2 로그로 변환 행렬 출력
    //RCLCPP_INFO(logger, "link3_Transformation:\n%s", ss.str().c_str());
    }

    //fcl에 사용하는 장애물과 링크를 정의하는 파트
    //장애물을 추가로 넣을 경우 다른 함수나 뭐시기를 만들어서 넣어주면 될 것 같다.
    void set_fcl(){

      // FCL 충돌 감지 및 거리 계산 - 이거 된다. 이거 기반으로 뭘 해보면 될듯
      //장애물 정의 - 일단 임시 장애물
      fcl::Sphered obstacle_Sphered(obstacle_radidus);
      Eigen::Translation3d obstacle_trans(ob1_pose[0],ob1_pose[1],ob1_pose[2]);

      //장애물2 
      fcl::Sphered obstacle_Sphered2(obstacle_radidus);
      Eigen::Translation3d obstacle_trans2(ob2_pose[0],ob2_pose[1],ob2_pose[2]);
      //현재 장애물 개수 설정
      cur_obstacle_count = 2;
      //거리 테스트할 캡슐 링크 정의하기 - 지금 이건 안씀
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
      link5_Transformation = trans_link5;
      link7_Transformation = trans_link7;

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
    //초기 셋팅 설정
    void set_init(){
      //한번 이동할 때마다 이동할 거리 설정 - timer callback 실행 시간 * 1초당 갈 시간 해주면 될듯.
      //ob1_pose[3] = 0.01 * 0.2;
      ob1_pose[4] = 0.01 * 0.1;
      //ob2_pose[3] = 0.01 * 0.2;
      ob2_pose[4] = 0.01 * 0.1;
      }

    //이 함수는 구형 장애물을 rviz 상에 표현하려고 만든 함수이다.
    void publish_obstacle(double obstacle_x, double obstacle_y, double obstacle_z, double radius, const std::string& maker_namespace, int marker_id) 
    {
      ////////////여기는 목표 점을 만드는 파트
      auto target_marker = visualization_msgs::msg::Marker();
      target_marker.header.frame_id = "world";  // RViz에서 사용하는 기준 프레임
      target_marker.header.stamp = this->get_clock()->now();
      
      target_marker.ns = maker_namespace;
      target_marker.id = marker_id;  // 마커 아이디
      target_marker.type = visualization_msgs::msg::Marker::SPHERE;  // 구형 장애물로 표시
      target_marker.action = visualization_msgs::msg::Marker::ADD;

      // 위치 설정
      target_marker.pose.position.x = obstacle_x;
      target_marker.pose.position.y = obstacle_y;
      target_marker.pose.position.z = obstacle_z;

      // 크기 설정 (반지름을 반영)
      target_marker.scale.x = radius * 2;  // 구형의 직경
      target_marker.scale.y = radius * 2;
      target_marker.scale.z = radius * 2;

      // 색상과 투명도 설정
      target_marker.color.a = 1.0;  // 투명도
      target_marker.color.b = 1.0;  // 파란색

      // 마커 퍼블리시
      marker_publisher_->publish(target_marker);
    }

    //장애물 위치를 여기서 변경하자 ,x,y,z값으로 범위를 조정하고, time_const 값을 이용하여, 이 함수를 실행시킬떄 마다 움직일 거리를 넣는다/
    //ob_pose_arr에는 xyz좌표, 뒤에 3개는 속도 비율이 들어간다. - 함수를 한번 실행할 때마다, 해당 값 만큼 이동한다
    void change_obstacle_position(double ob_pose_arr[] ,double x_range, double y_range, double z_range){
      //어차피 장애물의 위치는 x,y,z, 방향 6개일 거니까 함수의 크기는 받지 않는다.
      //x축 이동
      double range_arr[3] = {x_range, y_range, z_range};

      for(int i = 0; i < 3; i++){
        //일단 더해본다
        ob_pose_arr[i] += ob_pose_arr[i+3];
        //만약 범위를 +-로 벗어나면 이동 속도 부호 바꾸기
        if(ob_pose_arr[i] > range_arr[i] || ob_pose_arr[i] < -range_arr[i]){
          ob_pose_arr[i+3] = -1 * ob_pose_arr[i+3];
          //그리고 이동해 놓았던 것 수습하기
          ob_pose_arr[i] += 2 * ob_pose_arr[i+3];
        }
      }

      //RCLCPP_INFO(this -> get_logger(), "opstacle pose : %f, %f, %f", ob_pose_arr[0], ob_pose_arr[1],ob_pose_arr[2]);
    }
    int moving_flag = 0;
    //int RRT_point_time_count = 0;
    //int RRT_current_point = 0;
    //장애물 위치 갱신 파트 - 지금은 0.01초마다 실행
    void timer_callback1()
    {
      change_obstacle_position(ob1_pose, 0.5, 0.5, 0.5);
      change_obstacle_position(ob2_pose, 0.5, 0.5, 0.5);
      /* //임시로 목표지점을 움직이게 한 경우
      if(moving_flag == 0){
        if(goal_points[1] < 0.6)
          goal_points[1] = goal_points[1] + 0.01 * 0.1;
        else moving_flag = 1;  
      }
      else if(moving_flag == 1){
        if(goal_points[1] > -0.6)
          goal_points[1] = goal_points[1] - 0.01 * 0.1;
        else moving_flag = 0;
      }
      RCLCPP_INFO(this -> get_logger(), "goal point : %f, %f, %f", goal_points[0], goal_points[1],goal_points[2]);
      */
     //0.01 * 30 = 0.3초
     /*
      if(RRT_point_time_count > 30){
        for(int i = 0; i < 3; i++){
          rrt_result_points[RRT_point_time_count][i];
        }

        if(RRT_current_point >= (int)rrt_result_points.size())
          RRT_point_time_count = 0;
      }
      RRT_point_time_count++;
      */
      //RCLCPP_INFO(this -> get_logger(), "goal point : %f, %f, %f", goal_points[0], goal_points[1],goal_points[2]);
      
    }
    

    //500ms 마다 타이머 콜백 일어남 -> 일단 서비스 확인해 보려고 했던거고, 실제 코드에서는 이렇게는 말고 조금 다르게 해아할 것 같다.
    //예를 들어 보자면, end_effector와 장애물이 너무 가까워지면, client를 실행시켜서, RRT로 경로 다시 받아오는 형태를 지니는 게 좋을듯
    int mack_path_flag = 0;
    void timer_callback2()
    {
      if(mack_path_flag == 0)
      {
        ///////////////
      //서비스 클라이언트를 여기서 보낸다.
      ///////////////
      //보낼 클라이언트 형태 설정
      auto request = std::make_shared<apf_interfaces::srv::RRTSPoints::Request>();
      //좌표를 x,y,z 순으로 이렇게 저장한다.
      std::vector<double> obstacles;
      //깔끔하진 않지만, 나중에, 장애물 설정할 때, 하나의 배열에 넣어서 하는 것으로 하자. 지금은 좀 바빠서... 미래의 나야 파이팅
      for(int i = 0; i < 3; i++){
        obstacles.push_back(ob1_pose[i]);
      }
      obstacles.push_back(obstacle_radidus);
      for(int i = 0; i < 3; i++){
        obstacles.push_back(ob2_pose[i]);
      }
      obstacles.push_back(obstacle_radidus);

      //장애물 위치, 숫자 보낼 변수에 저장
      request -> obstacle_points = obstacles;
      request -> obstacle_count = cur_obstacle_count;
      ////////////////////////
      //시작, 목표점 변환해서 넣기
      ////////////////////////
      std::vector<double> start_point, end_point;
      //시작 점의 postition 값 넣고, 그 뒤에 쿼터니언 값 넣기
      for(int i = 0; i < 3; i++)
        start_point.push_back(position[i]);
      for(int i = 0; i < 4; i++)
        start_point.push_back(Quater[i]);
      //목표 점의 경우 조금 달라서 좀 다르게 해야한다.
      //목표 roll pitch yaw 쿼터니안으로 변환해서 저장하고, 현재 값도 쿼터니안으로 변환해서 저장하기
      tf2::Quaternion end_Quater;
      end_Quater.setRPY(init_goal_points[3], init_goal_points[4], init_goal_points[5]);
      for(int i = 0; i < 3; i++)
        end_point.push_back(init_goal_points[i]);
      end_point.push_back(end_Quater.x());
      end_point.push_back(end_Quater.y());
      end_point.push_back(end_Quater.z());
      end_point.push_back(end_Quater.w());

      //변환한 애들 변수에 넣기
      request->start_point = start_point;
      request->end_point = end_point;
      
      RCLCPP_INFO(this->get_logger(), "end_point_to_RRTs %f, %f, %f, %f, %f, %f, %f", end_point[0], end_point[1], end_point[2], end_point[3], end_point[4], end_point[5], end_point[6]);
      RCLCPP_INFO(this->get_logger(), "init_end_point_to_RRTs %f, %f, %f, %f, %f, %f, %f", init_goal_points[0], init_goal_points[1], init_goal_points[2], init_goal_points[3], init_goal_points[4], init_goal_points[5], init_goal_points[6]);


      //비동기 신호 전송
       auto future = rrt_client_->async_send_request(request,
            std::bind(&cul_distance_node::RRTs_result, this, std::placeholders::_1));
      //mack_path_flag = 1;
      }
      
    }


    //서비스 클라이언트로 메세지를 보낸 후 실행시킬 함수
    void RRTs_result(rclcpp::Client<apf_interfaces::srv::RRTSPoints>::SharedFuture future){
      auto response = future.get();
      //RCLCPP_INFO(this -> get_logger(), "result_points : %f, %f, %f, %f, %f, %f, %f, %f,", response -> result_points[0], response -> result_points[1], response -> result_points[2], response -> result_points[3], response -> result_points[4], response -> result_points[5], response -> result_points[6], response -> result_points[7]);
      rrt_result_points.clear();
      for (int i = 0; i < ((response -> result_points).size()/7); i++){
        std::array<double, 7> new_point;
        new_point[0] = response -> result_points[7*i + 0];
        new_point[1] = response -> result_points[7*i + 1];
        new_point[2] = response -> result_points[7*i + 2];
        new_point[3] = response -> result_points[7*i + 3];
        new_point[4] = response -> result_points[7*i + 4];
        new_point[5] = response -> result_points[7*i + 5];
        new_point[6] = response -> result_points[7*i + 6];
        rrt_result_points.push_back(new_point);
      }
      //초기 값 뽑기
      for (int i = 0; i < 7 ; i++){
        goal_points[0] = rrt_result_points[0][0];
        goal_points[1] = rrt_result_points[0][1];
        goal_points[2] = rrt_result_points[0][2];
        goal_points[3] = rrt_result_points[0][3];
        goal_points[4] = rrt_result_points[0][4];
        goal_points[5] = rrt_result_points[0][5];
        goal_points[6] = rrt_result_points[0][6];
        //RCLCPP_INFO(this->get_logger(), "new_count: %f, %f, %f", goal_points[0], goal_points[1], goal_points[2]);
      }
      RRT_current_point = 0;
      //RCLCPP_INFO(this->get_logger(), "Received point_count: %ld", response->point_count);
    }


    rclcpp::Publisher<visualization_msgs::msg::Marker>::SharedPtr marker_publisher_;
    rclcpp::Subscription<nav_msgs::msg::Odometry>::SharedPtr subscription_;
    rclcpp::Publisher<apf_interfaces::msg::Distance>::SharedPtr distance_publisher_;
    rclcpp::Client<apf_interfaces::srv::RRTSPoints>::SharedPtr rrt_client_;
    tf2_ros::Buffer tf_buffer_;
    tf2_ros::TransformListener tf_listener_;
    rclcpp::TimerBase::SharedPtr timer_;
    rclcpp::TimerBase::SharedPtr timer2_;
    size_t count_;
};

int main(int argc, char * argv[])
{
  rclcpp::init(argc, argv);
  rclcpp::spin(std::make_shared<cul_distance_node>());
  rclcpp::shutdown();
  return 0;
}