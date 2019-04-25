 # [对齐](https://zh.cppreference.com/w/cpp/language/object#.E5.AF.B9.E9.BD.90)
 
 ## alignof 运算符

 * [alignof](https://zh.cppreference.com/w/cpp/language/alignof)

返回由类型标识所指示的类型的任何实例所要求的对齐字节数，该类型可以为完整类型、数组类型或者引用类型。
若类型为引用类型，则运算符返回被引用类型的对齐；若类型为数组类型，则返回元素类型的对齐要求。

## 对齐

每个对象类型都具有被称为对齐要求（alignment requirement）的性质，它是一个整数（类型为 std::size_t，总是 2 的幂），表示这个类型的不同对象所能分配放置的连续相邻地址之间的字节数。可以使用 alignof 或 std::alignment_of 来查询类型的对齐要求。可以使用指针对齐函数 std::align 来获取某个缓冲区中经过适当对齐的指针，还可以使用 std::aligned_storage 来获取经过适当对齐的存储区。

对象类型会强制该类型的所有对象实行这个类型的对齐要求；可以使用 alignas 来要求更严格的对齐（更大的对齐要求）。

为了使类中的所有非静态成员都符合对齐要求，会在一些成员后面插入一些填充。

```c++
#include <iostream>
 
// S 类型的对象可以在任何地址上分配
// 因为 S.a 和 S.b 都可以在任何地址上分配
struct S {
  char a; // 大小：1，对齐：1
  char b; // 大小：1，对齐：1
}; // 大小：2，对齐：1
 
// X 类型的对象只能在 4 字节边界上分配
// 因为 X.n 必须在 4 字节边界上分配
// 因为 int 的对齐要求（通常）就是 4
struct X {
  int n;  // 大小：4，对齐：4
  char c; // 大小：1，对齐：1
  // 三个填充字节
}; // 大小：8，对齐：4
 
int main()
{
    std::cout << "sizeof(S) = " << sizeof(S)
              << " alignof(S) = " << alignof(S) << '\n';
    std::cout << "sizeof(X) = " << sizeof(X)
              << " alignof(X) = " << alignof(X) << '\n';
}
```