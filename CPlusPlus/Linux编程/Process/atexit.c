#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
static void my_exit1(void);
static void my_exit2(void);

int
main()
{
    extern char **environ;
    int i;
    if(atexit(my_exit2) != 0)
        puts("can't register my_exit2");
    if(atexit(my_exit1) != 0)
        puts("can't register my_exit1");
    if(atexit(my_exit1) != 0)
        puts("can't register my_exit1");

    for(i =  0; environ[i] != NULL; i++)
        puts(environ[i]);
    puts("main is done.");
    return(0);
}

static void
my_exit1()
{
    puts("first exit handler");
}

static void
my_exit2()
{
    puts("second exit handler");
}
