#include <stdio.h>

int *a();

int
main(void)
{
    int i;
    int *p = a();
    for(i = 0; i < 10; i++)
        printf("%d ", p[i]);
    printf("\n");
    return 0;
}

int*
a()
{
    int i;
    int arr[10];
    for(i = 0; i < 10; i++)
        arr[i] = i;
    return arr;
}
