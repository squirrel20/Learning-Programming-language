#include <iostream>
 
struct Foo {
    int   i;
    float f;
    char  c;
};
 
struct Empty {};
 
struct alignas(64) Empty64 {};
 
int main()
{
    std::cout << "Alignment of"  "\n"
        "- char             : " << alignof(char)    << "\n"
        "- pointer          : " << alignof(int*)    << "\n"
        "- class Foo        : " << alignof(Foo)     << "\n"
        "- empty class      : " << alignof(Empty)   << "\n"
        "- alignas(64) Empty: " << alignof(Empty64) << "\n";
}