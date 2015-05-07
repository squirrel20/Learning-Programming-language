#include <stdio.h>
#include <limits.h>
#include <string.h>

int main()
{
	int num[100002];
	int t,n,i,j=0;
	int sum,max,begin,end,tmp;

	scanf("%d", &t);
	
	for(i = 1; i <= t; i++)
	{
		sum	= 0;
		max	= INT_MIN;
		begin	= end = 1;
		tmp	= 1;	
		
		memset(num, 0, sizeof(num));
		scanf("%d", &n);
		
		for(j = 0; j < n; j++)
		{
			scanf("%d", &num[j]);
			sum += num[j];
			
			if(sum > max)
			{
				max	= sum;
				begin	= tmp;
				end = j + 1;
			}
			if(sum < 0)
			{
				sum	= 0;
				tmp	= j + 2;
			}
		}
		
		printf("Case %d:\n%d %d %d\n", i, max, begin, end);
		if(i < t)
			printf("\n");
	}
	return 0;
}
