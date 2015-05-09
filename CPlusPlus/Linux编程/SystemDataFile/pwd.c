#include <pwd.h>
#include <stdio.h>

int main(void)
{
    struct passwd *ptr;
    setpwent();
    while((ptr = getpwent()) != NULL)
        printf("%s:%s\n", ptr->pw_name, ptr->pw_passwd);
    endpwent();
    return 0;
}
