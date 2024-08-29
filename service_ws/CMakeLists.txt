cmake_minimum_required(VERSION 3.8)
project(service_ws)

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

# find dependencies
find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)

#加入config.cmake路径 或 CMAKE_PREFIX_PATH
set(CMAKE_MODULE_PATH /home/byd/src/ros2/service_interface_ws/install/service_interface_ws)
find_package(service_interface_ws REQUIRED)


#service
add_executable(service src/service.cpp)
target_include_directories(service PUBLIC
  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
  $<INSTALL_INTERFACE:include>)
target_compile_features(service PUBLIC c_std_99 cxx_std_17)  # Require C99 and C++17
ament_target_dependencies(
  service
  "rclcpp"
  "service_interface_ws"
)

install(TARGETS service
  DESTINATION lib/${PROJECT_NAME})

#client
add_executable(client src/client.cpp)
target_include_directories(client PUBLIC
  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
  $<INSTALL_INTERFACE:include>)
target_compile_features(client PUBLIC c_std_99 cxx_std_17)  # Require C99 and C++17
ament_target_dependencies(
  client
  "rclcpp"
  "service_interface_ws"
)

install(TARGETS client
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
