#include "stdafx.h"
#include <iostream>
using namespace std;

double a;
double b;
double c;
double d;

void duiqi()
{
	double *p = (double *)&a;

	*p = 1;
	p++;
	*p = 2;
	p++;
	*p = 3;
	p++;
	*p = 4;
	p++;

	cout << "hi" << endl;

	cout << a << endl;
	cout << b << endl;
	cout << c << endl;
	cout << d << endl;

}
