#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;

class Person
{
public:
	Person(int age)
	{
		m_age = age;
	}
	bool operator==(Person&p)//����==�������ʹ��bool����������ֵ����֤���
	{
		if (m_age == p.m_age)
		{
			return true;
		}
		return false;
	}
	int m_age;
};
void test()
{
	Person p1(10);
	Person p2(10);
	if (p1 == p2)
	{
		cout << "p1=p2" << endl;
	}
	else
	{
		cout << "p1������p2" << endl;
	}
}
int main()
{
	test(); \
		system("pause");
	return 0;
}