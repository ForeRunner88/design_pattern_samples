
/** Copyright (c) 2018 SenseTime Group. All rights reserved.
  * WuXiao <wuxiao@sensetime.com> create on 18-12-29.
  *
  * @file       compiler.hpp
  * @brief      sample 01 for facad pattern
  * @autor      Allen Wu
  * @version    1.0.0
  * @date       2019.01.15
  * @url        https://blog.csdn.net/wuzhekai1985/article/details/6667564
  * @note
  *     为子系统中的一组接口提供一个一致的界面
  *     外观模式定义了一个高层接口
  *     这个接口使得这一子系统更加容易使用
  * 特点：
  *     1.它对客户屏蔽子系统组件，因而减少了客户处理的对象的数目并使得子系统使用起来更加方便
  *     2.它实现了子系统与客户之间的松耦合关系，而子系统内部的功能组件往往是紧耦合的
  *     3.如果应用需要，它并不限制它们使用子系统类
  */

#ifndef SAMPLES_FACAD_PATTERN_COMPILER_SAMPLE_HPP
#define SAMPLES_FACAD_PATTERN_COMPILER_SAMPLE_HPP

#include <iostream>

class Scanner {
 public:
    void Scan() {
        std::cout << "词法分析" << std::endl;
    }
};

class Parser {
 public:
    void Parse() {
        std::cout << "语法分析" << std::endl;
    }
};

class GenMidCode {
 public:
    void GenCode() {
        std::cout << "产生中间代码" << std::endl;
    }
};

class GenMachineCode {
 public:
    void GenCode() {
        std::cout << "产生机器码" << std::endl;
    }
};

class Compiler {
 public:
    void Run() {
        Scanner scanner;
        Parser parser;
        GenMidCode gen_mid_code;
        GenMachineCode gen_machine_code;
        scanner.Scan();
        parser.Parse();
        gen_mid_code.GenCode();
        gen_machine_code.GenCode();
    }
};

#endif  // SAMPLES_FACAD_PATTERN_COMPILER_SAMPLE_HPP
