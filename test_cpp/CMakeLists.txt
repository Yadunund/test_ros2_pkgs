cmake_minimum_required(VERSION 3.8)
project(test_cpp)

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

# find dependencies
find_package(ament_cmake REQUIRED)
find_package(test_cpp_msgs REQUIRED)
find_package(std_msgs REQUIRED)
find_package(geometry_msgs REQUIRED)
find_package(rclcpp REQUIRED)

add_executable(test_sub src/TestSub.cpp)

ament_target_dependencies(
	test_sub
	rclcpp
	test_cpp_msgs
	std_msgs
	geometry_msgs
)

install(TARGETS
  test_sub
  DESTINATION lib/${PROJECT_NAME})

ament_package()
