cmake_minimum_required(VERSION 2.8.3)
project(ros_tutorials_topic)

find_package(catkin REQUIRED COMPONENTS message_generation std_msgs roscpp)

add_message_files(FILES MsgTutorial.msg)

generate_messages(DEPENDENCIES std_msgs)

catkin_package(
  LIBRARIES ros_tutorials_topic
  CATKIN_DEPENDS std_msgs roscpp
)

include_directories(${catkin_INCLUDE_DIRS})

add_executable(node1 src/node1.cpp)
add_dependencies(node1 ${${PROJECT_NAME}_EXPORTED_TARGETS} ${catkin_EXPORTED_TARGETS})
target_link_libraries(node1 ${catkin_LIBRARIES})

add_executable(node2 src/node2.cpp)
add_dependencies(node2 ${${PROJECT_NAME}_EXPORTED_TARGETS} ${catkin_EXPORTED_TARGETS})
target_link_libraries(node2 ${catkin_LIBRARIES})
