#include <stdio.h>
#include <string.h>
int main()
{
int totalSch, maxSch, curSch, ag, gg, paper, n;
char sc, ws;
char name[21], temp[21];
totalSch = maxSch = 0;
memset(name, '\0', 21);
scanf("%d", &n);
while(n--)
{
memset(temp, '\0', 21);
curSch = 0;
scanf("%s %d %d %c %c %d", temp, &ag, &gg, &sc, &ws, &paper);
if(ag > 80 && paper > 0) curSch += 8000;
if(ag > 85 && gg > 80) curSch += 4000;
if(ag > 90) curSch += 2000;
if(ag > 85 && ws == 'Y') curSch += 1000;
if(gg > 80 && sc == 'Y') curSch += 850;
totalSch += curSch;
if(curSch > maxSch){ maxSch = curSch; strncpy(name, temp, 21);}
}
printf("%s\n%d\n%d\nhi", name, maxSch, totalSch);
}
