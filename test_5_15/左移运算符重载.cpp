#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;

class Person
{
	friend ostream& operator<<(ostream& cout, Person& p);//ȫ�ֺ�������Ԫ

public:
	Person():m_A(10),m_B(10)
	{
		
	}
private:
	int m_A;
	int m_B;
};
ostream& operator<<(ostream&cout,Person& p)//����<<�������cout������Ϊosstream����ֻ��һ�ݣ�ֻ�����á�
{
	cout << "p.m_A=" << p.m_A << " p.m_B=" << p.m_B ;
	return cout;//��ʽ���˼�룬���ر���ַ

}
void test1()
{
	Person p1;
	//p1.m_A = 10;
	//p1.m_B = 10;
	cout << p1<<endl;
}
int main()
{
	test1();
	system("pause");
	return 0;
}
