#include <iostream>
#include <atomic>
#include <memory>

/**
 * [alignof](https://zh.cppreference.com/w/cpp/language/alignof)
 * 返回由类型标识所指示的类型的任何实例所要求的对齐字节数，该类型可以为完整类型、
 * 数组类型或者引用类型。若类型为引用类型，则运算符返回被引用类型的对齐；若类型
 * 为数组类型，则返回元素类型的对齐要求。
 */

using namespace std;

int main() {
    cout << "HI" << endl;
    
    atomic<bool> a;
    return 0;
}