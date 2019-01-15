// Copyright (c) 2018 SenseTime Group. All rights reserved.
// WuXiao <wuxiao@sensetime.com> create on 18-12-31.
#ifndef SAMPLES_BUILDER_PATTERN_DIRECTOR_COMPUTER_HPP
#define SAMPLES_BUILDER_PATTERN_DIRECTOR_COMPUTER_HPP

#include "builder_computer.hpp"

// 指挥者
class Director {
 public:
    void Create(std::shared_ptr<IBuilder> builder) {
        builder->BuildCpu();
        builder->BuildMainboard();
        builder->BuildRam();
        builder->BuildGpu();
    }
};

#endif  // SAMPLES_BUILDER_PATTERN_DIRECTOR_COMPUTER_HPP
