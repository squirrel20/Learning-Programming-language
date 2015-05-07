#include <stdio.h>
#include <stdlib.h>

int st[100], en[100];

int s_random(int p, int r)
{
	int num;
	num = rand() % (r - p);
	num += p;
	return num;
}

/*
 * 定义一个主元，使主元大于其左边的数字，小于其右边的数字
 */
int partition(int *A, int p, int r)
{
	int x, index, i, j, tmp;
	
	i 		= p - 1;
	index 	= s_random(p, r);
	tmp		= A[index];
	A[index]= A[r];
	A[r]	= tmp;
	
	tmp		= en[index];
	en[index]= en[r];
	en[r]	= tmp;
	
	x 		= A[r];
	
	for(j = p; j < r; j++)
	{
		/*
		 * i 始终指向比主元小的数字， i + 1 指向比主元大的数字
		 * j 指向的数字比住院小，所以与 i + 1指向的数字交换
		 * i++
		 * 交换A[i] A[j] , i仍然指向比主元小的数字
		 */
		if(A[j] <= x){
			i++;
			tmp 	= A[i];
			A[i] 	= A[j];
			A[j] 	= tmp;
			
			tmp 	= en[i];
			en[i] 	= en[j];
			en[j] 	= tmp;
		}
	}
	tmp = A[r];
	A[r] = A[i + 1];
	A[i + 1] = tmp;
	
	tmp = en[r];
	en[r] = en[i + 1];
	en[i + 1] = tmp;
	
	return i + 1;
}

void quiksort(int *A, int p, int r)
{
	int q;
	if(p < r){
		q = partition(A, p, r);
		quiksort(A, p, q - 1);
		quiksort(A, q + 1, r);
	}
}

int
main(void)
{
	int L, M, i, num, s, e;
	
	scanf("%d %d", &L, &M);
	for(i = 0; i < M; i++)
	{
		scanf("%d %d", &st[i], &en[i]);
		/*
		if(st[i] > L)
		{
			st[i] = en[i] = L;
		}
		if(en[i] > L)
			en[i] = L;
		*/
	}
	quiksort(st, 0, M - 1);
	
	num	= en[0] - st[0] + 1;
	e	= en[0];
	for(i = 1; i < M; i++)
	{
		if(st[i] > e){
			num += en[i] - st[i] + 1;
			e	= en[i];
		}else if(st[i] <= e && en[i] > e){
			num += en[i] - e;
			e	= en[i];
		}
		
	}
	printf("%d\n", L + 1 - num);
	exit(0);
}
