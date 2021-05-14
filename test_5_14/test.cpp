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
		SitingRome = "客厅";
		BedRome = "卧室";
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
		cout << "好基友正在参观" << house->SitingRome << endl;
		cout << "好基友正在参观" << house->BedRome << endl;
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