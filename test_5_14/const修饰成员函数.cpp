#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;
#include<string>

//class Person
//{
//public:
//	void ChangePersonAge(int age)const
//	{
//		this->m_age = age;
//	}
//	Person():m_age(0),m_num(0)
//	{
//
//	}
//	mutable int m_age;
//	int m_num;
//};
//void test01()
//{
//	const Person p1;
//	p1.ChangePersonAge(10);
//	cout << "p1'age is " << p1.m_age << endl;
//}
//int main()
//{
//	test01();
//	system("pause");
//	return 0;
//}

class Building
{
	friend void GoodGay();
public:
	void ShowBuilding();
	Building();
	string SitingRome;
private:
	string BedRome;
};
void Building::ShowBuilding()
{
	cout << "这是" << this->SitingRome << endl;
	cout << "这是" << this->BedRome << endl;
}
Building::Building()
{
	SitingRome = "客厅";
	BedRome = "卧室";
}

void GoodGay()
{
	Building B;
	B.ShowBuilding();
	cout << "好基友在参观" << B.SitingRome << endl;
	cout << "好基友在参观" << B.BedRome << endl;
}
void test01()
{
	GoodGay();
}
int main()
{
	test01();
	system("pause");
	return 0;
}
