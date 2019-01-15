#include <iostream>
#include "director_computer.hpp"

void builderPatternTest();

int main(int argc, char *argv[]) {
    builderPatternTest();
    return 0;
}

void builderPatternTest() {
    std::shared_ptr<Director> p_director(new Director());
    std::shared_ptr<IBuilder> p_tp_builder(new ThinkpadBuilder());
    std::shared_ptr<IBuilder> p_yoga_builder(new YogaBuilder());
    // 组装电脑
    p_director->Create(p_tp_builder);
    p_director->Create(p_yoga_builder);
    // 获取组装结果
    auto p_tp_computer = p_tp_builder->GetProduct();
    auto p_yoga_computer = p_yoga_builder->GetProduct();
    // 测试输出
    std::cout << "=== Thinkpad ===" << std::endl;
    std::cout << "CPU: " << p_tp_computer->GetCpu() << std::endl;
    std::cout << "Ram: " << p_tp_computer->GetRam() << std::endl;
    std::cout << "GPU: " << p_tp_computer->GetGpu() << std::endl;
    std::cout << "Mainboard: " << p_tp_computer->GetMainboard() << std::endl;
    std::cout << "=== Yoga ===" << std::endl;
    std::cout << "CPU: " << p_yoga_computer->GetCpu() << std::endl;
    std::cout << "Ram: " << p_yoga_computer->GetRam() << std::endl;
    std::cout << "GPU: " << p_yoga_computer->GetGpu() << std::endl;
    std::cout << "Mainboard: " << p_yoga_computer->GetMainboard() << std::endl;
}
