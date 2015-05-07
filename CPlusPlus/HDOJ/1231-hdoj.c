#include <stdio.h>
#include <limits.h>

int main()
{
	int k,begin,end,tmp,i,j,max,sum;
	int seq[10000];
	
	while(scanf("%d",&k) && k > 0)
	{
		max = INT_MIN;
		sum = 0;
		begin = end = tmp = 0;
		for(i = 0; i < k; i++)
		{
			scanf("%d", &seq[i]);
			sum += seq[i];
			if(sum > max)
			{
				max = sum;
				end = i;
				begin =tmp;
			}
			if(sum < 0)
			{
				sum = 0;
				tmp = i + 1;	// 若序列中有正整数，从下一个开始为起点
			}
		}
		if(max < 0)
		{
			max		= 0;
			begin 	= 0;
			end 	= k -1;
		}
		printf("%d %d %d\n", max, seq[begin], seq[end]);
	}
}
