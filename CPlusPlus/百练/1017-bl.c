#include <stdio.h>

int main(void)
{
	int a,b,c,d,e,f,N,x,y;
	int arr[4] = {0, 5, 3, 1};
	while(1)
	{
		scanf("%d %d %d %d %d %d",&a, &b, &c, &d, &e, &f);
		if(a == 0 && b == 0 && c == 0 && d == 0 && e == 0 && f == 0)
			break;
		N = f + e + d + (c + 3)/4;
		x = 5 * d + arr[ c % 4 ];
		if(b > x)
			N += (b - x + 8)/9;
		// now, we assume 2*2 puted in box, but we do nothing
		y = N * 36 - f * 36 - e * 25 - d * 16 - c * 9 - b * 4;
		if(a > y)
			N += (a - y + 35)/36;
		printf("%d\n",N);
	}
	return 0;
}
