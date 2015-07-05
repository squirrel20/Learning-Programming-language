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

// �������������������������������Ƿǳ�Ա����
ostream &operator<<(ostream& os, const OperatorTest& ot);

// �������������
istream &operator>>(istream& in, OperatorTest& ot);

void TestOperator();
void TestCopy();