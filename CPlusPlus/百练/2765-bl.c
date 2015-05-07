#include <stdio.h>
#include <string.h>
int main()
{
	char k[18],d[46];
	int i,len;
	double out;
	memset(k,'\0',18);
	while(scanf("%s", k) != EOF)
	{
		len = strlen(k);
		out = 0;
		for(i=len-1; i>=2; i--)
			out = (out + (k[i] - '0')) * 0.125;
		printf("%s [8] = %.45g [10]\n");
	}
	return 0;
}
