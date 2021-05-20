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