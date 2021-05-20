#define _CRT_SECURE_NO_WARNINGS 1
#include"WokerManager.h"

WorkerManager:: WorkerManager()
{
	this->m_Empnum = 0;
	this->m_EmpArray = NULL;
}

void WorkerManager::Show_Menu()
{
	cout << "********************" << endl;
	cout << "欢迎使用职工管理系统" << endl;
	cout << "***0.退出职工管理系统" << endl;
	cout << "***1.增加职工信息***" << endl;
	cout << "***2.显示职工信息***" << endl;
	cout << "***3.删除职工信息***" << endl;
	cout << "***4.修改职工信息***" << endl;
	cout << "***5.查找职工信息***" << endl;
	cout << "***6.按照编号排序***" << endl;
	cout << "***7.清空所有文档***" << endl;
	cout << "********************" << endl;
	cout << endl;
}

void WorkerManager::Exit_System() 
{
	cout << "欢迎下次使用" << endl;
	system("pause");
	exit(0);
}
void WorkerManager::Add_Emp()
{
	cout << "请输入添加职工数量" << endl;
	int AddNum = 0;
	cin >> AddNum;
	if (AddNum > 0)
	{
		int newSize = this->m_Empnum + AddNum;
		Worker**newSpace=new Worker* [newSize];
		if (this->m_EmpArray != NULL)
		{
			for (int i = 0; i < this->m_Empnum; i++)
			{
				newSpace[i] = this->m_EmpArray[i];
			}
		}
		for (int i = 0; i < AddNum; i++)
		{
			int id;
			string name;
			int dselect;
			
			cout << "请输入第" <<i+1<<"个新职工的编号"<< endl;
			cin >> id;
			cout << "请输入第" << i + 1 << "个新职工的姓名" << endl;
			cin >> name;
			cout << "请输入第" << i + 1 << "个新职工的职位" << endl;
			cout << "1.普通员工" << endl;
			cout << "2.经理" << endl;
			cout << "3.老板" << endl;
			cin >> dselect;
			Worker* worker = NULL;
			switch (dselect)
			{
			case 1:
				worker = new employee(id,name,dselect);
				break;
			case 2:
				worker = new manager(id, name, dselect);
				break;
			case 3:
				worker = new boss(id, name, dselect);
				break;
			}
			newSpace[this->m_Empnum + i] = worker;
		}
		delete[]this->m_EmpArray;
		this->m_EmpArray = newSpace;
		this->m_Empnum = newSize;
		cout << "成功添加"<<AddNum <<"个职工"<< endl;
		this->save();
	}
	else
	{
		cout << "输入数据有误" << endl;
	}
	system("pause");
	system("cls");
}

void WorkerManager::save()
{
	ofstream ofs;
	ofs.open(FILENAME, ios::out);
	for (int i = 0; i < this->m_Empnum; i++)
	{
		ofs << this->m_EmpArray[i]->m_Id << this->m_EmpArray[i]->m_Name
			<< this->m_EmpArray[i]->m_deptId << endl;
	}
	ofs.close();
}

WorkerManager::~WorkerManager()
{
	if (this->m_EmpArray != NULL)
	{
		delete[]this->m_EmpArray;
		this->m_EmpArray = NULL;
	}
}