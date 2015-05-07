#include <stdio.h>
#include <string.h>
int minB(char* p, char* q, char* r)
{
	int i,b,len;
	b = 0;
	len = strlen(p);
	for(i=0; i<len; i++){
		if(b < p[i] - '0')
			b = p[i] - '0';
	}
	len = strlen(q);
	for(i=0; i<len; i++){
		if(b < q[i] - '0')
			b = q[i] - '0';
	}
	len = strlen(r);
	for(i=0; i<len; i++){
		if(b < r[i] - '0')
			b = r[i] - '0';
	}
	return b + 1;
}

long bToTen(char* arr, int b)
{
	int i,len;
	long temp, jin;
	temp = 0;
	jin = 1;
	len = strlen(arr);
	for(i=len-1; i>=0; i--){
		temp += (arr[i] - '0') * jin;
		jin *= b;
	}
	return temp;
}

int main()
{
	int t,b;
	long longp,longq,longr;
	char p[7], q[7], r[7];
	scanf("%d", &t);
	while(t--){
		memset(p,'\0',7);
		memset(q,'\0',7);
		memset(r,'\0',7);
		scanf("%s %s %s",p,q,r);
		b = minB(p,q,r);
		for(;b<=16; b++){
			longp = bToTen(p,b);
			longq = bToTen(q,b);
			longr = bToTen(r,b);
			if(longp * longq == longr){
				printf("%d\n",b);
				break;
			}
		}
		if(b == 17)
			printf("0\n");
	}
	return 0;
}
