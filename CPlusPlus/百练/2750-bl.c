#include <stdio.h>

int
main(void)
{
	int n, a;
	scanf("%d", &n);
	while(n--)
	{
		scanf("%d", &a);
		if( a % 2)
			printf("0 0\n");
		else
			printf("%d %d\n", a / 4 + (a % 4) / 2, a / 2);
	}
	return 0;
}
