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
		cout << "父类test()的调用" << endl;
	}
	void test(int a)
	{
		cout << "父类test(int a)的调用" << endl;
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
		cout << "子类test()的调用" << endl;
	}
	int a;
};
void test01()
{
	Son s;
	cout << s.a << endl;//不加父类的作用域，默认同名成员为子类成员
	cout << s.Base::a << endl;//加父类作用域，调用父类成员
	s.test();//直接访问为子类成员
	s.Base::test();//访问父类同名成员函数要加父类作用域
	s.Base::test(10);//重构的同名函数也会被子类同名函数隐藏，必须加作用域
}
int main()
{
	test01();
	return 0;
}