#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;

class Base
{
public:
	Base()
	{
		cout << "Base�๹�캯���ĵ���" << endl;
	}
	int a;
protected:
	int b;
private:
	int c;
};
class Son1 :public Base
{
public:
	Son1()
	{
		cout << "Son1�๹�캯���ĵ���" << endl;
	}
	int d;
};
class Son2 :protected Base
{
public:
	Son2()
	{
		cout << "Son2�๹�캯���ĵ���" << endl;
	}

	int e;
};
class Son3 :private Base
{
public:
	Son3()
	{
		cout << "Son3�๹�캯���ĵ���" << endl;
	}

	int f;
};
void test()
{
	Son1 a;
	Son2 b;
	Son3 c;
	cout << a.a << endl;

}
int main()
{
	test();
	system("pause");
	return 0;
}