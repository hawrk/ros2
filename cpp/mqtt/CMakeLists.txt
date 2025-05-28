cmake_minimum_required(VERSION 3.10)
project(mqtt)

set(CMAKE_CXX_STANDARD 17)

#find_package(PahoMqttCpp REQUIRED)

add_executable(publisher publisher.cpp)
target_link_libraries(publisher paho-mqttpp3 paho-mqtt3a)

add_executable(subscribe subscribe.cpp)
target_link_libraries(subscribe paho-mqttpp3 paho-mqtt3a)

add_executable(pub_main pub_main.cpp mqtt/mqtt_publisher.cpp)
target_link_libraries(pub_main paho-mqttpp3 paho-mqtt3a)

add_executable(sub_main sub_main.cpp mqtt/mqtt_subscriber.cpp)
target_link_libraries(sub_main paho-mqttpp3 paho-mqtt3a)
