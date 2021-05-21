#pragma once
#include"worker.h"

class employee:public Worker
{
public:
	virtual void Show_Info();
	
	virtual string get_DeptName();
	
	employee(int id,string name,int dId);
};