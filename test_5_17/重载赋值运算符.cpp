#define _CRT_SECURE_NO_WARNINGS 
#include<iostream>
using namespace std;
//����=�����ʵ��p1=p2��p1�к��ж����ڴ棬����ʹ��������캯��
class Person
{
public:
	Person(int age)
	{
		m_Age = new int(age);//�������ٿռ���m_Age
	}
	~Person()
	{
		if (m_Age != NULL)//�����������ͷŶ����ڴ棬����ָ����Ϊ��
		{
			delete m_Age;
			m_Age = NULL;
		}
	}
	Person& operator=(Person&p)//����=�����������Ϊp1������
	{
		if (this->m_Age != NULL)//�����ͷ�ǳ�������ɵ�ָ��
		{
			delete m_Age;
		}
		m_Age =new int(*p.m_Age);//���������µ��ڴ棬������ݣ�����ǳ��������ͷ�ͬһƬ�ڴ�
		return *this;
	}
	int*m_Age;
};
void test()
{
	Person p1(10);
	Person p2(0);
	p2 = p1;
	cout << *p2.m_Age << endl;
}
int main()
{
	test();
	system("pause");
	return 0;
}