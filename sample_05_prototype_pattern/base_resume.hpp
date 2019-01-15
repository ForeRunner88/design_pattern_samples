// Copyright (c) 2018 SenseTime Group. All rights reserved.
// WuXiao <wuxiao@sensetime.com> create on 18-12-31.
#ifndef SAMPLES_PROTOTYPE_PATTERN_BASE_RESUME_HPP
#define SAMPLES_PROTOTYPE_PATTERN_BASE_RESUME_HPP

#include <memory>
#include <string>

class BaseResume {
 public:
    BaseResume() {}
    virtual ~BaseResume() {}
    virtual std::shared_ptr<BaseResume> Clone() {
        return nullptr;
    }
    virtual void Set(const std::string& str) {
        m_name = str;
    };
    virtual void Show() = 0;
 protected:
    std::string m_name;
};

#endif  // SAMPLES_PROTOTYPE_PATTERN_BASE_RESUME_HPP


