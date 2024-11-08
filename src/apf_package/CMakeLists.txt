cmake_minimum_required(VERSION 3.8)
project(apf_package)

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

# find dependencies
find_package(ament_cmake REQUIRED)

find_package(rclcpp REQUIRED)
find_package(std_msgs REQUIRED)
find_package(nav_msgs REQUIRED)
find_package(geometry_msgs REQUIRED)
find_package(visualization_msgs REQUIRED)
find_package(trajectory_msgs REQUIRED)

find_package(sensor_msgs REQUIRED)

# add tf2
find_package(tf2 REQUIRED)
find_package(tf2_ros REQUIRED)

# add eigen3
find_package(eigen3_cmake_module REQUIRED)
find_package(Eigen3)

# my_interfaces
find_package(apf_interfaces REQUIRED)

# uncomment the following section in order to fill in
# further dependencies manually.
# find_package(<dependency> REQUIRED)

#find fcl
find_package(fcl REQUIRED)

add_executable(apf_main_node src/apf_main_node.cpp)
ament_target_dependencies(apf_main_node rclcpp std_msgs Eigen3 apf_interfaces visualization_msgs geometry_msgs trajectory_msgs sensor_msgs)

add_executable(cul_distance_node src/cul_distance_node.cpp)
ament_target_dependencies(cul_distance_node rclcpp std_msgs Eigen3 nav_msgs apf_interfaces tf2 tf2_ros fcl visualization_msgs)
target_link_libraries(cul_distance_node fcl)

add_executable(save_jaco src/save_jaco.cpp)
ament_target_dependencies(save_jaco rclcpp std_msgs Eigen3 apf_interfaces visualization_msgs geometry_msgs trajectory_msgs sensor_msgs)



target_include_directories(apf_main_node PUBLIC
  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
  $<INSTALL_INTERFACE:include>
  )
target_compile_features(apf_main_node PUBLIC c_std_99 cxx_std_17)  # Require C99 and C++17

install(TARGETS 
  apf_main_node
  cul_distance_node
  save_jaco
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
