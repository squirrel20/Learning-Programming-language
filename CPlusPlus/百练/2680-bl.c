#include <stdio.h>
int main()
{
int k, hgb, hct, plt, num;
float wbc, rbc;
char sex[7];
scanf("%d", &k);
while(k--)
{
num = 0;
scanf("%s %f %f %d %d %d", sex, &wbc, &rbc, &hgb, &hct, &plt);
if(wbc > 10.0 || wbc < 4.0) num++;
if(rbc > 5.5 || rbc < 3.5) num++;
if(plt > 300 || plt < 100) num++;
if(sex[0] == 'm')
{
if(hgb > 160 || hgb < 120) num++;
if(hct > 48 || hct < 42) num++;
}else
{
if(hgb > 150 || hgb < 110) num++;
if(hct > 40 || hct < 36) num++;
}
if(num > 0) printf("%d\n",num);
else printf("normal\n");
}
}
