<!--
 * @Author: hawrkchen
 * @Date: 2025-05-28 10:41:31
 * @LastEditors: Do not edit
 * @LastEditTime: 2025-05-28 10:47:41
 * @Description: 
 * @FilePath: /mqtt/README.md
-->
# MQTT封装验证类
1. MQTT封装验证类，使用paho-mqtt库，实现MQTT协议的发布和订阅功能。
2. broker 使用mosquitto作为MQTT服务器验证通过
3. mqtt目录下，发布者和订阅者分为两个类处理，可直接集成到其他项目中
4. pub_main, sub_main是对mqtt的发布和订阅功能的测试代码
5. publisher.cpp  subscribe.cpp是非C++类封装的验证代码