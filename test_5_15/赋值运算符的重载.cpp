#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;

class Person
{
public:
	Person(int age)//��ͨ���캯��
	{
		m_Age = new int(age);
	}
	Person& operator=(Person&p)//��ֵ�������أ���������Ϊ���ã�������ʵ�εĵ�ַ��
	{
		if (m_Age != NULL)//�ж�ָ�����Ч��
		{
			delete m_Age;//ɾ��ǳ����ʱ��m_Age
			m_Age = NULL;
		}
		m_Age = new int(*p.m_Age);//�����ڶ������ٿռ䣬������������

		return *this;//���ر���ֵ����
	}
	~Person()
	{
		if (m_Age != NULL)//�ͷ�ͨ��������ٵĿռ䣬��ֹ��ͬһƬ�ڴ���ظ��ͷ�
		{
			delete m_Age;
			m_Age = NULL;
		}
	}
	int* m_Age;
};
void test()
{
	Person p1(10);
	Person p2(0);
	Person p3(0);
	p3=p2 = p1;
	cout << *p1.m_Age << endl;
	cout << *p2.m_Age << endl;
	cout << *p3.m_Age << endl;

}
int main()
{
	test();
	system("pause");
	return 0;
}