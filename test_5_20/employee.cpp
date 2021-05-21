#define _CRT_SECURE_NO_WARNINGS 1
#include"employee.h"

employee::employee(int id, string name, int dId)
{
	this->m_Id = id;
	this->m_Name = name;
	this->m_deptId = dId;
}
 void employee::Show_Info() 
{
	 cout << "职工编号： " << this->m_Id << "\t职工姓名：" << this->m_Name << "\t岗位:"
		 << this->get_DeptName() << "\t岗位职责:完成经理交给的任务" << endl;
}
 string employee::get_DeptName()
 {
	 return string("员工");
 }
