#include "my_log.hpp"

void MyLog::Log(const std::string& msg) {
    std::cout << "Log msg: " << msg << std::endl;
}

void singletonPatternTest() {
    std::cout << "[TEST] Singleton Pattern" << std::endl;
    auto log_handle1 = Singleton<MyLog>::getInstance();
    auto log_handle2 = Singleton<MyLog>::getInstance();
    std::cout << "log_handle1 ptr address: " << log_handle1.get() << std::endl;
    std::cout << "log_handle2 ptr address: " << log_handle2.get() << std::endl;
    log_handle1->Log("LOG_1: Hello");
    log_handle2->Log("LOG_2: Singleton");
}
