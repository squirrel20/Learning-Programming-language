// CPlusPlus.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"

extern void duiqi();
extern void testDe();
extern void test();

void arr(int* p)
{
	for (int i = 0; i < 2; i++)
		for (int j = 0; j < 2; j++)
		*p++ = 100;
}

int main(int argc, char* argv[])
{
	int a[2][2] = { 1,2,3,4 };
	arr(a[0]);
	cout << a[1][1] << endl;
	//TestOperator();

	//duiqi();

	//test_mul_256_add();
	//test_mul_256_add();
	//testEncyption();
	//testReversal();
	//test_mul_32();
	//int i = 1;
	//i = ~i;
	//cout << i << endl;

	//test();
	//testDe();

	/*int a = 0x00000001;
	a = ~a;
	printf("0x%04X\n", a);
*/
}

