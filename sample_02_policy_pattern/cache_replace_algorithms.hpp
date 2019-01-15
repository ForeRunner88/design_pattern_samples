// Copyright (c) 2018 SenseTime Group. All rights reserved.
// WuXiao <wuxiao@sensetime.com> create on 18-12-29.
#ifndef SAMPLES_CACHE_REPLACE_ALGORITHMS_HPP
#define SAMPLES_CACHE_REPLACE_ALGORITHMS_HPP

#include <iostream>

class ReplaceAlgorithm {
 public:
    virtual void Replace() = 0;
};

class LRU_ReplaceAlgorithm : public ReplaceAlgorithm {
 public:
    void Replace() {
        std::cout << "Least Recently Used replace algorithm" << std::endl;
    }
};

class FIFO_ReplaceAlgorithm : public ReplaceAlgorithm {
 public:
    void Replace() {
        std::cout << "First in First out replace algorithm" << std::endl;
    }
};

class Random_ReplaceAlgorithm : public ReplaceAlgorithm {
 public:
    void Replace() {
        std::cout << "Random replace algorithm" << std::endl;
    }
};

#endif //SAMPLES_CACHE_REPLACE_ALGORITHMS_HPP
