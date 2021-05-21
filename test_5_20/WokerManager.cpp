#define _CRT_SECURE_NO_WARNINGS 1
#include"WokerManager.h"

WorkerManager:: WorkerManager()
{
	//1.�ļ�������
	ifstream ifs;
	ifs.open(FILENAME,ios::in);
	if (!ifs.is_open())
	{
		//cout << "�ļ�������" << endl;
		this->m_Empnum = 0;
		this->m_EmpArray = NULL;
		this->m_FileIsEmpty = true;
		ifs.close();
		return;
	}
	//2.�ļ����ڵ�����Ϊ��
	char ch;
	ifs >> ch;
	if (ifs.eof())
	{
		//cout << "�ļ�Ϊ��" << endl;
		this->m_Empnum = 0;
		this->m_EmpArray = NULL;
		this->m_FileIsEmpty = true;
		ifs.close();
		return;
	}
	//3.�ļ����ڲ���¼������
	int num = this->get_EmpNum();
	//cout << "ְ������Ϊ��" <<num<< endl;
	this->m_Empnum = num;

	this->m_EmpArray = new Worker * [this->m_Empnum];

	this->Init_Emp();
	/*for (int i = 0; i < this->m_Empnum; i++)
	{
		cout << "ְ����ţ�" << this->m_EmpArray[i]->m_Id
			<< "\tְ��������" << this->m_EmpArray[i]->m_Name
			<< "\tְ����λ��" << this->m_EmpArray[i]->m_deptId << endl;
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
	cout << "��ӭʹ��ְ������ϵͳ" << endl;
	cout << "***0.�˳�ְ������ϵͳ" << endl;
	cout << "***1.����ְ����Ϣ***" << endl;
	cout << "***2.��ʾְ����Ϣ***" << endl;
	cout << "***3.ɾ��ְ����Ϣ***" << endl;
	cout << "***4.�޸�ְ����Ϣ***" << endl;
	cout << "***5.����ְ����Ϣ***" << endl;
	cout << "***6.���ձ������***" << endl;
	cout << "***7.��������ĵ�***" << endl;
	cout << "********************" << endl;
	cout << endl;
}

void WorkerManager::Exit_System() 
{
	cout << "��ӭ�´�ʹ��" << endl;
	system("pause");
	exit(0);
}
void WorkerManager::Add_Emp()
{
	cout << "���������ְ������" << endl;
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
			
			cout << "�������" <<i+1<<"����ְ���ı��"<< endl;
			cin >> id;
			cout << "�������" << i + 1 << "����ְ��������" << endl;
			cin >> name;
			cout << "�������" << i + 1 << "����ְ����ְλ" << endl;
			cout << "1.��ͨԱ��" << endl;
			cout << "2.����" << endl;
			cout << "3.�ϰ�" << endl;
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
		cout << "�ɹ����"<<AddNum <<"��ְ��"<< endl;
		this->save();
		this->m_FileIsEmpty = false;

	}
	else
	{
		cout << "������������" << endl;
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
		cout << "�ļ������ڻ��¼Ϊ�գ�" << endl;
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
		cout << "�ļ������ڻ��¼Ϊ��" << endl;
	}
	else
	{
		cout << "������Ҫɾ����Ա�����" << endl;
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
			cout << "ɾ���ɹ�" << endl;
		}
		else 
		{
			cout << "ɾ��ʧ�ܣ�δ�ҵ���ְ��" << endl;
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
		cout << "�ļ�Ϊ�ջ��ļ�������" << endl;
	}
	else
	{
		cout << "������Ҫ�޸�Ա�����" << endl;
		int id = 0;
		cin >> id;
		int ret = this->IsExist(id);
		if (ret != -1)
		{
			delete this->m_EmpArray[ret];
			cout << "�������µ�ְ�����" << endl;
			int Newid=0;
			cin >> Newid;
			cout << "�������µ�ְ������" << endl;
			string Newname="";
			cin >> Newname;
			cout << "�������µ�ְ�����ű��" << endl;
			cout << "1.��ͨԱ�� 2.���� 3.�ϰ�" << endl;
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
				cout << "�������" << endl;
				break;
			}
			
			this->m_EmpArray[ret] = worker;
			cout << "�޸ĳɹ�" << endl;
			this->save();
		}
		else
		{
			cout << "ְ��������" << endl;
		}


	}
	system("pause");
	system("cls");
}

void WorkerManager::Find_Emp()
{
	if (this->m_FileIsEmpty)
	{
		cout << "�ļ������ڻ��¼��ϢΪ��" << endl;
	}
	else
	{
		cout << "��������ҷ�ʽ" << endl;
		cout << "1.��ְ����Ų���" << endl;
		cout << "2.��ְ����������" << endl;

		int select = 0;
		
		cin >> select;
		if (select == 1)
		{
			int id = 0;
			cout << "��������ұ��" << endl;
			cin >> id;
			int ret=this->IsExist(id);
			if (ret != -1)
			{
				cout << "���ҳɹ�" << endl;
				this->m_EmpArray[ret]->Show_Info();
			}
			else
			{
				cout << "����ʧ�ܣ����޴���" << endl;
			}
		}
		else if(select==2)
		{
			string name = "";
			bool flag = false;
			cout << "��������ҵ�����" << endl;
			cin >> name;
			for (int i = 0; i < this->m_Empnum; i++)
			{
				if (this->m_EmpArray[i]->m_Name == name)
				{
					cout << "���ҳɹ�" << endl;
					this->m_EmpArray[i]->Show_Info();
					flag = true;
				}
			}
			if (flag == false)
			{
				cout << "���޴���" << endl;
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
		cout << "�ļ�Ϊ�ջ��ļ�������" << endl;
		system("pause");
		system("cls");
	}
	else
	{
		cout << "��ѡ������ʽ" << endl;
		cout << "1.��ְ������������" << endl;
		cout << "2.��ְ���Ž�������" << endl;
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
		cout << "����ɹ�" << endl;
		this->save();
		this->Show_Emp();
	}
	
}
void WorkerManager::clean_Emp()
{
	cout << "ȷ����գ�" << endl;
	cout << "1.ȷ��" << endl;
	cout << "2.ȡ��" << endl;
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
		cout << "��ճɹ�" << endl;
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