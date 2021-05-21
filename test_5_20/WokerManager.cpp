#define _CRT_SECURE_NO_WARNINGS 1
#include"WokerManager.h"

WorkerManager:: WorkerManager()
{
	//1.文件不存在
	ifstream ifs;
	ifs.open(FILENAME,ios::in);
	if (!ifs.is_open())
	{
		//cout << "文件不存在" << endl;
		this->m_Empnum = 0;
		this->m_EmpArray = NULL;
		this->m_FileIsEmpty = true;
		ifs.close();
		return;
	}
	//2.文件存在但数据为空
	char ch;
	ifs >> ch;
	if (ifs.eof())
	{
		//cout << "文件为空" << endl;
		this->m_Empnum = 0;
		this->m_EmpArray = NULL;
		this->m_FileIsEmpty = true;
		ifs.close();
		return;
	}
	//3.文件存在并记录着数据
	int num = this->get_EmpNum();
	//cout << "职工人数为：" <<num<< endl;
	this->m_Empnum = num;

	this->m_EmpArray = new Worker * [this->m_Empnum];

	this->Init_Emp();
	/*for (int i = 0; i < this->m_Empnum; i++)
	{
		cout << "职工编号：" << this->m_EmpArray[i]->m_Id
			<< "\t职工姓名：" << this->m_EmpArray[i]->m_Name
			<< "\t职工岗位：" << this->m_EmpArray[i]->m_deptId << endl;
	}*/

	
}

int WorkerManager::get_EmpNum()
{
	ifstream ifs;
	ifs.open(FILENAME, ios::in);

	int id;
	string name;
	int dId;

	int num = 0;

	while (ifs >> id && ifs >> name && ifs >> dId)
	{
		num++;
	}
	return num;
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
		this->m_FileIsEmpty = false;

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
		ofs << this->m_EmpArray[i]->m_Id <<"\t"<< this->m_EmpArray[i]->m_Name
			<<"\t"<<this->m_EmpArray[i]->m_deptId << endl;
	}
	ofs.close();
}

void WorkerManager::Init_Emp()
{
	ifstream ifs;
	ifs.open(FILENAME, ios::in);

	int id;
	string name;
	int dId;

	int index = 0;

	while (ifs >> id && ifs >> name && ifs >> dId)
	{
		Worker* worker=NULL;
		switch(dId)
		{
		case 1:
			worker = new employee(id, name, dId);
			break;
		case 2:
			worker = new manager(id, name, dId);
			break;
		case 3:
			worker = new boss(id, name, dId);
			break;
		}
		this->m_EmpArray[index] = worker;
		index++;
	}
	ifs.close();
}

void WorkerManager::Show_Emp()
{
	if (this->m_FileIsEmpty)
	{
		cout << "文件不存在或记录为空！" << endl;
	}
	else
	{
		for (int i = 0; i < this->m_Empnum; i++)
		{
			this->m_EmpArray[i]->Show_Info();
		}
	}
	system("pause");
	system("cls");
}

void WorkerManager::DeleteEmp()
{
	if (this->m_FileIsEmpty)
	{
		cout << "文件不存在或记录为空" << endl;
	}
	else
	{
		cout << "请输入要删除的员工编号" << endl;
		int id = 0;
		cin >> id;
		int index = this->IsExist(id);
		if (index != -1)
		{
			for (int i = index; i < this->m_Empnum-1; i++)
			{
				this->m_EmpArray[i] = this->m_EmpArray[i + 1];
			}
			this->m_Empnum--;
			cout << "删除成功" << endl;
		}
		else 
		{
			cout << "删除失败，未找到该职工" << endl;
		}
	
		
	}
	this->save();
	system("pause");
	system("cls");
}

int WorkerManager::IsExist(int id)
{
	int index = -1;
	for (int i = 0; i < this->m_Empnum; i++)
	{
		if (this->m_EmpArray[i]->m_Id == id)
		{
			index = i;
			break;
		}
	}
	return index;
}

void WorkerManager::mod_Emp()
{
	if (this->m_FileIsEmpty)
	{
		cout << "文件为空或文件不存在" << endl;
	}
	else
	{
		cout << "请输入要修改员工编号" << endl;
		int id = 0;
		cin >> id;
		int ret = this->IsExist(id);
		if (ret != -1)
		{
			delete this->m_EmpArray[ret];
			cout << "请输入新的职工编号" << endl;
			int Newid=0;
			cin >> Newid;
			cout << "请输入新的职工姓名" << endl;
			string Newname="";
			cin >> Newname;
			cout << "请输入新的职工部门编号" << endl;
			cout << "1.普通员工 2.经理 3.老板" << endl;
			int NewDId=0;
			cin >> NewDId;
			Worker* worker = NULL;
			switch (NewDId)
			{
			case 1:
				 worker = new employee(Newid,Newname,NewDId);
				break;
			case 2:
				 worker = new manager(Newid,Newname,NewDId);
				break;
			case 3:
				 worker = new boss(Newid, Newname, NewDId);
				break;
			default:
				cout << "输入错误" << endl;
				break;
			}
			
			this->m_EmpArray[ret] = worker;
			cout << "修改成功" << endl;
			this->save();
		}
		else
		{
			cout << "职工不存在" << endl;
		}


	}
	system("pause");
	system("cls");
}

void WorkerManager::Find_Emp()
{
	if (this->m_FileIsEmpty)
	{
		cout << "文件不存在或记录信息为空" << endl;
	}
	else
	{
		cout << "请输入查找方式" << endl;
		cout << "1.按职工编号查找" << endl;
		cout << "2.按职工姓名查找" << endl;

		int select = 0;
		
		cin >> select;
		if (select == 1)
		{
			int id = 0;
			cout << "请输入查找编号" << endl;
			cin >> id;
			int ret=this->IsExist(id);
			if (ret != -1)
			{
				cout << "查找成功" << endl;
				this->m_EmpArray[ret]->Show_Info();
			}
			else
			{
				cout << "查找失败，查无此人" << endl;
			}
		}
		else if(select==2)
		{
			string name = "";
			bool flag = false;
			cout << "请输入查找的姓名" << endl;
			cin >> name;
			for (int i = 0; i < this->m_Empnum; i++)
			{
				if (this->m_EmpArray[i]->m_Name == name)
				{
					cout << "查找成功" << endl;
					this->m_EmpArray[i]->Show_Info();
					flag = true;
				}
			}
			if (flag == false)
			{
				cout << "查无此人" << endl;
			}
		}
		else
		{

		}

	}
	system("pause");
	system("cls");
}

void WorkerManager::sort_Emp()
{
	if (this->m_FileIsEmpty)
	{
		cout << "文件为空或文件不存在" << endl;
		system("pause");
		system("cls");
	}
	else
	{
		cout << "请选择排序方式" << endl;
		cout << "1.按职工号升序排列" << endl;
		cout << "2.按职工号降序排列" << endl;
		int select = 0;
		cin >> select;
		for (int i = 0; i < this->m_Empnum; i++)
		{
			int MinOrMax = i;
			for (int j = 0; j < this->m_Empnum; j++)
			{
				if (select == 1)
				{
					if (this->m_EmpArray[MinOrMax]->m_Id > this->m_EmpArray[j]->m_Id)
					{
						MinOrMax = j;
					}
					
				}
				else if(select==2)
				{
					if (this->m_EmpArray[MinOrMax]->m_Id < this->m_EmpArray[j]->m_Id)
					{
						MinOrMax = j;
					}
				}
			}
			if (i != MinOrMax)
			{
				Worker* temp = this->m_EmpArray[i];
				this->m_EmpArray[i] = this->m_EmpArray[MinOrMax];
				this->m_EmpArray[MinOrMax] = temp;
			}
		
		}
		cout << "排序成功" << endl;
		this->save();
		this->Show_Emp();
	}
	
}
void WorkerManager::clean_Emp()
{
	cout << "确认清空？" << endl;
	cout << "1.确认" << endl;
	cout << "2.取消" << endl;
	int select = 0;
	cin >> select;
	if (select == 1)
	{
		ofstream ofs;
		ofs.open(FILENAME, ios::trunc);
		ofs.close();
		if (this->m_EmpArray != NULL)
		{
			for (int i = 0; i < this->m_Empnum; i++)
			{
				if (this->m_EmpArray[i] != NULL)
				{
					delete this->m_EmpArray[i];
					this->m_EmpArray[i] = NULL;
				}
			}

			delete[]this->m_EmpArray;
			this->m_EmpArray = NULL;
			this->m_Empnum = 0;
			this->m_FileIsEmpty = true;
		}
		cout << "清空成功" << endl;
	}
	system("pause");
	system("cls");

}


WorkerManager::~WorkerManager()
{
	if (this->m_EmpArray != NULL)
	{
		for (int i = 0; i < this->m_Empnum; i++)
		{
			if (this->m_EmpArray[i] != NULL)
			{
				delete this->m_EmpArray[i];
				this->m_EmpArray[i] = NULL;
			}
		}

		delete[]this->m_EmpArray;
		this->m_EmpArray = NULL;
	}
}