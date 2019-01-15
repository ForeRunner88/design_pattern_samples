// Copyright (c) 2018 SenseTime Group. All rights reserved.
// WuXiao <wuxiao@sensetime.com> create on 18-12-29.
#ifndef SAMPLES_ADPTER_HPP
#define SAMPLES_ADPTER_HPP

#include <memory>
#include "target.hpp"
#include "adapatee.hpp"

/** 适配器模式
 *  优点: 1.可以让任何两个没有关联的类一起运行
 *       2.提高了类的复用性
 *       3.增加了类的透明度
 *       4.灵活性好
 *  缺点: 过多地使用适配器，会导致系统非常凌乱，不利于整体把控
 */

//!< 对象适配器
//!< 1.有时构造一个Adaptee类型的对象不是很容易
//!< 2.当Adaptee中添加新的抽象方法时,Adapter类不需要做任何调整,也能正常工作
//!< 3.可以使用多态的方式在Adapter类中调用Adaptee类子类的方法
class PowerAdapter : public IRussiaSocket {
 public:
    PowerAdapter() : m_charger(new ChinaCharger()) {}
    void Charge() {
        // 插入（两脚扁型）充电头
        m_charger->ChargeWithFeetFlat();
    }
 private:
    std::shared_ptr<ChinaCharger> m_charger;
};

//! < 类适配器
//! < 1.Adapter直接集成Adaptee类,在Adapter类中可以对Adaptee类的方法进行重定义
//! < 2.如果Adaptee中添加了一个抽象方法,那么Adapter类也要进行相应的改动,高耦合
//! < 3.如果Adaptee还有其他子类,而在Adapter中想调用Adaptee其他子类的方法时,类适配器无法做到
class PowerAdapter2 : public IRussiaSocket, ChinaCharger {
 public:
    PowerAdapter2() = default;
    void Charge() {
        this->ChargeWithFeetFlat();
    }
};

void adapterPatternTest();

#endif //SAMPLES_ADPTER_HPP
