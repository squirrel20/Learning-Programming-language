#include <stdio.h>
#include <string.h>
#include <stdlib.h>
void count(char *p, int *a)
{
	int i, len;
	len = strlen(p);
	for(i = 0; i < len; i++)
		a[p[i] - 'A']++;
}

int compare(const void *a, const void *b)
{
	return *(int*)a - *(int*)b;
}

int main()
{
	int i,len;
	int a1[26], a2[26];
	char s1[101], s2[101];
	memset(a1, 0, sizeof(int)*26);
	memset(a2, 0, sizeof(int)*26);
	scanf("%s %s",s1, s2);
	count(s1, a1);
	count(s2, a2);
	qsort(a1, 26, sizeof(int), compare);
	qsort(a2, 26, sizeof(int), compare);
	if(memcmp(a1, a2, sizeof(int)*26) == 0)
		puts("YES");
	else
		puts("NO");
	return 0;
}
