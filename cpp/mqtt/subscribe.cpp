#include <iostream>
#include <string>
#include <mqtt/async_client.h>

using namespace std;
using namespace mqtt;

class MQTTCallback : public virtual mqtt::callback {
    public:
        MQTTCallback(async_client& cli) : cli_(cli) {}

        void message_arrived(mqtt::const_message_ptr msg) override {
            cout << "Received message: " << msg->get_topic() << " -> " << msg->get_payload_str() << endl;
        }

        void connection_lost(const string& cause) override {
            cout << "Connection lost: " << cause << endl;
        }

        void delivery_complete(mqtt::delivery_token_ptr token) override {
            cout << "Delivery complete:" << (token ? token->get_message_id() : -1) << endl;
        }

    private:
        async_client& cli_;

};

int main(int argc, char* argv[]) {
    string address = "tcp://localhost:1883";
    string cliend_id = "subscribe";

    async_client client(address, cliend_id);
    MQTTCallback callback(client);
    client.set_callback(callback);

    // 创建MQTT选项
    connect_options conn_opts;
    conn_opts.set_keep_alive_interval(20);
    conn_opts.set_clean_session(true);

    try {
        // 连接MQTT服务器
        client.connect(conn_opts)->wait();
        cout << "Connected to " << address << "OK" <<endl;

        // 订阅主题
        string topic = "test/topic";
        
        client.subscribe(topic, 1)->wait();
        cout << "Subscribed to " << topic << "OK" << endl;

        cin.get();

        // 断开连接
        client.disconnect()->wait();
        cout << "Disconnected from " << address << "OK" << endl;
    } catch (const mqtt::exception& e) {
        cerr << "Error: " << e.what() << endl;
        return 1;
    }  
    
    
    return 0;
}