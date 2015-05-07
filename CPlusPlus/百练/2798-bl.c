#include <stdio.h>
#include <string.h>
#define BNUM 10001
#define XNUM 2501

int main()
{
int i,j,tmp,n,blen;
int btx[4] = {1,2,4,8};
char b[BNUM],x[XNUM];
scanf("%d",&n);
while(n--)
{
memset(b,'\0',BNUM);
memset(x,'\0',XNUM);
scanf("%s",b);
blen=strlen(b);
i=j=0;
if(blen%4)
{
tmp = 0;
for(j=0; j<blen%4; j++)
tmp += (b[j] - '0') * btx[blen%4 - 1 - j];
if(tmp < 10)
x[i] = tmp + '0';
else
x[i] = tmp - 10 + 'A';
i++;
}
for(;j<blen;i++, j+=4)
{
tmp = (b[j]-'0') * 8 + (b[j+1]-'0') * 4 + (b[j+2]-'0') * 2 + (b[j+3]-'0');
if(tmp < 10)
x[i] = tmp + '0';
else
x[i] = tmp - 10 + 'A';
}
printf("%s\n",x);
}
return 0;
}
