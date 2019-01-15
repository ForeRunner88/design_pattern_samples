// Copyright (c) 2018 SenseTime Group. All rights reserved.
// WuXiao <wuxiao@sensetime.com> create on 18-12-29.
#ifndef SAMPLES_CACHES_HPP
#define SAMPLES_CACHES_HPP

#include <memory>
#include "cache_replace_algorithms.hpp"

class Cache1 {
 public:
    Cache1(std::shared_ptr<ReplaceAlgorithm>& ra) : m_ra(ra) {}
    void Replace() {
        if (nullptr != m_ra) {
            m_ra->Replace();
        }
    }
 private:
    std::shared_ptr<ReplaceAlgorithm> m_ra;
};

class Cache2 {
 public:
    enum ReplacePolicy {LRU, FIFO, RANDOM};
    Cache2(const ReplacePolicy& policy) {
        if (ReplacePolicy::LRU == policy) {
            m_ra = std::shared_ptr<ReplaceAlgorithm>(new LRU_ReplaceAlgorithm());
        } else if (ReplacePolicy::FIFO == policy) {
            m_ra = std::shared_ptr<ReplaceAlgorithm>(new FIFO_ReplaceAlgorithm());
        } else if (ReplacePolicy::RANDOM == policy) {
            m_ra = std::shared_ptr<ReplaceAlgorithm>(new Random_ReplaceAlgorithm());
        } else {
            m_ra = nullptr;
        }
    }
    void Replace() {
        if (nullptr != m_ra) {
            m_ra->Replace();
        }
    }
 private:
    std::shared_ptr<ReplaceAlgorithm> m_ra;
};

template <typename T_RA>
class Cache3 {
 public:
    Cache3() : m_ra(std::shared_ptr<T_RA>(new T_RA())) {}
    void Replace() {
        if (nullptr != m_ra) {
            m_ra->Replace();
        }
    }
 private:
    std::shared_ptr<T_RA> m_ra;
};

void policyPatternTest();

#endif //SAMPLES_CACHES_HPP
