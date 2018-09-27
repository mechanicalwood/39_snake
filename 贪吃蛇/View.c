#include "Model.h"
#include <Windows.h>
#include <stdio.h>

static void SetCurPos(int X, int Y)
{
	HANDLE hStdOutput = GetStdHandle(STD_OUTPUT_HANDLE);
	// 标准输入/标准输出/标准错误输出
	COORD coord = { X, Y };
	SetConsoleCursorPosition(hStdOutput, coord);
}

void DisplayWall(int width, int height)
{
	// 上边的墙
	SetCurPos(0, 0);
	for (int i = 0; i < width + 2; i++) {
		printf("#");
	}

	// 下边的
	SetCurPos(0, height + 1);
	for (int i = 0; i < width + 2; i++) {
		printf("#");
	}

	// 左边的
	for (int i = 0; i < height + 2; i++) {
		SetCurPos(0, i);
		printf("#");
	}

	// 右边的
	for (int i = 0; i < height + 2; i++) {
		SetCurPos(1 + width, i);
		printf("#");
	}
}

void DisplaySnake(const Snake *pSnake)
{
	for (Node *cur = pSnake->head; cur != NULL; cur = cur->next) {
		SetCurPos(cur->pos.x, cur->pos.y);	// 先统一两个坐标系
		printf("#");
	}
}

void DisplaySnakeBlock(int x, int y)
{
	SetCurPos(x, y);	// 先统一两个坐标系
	printf("#");
}
void CleanSnakeBlock(int x, int y)
{
	SetCurPos(x, y);	// 先统一两个坐标系
	printf(" ");
}