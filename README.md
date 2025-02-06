# 2024_7Dof


### 1. 환경 설정

[https://github.com/lbr-stack/lbr_fri_ros2_stack](https://github.com/ICube-Robotics/iiwa_ros2)

위의 iiwa 7 R800을 불러와서 사용하였다. 해당 내용에 맞게 환경 설정 필요

https://github.com/flexible-collision-library/fcl

또한 FCL라이브러리를 위와 같이 설정하여 주어야 한다


### 2. 사용 방법

1. 기존 package의 lauch 파일 실행
```
ros2 launch iiwa_bringup iiwa.launch.py
```


2. 각각의 개인 노드 실행(추후 lauch 파일로 묶어야 한다)


apf 알고리즘의 main_node(jacobain, taget point위치를 입력 받아 apf알고리즘 계산 및 출력값 전송)
```
ros2 run apf_package apf_main_node
```



DH 파라미터 저장과 jacobian 계산 노드
```
ros2 run culjaco jaco_node
```



끝단 위치와 최종 목표지점 사이의 path_planning 수행 및 interplation 수행해당 결과로 나온 경유점 전송
```
ros2 run apf_package path_planning_node
```



fcl 라이브러리를 이용하여, 장애물과의 거리 감지 수행 
```
ros2 run apf_package cul_distance_node
```


