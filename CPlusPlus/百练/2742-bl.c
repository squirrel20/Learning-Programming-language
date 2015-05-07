#include <stdio.h>

int main()
{
	int i,n,tmp;
	int arr[26];
	char in[1002];
	scanf("%d", &n);
	while(n--){
		for(i=0; i<26; i++)
			arr[i] = 0;
		scanf("%s",in);
		for(i=0; in[i]; i++)
			arr[in[i] - 'a']++;
		tmp = 0;
		for(i=0; i<26; i++)
			if(arr[i] > arr[tmp])
				tmp = i;
		printf("%c %d\n",tmp + 'a',arr[tmp]);
	}
}
