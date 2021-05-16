#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;

class MyInteger
{
	friend ostream& operator<<(ostream&cout, MyInteger myint);//这里的myint参数不能使用引用，否则后置++的输出类型错误
public:
	MyInteger()
	{
		this->m_num = 0;
	}
	MyInteger& operator++()//前置++，返回this的引用
	{
		this->m_num++;
		return *this;
	}
	MyInteger operator++(int)//后置++，返回局部变量temp的值，如果返回类型为引用，则退出函数后，引用的指针变为野指针，造成错误
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
ostream& operator<<(ostream& cout, MyInteger myint)//对左移运算符的重载
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