#pragma once
#include <iostream>
using namespace std;

class OperatorTest
{
public:
	OperatorTest() = default;
	OperatorTest(int i):id(i){}
	int GetId() const { return id; }
	void SetId(int i) { id = i; }
	OperatorTest& operator=(const OperatorTest&);
private:
	int id;
};

// 重载输出运算符，输入输出运算符必须是非成员函数
ostream &operator<<(ostream& os, const OperatorTest& ot);

// 重载输入运算符
istream &operator>>(istream& in, OperatorTest& ot);

void TestOperator();
void TestCopy();