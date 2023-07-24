cmake_minimum_required(VERSION 3.0.2)
project(skyrats_cpp)

## Find catkin macros and libraries
## if COMPONENTS list like find_package(catkin REQUIRED COMPONENTS xyz)
## is used, also find other catkin packages
find_package(catkin REQUIRED COMPONENTS
  geometry_msgs
  roscpp
)

## Declare catkin package
catkin_package(
  INCLUDE_DIRS include
  LIBRARIES skyrats_cpp
  CATKIN_DEPENDS geometry_msgs roscpp
)

## Specify additional locations of header files
## Your package locations should be listed before other locations
include_directories(
  include
  ${catkin_INCLUDE_DIRS}
)

## Declare a C++ executable
add_executable(skyrats_cpp src/example.cpp)

## Add cmake target dependencies of the executable
add_dependencies(skyrats_cpp ${skyrats_cpp_EXPORTED_TARGETS} ${catkin_EXPORTED_TARGETS})

## Specify libraries to link a library or executable target against
target_link_libraries(skyrats_cpp
  ${catkin_LIBRARIES}
)


