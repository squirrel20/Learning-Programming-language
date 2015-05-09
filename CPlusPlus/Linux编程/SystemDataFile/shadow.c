#include <stdio.h>
#include <shadow.h>

int main(void)
{
    struct spwd *sp;
    setspent();
    while((sp = getspent()) != NULL)
        printf("%s:%s\n", sp->sp_namp, sp->sp_pwdp);
    endspent();
    return 0;
}
