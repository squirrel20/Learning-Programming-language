#include <stdio.h>
#include <string.h>
int main()
{
	int i, j, tmp, slen, tlen;
	char s[100001],t[100001];
	while(scanf("%s %s", s, t) != EOF){
		slen = strlen(s);
		tlen = strlen(t);
		tmp = 0;
		for(i=0; i<slen; i++){
			for(j = tmp; j<tlen; j++)
				if(t[j] == s[i]){
					tmp = j + 1;
					break;
				}
			if(j >= tlen){
				puts("No");
				break;
			}
		}
		if(i >= slen)
			puts("Yes");
	}
	return 0;
}
