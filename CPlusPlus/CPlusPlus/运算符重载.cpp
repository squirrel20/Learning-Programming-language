#include "stdafx.h"

// ��ֵ��������붨��Ϊ��Ա������
// ���һ���������һ����Ա������������������Ͱ󶨵���ʽ��this���������Ҳ����������Ϊ��ʾ�������ݡ�
// ��ֵ�����ͨ��Ӧ�÷���һ��ָ������������������á�
OperatorTest& OperatorTest::operator=(const OperatorTest& right)
{
	id = right.GetId();
	return *this;
}

// ���ڶ�Ԫ�������<<����˵�����������󴫵ݸ���һ���������Ҳ�������󴫵ݸ��ڶ�������
// cout << ot; ����cout�ʹ��ݸ�os��ot���ݸ�ot
ostream &operator<<(ostream &os, const OperatorTest &ot)
{
	os << ot.GetId();
	return os;
}

istream &operator>>(istream &in, OperatorTest& ot)
{
	int i;
	in >> i;
	// ������������봦���������ʧ�ܵ��������������������Ҫ
	if (in)
		ot.SetId(i);
	return in;
}

// ����һ�������������˵������������ĳ�Ա������������һ�������͵Ĳ���
// ֻ���Զ���������Ͳſ��������������string�Ѿ����ع��������
//ostream &operator<<(ostream &os, const string &info)
//{
//	os << " " << info;
//	return os;
//}

// ��������ز���
void TestOperator()
{
	PutPre("��������ز���");
	OperatorTest ot(3);
	cout << ot << endl;
	cout << "����һ��������";
	cin >> ot;
	cout << ot << endl;
	string s = "hi";
	cout << s << endl;
}

// ������ֵ���������
void TestCopy()
{
	PutPre("������ֵ���������");
	OperatorTest a(1);
	OperatorTest b(2);
	a = b;
	cout << a << endl;
}