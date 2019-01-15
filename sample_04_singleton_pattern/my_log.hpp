// Copyright (c) 2018 SenseTime Group. All rights reserved.
// WuXiao <wuxiao@sensetime.com> create on 18-12-31.
#ifndef SAMPLES_MY_LOG_HPP
#define SAMPLES_MY_LOG_HPP

#include <iostream>
#include <string>
#include "singleton.hpp"

class MyLog {
    // friend class std::shared_ptr<MyLog>;
    friend class Singleton<MyLog>;
 public:
    void inline Log(const std::string& msg);
 private:
    MyLog() {}
    // virtual ~MyLog() {}
    MyLog(const MyLog&) {}
    MyLog& operator= (const MyLog&) {}
};

void singletonPatternTest();

#endif  // SAMPLES_MY_LOG_HPP
