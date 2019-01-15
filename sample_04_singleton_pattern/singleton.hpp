// Copyright (c) 2018 SenseTime Group. All rights reserved.
// WuXiao <wuxiao@sensetime.com> create on 18-12-31.
#ifndef SAMPLES_SINGLETON_HPP
#define SAMPLES_SINGLETON_HPP

#include <memory>

template <typename T>
class Singleton {
 public:
     static inline std::shared_ptr<T> getInstance() {
        return mp_instace_;
     }
 private:
     Singleton() {}
     ~Singleton() {}
     Singleton(const Singleton&) {}
     Singleton & operator= (const Singleton &) {}

     static std::shared_ptr<T> mp_instace_;
};

template <typename T>
std::shared_ptr<T> Singleton<T>::mp_instace_ = std::shared_ptr<T>(new T());

#endif  // SAMPLES_SINGLETON_HPP
