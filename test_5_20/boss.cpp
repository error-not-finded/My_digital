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
	cout << "ְ����ţ� " << this->m_Id << "\tְ��������" << this->m_Name << "\t��λ:"
		<< this->get_DeptName() << "\t��λְ��:����˾��������" << endl;
}
 string boss::get_DeptName()
{
	return string("�ϰ�");
}

