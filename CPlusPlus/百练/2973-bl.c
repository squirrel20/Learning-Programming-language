#include <stdio.h>
#include <string.h>
int main()
{
	char skew[32];
	int base[31];
	int i,num,len;
	base[0] = 1;
	for(i=1; i<31; i++) base[i] = base[i-1] * 2 + 1;
	while(1){
		memset(skew,'\0',32);
		scanf("%s", skew);
		if(skew[0] == '0') break;
		num = 0;
		len = strlen(skew);
		for(i=len-1; i>=0; i--){
			num += (skew[i]-'0') * base[len-1 - i];
		}
		printf("%d\n",num);
	}
	return 0;
}
