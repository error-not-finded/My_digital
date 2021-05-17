#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;

class Base
{
public:
	static int a;//类内声明，类外初始化，必须要做的操作
	static void func()
	{
		cout << "父类的静态成员函数" << endl;
	}
};
int Base::a = 10;//类外初始化
class Son :public Base
{
public:
	static int a;
	static void func()
	{
		cout << "子类的静态成员函数" << endl;
	}
};
int Son::a = 20;
void test()
{
	Son s1;
	cout << s1.a << endl;//直接访问，默认访问子类的静态成员
	cout << s1.Base::a << endl;//加父类作用域访问父类同名静态成员
	cout << Son::a << endl;//两种访问方式，一种通过变量，另一种通过作用域直接访问
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