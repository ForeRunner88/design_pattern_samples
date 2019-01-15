// Copyright (c) 2018 SenseTime Group. All rights reserved.
// WuXiao <wuxiao@sensetime.com> create on 18-12-31.
#ifndef SAMPLES_PROTOTYPE_PATTERN_DERIVED_RESUME_HPP
#define SAMPLES_PROTOTYPE_PATTERN_DERIVED_RESUME_HPP

#include "base_resume.hpp"

class ResumeA : public BaseResume {
 public:
    ResumeA(const std::string& str);
    ResumeA(const ResumeA& resume);
    std::shared_ptr<BaseResume> Clone();
    void Show();
};

class ResumeB : public BaseResume {
 public:
    ResumeB(const std::string& str);
    ResumeB(const ResumeB& resume);
    std::shared_ptr<BaseResume> Clone();
    void Show();
};

void prototypePatternTest();

#endif  // SAMPLES_PROTOTYPE_PATTERN_DERIVED_RESUME_HPP

