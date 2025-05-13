cmake_minimum_required(VERSION 3.8)
project(sys_server_ros)

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

#add_compile_options(-g -Wall -O2)

set(CMAKE_CXX_STANDARD 17)

# find dependencies
find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(std_msgs REQUIRED)

find_package(SQLite3 REQUIRED)
find_package(SqliteOrm REQUIRED)

# common dir to so lib
file(GLOB COMM_SRC_FILES common/*.cpp)

add_library(hv_common SHARED ${COMM_SRC_FILES})

set(OTA_SRC_LIST internal/ota/ota_mng_query.cpp
        internal/ota/ota_mng_upgrade.cpp
        internal/ota/ota_mng_rollback.cpp
        internal/ota/ota_app_manager.cpp)

set(HANDLER_SRC_LIST handler/sys_handler.cpp
        handler/router.cpp)

add_executable(main src/main.cpp ${HANDLER_SRC_LIST} ${OTA_SRC_LIST})
target_include_directories(main PUBLIC
  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
  $<INSTALL_INTERFACE:include>)
target_compile_features(main PUBLIC c_std_99 cxx_std_17)  # Require C99 and C++17
ament_target_dependencies(
  main
  "rclcpp"
  "std_msgs"
)

target_link_libraries(main hv_common hv z archive udev sqlite3)
target_link_libraries(main ssl crypto curl)


install(TARGETS main
  DESTINATION lib/${PROJECT_NAME})

#安装生成的共享库
install(TARGETS hv_common
  DESTINATION lib/)
  
#安装配置文件
install(DIRECTORY etc
  DESTINATION share/${PROJECT_NAME}/)

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
