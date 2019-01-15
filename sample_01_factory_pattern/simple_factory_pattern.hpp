// Copyright (c) 2018 SenseTime Group. All rights reserved.
// WuXiao <wuxiao@sensetime.com> create on 18-12-27.

#ifndef SAMPLES_SIMPLE_FACTORY_PATTERN_HPP
#define SAMPLES_SIMPLE_FACTORY_PATTERN_HPP

#include <iostream>
#include <memory>

namespace simple_factory {
// 简单工厂模式
enum class CTYPE { COREA, COREB };

class SingleCore {
 public:
    virtual void Show() = 0;
};

class SingleCoreA : public SingleCore {
 public:
    void Show() {
        std::cout << "SingleCore A" << std::endl;
    }
};

class SingleCoreB : public SingleCore {
 public:
    void Show() {
        std::cout << "SingleCore B" << std::endl;
    }
};

class SimpleFactory {
 public:
    std::shared_ptr<SingleCore> CreateSingleCore(const CTYPE &ctype) {
        if (ctype == CTYPE::COREA) {
            return std::shared_ptr<SingleCore>(new SingleCoreA());
        } else if (ctype == CTYPE::COREB) {
            return std::shared_ptr<SingleCore>(new SingleCoreB());
        } else {
            return nullptr;
        }
    }
};

void simpleFactoryPatternTest();
}  // namespace simple_factory
#endif //SAMPLES_SIMPLE_FACTORY_PATTERN_HPP
