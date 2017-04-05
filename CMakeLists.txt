cmake_minimum_required(VERSION 2.8.3)
project(rosbag_imu_tools)

find_package(catkin REQUIRED COMPONENTS 
	roscpp 
	topic_tools
	rosbag
)


find_package(Boost REQUIRED COMPONENTS system filesystem thread)

catkin_package(
	CATKIN_DEPENDS roscpp topic_tools rosbag
	DEPENDS Boost
	)

include_directories(
    	include
	${catkin_INCLUDE_DIRS}
	${roscpp_INCLUDE_DIRS}
	${Boost_INCLUDE_DIRS}
)


add_executable(reader src/read.cpp)
target_link_libraries(reader ${catkin_LIBRARIES} ${Boost_LIBRARIES})

add_executable(writer src/write.cpp)
target_link_libraries(writer ${catkin_LIBRARIES} ${Boost_LIBRARIES})