#define _CRT_SECURE_NO_WARNINGS 1
#include"manager.h"

manager::manager(int id, string name, int dId)
{
	this->m_Id = id;
	this->m_Name = name;
	this->m_deptId = dId;
}
void manager::Show_Info()
{
	cout << "ְ����ţ� " << this->m_Id << "\tְ��������" << this->m_Name << "\t��λ:"
		<< this->get_DeptName() << "\t��λְ��:����ϰ彻�������񣬸�Ա����������" << endl;
}
string manager::get_DeptName()
{
	return string("����");
}
