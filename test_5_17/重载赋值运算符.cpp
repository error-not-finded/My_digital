#define _CRT_SECURE_NO_WARNINGS 
#include<iostream>
using namespace std;
//重载=运算符实现p1=p2；p1中含有堆区内存，必须使用深拷贝构造函数
class Person
{
public:
	Person(int age)
	{
		m_Age = new int(age);//堆区开辟空间存放m_Age
	}
	~Person()
	{
		if (m_Age != NULL)//析构函数，释放堆区内存，并把指针置为空
		{
			delete m_Age;
			m_Age = NULL;
		}
	}
	Person& operator=(Person&p)//重载=运算符，参数为p1的引用
	{
		if (this->m_Age != NULL)//堆区释放浅拷贝生成的指针
		{
			delete m_Age;
		}
		m_Age =new int(*p.m_Age);//堆区开辟新的内存，存放数据，避免浅拷贝多次释放同一片内存
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