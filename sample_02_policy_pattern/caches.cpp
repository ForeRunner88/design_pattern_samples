#include "caches.hpp"

void testCache1();
void testCache2();
void testCache3();

void policyPatternTest() {
    std::cout << "[TEST] Policy Pattern" << std::endl;
    testCache1();
    testCache2();
    testCache3();
}

void testCache1() {
    std::cout << "==== Test Cache1 ====" << std::endl;
    std::shared_ptr<ReplaceAlgorithm> replace_al;
    replace_al = std::shared_ptr<ReplaceAlgorithm>(new LRU_ReplaceAlgorithm());
    Cache1 c1(replace_al);
    c1.Replace();
    replace_al = std::shared_ptr<ReplaceAlgorithm>(new FIFO_ReplaceAlgorithm());
    c1 = Cache1(replace_al);
    c1.Replace();
    replace_al = std::shared_ptr<ReplaceAlgorithm>(new Random_ReplaceAlgorithm());
    c1 = Cache1(replace_al);
    c1.Replace();
}

void testCache2() {
    std::cout << "==== Test Cache2 ====" << std::endl;
    Cache2 c2(Cache2::ReplacePolicy::LRU);
    c2.Replace();
    c2 = Cache2(Cache2::ReplacePolicy::FIFO);
    c2.Replace();
    c2 = Cache2(Cache2::ReplacePolicy::RANDOM);
    c2.Replace();
}

void testCache3() {
    std::cout << "==== Test Cache3 ====" << std::endl;
    Cache3<LRU_ReplaceAlgorithm> c3_1;
    c3_1.Replace();
    Cache3<FIFO_ReplaceAlgorithm> c3_2;
    c3_2.Replace();
    Cache3<Random_ReplaceAlgorithm> c3_3;
    c3_3.Replace();
}
