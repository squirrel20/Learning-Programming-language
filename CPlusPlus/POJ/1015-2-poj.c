#include <stdio.h>
#include <stdlib.h>

struct can
{
    int minus;
    int absm;   // abs minus;
    int sum;
    int p;
    int d;
    int index;
};

int myabs(int num)
{
    return num > 0 ? num : (-1 * num);
}

int comp(const struct can *a, const struct can *b)
{
    return a->absm - b->absm;
}

int comp2(const struct can *a, const struct can *b)
{
    return b->sum - a->sum;
}


int main(void)
{
    int m,n,i,p,d,index;
    struct can c[200];
    
    index = 1;
    scanf("%d %d", &m, &n);
    while(m > 0 && n > 0) {
        for(i = 0; i < n; i++) {
            scanf("%d %d", &p, &d);
            c[i].p = p;
            c[i].d = d;
            c[i].minus = p - d;
            c[i].absm = myabs(p - d);
            c[i].sum = p + d;
            c[i].index = i + 1;
        }
        qsort(c, n, sizeof(struct can), comp);
        p = 1;
        for(i = 1; i < n; i++) {
            if(c[i].sum == c[i-1].sum) {
                p++;

            } else {
                if(p > 1) {
                    qsort(&c[i - p], p, sizeof(struct can), comp);
                }
                p = 1;
            }
        }

        printf("Jury #%d\n", index++);
        p = d = 0;
        for(i = 0; i < m; i++) {
            p += c[i].minus;
            d += c[i].sum;
        }

        scanf("%d %d", &m, &n);
    }
    return 0;
}