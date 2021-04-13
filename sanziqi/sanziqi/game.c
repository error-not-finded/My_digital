#define _CRT_SECURE_NO_WARNINGS 1
#include"game.h"

void InitBoard(int board[ROW][COL], int row, int col)
{
	int i = 0;
	int j = 0;
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < COL; j++)
		{
			board[i][j] = " ";

		}
	}
}
void Dispalyboard(char board[ROW][COL], int row, int col)
{

}