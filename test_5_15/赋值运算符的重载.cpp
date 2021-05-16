#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;

class Person
{
public:
	Person(int age)//普通构造函数
	{
		m_Age = new int(age);
	}
	Person& operator=(Person&p)//赋值函数重载，返回类型为引用，即返回实参的地址；
	{
		if (m_Age != NULL)//判断指针的有效性
		{
			delete m_Age;//删除浅拷贝时的m_Age
			m_Age = NULL;
		}
		m_Age = new int(*p.m_Age);//重新在堆区开辟空间，存放深拷贝的数据

		return *this;//返回变量值本身
	}
	~Person()
	{
		if (m_Age != NULL)//释放通过深拷贝开辟的空间，防止对同一片内存的重复释放
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