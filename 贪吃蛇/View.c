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

void DisplayWall(int width, int height)
{
	// �ϱߵ�ǽ
	SetCurPos(0, 0);
	for (int i = 0; i < width + 2; i++) {
		printf("#");
	}

	// �±ߵ�
	SetCurPos(0, height + 1);
	for (int i = 0; i < width + 2; i++) {
		printf("#");
	}

	// ��ߵ�
	for (int i = 0; i < height + 2; i++) {
		SetCurPos(0, i);
		printf("#");
	}

	// �ұߵ�
	for (int i = 0; i < height + 2; i++) {
		SetCurPos(1 + width, i);
		printf("#");
	}
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