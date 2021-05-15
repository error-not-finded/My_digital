#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;
#include<string>
class Building;
class GoodGay
{
public:
	GoodGay();
	void Visit();
	void Visit01();
	Building* building;
};
class Building
{
	friend void GoodGay::Visit();

public:
	Building();
	string SitingRome;
private:
	string BedRome;
};
Building::Building()
{
	this->SitingRome = "客厅";
	this->BedRome = "卧室";
}

GoodGay::GoodGay()
{
	building = new Building;
}
void GoodGay::Visit()
{
	cout << "好基友visit正在参观" << building->SitingRome<< endl;
	cout << "好基友正在参观" << building->BedRome<< endl;

}
void GoodGay::Visit01()
{
	cout << "好基友visit01正在参观" << building->SitingRome<< endl;

}
void test01()
{
	GoodGay p1;
	p1.Visit();
	p1.Visit01();
}
int main()
{
	
	test01();
	system("pause");
	return 0;
}