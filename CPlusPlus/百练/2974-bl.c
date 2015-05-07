#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char tel[100000][9], in[16];
char stan[] = "22233344455566677778889999";

int compare(const void *a, const void *b)
{
	return (strcmp((char*)a, (char*)b));
}

void toNum(int index)
{
	int i,j;
	i=j=0;
	while(i < 9){
		if(in[j] == '-'){
			j++;
			continue;
		}
		if(i == 3){
			tel[index][i] = '-';
			i++;
		}
		if(in[j] >= 'A' && in[j] <= 'Z')
			tel[index][i] = stan[in[j] - 'A'];
		if(in[j] >= '0' && in[j] <= '9')
			tel[index][i] = in[j];
		j++;
		i++;
	}
}
int main()
{
	int i,j,n, nodup;
	scanf("%d", &n);
	for(i=0; i<n; i++){
		scanf("%s", in);
		toNum(i);
	}
	
	qsort(tel, n, 9, compare);
	
	nodup = 1;
	i=0;
	while(i<n){
		j=i;
		i++;
		while(i<n && strcmp(tel[i], tel[j]) == 0) i++;
		if(i - j > 1){
			printf("%s %d\n", tel[j], i-j);
			nodup = 0;
		}
	}
	if(nodup)
		printf("No duplicates.\n");
	
	return 0;
}
