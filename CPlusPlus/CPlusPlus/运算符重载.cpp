#include "stdafx.h"

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
