#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;

class Person
{
	friend ostream& operator<<(ostream& cout, Person& p);//全局函数作友元

public:
	Person():m_A(10),m_B(10)
	{
		
	}
private:
	int m_A;
	int m_B;
};
ostream& operator<<(ostream&cout,Person& p)//重载<<运算符，cout的类型为osstream，且只有一份，只能引用。
{
	cout << "p.m_A=" << p.m_A << " p.m_B=" << p.m_B ;
	return cout;//链式编程思想，返回本地址

}
void test1()
{
	Person p1;
	//p1.m_A = 10;
	//p1.m_B = 10;
	cout << p1<<endl;
}
int main()
{
	test1();
	system("pause");
	return 0;
}
