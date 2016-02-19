// gcc -O1 -S code.c    产生汇编代码
// gcc -O1 -c code.c    产生目标代码文件
int accum = 0;

int sum(int x, int y)
{
    int t = x + y;
    accum += t;
    return t;
}
