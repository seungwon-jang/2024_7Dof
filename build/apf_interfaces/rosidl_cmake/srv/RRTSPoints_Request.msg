#장애물 배열과, 장애물 개수를 받는다.
#장애물 배열의 경우 장애물의 중심점의 좌표와 반지름을 받아서 x,y,z,radius
float64[] obstacle_points
int64 obstacle_count

#이거는 RRTs를 수행할 시작지점과 도착지점을 보낸다.
#(x,y,z,x,y,z,w)로 보낸다
float64[] start_point
float64[] end_point
