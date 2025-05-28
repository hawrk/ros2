
#include "mqtt_publisher.hpp"

MqttPublisher::MqttPublisher(const std::string& address, const std::string& client_id,
                      const std::string& username, const std::string& password)
                      :address_(address), 
                      client_id_(client_id), 
                      username_(username), 
                      password_(password),
                      client_(address, client_id) {
    
}

MqttPublisher::~MqttPublisher() {
    if(is_connected_) {
        disconnect();
    }
}

bool MqttPublisher::connect(int keep_alive, bool clean_session) {
    try {
        mqtt::connect_options conn_opts;
        conn_opts.set_keep_alive_interval(keep_alive);
        conn_opts.set_clean_session(clean_session);
        if(!username_.empty()) {
            conn_opts.set_user_name(username_);
        }
        if(!password_.empty()) {
            conn_opts.set_password(password_);
        }

        std::cout << "Connecting to " << address_ << " with client ID " << client_id_ << std::endl;
        client_.connect(conn_opts)->wait();
        is_connected_ = true;
        std::cout << "connected successfully" << std::endl;
        return true;
    } catch (const mqtt::exception& exc) {
        std::cerr << "Error connecting to " << address_ << ": " << exc.what() << std::endl;
        return false;
    }
}

void MqttPublisher::disconnect() {
    try {
        std::cout << "Disconnecting from " << address_ << std::endl;
        client_.disconnect()->wait();
        is_connected_ = false;
        std::cout << "disconnected successfully" << std::endl;
    } catch (const mqtt::exception& exc) {
        std::cerr << "Error disconnecting from " << address_ << ": " << exc.what() << std::endl;
    }
}

bool MqttPublisher::publish(const std::string& topic, const std::string& message) {
    try {
        if(!is_connected_) {
            std::cerr << "Error: not connected to " << address_ << std::endl;
            return false;
        }
        std::cout << "Publishing message to topic " << topic << std::endl;
        mqtt::message_ptr pubmsg = mqtt::make_message(topic, message);
        client_.publish(pubmsg)->wait();
        std::cout << "published successfully" << std::endl;
        return true;
    } catch (const mqtt::exception& exc) {
        std::cerr << "Error publishing message to topic " << topic << ": " << exc.what() << std::endl;
        return false;
    }
}

void MqttPublisher::publish_loop(const std::string& topic, const std::string& message, int interval_ms) {
    while(true) {
        if(!publish(topic, message)) {
            std::cerr << "Error publishing message, reconnecting in 5 seconds" << std::endl;
            break;   // 出错则退出循环
        }
        std::this_thread::sleep_for(std::chrono::milliseconds(interval_ms));
    }
}