#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;
#include<string>

class House
{
	friend class GoodGay;

public:
	House()
	{
		SitingRome = "����";
		BedRome = "����";
	}
	string SitingRome;
private:
	string BedRome;
};
class GoodGay
{
public:
	GoodGay()
	{
		house = new House;
	}
	void visit()
	{
		cout << "�û������ڲι�" << house->SitingRome << endl;
		cout << "�û������ڲι�" << house->BedRome << endl;
	}
	House* house;
};
void test01()
{
	GoodGay p;
	p.visit();
}
int main()
{

	test01();
	system("pause");
	return 0;
}