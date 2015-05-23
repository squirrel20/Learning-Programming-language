#include "stdafx.h"

// 对于二元运算符（<<）来说，左侧运算对象传递给第一个参数，右侧运算对象传递给第二个参数
// cout << ot; 这里cout就传递给os，ot传递给ot
ostream &operator<<(ostream &os, const OperatorTest &ot)
{
	os << ot.GetId();
	return os;
}

istream &operator>>(istream &in, OperatorTest& ot)
{
	int i;
	in >> i;
	// 输入运算符必须处理输入可能失败的情况，而输出运算符不需要
	if (in)
		ot.SetId(i);
	return in;
}

// 对于一个运算符函数来说，它或者是类的成员，或者至少有一个类类型的参数
// 只有自定义的类类型才可以重载运算符，string已经重载过运算符了
//ostream &operator<<(ostream &os, const string &info)
//{
//	os << " " << info;
//	return os;
//}

void TestOperator()
{
	PutPre("运算符重载测试");
	OperatorTest ot(3);
	cout << ot << endl;
	cout << "输入一个整数：";
	cin >> ot;
	cout << ot << endl;
	string s = "hi";
	cout << s << endl;
}
