#include "factory_method_pattern.hpp"

namespace factory_method {
void factoryMethodPatternTest() {
    FactoryA fact_A;
    auto core_A = fact_A.CreateSingleCore();
    core_A->Show();
    FactoryB fact_B;
    auto core_B = fact_B.CreateSingleCore();
    core_B->Show();
}
}