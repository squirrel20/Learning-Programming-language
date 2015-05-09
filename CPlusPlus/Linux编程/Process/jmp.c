#include <stdio.h>
#include <setjmp.h>

jmp_buf jmpbuffer;

void a();
void b();

int
main(void)
{
    if(setjmp(jmpbuffer) == 0)
        puts("self call");
    else
    {
        puts("jmp here");
        return 0;
    }
    a();
    return 0;
}

void a()
{
    b();
}

void b()
{
    longjmp(jmpbuffer, 1);
}
