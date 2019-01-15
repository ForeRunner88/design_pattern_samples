// Copyright (c) 2018 SenseTime Group. All rights reserved.
// WuXiao <wuxiao@sensetime.com> create on 18-12-31.
#ifndef SAMPLES_BUILDER_PATTERN_PRODUCT_COMPUTER_HPP
#define SAMPLES_BUILDER_PATTERN_PRODUCT_COMPUTER_HPP

#include <string>

class Computer {
 public:
    void SetCpu(const std::string& cpu) {
        m_cpu = cpu;
    }
    std::string GetCpu() const {
        return m_cpu;
    }

    void SetMainboard(const std::string& mainboard) {
        m_mainboard = mainboard;
    }
    std::string GetMainboard() const {
        return m_mainboard;
    }

    void SetRam(const std::string& ram) {
        m_ram = ram;
    }
    std::string GetRam() const {
        return m_ram;
    }

    void SetGpu(const std::string& gpu) {
        m_gpu = gpu;
    }
    std::string GetGpu() const {
        return m_gpu;
    }
 protected:
    std::string m_cpu;  // CPU
    std::string m_mainboard;  // 主板
    std::string m_ram;  // 内存
    std::string m_gpu;  // 显卡
};

#endif  // SAMPLES_BUILDER_PATTERN_PRODUCT_COMPUTER_HPP



