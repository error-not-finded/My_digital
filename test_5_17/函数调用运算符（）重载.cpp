#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;

//class Print
//{
//public:
//	
//	void operator()(string name)//重载（）运算符，建立一个变量，变量()就像函数一样，称仿函数
//	{
//		cout << name << endl;
//	}
//
//};
//int main()
//{
//	Print p1;
//	p1("sas");
//	
//	system("pause");
//	return 0;
//}

class MyAdd
{
public:
	int operator()(int a, int b)
	{
		return a + b;
	}
};
int main()
{
	MyAdd myadd;
	int ret = myadd(10, 10);
	cout << ret << endl;
	return 0;
}