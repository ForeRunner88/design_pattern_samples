// Copyright (c) 2018 SenseTime Group. All rights reserved.
// WuXiao <wuxiao@sensetime.com> create on 18-12-27.
#include "simple_factory_pattern.hpp"
namespace simple_factory {
void simpleFactoryPatternTest() {
    SimpleFactory factory;
    auto core_A = factory.CreateSingleCore(CTYPE::COREA);
    auto core_B = factory.CreateSingleCore(CTYPE::COREB);
    core_A->Show();
    core_B->Show();
}
}