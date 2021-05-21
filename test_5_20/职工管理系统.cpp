#include<iostream>
using namespace std;
#include"WokerManager.h"
#include"manager.h"
#include"employee.h"
#include"boss.h"



int main()
{
	WorkerManager wm;
	int choice;
	while (true)
	{
		wm.Show_Menu();
		cout << "ÇëÊäÈëÄãµÄÑ¡Ôñ" << endl;
		cin >> choice;
		switch (choice)
		{
		case 0:wm.Exit_System();
			break;
		case 1:wm.Add_Emp();
			break;
		case 2:wm.Show_Emp();
			break;
		case 3:
			wm.DeleteEmp();
			break;
		case 4:
			wm.mod_Emp();
			break;
		case 5:wm.Find_Emp();
			break;
		case 6:
			wm.sort_Emp();
			break;
		case 7:
			wm.clean_Emp();
			break;
		default:
			system("cls");
			break;
		}
	}


	system("pause");
	return 0;
}