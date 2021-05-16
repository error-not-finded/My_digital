#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;

class MyInteger
{
	friend ostream& operator<<(ostream&cout, MyInteger myint);//�����myint��������ʹ�����ã��������++��������ʹ���
public:
	MyInteger()
	{
		this->m_num = 0;
	}
	MyInteger& operator++()//ǰ��++������this������
	{
		this->m_num++;
		return *this;
	}
	MyInteger operator++(int)//����++�����ؾֲ�����temp��ֵ�������������Ϊ���ã����˳����������õ�ָ���ΪҰָ�룬��ɴ���
	{
		MyInteger temp = *this;
		m_num++;
		return temp;
	}
	MyInteger& operator--()
	{
		this->m_num--;
		return*this;
	}
	MyInteger operator--(int)
	{
		MyInteger temp = *this;
		this->m_num--;
		return temp;
	}
private:
	int m_num;
};
ostream& operator<<(ostream& cout, MyInteger myint)//�����������������
{
	cout<< myint.m_num;
	return cout;
}
void test()
{

	MyInteger myint;
	cout << ++myint << endl;
	cout << --myint << endl;

	cout << myint++ << endl;
	cout << myint-- << endl;

}
int main()
{
	test();
	system("pause");
	return 0;
}