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
	 cout << "ְ����ţ� " << this->m_Id << "\tְ��������" << this->m_Name << "\t��λ:"
		 << this->get_DeptName() << "\t��λְ��:��ɾ�����������" << endl;
}
 string employee::get_DeptName()
 {
	 return string("Ա��");
 }
