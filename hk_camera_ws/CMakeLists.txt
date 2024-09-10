cmake_minimum_required(VERSION 3.8)
project(hk_camera_ws)

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-g -Wall -Wextra -Wpedantic -Wno-missing-field-initializers -Wno-return-type)
endif()

# 开启编译优化
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O2")

# find dependencies
find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(OpenCV REQUIRED)

include_directories(${OpenCV_INCLUDE_DIRS})

link_directories(${CMAKE_CURRENT_SOURCE_DIR}/lib/hk_lib/aarch64)

add_executable(camera src/camera.cpp)
target_include_directories(camera PUBLIC
  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
  $<INSTALL_INTERFACE:include>)
target_compile_features(camera PUBLIC c_std_99 cxx_std_17)  # Require C99 and C++17
ament_target_dependencies(
  camera
  "rclcpp"
)

target_link_libraries(camera
  MvCameraControl
  ${OpenCV_LIBS}
)



install(TARGETS camera
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
