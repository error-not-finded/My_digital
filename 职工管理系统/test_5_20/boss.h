#pragma once
#include"worker.h"

class boss :public Worker
{
public:
	boss(int id,string name,int dId);

	virtual void Show_Info();

	virtual string get_DeptName();

};