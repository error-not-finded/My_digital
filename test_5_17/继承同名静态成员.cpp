#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;

class Base
{
public:
	static int a;//���������������ʼ��������Ҫ���Ĳ���
	static void func()
	{
		cout << "����ľ�̬��Ա����" << endl;
	}
};
int Base::a = 10;//�����ʼ��
class Son :public Base
{
public:
	static int a;
	static void func()
	{
		cout << "����ľ�̬��Ա����" << endl;
	}
};
int Son::a = 20;
void test()
{
	Son s1;
	cout << s1.a << endl;//ֱ�ӷ��ʣ�Ĭ�Ϸ�������ľ�̬��Ա
	cout << s1.Base::a << endl;//�Ӹ�����������ʸ���ͬ����̬��Ա
	cout << Son::a << endl;//���ַ��ʷ�ʽ��һ��ͨ����������һ��ͨ��������ֱ�ӷ���
	cout << Son::Base::a << endl;
	s1.func;
	s1.Base::func;
	Son::func;
	Son::Base::func;
}
int main()
{
	test();
	return 0;
}