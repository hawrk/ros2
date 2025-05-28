/*
 * @Author: hawrkchen
 * @Date: 2025-05-22 14:03:19
 * @LastEditors: Do not edit
 * @LastEditTime: 2025-05-22 14:50:21
 * @Description:  mqtt publisher
 * @FilePath: /mqtt/publisher.cpp
 */

#include <iostream>
#include <string>
#include <thread>
#include <chrono>
#include <mqtt/async_client.h>

using namespace std;
using namespace mqtt;

int main(int argc,char* argv[]) {
    string address = "tcp://localhost:1883";
    string cliend_id = "publisher";

    // create client
    async_client client(address, cliend_id);

    //创建连接选项
    connect_options conn_opts;
    conn_opts.set_keep_alive_interval(20);
    conn_opts.set_clean_session(true);

    //连接服务器
    try {
        cout << "Connecting to " << address << "..." << endl;
        client.connect(conn_opts)->wait();

        cout << "connect OK" << endl;

        //发布消息
        string topic = "test/topic";
        string message = "Hello MQTT";
        cout << "Publishing message to topic " << topic << "..." << endl;
        while(true) {
            client.publish(topic, message)->wait();
            cout << "publish OK" << endl;
            std::this_thread::sleep_for(std::chrono::seconds(1));
        }


        //断开连接
        cout << "Disconnecting..." << endl;
        client.disconnect()->wait();
        cout << "disconnect OK" << endl;
    } catch (const mqtt::exception& e) {
        cerr << "Error: " << e.what() << endl;
        return 1;
    }
    return 0;
}

