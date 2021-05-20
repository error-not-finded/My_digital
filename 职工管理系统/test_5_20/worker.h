#pragma once
#include<iostream>
#include<string>
using namespace std;


class Worker
{
public:
	virtual void Show_Info()=0;

	virtual string get_DeptName() = 0;

	int m_Id;
	string m_Name;
	int m_deptId;
};