// Copyright (c) 2018 SenseTime Group. All rights reserved.
// WuXiao <wuxiao@sensetime.com> create on 18-12-29.

#include "abstract_factory.hpp"

namespace abstract_factory {
void abstractFactoryPatternTest() {
    CoreFactoryA factoryA;
    auto single_core_A = factoryA.CreateSingleCore();
    auto multi_core_A = factoryA.CreateMultiCore();
    single_core_A->Show();
    multi_core_A->Show();
    CoreFactoryB factoryB;
    auto single_core_B = factoryB.CreateSingleCore();
    auto multi_core_B = factoryB.CreateMultiCore();
    single_core_B->Show();
    multi_core_B->Show();
}
}  // namespace abstract_factory
