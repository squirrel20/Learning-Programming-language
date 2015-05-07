#include <stdio.h>



int main(void)
{
    int n, m, letpos, i;
    int f[21][900], path[21][900], p[201], d[201];

    scanf("%d %d", &n, &m);
    while (n > 0 && m > 0) {

        for (i = 1; i <= n; i++)
            scanf("%d %d", &p[i], &d[i]);

        letpos = m * 20;

        f[0][0] = 0;

        scanf("%d %d", &n, &m);
    }
    return 0;
}