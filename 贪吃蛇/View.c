#include "Model.h"
#include <Windows.h>
#include <stdio.h>

static void SetCurPos(int X, int Y)
{
	HANDLE hStdOutput = GetStdHandle(STD_OUTPUT_HANDLE);
	// ��׼����/��׼���/��׼�������
	COORD coord = { X, Y };
	SetConsoleCursorPosition(hStdOutput, coord);
}

void DisplaySnake(const Snake *pSnake)
{
	for (Node *cur = pSnake->head; cur != NULL; cur = cur->next) {
		SetCurPos(cur->pos.x, cur->pos.y);	// ��ͳһ��������ϵ
		printf("#");
	}
}

void DisplaySnakeBlock(int x, int y)
{
	SetCurPos(x, y);	// ��ͳһ��������ϵ
	printf("#");
}
void CleanSnakeBlock(int x, int y)
{
	SetCurPos(x, y);	// ��ͳһ��������ϵ
	printf(" ");
}