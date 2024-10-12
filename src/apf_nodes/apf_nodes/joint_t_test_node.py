# Copyright 2016 Open Source Robotics Foundation, Inc.
#
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
#
#     http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.

#노드 관련 기본 설정
import rclpy
from rclpy.node import Node
#interface type
from std_msgs.msg import String
from trajectory_msgs.msg import JointTrajectory, JointTrajectoryPoint
from builtin_interfaces.msg import Duration


class joint_t_test_node(Node):

    def __init__(self):
        super().__init__('joint_t_test_node')
        #해당 토픽(iiwa_arm_controller/joint_trajectory)으로 값을 publish 한다!!
        self.publisher_ = self.create_publisher(JointTrajectory, 'iiwa_arm_controller/joint_trajectory', 10)
        self.timer_period = 5  # seconds
        self.timer = self.create_timer(self.timer_period, self.timer_callback)
        self.i = 0
        self.mode_num = 4

    def timer_callback(self):
        target_point = JointTrajectory()
        target_point.joint_names = ['joint_a1','joint_a2','joint_a3','joint_a4','joint_a5','joint_a6','joint_a7']

        point = JointTrajectoryPoint()
        #ros2에서 시간간격을 나타내는 메세지 타입 sec와 나노초를 더하는 형태를 지닌다.
        point.time_from_start = Duration(sec=3, nanosec=0)

        self.i = 3

        if self.i % self.mode_num == 0:
            point.positions = [0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0]
        elif self.i % self.mode_num == 1:
            point.positions = [1.5, 1.5, 0.0, 1.5, 0.0, 1.5, 0.0]
        elif self.i % self.mode_num == 2:
            point.positions = [-1.5, -1.5, 0.0, -1.5, 0.0, -1.5, 0.0]
        elif self.i % self.mode_num == 3:
            point.positions = [-1.5, 1.0, 0.0, -1.5, 0.0, 1.5, 0.0]

        target_point.points.append(point) 

        self.publisher_.publish(target_point)
        self.get_logger().info('Publishing: "{}", i: "{}"' .format(target_point.joint_names, point.positions))
        self.i = self.i + 1


def main(args=None):
    rclpy.init(args=args)

    my_node = joint_t_test_node()

    rclpy.spin(my_node)

    # Destroy the node explicitly
    # (optional - otherwise it will be done automatically
    # when the garbage collector destroys the node object)
    my_node.destroy_node()
    rclpy.shutdown()


if __name__ == '__main__':
    main()
