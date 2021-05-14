#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;

class Person
{
public:
	void ShowPerson()
	{
		cout << "this is Person" << endl;
	}
	void ChangeAge(int age)
	{
		if (this == NULL)
		{
			return;
		}
		m_age = age;
		cout << "age is " << this->m_age << endl;

	}
	Person():m_age(0)
	{

	}
	int m_age;
	int hietgh;
};
void test01()
{
	Person* p = NULL;
	p->ShowPerson();
	p->ChangeAge(10);
	//cout << "age is " << p->m_age << endl;
}
int main()
{
	test01();

	system("pause");
	return 0;
}