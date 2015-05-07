#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct Word{
	char en[21];
	int prelen;
	int index;
}Word, PWord;

Word word[1001];

int compare(const void *a, const void *b)
{
	return strcmp(((struct Word*)b)->en, ((struct Word*)a)->en);
}

int compare_int(const void *a, const void *b)
{
	return ((struct Word*)a)->index - ((struct Word*)b)->index;
}

int min(int a, int b)
{
	if(a > b)
		a = b;
	return a;
}

int main(void)
{
	int i,j,k,len;
	char tmp[21];

	len = 0;
	while(scanf("%s", word[len].en)!=EOF){ 
		word[len].index = len;
		word[len].prelen = 0;
		len++;
	}	
	qsort(word, len, sizeof(Word), compare);	

	for(i = 0; i < len-1; i++)
	{
		k = min( strlen(word[i].en), strlen(word[i+1].en) );
		for(j = 0; j < k; j++)
		{
			if( word[i].en[j] == word[i+1].en[j] )
				word[i+1].prelen++;	
			else
				break;
		}
		if(word[i].prelen < word[i+1].prelen)
			word[i].prelen = word[i+1].prelen;
		//printf("%s %d %d\n", word[i].en, word[i].prelen, k);
	}
	//printf("%s %d %d\n", word[i].en, word[i].prelen, k);
	qsort(word, len, sizeof(Word), compare_int);
	for(i = 0; i < len; i++)
	{
		memset(tmp, '\0', 21);
		if(word[i].prelen > 0)
		{
			strncpy(tmp, word[i].en, word[i].prelen+1);
			printf("%s %s\n", word[i].en, tmp);
		}
		else
			printf("%s %s\n", word[i].en, word[i].en);
	}
	return 0;
}
