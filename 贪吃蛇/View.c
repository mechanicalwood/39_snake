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

void ViewInit(int width, int height)
{
	HANDLE hStdOutput = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO info;
	GetConsoleCursorInfo(hStdOutput, &info);
	info.bVisible = 0;
	SetConsoleCursorInfo(hStdOutput, &info);
}

void DisplayWall(int width, int height)
{
	// 上边的墙
	SetCurPos(0, 0);
	for (int i = 0; i < width + 2; i++) {
		printf("█");
	}

	// 下边的
	SetCurPos(0, height + 1);
	for (int i = 0; i < width + 2; i++) {
		printf("█");
	}

	// 左边的
	for (int i = 0; i < height + 2; i++) {
		SetCurPos(0, i);
		printf("█");
	}

	// 右边的
	for (int i = 0; i < height + 2; i++) {
		SetCurPos(2 * (1 + width), i);
		printf("█");
	}
}

void DisplaySnake(const Snake *pSnake)
{
	for (Node *cur = pSnake->head; cur != NULL; cur = cur->next) {
		SetCurPos(2 * (cur->pos.x + 1), cur->pos.y + 1);
		printf("█");
	}
}

void DisplaySnakeBlock(int x, int y)
{
	SetCurPos(2 * (x + 1), y + 1);
	printf("█");
}

void DisplayFood(int x, int y)
{
	SetCurPos(2 * (x + 1), y + 1);
	printf("█");
}

void CleanSnakeBlock(int x, int y)
{
	SetCurPos(2 * (x + 1), y + 1);
	printf("  ");
}

void DisplayScore(int score)
{
	SetCurPos(30 * 2 + 10, 10);
	printf("得分: %d", score);
}