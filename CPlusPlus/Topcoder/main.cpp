#include <string>
#include <vector>
#include <iostream>
#include <stdio.h>
#include "lib.h"
#include "test.h"
#include "TwoWaysSorting.h"
#include "FibonacciDiv2.h"
#include "BoxesDiv2.h"
#include "time.h"
#include "BinaryCode.h"
#include "heapsort.h"

using namespace std;

void test_heapsort()
{
	int i;
	int arr[] = { 0, 16, 4, 10, 14, 7, 9, 3, 2, 8, 1 };
	heapsort(arr, 10);

	for (i = 1; i <= 10; i++){
		printf("%d ", arr[i]);
	}
	printf("\n");
	getchar();
}

void test_FibonacciDiv2()
{
	FibonacciDiv2 f;
	cout << f.find(1) << endl;
	cout << f.find(13) << endl;
	cout << f.find(15) << endl;
	cout << f.find(19) << endl;
	cout << f.find(1000000) << endl;

}

void test_BoxesDiv2()
{
	BoxesDiv2 bd;

	vector <int> v;
	v.push_back(8);
	v.push_back(8);

	cout << bd.findSize(v) << endl;
}

void test_TimeDiv2()
{
	Time t;

	cout << t.whatTime(0) << endl;
	cout << t.whatTime(3661) << endl;
}

void test_BinaryCodeDiv2()
{
	BinaryCode bc;

	vector <string> vs = bc.decode("123210122");

	cout << vs[0] << " : " << vs[1] << endl;
}

void test(int i)
{
	const int cc = 0;

	int a = cc;

	//int *p = &cc;

	cout << a << endl;
}

void test_binary_search()
{
	int arr[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	int index = binary_search(arr, 10, 4);

	cout << index << endl;
}


int main(int argc, char **argv)
{
	test_binary_search();
	getchar();
	//test_heapsort();
	return 0;
}
