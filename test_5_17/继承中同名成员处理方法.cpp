#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;

class Base
{
public:
	Base() :a(10)
	{

	}
	void test()
	{
		cout << "����test()�ĵ���" << endl;
	}
	void test(int a)
	{
		cout << "����test(int a)�ĵ���" << endl;
	}
	int a;
};
class Son :public Base
{
public:
	Son() :a(20)
	{

	}
	void test()
	{
		cout << "����test()�ĵ���" << endl;
	}
	int a;
};
void test01()
{
	Son s;
	cout << s.a << endl;//���Ӹ����������Ĭ��ͬ����ԱΪ�����Ա
	cout << s.Base::a << endl;//�Ӹ��������򣬵��ø����Ա
	s.test();//ֱ�ӷ���Ϊ�����Ա
	s.Base::test();//���ʸ���ͬ����Ա����Ҫ�Ӹ���������
	s.Base::test(10);//�ع���ͬ������Ҳ�ᱻ����ͬ���������أ������������
}
int main()
{
	test01();
	return 0;
}