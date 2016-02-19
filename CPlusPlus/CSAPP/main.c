#include "inc.h"

int main(int argc, char *argv)
{
    show_bytes_test();
    is_little_endian_test();
    f259_test();
    put_byte_test();
    f261_test();
    int_shifts_are_logical_test();
    sra_test();
    any_even_one_test();
    even_ones_test();

    return 0;
}

///
void show_bytes(byte_pointer start, int len)
{
    int i;
    for(i = 0; i < len; i++)
        printf(" %.2x", start[i]);
    printf("\n");
}

void show_int(int x)
{
    show_bytes((byte_pointer) &x, sizeof(int));
}

void show_float(float x)
{
    show_bytes((byte_pointer) &x, sizeof(float));
}

void show_pointer(void *x)
{
    show_bytes((byte_pointer) &x, sizeof(void *));
}

void show_short(short x)
{
    show_bytes((byte_pointer) &x, sizeof(short));
}

void show_long(long x)
{
    show_bytes((byte_pointer) &x, sizeof(long));
}

void show_double(double x)
{
    show_bytes((byte_pointer) &x, sizeof(double));
}

void show_bytes_test()
{
    // 其实没必要定义这么多变量，函数传参时可以类型转换
    int ival = 0x01020304;
    float fval = (float)ival;
    int *pval = &ival;
    short sval = (short)ival;   // 小端机器上，截断更容易被理解，低位值会被保留，高位值会被截断
    long lval = (long)ival;
    double dval = (double)ival;


    BEGIN_TEST;

    show_int(ival);
    show_float(fval);
    show_pointer(pval);
    show_short(sval);
    show_long(lval);
    show_double(dval);

    END_TEST;
}

///
int is_little_endian()
{
    // 假设short类型为两个字节
    // short s = 0x01 
    // 小端存储：01 00
    // 大端存储：00 01
    // char c = (char)s; 类型转换会截断，只取第一个字节，因此小端取01，大端取00
    short s = 0x01;

    return (char)s;
}

void is_little_endian_test()
{
    BEGIN_TEST;
    printf("is_little_endian: %d\n", is_little_endian());
    END_TEST;
}

int f259(int x, int y)
{
    return (x & 0xFF) | (y & ((~0) ^ 0xFF));
}

void f259_test()
{
    int x, y;
    x = 0x89ABCDEF;
    y = 0x76543210;

    BEGIN_TEST;

    printf("0x%x\n", f259(x, y));

    END_TEST;
}

unsigned put_byte(unsigned x, unsigned char b, int i)
{
    // 将x的第i个字节置为b，小端存储
    if(sizeof(unsigned) <= (unsigned)i) return x;

    unsigned y = x;

    byte_pointer p = (byte_pointer)&y;
    p[i] = b;

    return y;
}

void put_byte_test()
{
    BEGIN_TEST;

    printf("0x%x\n", put_byte(0x12345678, 0xAB, 2));
    printf("0x%x\n", put_byte(0x12345678, 0xAB, 0));

    END_TEST;
}

int f261(int x)
{
    // 满足下面四种条件返回1， 否则返回0
    //
    // 四种条件产生1，把四种运算结果用逻辑或组合起来就可以了
    // 思路，在这四种条件下，通过运算最后得到0，!0 = 1
    //
    // A. 当x任何位都等于1时， x ^ x = 0;
    // B. 当x任何位都等于0时，x = 0, !x = 1;
    // C. 当x最高有效字节中的位都等于1时，
    //    先把最高字节算术右移到最低字节，再将x的高位字节全部置0，
    //    对最低字节异或0xFF, 最终结果会等于0
    // D. 当x最低有效字节中的位都等于0时，
    //    对x按位与0xFF，最终结果会等于0

    int shift_val = (sizeof(int) - 1) << 3;
    return 
        !(x ^ (~0))                             // A. x的任何位都等于1
        || !x                                   // B. x的任何为都等于0
        || !(((x >> shift_val) & 0xFF) ^ 0xFF)  // C. x的最高有效字节中的位都等于1
        || !(x & 0xFF)                          // D. x的最低有效字节中的位都等于0
        ;
}

void f261_test()
{
    BEGIN_TEST;

    int a = ~0;
    int b = 0;
    int c = (INT_MIN >> 8) + 1;   // 有符号数右移，最高位算术补齐，负数补1
    int d = 123 << 8;   // 左移补0
    int e = 123;

    printf("A. 0X%x : %d\n", a, f261(a));
    printf("B. 0X%x : %d\n", b, f261(b));
    printf("C. 0X%x : %d\n", c, f261(c));
    printf("D. 0X%x : %d\n", d, f261(d));
    printf("O. 0X%x : %d\n", e, f261(e));

    END_TEST;
}

int int_shifts_are_logical()
{
    // 算术右移返回1，否则返回0
    // 如果是算术右移，那么-1右移一位还是-1，而 -1 ^ -1 = 0
    return !((~0 >> 1) ^ (~0));
}

void int_shifts_are_logical_test()
{
    BEGIN_TEST;
    printf("int_shifts_are_logical: %d\n", int_shifts_are_logical());
    END_TEST;
}

int sra(int x, int k)
{
    int xsrl = (unsigned) x >> k;   // 逻辑右移

    // 手动实现高位的算术补齐，就是用x的最高位来补齐
    // 1. 获取x的最高位
    // 2. 将x的最高位补齐在xsrl的高位

    int shift = sizeof(unsigned) << 3;
    int h = !!((1 << (shift - 1)) & x);  // 若最高有效位为1， h = 1, 否则 h = 0 

    return xsrl | ((h << k) - h) << (shift - k - !h);
}

unsigned srl(unsigned x, int k)
{
    unsigned xsra = (int) x >> k;

    // 将算术右移的高位全部置为0

    // 使用逻辑非运算，可以把int型隐式转换为bool型
    int shift = sizeof(unsigned) << 3;

    int h = ((~0) << (shift - k)) ^ (~0); // 高位全为0， 低位为1

    return xsra & h;
}

void sra_test()
{
    BEGIN_TEST;
    printf("0x%xu >> %d = 0x%xu\n", 0xF0010203, 8, srl(0xF0010203, 8));
    printf("0x%x >> %d = 0x%x\n",  0xF0010203, 8, sra(0xF0010203, 8));
    END_TEST;
}

int any_even_one(unsigned x)
{
    return !!(x | 0);
}

void any_even_one_test()
{
    BEGIN_TEST;
    printf("any_even_one(0) = %d\n", any_even_one(0));
    printf("any_even_one(2) = %d\n", any_even_one(2));
    END_TEST;
}

int even_ones(unsigned x)
{
    // x的二进制位有偶数个1，返回1，否则返回0
    // 代码最多只能包含12个算术运算、位运算和逻辑运算
    // 异或：1 ^ 1 = 0 一次异或消掉偶数个1
    
    x ^= x >> 16;
    x ^= x >> 8;
    x ^= x >> 4;
    x ^= x >> 2;
    x ^= x >> 1;

    return !(x & 1);
}

void even_ones_test()
{
    unsigned i;
    BEGIN_TEST;

    for(i = 0xff; i < 0x10f; i++)
        printf("even_ones(0x%x) = %d\n", i, even_ones(i));
    END_TEST;
}
