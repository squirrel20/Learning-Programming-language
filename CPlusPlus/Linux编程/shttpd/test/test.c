#include <stdio.h>

int main(void)
{
	int i, num;

	num = 1;
	for (i = 2; i <= 15; i++)
		num += (i * 4);

	printf("%d\n", num);
	return 0;
}
