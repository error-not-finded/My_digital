#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;
#include"boss.h"

boss::boss(int id, string name, int dId)
{
	this->m_Id = id;
	this->m_Name = name;
	this->m_deptId = dId;
}
void boss::Show_Info()
{
	cout << "职工编号： " << this->m_Id << "\t职工姓名：" << this->m_Name << "\t岗位:"
		<< this->get_DeptName() << "\t岗位职责:管理公司所有事物" << endl;
}
 string boss::get_DeptName()
{
	return string("老板");
}

