cmake_minimum_required(VERSION 3.8)
project(data_collection_service)

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

set(CMAKE_CXX_STANDARD 17)

#导入第三方库目录路径
set(CMAKE_PREFIX_PATH "/home/byd/third_party/real_sense/lib/cmake/realsense2")

include_directories("/home/byd/third_party/real_sense/include")

# find dependencies
find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)

find_package(realsense2 2.55.1)
if (BUILD_ACCELERATE_GPU_WITH_GLSL)
  find_package(realsense2-gl 2.55.1)
endif()
if(NOT realsense2_FOUND)
    message(FATAL_ERROR "\n\n Intel RealSense SDK 2.0 is missing, please install it from https://github.com/IntelRealSense/librealsense/releases\n\n")
endif()

add_executable(manager src/main.cpp src/data_collection_manager.cpp)

target_include_directories(manager PUBLIC
  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
  $<INSTALL_INTERFACE:include>)
target_compile_features(manager PUBLIC c_std_99 cxx_std_17)  # Require C99 and C++17
ament_target_dependencies(
  manager
  "rclcpp"
  "std_msgs"
)

install(TARGETS manager
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
