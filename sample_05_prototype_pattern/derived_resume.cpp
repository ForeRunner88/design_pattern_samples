#include <iostream>
#include "derived_resume.hpp"

ResumeA::ResumeA(const std::string& str) {
    this->m_name = str;
}

ResumeA::ResumeA(const ResumeA& resume) {
    this->m_name = resume.m_name;
}

std::shared_ptr<BaseResume> ResumeA::Clone() {
    return std::shared_ptr<BaseResume>(new ResumeA(*this));
}

void ResumeA::Show() {
    std::cout << "ResumeA name: " << m_name << std::endl;
}

ResumeB::ResumeB(const std::string& str) {
    this->m_name = str;
}

ResumeB::ResumeB(const ResumeB& resume) {
    this->m_name = resume.m_name;
}

std::shared_ptr<BaseResume> ResumeB::Clone() {
    return std::shared_ptr<BaseResume>(new ResumeB(*this));
}

void ResumeB::Show() {
    std::cout << "ResumeB name: " << m_name << std::endl;
}

void prototypePatternTest() {
    std::shared_ptr<BaseResume> r3, r4;
    {
        std::shared_ptr<BaseResume> r1(new ResumeA("I am ResumeA with r1"));
        std::shared_ptr<BaseResume> r2(new ResumeB("I am ResumeB with r2"));
        r3 = r1->Clone();
        r4 = r2->Clone();
        std::cout << "r1 addr: " << r1.get() << std::endl;
        std::cout << "r2 addr: " << r2.get() << std::endl;
        std::cout << "r3 addr: " << r3.get() << std::endl;
        std::cout << "r4 addr: " << r4.get() << std::endl;
    }
    r3->Show();
    r4->Show();
}

