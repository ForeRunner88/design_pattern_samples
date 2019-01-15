/** Copyright (c) 2018 SenseTime Group. All rights reserved.
  * WuXiao <wuxiao@sensetime.com> create on 18-12-29.
  *
  * @file       facade.hpp
  * @brief      sample 02 for facad pattern
  * @autor      Allen Wu
  * @version    1.0.0
  * @date       2019.01.15
  * @url        https://blog.csdn.net/liang19890820/article/details/70850367
  * @note
  *
  * Facade(外观):
  *     模式的核心，被 Client 调用，知晓相关子系统的功能和责任，在正常情况下，它将所有
  *     从 Client 发来的请求委派到相应的子系统去，让子系统处理
  * SubSystem(子系统):
  *     可以同时有一个或者多个子系统，子系统可以是一个单独的类或类的集合。每个子系统都
  *     可以被 Client 直接调用，或者被 Facade 调用，它处理由 Facade 传过来的请求。子系
  *     统并不知道 Facade 的存在，对于子系统而言，Facade 仅仅是另外一个 Client 而已。
  *    
  * 优点:
  *     1.对 Client 屏蔽子系统组件，减少了 Client 处理的对象数目，并使得子系统使用起来
  *       更加容易。通过引入外观模式，Client 的代码将变得很简单，与之关联的对象也很少；
  *     2.实现了子系统与 Client 之间的松耦合关系，这使得子系统的组件变化不会影响到调用
  *       它的 Client，只需要调整 Facade 即可；
  *     3.降低了大型软件系统中的编译依赖性，并简化了系统在不同平台之间的移植过程，因为
  *       编译一个子系统一般不需要编译所有其他的子系统。一个子系统的修改对其他子系统没
  *       有任何影响，而且子系统内部变化也不会影响到外观对象；
  *     4.只是提供了一个访问子系统的统一入口，并不影响用户直接使用子系统类。
  * 缺点:
  *     1.不能很好地限制 Client 使用子系统类，如果对 Client 访问子系统类做太多的限制，
  *       则会减少可变性和灵活性；
  *     2.在不引入抽象外观类的情况下，增加新的子系统可能需要修改 Facade 或 Client 的源
  *       代码，违背了“开闭原则”。
  *
  * 试用场景:
  *     1.当要为一个复杂子系统提供一个简单接口时。该接口可以满足大多数用户的需求，而且
  *       用户也可以越过外观类直接访问子系统；
  *     2.Client 与多个子系统之间存在很大的依赖性。引入外观类将子系统与 Client 以及其他
  *       子系统解耦，可以提高子系统的独立性和可移植性；
  *     3.在层次化结构中，可以使用外观模式定义系统中每一层的入口。层与层之间不直接产生
  *       联系，而通过外观类建立联系，降低层之间的耦合度。
  */

#ifndef SAMPLES_FACAD_PATTERN_FACADE_HPP
#define SAMPLES_FACAD_PATTERN_FACADE_HPP

#include "sub_system.hpp"

// 网购外观
class OnlineShoppingFacade {
 public:
    enum class States : int {
        Received = 0,           // 收到订单
        SubmittedToOrderTeam,   // 提交给订单团队
        SubmittedToVendor,      // 提交给供应商
        SubmittedToCourier      // 提交给快递员
    };
 public:
    OnlineShoppingFacade() : m_count_(0) {}

    int GetFollowUpNum() const {
        return m_count_;
    }

    void SubmitRequest() {
        m_state_ = static_cast<int>(States::Received);
    }

    bool CheckStates() {
        switch (m_state_) {
            case static_cast<int>(States::Received):
                ++m_state_;
                m_order_.SubmitRequest();
                std::cout << "***** submitted order to order team, "
                    << "follow times: " << m_count_ << " *****" << std::endl;
                break;
            case static_cast<int>(States::SubmittedToOrderTeam):
                if (m_order_.CheckStates()) {
                    ++m_state_;
                    m_vendor_.SubmitRequest();
                    std::cout << "***** submitted order to vendor, follow times: "
                        << m_count_ << " *****" << std::endl;
                }
                break;
            case static_cast<int>(States::SubmittedToVendor):
                if (m_vendor_.CheckStates()) {
                    ++m_state_;
                    m_courier_.SubmitRequest();
                    std::cout << "***** submitted order to courier, follow times: "
                        << m_count_ << " *****" << std::endl;
                }
                break;
            case static_cast<int>(States::SubmittedToCourier):
                if (m_courier_.CheckStates()) {
                    return true;
                }
            default:
                break;
        }
        ++m_count_;
        return false;
    }

 private:
    int m_state_;   // 订单状态
    int m_count_;   // 跟踪次数

    OrderTeam m_order_;
    Vendor    m_vendor_;
    Courier   m_courier_;
};

#endif  // SAMPLES_FACAD_PATTERN_FACADE_HPP
