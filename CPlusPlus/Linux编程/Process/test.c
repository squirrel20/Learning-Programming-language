#include <stdio.h>

int *a();
//void b();

int
main(void)
{
    int i;
    int *p = a();
    //b();
    for(i = 0; i < 10; i++)
        printf("%d ", p[i]);
    printf("\n");
    return 0;
}

int *a()
{
    int arr[10];
    int i;
    for(i = 0; i < 10; i++)
        arr[i] = i;
    return arr;
}

