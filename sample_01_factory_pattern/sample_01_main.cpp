#include <iostream>
#include "simple_factory_pattern.hpp"
#include "factory_method_pattern.hpp"
#include "abstract_factory.hpp"

int main(int argc, char *argv[]) {
    std::cout << "[TEST] Simple Factory" << std::endl;
    simple_factory::simpleFactoryPatternTest();
    std::cout << "[TEST] Factory Method" << std::endl;
    factory_method::factoryMethodPatternTest();
    std::cout << "[TEST] Abstract Factory" << std::endl;
    abstract_factory::abstractFactoryPatternTest();
}

