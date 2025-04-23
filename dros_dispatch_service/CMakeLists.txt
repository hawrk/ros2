cmake_minimum_required(VERSION 3.8)
project(dros_dispatch_service)

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

# find dependencies
find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(std_msgs REQUIRED)
find_package(rclcpp_action REQUIRED)

find_package(nav2_msgs REQUIRED)

find_package(turtlesim REQUIRED)

add_executable(main src/main.cpp)
target_include_directories(main PUBLIC
  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
  $<INSTALL_INTERFACE:include>)
target_compile_features(main PUBLIC c_std_99 cxx_std_17)  # Require C99 and C++17
ament_target_dependencies(
  main
  "rclcpp"
  "std_msgs"
  "rclcpp_action"
  "nav2_msgs"
  "turtlesim"
)

target_link_libraries(main behaviortree_cpp)

install(TARGETS main
  DESTINATION lib/${PROJECT_NAME})

# pub main
add_executable(pub_main src/pub_main.cpp)
target_include_directories(pub_main PUBLIC
  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
  $<INSTALL_INTERFACE:include>)
target_compile_features(pub_main PUBLIC c_std_99 cxx_std_17)  # Require C99 and C++17
ament_target_dependencies(
  pub_main
  "rclcpp"
  "std_msgs"
)

install(TARGETS pub_main
  DESTINATION lib/${PROJECT_NAME})

#action server
add_executable(action_main src/action_main.cpp)
target_include_directories(action_main PUBLIC
  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
  $<INSTALL_INTERFACE:include>)
target_compile_features(action_main PUBLIC c_std_99 cxx_std_17)  # Require C99 and C++17
ament_target_dependencies(
  action_main
  "rclcpp"
  "std_msgs"
  "rclcpp_action"
  "nav2_msgs"
  "turtlesim"
)

install(TARGETS action_main
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
