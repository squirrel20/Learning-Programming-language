#include <stdio.h>

int main(void)
{
	int i,n,m,num;
	scanf("%d%d", &n, &m);
	while(m > 0 && n > 0)
	{
		num = 0;
		for(i = 1; i < n; i++)
			num = (num + m) % (i + 1);
		printf("%d\n", num + 1);
		scanf("%d%d", &n, &m);
	}
	return 0;
}
