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
	this->SitingRome = "����";
	this->BedRome = "����";
}

GoodGay::GoodGay()
{
	building = new Building;
}
void GoodGay::Visit()
{
	cout << "�û���visit���ڲι�" << building->SitingRome<< endl;
	cout << "�û������ڲι�" << building->BedRome<< endl;

}
void GoodGay::Visit01()
{
	cout << "�û���visit01���ڲι�" << building->SitingRome<< endl;

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