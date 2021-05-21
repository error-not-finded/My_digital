#pragma once
#include"worker.h"

class manager :public Worker
{
public:
	virtual void Show_Info();

	virtual string get_DeptName();

	manager(int id, string name, int dId);
};