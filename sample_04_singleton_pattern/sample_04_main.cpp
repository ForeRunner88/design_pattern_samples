#include "singleton.hpp"
#include "my_log.hpp"
int main(int argc, char *argv[]) {
    singletonPatternTest();
    // auto p_singleton1 = Singleton<int>::getInstance();
    // auto p_singleton2 = Singleton<int>::getInstance();
    // std::cout << (p_singleton1.get() == p_singleton2.get()) << std::endl;
    // std::cout << *p_singleton1 << std::endl;
    // std::cout << *p_singleton2 << std::endl;
    // auto p_singleton1 = Singleton::getInstance();
    // auto p_singleton2 = Singleton::getInstance();
    // std::cout << (p_singleton1.get() == p_singleton2.get()) << std::endl;
}
