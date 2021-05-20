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
		case 2:
			break;
		case 3:
			break;
		case 4:
			break;
		case 5:
			break;
		case 6:
			break;
		case 7:
			break;
		default:
			system("cls");
			break;
		}
	}


	system("pause");
	return 0;
}