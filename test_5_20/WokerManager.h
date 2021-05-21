#pragma once
#include<iostream>
#include<fstream>
#include<string>
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

	void Show_Emp();
		
	int get_EmpNum();

	void Init_Emp();

	void DeleteEmp();

	int IsExist(int id);

	void mod_Emp();

	void Find_Emp();

	void sort_Emp();

	void clean_Emp();

	~WorkerManager();

	bool m_FileIsEmpty;

	int m_Empnum;

	Worker** m_EmpArray;

};