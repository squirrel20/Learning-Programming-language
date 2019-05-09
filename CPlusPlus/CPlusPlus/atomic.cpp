/**
 * @file atomic.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2019-05-09
 * 
 * @copyright Copyright (c) 2019
 * 
 */
#include <atomic>
#include <iostream>
#include <thread>
#include <memory>

/**
 * [alignof](alignof.md)
 */

std::atomic_llong total {0};

void func() {
    for (size_t i = 0; i < 100000000; i++) {
        total += i;
    }
}

int main() {
    std::thread t1(func);
    std::thread t2(func);
    t1.join();
    t2.join();
    std::cout << total << std::endl;
    return 0;
}
