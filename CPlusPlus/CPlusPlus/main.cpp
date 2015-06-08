// CPlusPlus.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"


const int BLOCK = 20;

typedef struct {
	int *array;
	int size;
}Array;

Array array_create(int init_size)
{
	Array a;
	a.size = init_size;
	a.array = (int*)malloc(sizeof(int)*a.size);//分配内存
	return a;
}

void array_free(Array*a)
{
	free(a->array);//释放内存

	a->array = 0;
	a->size = 0;
}

//封装
int array_size(const Array*a)
{
	return a->size;
}

void array_inflate(Array*a, int more_size)
{
	int *p = (int*)malloc(sizeof(int)*(a->size + more_size));
	int i;
	for (i = 0; i < a->size; i++) {
		p[i] = a->array[i];
	}
	free(a->array);
	a->array = p;
	a->size += more_size;
}

int *array_at(Array *a, int index)
{
	if (index >= a->size) {
		array_inflate(a, (index / BLOCK + 1)*BLOCK - a->size);
	}
	return &(a->array[index]);
}

int main(void)
{

	Array a = array_create(100);
	printf("%d\n", array_size(&a));
	*array_at(&a, 0) = 10;
	printf("%d\n", *array_at(&a, 0));

	int number = 0;
	int cnt = 0;
	while (number != -1) {
		scanf("%d", &number);
		if (number != -1) {
			*array_at(&a, cnt++) = number;
		}
	}

	array_free(&a);
	return 0;
}
