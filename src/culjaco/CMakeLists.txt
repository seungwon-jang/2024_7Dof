cmake_minimum_required(VERSION 3.8)
project(culjaco)

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

# find dependencies
find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(std_msgs REQUIRED)

# add eigen3
find_package(eigen3_cmake_module REQUIRED)
find_package(Eigen3)

#find_iiwa_controler interface
find_package(sensor_msgs REQUIRED)

# uncomment the following section in order to fill in
# further dependencies manually.
# find_package(<dependency> REQUIRED)

# find my_interfaces
find_package(apf_interfaces REQUIRED)

find_package(nav_msgs REQUIRED)


add_executable(forward src/forward.cpp)
target_include_directories(forward PUBLIC
  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
  $<INSTALL_INTERFACE:include>)
target_compile_features(forward PUBLIC c_std_99 cxx_std_17)  # Require C99 and C++17
#add eigen3

add_executable(talker src/publisher_member_function.cpp)
ament_target_dependencies(talker rclcpp std_msgs Eigen3)

add_executable(listener src/subscriber_member_function.cpp)
ament_target_dependencies(listener rclcpp std_msgs)

add_executable(forward_node src/forward_node.cpp)
ament_target_dependencies(forward_node rclcpp std_msgs Eigen3)

add_executable(jaco_node src/cul_jaco.cpp)
ament_target_dependencies(jaco_node rclcpp std_msgs sensor_msgs Eigen3 apf_interfaces)

add_executable(save_position src/save_position.cpp)
ament_target_dependencies(save_position rclcpp std_msgs sensor_msgs Eigen3 apf_interfaces nav_msgs)

install(TARGETS 
  forward
  talker
  listener
  forward_node
  jaco_node
  save_position
  DESTINATION lib/${PROJECT_NAME})


if(BUILD_TESTING)
  find_package(ament_lint_auto REQUIRED)
  # the following line skips the linter which checks for copyrights
  # comment the line when a copyright and license is added to all source files
  set(ament_cmake_copyright_FOUND TRUE)
  # the following line skips cpplint (only works in a git repo)
  # comment the line when this package is in a git repo and when
  # a copyright and license is added to all source files
  set(ament_cmake_cpplint_FOUND TRUE)
  ament_lint_auto_find_test_dependencies()
endif()

ament_package()
