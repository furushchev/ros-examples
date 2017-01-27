cmake_minimum_required(VERSION 2.8.3)
project(pluginlib_examples)

find_package(catkin REQUIRED COMPONENTS
  nodelet
  pluginlib
  roscpp
)

find_package(Boost REQUIRED COMPONENTS system)

catkin_package(
  INCLUDE_DIRS include
)

include_directories(
  include
  ${Boost_INCLUDE_DIRS}
  ${catkin_INCLUDE_DIRS}
)

add_library(pluginlib_examples
  src/plugin_fizz.cpp
  src/plugin_buzz.cpp)

target_link_libraries(pluginlib_examples
  ${Boost_LIBRARIES}
  ${catkin_LIBRARIES})

add_library(fizz_buzz
  src/fizz_buzz_nodelet.cpp)

target_link_libraries(fizz_buzz
  ${Boost_LIBRARIES}
  ${catkin_LIBRARIES})

add_executable(fizz_buzz_node
  src/fizz_buzz_node.cpp)

target_link_libraries(fizz_buzz_node
  ${Boost_LIBRARIES}
  ${catkin_LIBRARIES})

add_executable(count_publisher
  src/count_publisher.cpp)

target_link_libraries(count_publisher
  ${catkin_LIBRARIES})
