#include <stdio.h>
#include <string.h>
#define NUM 202

int main()
{
	int i,j,tmp,count,n,k;
	int key[NUM],cur[NUM];
	char c,pt[NUM],ct[NUM];
	while(scanf("%d",&n)!= EOF && n > 0){
		for(i=1; i<=n; i++)
			scanf("%d", &key[i]);
		for(i=1; i<=n; i++)
			cur[i] = -1;
		for(i=1; i<=n; i++){
			if(cur[i] == -1){
				tmp = i;
				cur[i] = 0;
				do{
					tmp = key[tmp];
					cur[i]++;
					if(tmp != i)
						cur[tmp] = -2;
				}while(tmp != i);
				for(j=1; j<=n; j++)
					if(cur[j] == -2)
						cur[j] = cur[i];
			}
		}
		
		while(scanf("%d",&k)!= EOF && k > 0){
			getchar();
			i = 1;
			while(scanf("%c", &pt[i]) && pt[i] != '\n') i++;
			for(; i<=n; i++)
				pt[i] = ' ';
			memset(ct, ' ', NUM);
			for(i=1; i<=n; i++){
				count = k % cur[i];
				tmp = i;
				while(count--){
					tmp = key[tmp];
				}
				ct[tmp] = pt[i];
			}
			ct[n+1] = '\0';
			printf("%s\n",ct + 1);
		}

		printf("\n");
	}
	return 0;
}

/*
我的第一种想法：
明文经过T次加密后又变为明文。
我假设T<=n
但事实上T<=n是否成立，我也不能证明。
我一直以T<=n为前提来解题，多次实验后返回的结果仍然是WA

参考通过的同学的代码后，又有了第二种想法：
明文中的每一位经过Ti次加密后与原来一样。
这样的话明文中的每一位的Ti都不相同，这次我也没假设Ti<=n
然后代码就通过了。

之间有个小插曲：
scanf(" ");与getchar();
这两者之间的区别

第三种想法：优化第二种思路
明文中的某一位在移位加密过程中，它曾经所在的位置与它的周期相同。
*/
