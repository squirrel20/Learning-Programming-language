#include <stdio.h>
#include <math.h>

int max(int a, int b)
{
	if(a > b)
		return a;
	return b;
}

int
main(void)
{
	int		t,sx,sy,ex,ey,a,b;
	char	arr[6];
	scanf("%d\n", &t);
	
	while(t--)
	{
		gets(arr);
		sx = arr[0] - 96;
		sy = arr[1] - 48;
		ex = arr[3] - 96;
		ey = arr[4] - 48;
		
		if(sx == ex && sy == ey)
			puts("0 0 0 0");
		else if(sx == ex){
			printf("%d 1 1 ", abs(sy - ey));
			if((ey - sy) % 2 == 0)
				puts("2");
			else
				puts("Inf");
		}else if(sy == ey){
			printf("%d 1 1 ", abs(sx - ex));
			if((ex - sx) % 2 == 0)
				puts("2");
			else
				puts("Inf");
		}else{
			printf("%d ", max(abs(sy - ey), abs(sx - ex)));
			
			a = abs(sx - ex);
			b = abs(sy - ey);
			if(a == b)
				printf("1 ");
			else
				printf("2 ");
				
			printf("2 ");
			
			if(a == b)
				puts("1");
			else
			{
				sx %= 2;
				sy %= 2;
				ex %= 2;
				ey %= 2;
				if(sx == ex && sy == ey)
					puts("2");
				else
					puts("Inf");
			}
			
				
		}
	}
	return 0;
}
