// Copyright (c) 2018 SenseTime Group. All rights reserved.
// WuXiao <wuxiao@sensetime.com> create on 18-12-29.

#ifndef SAMPLES_ABSTRACT_FACTORY_HPP
#define SAMPLES_ABSTRACT_FACTORY_HPP

#include <iostream>
#include <memory>

namespace abstract_factory {
// 抽象工厂模式
class SingleCore {
 public:
    virtual void Show() = 0;
};

class SingleCoreA : public SingleCore {
 public:
    void Show() {
        std::cout << "Single Core A" << std::endl;
    }
};

class SingleCoreB : public SingleCore {
 public:
    void Show() {
        std::cout << "Single Core B" << std::endl;
    }
};

class MultiCore {
 public:
    virtual void Show() = 0;
};

class MultiCoreA : public MultiCore {
 public:
    void Show() {
        std::cout << "Multi Core A" << std::endl;
    }
};

class MultiCoreB : public MultiCore {
 public:
    void Show() {
        std::cout << "Multi Core B" << std::endl;
    }
};

class CoreFactory {
 public:
    virtual std::shared_ptr<SingleCore> CreateSingleCore() = 0;
    virtual std::shared_ptr<MultiCore> CreateMultiCore() = 0;
};

class CoreFactoryA : public CoreFactory {
 public:
    std::shared_ptr<SingleCore> CreateSingleCore() {
        return std::shared_ptr<SingleCore>(new SingleCoreA());
    }
    std::shared_ptr<MultiCore> CreateMultiCore() {
        return std::shared_ptr<MultiCore>(new MultiCoreA());
    }
};

class CoreFactoryB : public CoreFactory {
 public:
    std::shared_ptr<SingleCore> CreateSingleCore() {
        return std::shared_ptr<SingleCore>(new SingleCoreB());
    }
    std::shared_ptr<MultiCore> CreateMultiCore() {
        return std::shared_ptr<MultiCore>(new MultiCoreB());
    }
};

void abstractFactoryPatternTest();
}  // namespace abstract_factory
#endif //SAMPLES_ABSTRACT_FACTORY_HPP
