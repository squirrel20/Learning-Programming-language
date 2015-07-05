#include "stdafx.h"

// 赋值运算符必须定义为成员函数。
// 如果一个运算符是一个成员函数，其左侧运算对象就绑定到隐式的this参数，其右侧运算对象作为显示参数传递。
// 赋值运算符通常应该返回一个指向其左侧运算对象的引用。
OperatorTest& OperatorTest::operator=(const OperatorTest& right)
{
	id = right.GetId();
	return *this;
}

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

// 运算符重载测试
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

// 拷贝赋值运算符测试
void TestCopy()
{
	PutPre("拷贝赋值运算符测试");
	OperatorTest a(1);
	OperatorTest b(2);
	a = b;
	cout << a << endl;
}