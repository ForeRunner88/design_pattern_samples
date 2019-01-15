// Copyright (c) 2018 SenseTime Group. All rights reserved.
// WuXiao <wuxiao@sensetime.com> create on 18-12-27.

#ifndef SAMPLES_FACTORY_METHOD_PATTERN_HPP
#define SAMPLES_FACTORY_METHOD_PATTERN_HPP

#include <iostream>
#include <memory>

namespace factory_method {
// 工厂方法模式
class SingleCore {
 public:
    virtual void Show() = 0;
};

class SingleCoreA : public SingleCore {
    void Show() {
        std::cout << "SingleCore A" << std::endl;
    }
};

class SingleCoreB : public SingleCore {
    void Show() {
        std::cout << "SingleCore B" << std::endl;
    }
};

class Factory {
 public:
    virtual std::shared_ptr<SingleCore> CreateSingleCore() = 0;
};

class FactoryA : public Factory {
 public:
    std::shared_ptr<SingleCore> CreateSingleCore() {
        return std::shared_ptr<SingleCore>(new SingleCoreA());
    }
};

class FactoryB : public Factory {
 public:
    std::shared_ptr<SingleCore> CreateSingleCore() {
        return std::shared_ptr<SingleCore>(new SingleCoreB());
    }
};

void factoryMethodPatternTest();
}  // namespace factory_method
#endif //SAMPLES_FACTORY_METHOD_PATTERN_HPP
