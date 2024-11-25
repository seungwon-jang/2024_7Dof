#include <chrono>
#include <functional>
#include <memory>
#include <string>
#include <Eigen/Dense>
#include <random>

#include <visualization_msgs/msg/marker.hpp>
#include <visualization_msgs/msg/marker_array.hpp>
#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/string.hpp"
#include "apf_interfaces/srv/rrts_points.hpp"

#include "fcl/fcl.h"

using namespace std::chrono_literals;


class Path_planning_node : public rclcpp::Node
{
  public:
    Path_planning_node()
    : Node("Path_planning_node"), count_(0)
    {
      publisher_ = this->create_publisher<std_msgs::msg::String>("topic", 10);
      timer_ = this->create_wall_timer(
      500ms, std::bind(&Path_planning_node::timer_callback, this));

      rrt_server_ = this->create_service<apf_interfaces::srv::RRTSPoints>(
        "rrt_points", std::bind(&Path_planning_node::rrt_service_callback, this, 
        std::placeholders::_1, std::placeholders::_2));

      marker_array_pub_ = this->create_publisher<visualization_msgs::msg::MarkerArray>("visualization_marker_array", 10);
    }

    //RRTs에서 사용할 노드를 이렇게 정리하였다.
    //x,y,z
    //x,y,z,w순으로 넣었다.
    struct RRTs_node{
      std::array<double, 3> position = {0,};
      int parent_index = 0;
      double current_dis = 0;
    }; 
    typedef struct RRTs_node R_node;

  private:
    void timer_callback()
    {
      auto message = std_msgs::msg::String();
      message.data = "Hello, world! " + std::to_string(count_++);
      //RCLCPP_INFO(this->get_logger(), "Publishing: '%s'", message.data.c_str());
      publisher_->publish(message);

    }

    // 서비스 콜백 함수 - 장애물의 위치가 여기에서 들어올 것이니까, 받으면, RRTs_function 수행해서 거리 계산한 후 그 값을 줄거다.
    void rrt_service_callback(const std::shared_ptr<apf_interfaces::srv::RRTSPoints::Request> request,
                               std::shared_ptr<apf_interfaces::srv::RRTSPoints::Response> response)
    {
      //최종 결과 점을 저장할 배열
      std::vector<double> result_points;

      //rrts의 결과를 통해 얻은 배열 - x, y, z 값이 순서대로 들어있다
      std::vector<double> RRTs_result = RRTs_function(request->obstacle_points, request->obstacle_count, request->start_point, request->end_point, 0.1);
      int RRTs_reuslt_size = RRTs_result.size() / 3;

      //Slerp의 결과를 통해 얻은 배열 - x, y, z, w 값이 순서대로 들어있다
      std::vector<double> Slerp_result = quarter_Slerp(request->start_point, request->end_point, RRTs_reuslt_size);

      //일단 데이터를 저장할 result_points의 크기 정하기 -> vector로 하기에는 하나하나 push_back이 비효울적
      result_points.reserve(RRTs_result.size() + Slerp_result.size());

      size_t index1 = 0, index2 = 0;
      while (index1 < RRTs_result.size() || index2 < Slerp_result.size()){
        //RRT 쪽에 여유가 있는 경우
        if(index1 < RRTs_result.size()){
          size_t copy_count = 3;
          result_points.insert(result_points.end(), RRTs_result.begin() + index1, RRTs_result.begin() + index1 + copy_count);
          index1 += copy_count;
        }
        if(index2 < Slerp_result.size()){
          size_t copy_count = 4;
          result_points.insert(result_points.end(), Slerp_result.begin() + index2, Slerp_result.begin() + index2 + copy_count);
          index2 += copy_count;
        }

      }


      RCLCPP_INFO(this -> get_logger(), "RRT : %f, %f, %f, %f, %f, %f,", RRTs_result[0], RRTs_result[1], RRTs_result[2], RRTs_result[3], RRTs_result[4], RRTs_result[5]);
      RCLCPP_INFO(this -> get_logger(), "slerp : %f, %f, %f, %f, %f, %f, %f, %f,", Slerp_result[0], Slerp_result[1], Slerp_result[2], Slerp_result[3], Slerp_result[4], Slerp_result[5], Slerp_result[6], Slerp_result[7]);
      RCLCPP_INFO(this -> get_logger(), "result_points : %f, %f, %f, %f, %f, %f, %f, %f,", result_points[0], result_points[1], result_points[2], result_points[3], result_points[4], result_points[5], result_points[6], result_points[7]);

      response-> result_points = result_points;
      response-> point_count = RRTs_reuslt_size; //RRTs 노드의 결과를 통해 나온 노드의 개수가 사이즈랑 같다.
      //RCLCPP_INFO(this->get_logger(), "Incoming request: %ld", request->obstacle_count);
      //RCLCPP_INFO(this->get_logger(), "Sending back response: [%ld]", response->point_count);
    }

    //RRT* 메인 함수 - 여기서 메인 작업 수행 - 장애물 위치와 개수, 시작지점, 목표지점 좌표, step 범위를 입력받고 RRT*를 수행해서 완료 점들을 반환한다. 
    std::vector<double> RRTs_function(std::vector<double> obstacle_points, int obstacle_count, std::vector<double> start_point, std::vector<double> end_point, double step_range = 0.05, int max_try = 1000000){
        //장애물 지우기
        delete_rrt_points();
        //장애물의 경우 잘 들어온다. - 이 밑에 로그 띄우는게 그거 값임
        //RCLCPP_INFO(this->get_logger(), "obstacle_count: [%ld]", obstacle_count);
        //RCLCPP_INFO(this->get_logger(), "obstacle_points %lf, %lf, %lf, %lf, %lf, %lf, %lf, %lf", obstacle_points[0], obstacle_points[1], obstacle_points[2], obstacle_points[3], obstacle_points[4], obstacle_points[5], obstacle_points[6], obstacle_points[7]);
        //RCLCPP_INFO(this->get_logger(), "start_point %lf, %lf, %lf, %lf, %lf, %lf, %lf", start_point[0], start_point[1], start_point[2], start_point[3], start_point[4], start_point[5], start_point[6]);
        //RCLCPP_INFO(this->get_logger(), "end_point %lf, %lf, %lf, %lf, %lf, %lf, %lf", end_point[0], end_point[1], end_point[2], end_point[3], end_point[4], end_point[5], end_point[6]);
        
        //일단 끝날때까지 바뀌지 않는 변수들을 여기 선언해 놓자
        //만들어가는 트리를 여기에 저장할거다.
        std::vector<R_node> RRTs_tree;
        R_node first_node;
        first_node.position[0] = start_point[0];
        first_node.position[1] = start_point[1];
        first_node.position[2] = start_point[2];
        first_node.current_dis = 0;
        first_node.parent_index = -1;
        RRTs_tree.push_back(first_node);

        //결과로 나온 것들을 좌표만 변환해서 이렇게 넣을 것이다.
        std::vector<double> RRTs_result;              //마지막에 출력할 결과 값
        std::vector<std::array<double,3>> points;     //rviz에 시각화 할때 보내려고 이렇게 저장했다.

        //이거는 랜덤 점 생성관련 변수들
        std::array<double, 3> conter_point = {0,0,0.36};
        double min_radius = 0.42;
        double max_radius = 0.974;
        //점 몇개 만들었는지 세기
        int point_count = 1;


        //일단 끝날 때까지 무한 반복해야한다.
        while(true){

          ///////////////RRT만 쓴경우
          /*
          //RRT에서 먼저 할 것은 랜덤 점 생성하기
          //근데, workspace 안에서 점을 만들어야 한다.
          std::array<double, 3> random_point;
          random_point = make_random_point(conter_point, max_radius);
          
          //가장 가까운 점 찾기
          int nearest_point_index = find_nearest_point(RRTs_tree, random_point);
          std::array<double,3> nearest_point_arr = {RRTs_tree[nearest_point_index].position[0], RRTs_tree[nearest_point_index].position[1], RRTs_tree[nearest_point_index].position[2]};

          //랜덤 점과 가장 가까운 점 사이의 방향 벡터 방향으로 띄어진 곳에 점 찍기
          //방향 벡터를 위한 거리 계산
          double new_point_distance = sqrt(pow(random_point[0] - nearest_point_arr[0],2) + pow(random_point[1] - nearest_point_arr[1],2) + pow(random_point[2] - nearest_point_arr[2],2));
          std::array<double,3> new_point = {step_range*((random_point[0] - nearest_point_arr[0])/new_point_distance) + nearest_point_arr[0] , step_range*((random_point[1] - nearest_point_arr[1])/new_point_distance) + nearest_point_arr[1], step_range*((random_point[2] - nearest_point_arr[2])/new_point_distance) + nearest_point_arr[2]};
          //RCLCPP_INFO(this->get_logger(), " nearest_point_arr : %f, %f, %f", nearest_point_arr[0], nearest_point_arr[1], nearest_point_arr[2]);
          //RCLCPP_INFO(this->get_logger(), " new_point : %f, %f, %f", new_point[0], new_point[1], new_point[2]);

          //만약 새로운 점과 이은 직선이 충돌이 일어나지 않는다면
          if (collision_test(nearest_point_arr, new_point, obstacle_points, obstacle_count, min_radius) == true){
            //새로 노드 넣을 구조체 변수를 만들고, 점 좌표, 부모 인덱스, 부모까지의 거리 + 새로 추가된 거리 해서 계산해 준다.
            R_node new_node;
            new_node.position = new_point;
            new_node.parent_index = nearest_point_index;
            new_node.current_dis = RRTs_tree[nearest_point_index].current_dis + new_point_distance;
            //배열에 넣기
            //points.push_back(new_point);
            RRTs_tree.push_back(new_node);
            //RCLCPP_INFO(this -> get_logger(), "in if : %d", point_count);
          }

          */

          ///////////////////////////////////////
          //이거 전에는 범위 내에서 랜덤 점 만들어야 한다.
          //RRT*의 경우에도 먼저 할 것은 랜덤 점 생성하기
          //근데, workspace 안에서 점을 만들어야 한다.
          std::array<double, 3> random_point;
          random_point = make_random_point(conter_point, max_radius);
          //가장 가까운 점 찾기
          int nearest_point_index = find_nearest_point(RRTs_tree, random_point);
          std::array<double,3> nearest_point_arr = {RRTs_tree[nearest_point_index].position[0], RRTs_tree[nearest_point_index].position[1], RRTs_tree[nearest_point_index].position[2]};
          //그 방향으로 새로운 점을 찍는다.
          double new_point_distance = sqrt(pow(random_point[0] - nearest_point_arr[0],2) + pow(random_point[1] - nearest_point_arr[1],2) + pow(random_point[2] - nearest_point_arr[2],2));
          std::array<double,3> new_point = {step_range*((random_point[0] - nearest_point_arr[0])/new_point_distance) + nearest_point_arr[0] , step_range*((random_point[1] - nearest_point_arr[1])/new_point_distance) + nearest_point_arr[1], step_range*((random_point[2] - nearest_point_arr[2])/new_point_distance) + nearest_point_arr[2]};

          //만약 새로운 점과 이은 직선이 충돌이 일어나지 않는다면
          if (collision_test(nearest_point_arr, new_point, obstacle_points, obstacle_count, min_radius) == true){
            //새로 노드 넣을 구조체 변수를 만들고, 점 좌표, 부모 인덱스, 부모까지의 거리 + 새로 추가된 거리 해서 계산해 준다.
            R_node new_node;
            new_node.position = new_point;
            new_node.parent_index = nearest_point_index;
            new_node.current_dis = RRTs_tree[nearest_point_index].current_dis + new_point_distance;
            //배열에 넣기
            //points.push_back(new_point);
            RRTs_tree.push_back(new_node);
            //RCLCPP_INFO(this -> get_logger(), "in if : %d", point_count);
          }
          /////////////////////
          //rrt에 의해 새로운 점을 만들었다면 일단 해당 내용을 저장한다.


          //RRT*에서 트리를 재구성하는 파트
          remake_tree(RRTs_tree, obstacle_points, obstacle_count, 0.5);


          //만약 도착지점에 들어오면 실행되는 파트
          if (goal_check(new_point, end_point, step_range) == true){

            RCLCPP_INFO(this -> get_logger(), "find_path : %d", point_count);
            //마지막 인덱스는 사이즈 - 1과 같겠지
            int current_index = RRTs_tree.size() - 1;
            //마지막 점과 도착지점을 이어주자.
            R_node end_node;
            for(int i =0; i < 3; i++)
              end_node.position[i] = end_point[i];
            end_node.parent_index = current_index;
            end_node.current_dis = RRTs_tree[current_index].current_dis + step_range;
            RRTs_tree.push_back(end_node);
            //하나늘었으니 마지막 인덱스 값 1늘려주기, RRT*로 마지막 점에 대해 최적화 실행시켜주기
            current_index += 1; 
            remake_tree(RRTs_tree, obstacle_points, obstacle_count, 0.5);

            //최종 경로 재생성하기
            //이떄는 노드안에 거리를 저장할 필요가 없다고 생각하여(RRT* 할 필요가 없으니까) 저장을 안한다.
            remake_final_path(RRTs_tree, current_index, 0.05);

            //최종 경로점 만들기

            //부모노드가 -1로 설정된 마지막 노드를 넣을 후 일때 까지 반복하기
            while(current_index != -1){
              //RRTs의 result에 앞에서부터 지금의 position 넣기
              for (int i = 2; i >=0; i--){
                RRTs_result.insert(RRTs_result.begin(), RRTs_tree[current_index].position[i]);
              }
              points.push_back(RRTs_tree[current_index].position);
              //지금의 부모노드를 저장해서 다음 부모노드로 가기
              current_index = RRTs_tree[current_index].parent_index;
              RCLCPP_INFO(this -> get_logger(), "current index : %d", current_index);
            }
            break;
          }
            
          //횟수 제한
          if(point_count == max_try) break;
          point_count++;
        }
        
        publish_rrt_points(points);

        //장애물 거리 계산 테스트
        //std::array<double,3> test_pre = {0.1, 0.1, 0.8};
        //std::array<double,3> test_new = {-0.1, -0.1, 0.8};
        //collision_test(test_pre, test_new, obstacle_points, obstacle_count, min_radius);



        //최종으로 나온 경로를 여기서 출력할 것이다. 지금은 테스트로 RRTs_tree를 출력한 것.
        return RRTs_result;
    }

    ////////////////////////////////////////
    //workspace 내에서 랜덤으로 점 찍는 함수
    //최소 반지름과, 최대 반지름 사이의 공간에 점을 만든다.
    ///////////////////////////////////////
    std::array<double, 3> make_random_point(const std::array<double, 3>& center, double radius) {
      std::random_device rd;
      std::mt19937 gen(rd());
      std::uniform_real_distribution<> dis(0.0, 1.0);  // 0과 1 사이의 난수 생성

      double theta = dis(gen) * 2 * M_PI;  // 0 ~ 2π 사이의 각도
      double phi = acos(1 - 2 * dis(gen)); // 0 ~ π 사이의 각도
      double r = radius * std::cbrt(dis(gen));  // 구 내부 균일 분포를 위해 세제곱근 사용

      // 구면 좌표계에서 직교 좌표계로 변환하는 식이다.
      double x = r * sin(phi) * cos(theta);
      double y = r * sin(phi) * sin(theta);
      double z = r * cos(phi);

      // 구의 중심을 기준으로 좌표 이동
      x = center[0] + x;
      y = center[1] + y;
      z = center[2] + z;
      //땅에 박으면 안되니까 값 클리핑 해주기
      if(z < 0.05) z = 0.05;
      return {x,y,z};
    }

    /////////////////////
    //두 점 사이 거리 계산 함수
    /////////////////////
    double two_point_distance(std::array<double,3> first_point, std::array<double, 3> second_point){
      double distance = sqrt(pow(first_point[0] - second_point[0] ,2) + pow(first_point[1] - second_point[1] ,2) + pow(first_point[2] - second_point[2] ,2));
      return distance;
    }

    /////////////////////
    //새로 생긴 점과 저장된 노드 중에서 가장 가까운 점 찾기
    int find_nearest_point(std::vector<R_node> point_stuct_arr,std::array<double,3> new_point_arr){
      int result_index = 0;
      double min_distance = 9999999;

      for (int i = 0; i < (int)point_stuct_arr.size(); i++){
        //첫번째 점부터 거리 계산
        double cur_distance = std::pow(new_point_arr[0] - point_stuct_arr[i].position[0], 2) + std::pow(new_point_arr[1] - point_stuct_arr[i].position[1], 2) + std::pow(new_point_arr[2] - point_stuct_arr[i].position[2], 2);

        if(cur_distance < min_distance){
          min_distance = cur_distance;
          result_index = i;
        }
      }
      return result_index;
    }

    //장애물이랑 충돌하는지? - 충돌하면 -1 반환하고, 충돌을 안하면 1 반환한다.
    //장애물 전부와, 새로 선을 그을 점 2개의 값을 받아와서 충돌을 계산한다
    //fcl을 여기에 써고 괜찮지 않을까?
    //일단 장애물을 모두 구형으로 가정하자.
    //추후에 장애물의 종류를 받아오고, 그게에 맞게 CollisionObject를 설정해 주는 조건문을 넣어주면 될 듯하다
    bool collision_test(std::array<double,3> pre_point_arr, std::array<double,3> new_point_arr, std::vector<double> obstacle_points, int obstacle_count , double obstacle_min_radius = 0.42, double collision_gap = 0.1){
      //각 점을 정의
      Eigen::Vector3d pre_point(pre_point_arr[0], pre_point_arr[1], pre_point_arr[2]);
      Eigen::Vector3d end_point(new_point_arr[0], new_point_arr[1], new_point_arr[2]);
      
      //충돌을 감지할 배열 정의
      std::vector<fcl::CollisionObjectd> objects;

      //차이를 계산한 뒤에 두 점 사이의 거리와 방향벡터를 구한다.
      Eigen::Vector3d direction = end_point - pre_point;
      double length = direction.norm();
      direction.normalize();

      ///////////////////
      //선을 정의
      ///////////////////
      fcl::Capsuled line(collision_gap, length);
      fcl::Transform3d line_trans;
      //중간점을 정해서 위치 설정
      line_trans.translation() = (end_point + pre_point) / 2.0;
      //회전 설정
      Eigen::Matrix3d rotation;
      rotation = Eigen::Quaterniond::FromTwoVectors(Eigen::Vector3d::UnitZ(), direction);
      line_trans.linear() = rotation;
      //CollisionObjectd 설정
      fcl::CollisionObjectd line_object(std::make_shared<fcl::Capsuled>(line), line_trans);
      objects.push_back(line_object);

      /////////////
      //장애물
      /////////////
      //장애물 개수만큼 반복해서 충돌 오브젝트 정의하기
      for(int i = 0; i < obstacle_count; i++){
        //4번째에 크기가 있다.
        fcl::Sphered obstacle(obstacle_points[i*4 + 3]);
        fcl::Transform3d obstacle_trans;
        //이동 성분 넣기
        Eigen::Translation3d Eigen_trance(obstacle_points[i*4 + 0], obstacle_points[i*4 + 1] ,obstacle_points[i*4 + 2]);
        obstacle_trans = Eigen_trance;
        fcl::CollisionObjectd obstacle_object(std::make_shared<fcl::Sphered>(obstacle), obstacle_trans);

        objects.push_back(obstacle_object);
      }

      //workspace 내에서 안되는 공간을 장애물로 설정
      fcl::Sphered workspace_obstacle(obstacle_min_radius);
      fcl::Transform3d workspace_trans;
      //이동 성분 넣기
      Eigen::Translation3d Eigen_trance(0, 0 , 0.36);
      workspace_trans = Eigen_trance;
      //RCLCPP_INFO(this->get_logger(), "obstacle distance %f, %f, %f", Eigen_trance.x(), Eigen_trance.y(), Eigen_trance.z());
      fcl::CollisionObjectd workspace_object(std::make_shared<fcl::Sphered>(workspace_obstacle), workspace_trans);
      objects.push_back(workspace_object);

      //하나하나씩 비교하기
      for(int i = 1; i < (obstacle_count + 2); i++){

        //결과를 저장할 친구들
        fcl::DistanceRequestd request;
        fcl::DistanceResultd result;

        fcl::distance(&objects[0], &objects[i], request, result);
        double obstacle_distance = result.min_distance;

        //RCLCPP_INFO(this->get_logger(), "obstacle distance %f", obstacle_distance);
        //만약 충돌하면 false 출력
        if (obstacle_distance < 0){
          return false;}
      }
      //아니면 true 출력
      return true;
    }

    bool goal_check(std::array<double, 3> new_point, std::vector<double> end_point, double arrive_range){
      double distance = pow(end_point[0] - new_point[0],2) + pow(end_point[1] - new_point[1],2) + pow(end_point[2] - new_point[2],2); 
      //만약 지정 거리 내에 들어오면
      if(distance < pow(arrive_range,2))
        return true;
      else
        return false;
    }

    /////////////////////////////
    //점들을 출력하는 함수
    ////////////////////////////
    void publish_rrt_points(std::vector<std::array<double,3>> point_array) {
        // 구의 중심과 반지름 설정
        std::array<double, 3> center = {0.0, 0.0, 0.36};
        int num_points = (int)point_array.size();

        // MarkerArray 메시지 생성
        visualization_msgs::msg::MarkerArray marker_array;

        for (int i = 0; i < num_points; ++i) {
            auto random_point = point_array[i];

            // 각 점을 Marker로 생성
            visualization_msgs::msg::Marker marker;
            marker.header.frame_id = "world";  // RViz에서 사용할 프레임
            marker.header.stamp = this->get_clock()->now();
            marker.ns = "rrt_points";
            marker.id = i;  // 각 점에 고유 ID 할당
            marker.type = visualization_msgs::msg::Marker::SPHERE;
            marker.action = visualization_msgs::msg::Marker::ADD;

            // 랜덤 점 위치 지정
            marker.pose.position.x = random_point[0];
            marker.pose.position.y = random_point[1];
            marker.pose.position.z = random_point[2];

            // 점 크기 설정
            marker.scale.x = 0.05;
            marker.scale.y = 0.05;
            marker.scale.z = 0.05;

            // 색상 설정
            marker.color.r = 0.0;
            marker.color.g = 1.0;
            marker.color.b = 0.0;
            marker.color.a = 1.0;

            marker.lifetime = rclcpp::Duration::from_seconds(0);  // 영구 표시

            // MarkerArray에 추가
            marker_array.markers.push_back(marker);
        }

        // 한 번에 퍼블리시
        marker_array_pub_->publish(marker_array);
    }

    void delete_rrt_points(){
      // MarkerArray 메시지 생성
      visualization_msgs::msg::MarkerArray marker_array;
      
      for (int i = 0; i < 1; ++i) {
        visualization_msgs::msg::Marker marker;
        marker.header.frame_id = "world";  // RViz에서 사용할 프레임
        marker.header.stamp = this->get_clock()->now();
        marker.ns = "rrt_points";
        marker.action = visualization_msgs::msg::Marker::DELETEALL;

        // MarkerArray에 추가
        marker_array.markers.push_back(marker);
        }

        // 한 번에 퍼블리시
        marker_array_pub_->publish(marker_array);
    }

    //RRT* 파트!!!!!!!!!!!!!!!!!!!!!!1
    ///////////////////////////////////////////////////////////////////////////////
    //////////////////////
    //RRT*에서 점을 새로 만든 이후 트리를 재구성하는 파트
    //인자로 RRTs_tree(전체 rrt노드 트리)와 장애물 점들, 장애물 개수, 점 주변에 탐색할 범위를 입력받는다.
    //마지막으로 트리에 입력된 점을 기준으로 한다.
    void remake_tree(std::vector<R_node>& rrts_tree, std::vector<double> obstacle_points, int obstacle_count, double searching_range = 0.1, double collision_gap = 0.1, double obstacle_min_radius = 0.42){
      int cur_node_index = (int)rrts_tree.size() - 1;

      //여기서 i는 원래 트리 구조에서의 
      for (int i = 0; i < (int)rrts_tree.size(); i++){
        //첫번째 점부터 거리 계산
        double range_distance = two_point_distance(rrts_tree[cur_node_index].position, rrts_tree[i].position);

        //탐색 범위 안에 있는 점들을 찾고, 현재 노드랑 거리를 비교한다.
        if(range_distance < searching_range){
          
          //1 -> 부모노드 재구성
          //시작 지점부터 지금까지 노드의 거리와 탐색 범위 안에 있는 i번째 노드와 연결한 경우의 거리를 비교한다. - 만약 이게 더 작으면
          if (rrts_tree[cur_node_index].current_dis > rrts_tree[i].current_dis + range_distance){
            //2개를 이었을 때 충돌하는지에 대한 검증 진행 후 경로를 이어서 진행한다.
            if (collision_test(rrts_tree[i].position, rrts_tree[cur_node_index].position, obstacle_points, obstacle_count, obstacle_min_radius) == true){
              rrts_tree[cur_node_index].parent_index = i; //이러면 부모노드를 바꾸기
              rrts_tree[cur_node_index].current_dis = rrts_tree[i].current_dis + range_distance; //거리 노드도 바꾸기
            }
          }
          //아님 말고
        }
      }  

      for (int i = 0; i < (int)rrts_tree.size(); i++){
          //2 -> 트리 재구성
          //1 을 통해 부모노드를 재구성 한 경우에, 이번에는 주변 점들을 새로 생긴 점의 자식으로 할때, 거리가 더 짧아지면 연결하는 것을 진행하는 파트다.
          //만약 새로 생긴 노드의 주변에 있는 노드의 시작부터 i번째 노드까지의 거리가 > 새로 생긴 노드 + 새로 생긴 노드와 주변에 있는 노드 사이의 거리 보다 크면, 부모를 새로 생긴 노드로 변경하는 것이 이득이다.
        double range_distance = two_point_distance(rrts_tree[cur_node_index].position, rrts_tree[i].position);
        if(range_distance < searching_range){  
          if (rrts_tree[i].current_dis > rrts_tree[cur_node_index].current_dis + range_distance){
            //두 점 사이에 충돌이 있는지 없는지도 파악하고
            if (collision_test(rrts_tree[i].position, rrts_tree[cur_node_index].position, obstacle_points, obstacle_count, obstacle_min_radius) == true){
              //범위 내에 있는 노드의 부모 노드를 새로 생긴 노드의 부모노드로 변경한다.
              rrts_tree[i].parent_index = cur_node_index; //새로운 노드로 부모를 변경하고
              rrts_tree[i].current_dis = rrts_tree[cur_node_index].current_dis + range_distance; //거리값 갱신
            }
          }
        }
      }
    }

    //최종 경로를 재구성하여, 적당한 간격으로 만드는 함수
    //RRT트리, 최종 인덱스, setp size를 받아서 재구성한다.
    void remake_final_path(std::vector<R_node>& RRTs_tree, int real_point_index, double step_range){
      RCLCPP_INFO(this -> get_logger(), "start\n");
      //지금 노드의 부모노드가 없을 때까지 하는데.
      //밑에서는 새로운 노드를 계속 추가할 거니까, 바로 직전의 index가 된다.
      int pre_index = real_point_index;

      while (RRTs_tree[real_point_index].parent_index != -1){
        //부모노드 저장
        int parent_index = RRTs_tree[real_point_index].parent_index;
        //두 노드 사이의 거리를 구해서 step_range에 따라 사이를 얼마나 분할할지 정하자.
        double node_distance = two_point_distance(RRTs_tree[real_point_index].position, RRTs_tree[parent_index].position);
        int aditional_node_count = 0;
        //if 거리가 0.6일 때, (0.6 % 0.1) - 1 = 5 사이에 점 5개 만들거임
        aditional_node_count = (node_distance / step_range) - 1;
        //RCLCPP_INFO(this -> get_logger(), "aditional_node_count : %d", aditional_node_count);
        //추가할 노드의 개수만큼 반복한다.
        for(int i = 0; i < aditional_node_count; i++){

          //이만큼씩 이동한 노드 점을 만든다. - 두개의 노드 사이의 거리를 노드 개수 만큼 나눠서 이동하는 것.
          double scale_factor = (double)(i + 1)/(double)(aditional_node_count + 1);
          std::array<double, 3> new_point_position = {RRTs_tree[real_point_index].position[0] + scale_factor * (RRTs_tree[parent_index].position[0] - RRTs_tree[real_point_index].position[0]),
                                                      RRTs_tree[real_point_index].position[1] + scale_factor * (RRTs_tree[parent_index].position[1] - RRTs_tree[real_point_index].position[1]),
                                                      RRTs_tree[real_point_index].position[2] + scale_factor * (RRTs_tree[parent_index].position[2] - RRTs_tree[real_point_index].position[2])};

          //RCLCPP_INFO(this -> get_logger(), "scale_factor : %d ,%f", i, scale_factor);
          //이렇게 이동한만큼의 새 노드를 생성하고, 이동 값을 넣고,
          R_node new_node;
          new_node.position = new_point_position;
          //이전 점의 부모로 새로 생긴 점을 설정해 주어야 한다. - 우리는 끝에서부터 조금씩 뒤로가면서 채운다
          //끝점 -> 원래부모 에서  긑점 -> 새점1 -> 새점2 -> 원래부모가 되는 형태이기 때문
          //그러면 점을 만들고 -> 이전 노드에 새로운 노드 연결 반복 -> 근데 이러면 마지막으로 새로운 노드가 만들어진 경우, 얘는 부모를 설정해주는 파트가 없다.
          //만약 첫번째 새 노드면, 끝점에 새로운 노드를 부모로 넣고, 그 다음부터는 이전 새로운 노드의 인덱스를 넣기
          if(i == 0)
            RRTs_tree[real_point_index].parent_index = pre_index + 1;
          else
            RRTs_tree[pre_index].parent_index = pre_index + 1;
          RRTs_tree.push_back(new_node);
          //RCLCPP_INFO(this -> get_logger(), "scale_factor : %d ,%f, new_node_parent_index : %d", i, scale_factor, pre_index);
          pre_index = pre_index + 1; 
          //그래서 위의 새점2와 같이 마지막으로 새로운 노드를 만들었을때,새 노드의 부모를 원래 부모 노드로 설정하여 이어준다
          if (i == (aditional_node_count - 1))
            RRTs_tree[pre_index].parent_index = parent_index;
        }
        //똑같은 것을 다음 원래 부모 노드 -> 원래 부모 노드의 부모노드 -> 이 사이 간극을 매꿔주는 것을 반복해가면서 채운다
        real_point_index = parent_index;
      }
    }
    /////////////////////////////////////
    //Slerp 보간법을 이용하여, 계산을 하는 파트
    std::vector<double> quarter_Slerp(std::vector<double> start_point, std::vector<double> end_point ,int RRTs_point_count){
      //우리가 topic에서 다루는 쿼터니언이랑 순서가 반대니까 주의하자. 우리는 x y z w로 쓰는데 Eigen은 w x y z를 쓴다.
      Eigen::Quaterniond q_start(start_point[6], start_point[3], start_point[4], start_point[5]);
      Eigen::Quaterniond q_end(end_point[6], end_point[3], end_point[4], end_point[5]);
      //혹시 모르니까 정규화 하자
      q_start.normalize();
      q_end.normalize();

      //보간의 한 타임 타임 시간을 의미
      //RRTs로 나온 점들의 개수만큼 보간해서 값을 같이 넣어줄거니까 개수 맞추기 예를 들어 노드가 7개면 0 ~ 6까지 7개 
      double time_step = 1.0/(RRTs_point_count-1);
      //쿼터니언 결과값을 저장할 벡터 배열 선언
      std::vector<double> quater_arr;

      //모든 점에 대하여 쿼터니언 계산
      for(int i = 0; i < RRTs_point_count; i++){
        //SLERP를 통해 중간 쿼터니언 계산
        Eigen::Quaterniond interpolated_q = q_start.slerp(time_step * i, q_end);
        //해당 행렬에 x,y,z,w 순으로 저장
        quater_arr.push_back(interpolated_q.x());
        quater_arr.push_back(interpolated_q.y());
        quater_arr.push_back(interpolated_q.z());
        quater_arr.push_back(interpolated_q.w());
      }
      //결과 출력
      return quater_arr;
    }
 

    rclcpp::TimerBase::SharedPtr timer_;
    rclcpp::Publisher<std_msgs::msg::String>::SharedPtr publisher_;
    rclcpp::Service<apf_interfaces::srv::RRTSPoints>::SharedPtr rrt_server_;  // 서비스 서버 선언
    rclcpp::Publisher<visualization_msgs::msg::MarkerArray>::SharedPtr marker_array_pub_;
    size_t count_;
};

int main(int argc, char * argv[])
{
  rclcpp::init(argc, argv);
  rclcpp::spin(std::make_shared<Path_planning_node>());
  rclcpp::shutdown();
  return 0;
}