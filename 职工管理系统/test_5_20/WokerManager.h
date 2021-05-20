#pragma once
#include<iostream>
#include<fstream>
using namespace std;
#include"worker.h"
#include"employee.h"
#include"manager.h"
#include"boss.h"
#define FILENAME "Emplist.txt"


class WorkerManager
{
public:

	WorkerManager();

	void Show_Menu();

	void Exit_System();

	void Add_Emp();
	void save();

	~WorkerManager();

	int m_Empnum;

	Worker** m_EmpArray;
};