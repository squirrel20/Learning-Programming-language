#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct Item{
	char en[11];
	char ab[11];
};

struct Item item[100001];
int len;

int compare(const void *a, const void *b)
{
	return strcmp(((struct Item*)a)->ab, ((struct Item*)b)->ab);
}

int main()
{
	int i;
	char tmp[22], ab[11];
	struct Item tmpItem;
	struct Item *p;
	len = 0;
	gets(tmp);
	while(1){
		if(!tmp[0])
			break;
		sscanf(tmp,"%s %s", item[len].en, item[len].ab);
		len++;
		gets(tmp);
	}
	qsort(item, len, sizeof(struct Item), compare);
	while(scanf("%s", ab) != EOF){
		strcpy(tmpItem.ab, ab);
		p = bsearch(&tmpItem, item, len, sizeof(struct Item), compare);
		if(p)
			puts(p->en);
		else
			puts("eh");
	}
	return 0;
}
