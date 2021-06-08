#pragma once
#include <iostream>
#include <Windows.h>
#include <conio.h>
#include "pc.h"
#define Order_X 40
#define Order_Y 11
int Order_x = 40;
int Order_y = 11;
CONSOLE_SCREEN_BUFFER_INFO CurInfo1;
CONSOLE_SCREEN_BUFFER_INFO CurInfo2;
void Cursor_Pos_Start()
{
	GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &CurInfo1);
	//커서의 x 좌표 : CurInfo.X;		//커서의 y 좌표 : CurInfo.y;
}
void Cursor_Pos_End()
{
	GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &CurInfo2);
}
void Combat_Ui(My_Character* Character, Monster* mob = NULL)
{
	COORD cur;
	cur.X = 60;
	cur.Y = 0;
	for (int i = 0; i < 10; i++)
	{
		cur.Y = i;
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), cur);
		cout << "■";
	}
	COORD cur2;
	cur2.X = 0;
	cur2.Y = cur.Y;
	for (int i = 0; i < 60; i++)
	{
		Cursor_Move(i, cur.Y);
		cout << "■";
	}
	if (mob != NULL)
	{
		mob->Get_Info_Right();
	}
	Character->Get_Character_Info_Left();
}
int Cursor_Pos(const char* s)
{
	string str = s;
	int c = str.size();
	return Order_X + c;
}
int Cursor_Pos(string s)
{
	string str = s;
	int c = str.size();
	return Order_X + c;
}
void Player_Attack_Result(double a)
{
	string stod = to_string(a);
	Cursor_Move(Order_X, Order_y);
	setColor(10);
	cout << "【플레이어의 공격!】";
	Order_y++;
	setColor(15);

	Cursor_Move(Order_X, Order_y);
	cout << "플레이어는 ";

	Cursor_Move(Cursor_Pos("플레이어는 "), Order_y);
	setColor(12);
	cout << a;
	setColor(15);

	stod = "플레이어는" + stod;
	Cursor_Move(Cursor_Pos(stod), Order_y);
	cout << " 의 피해를 입혔다!";
	Order_y++;
}
void Monster_Attack_Result(Monster *Mob,double a)
{
	string stod = to_string(a);
	Cursor_Move(Order_X, Order_y);
	setColor(10);
	cout << "【" << Mob->Kind << " 의 공격!】" << endl;
	Order_y++;
	setColor(15);

	Cursor_Move(Order_X, Order_y);
	cout << "플레이어는 ";

	Cursor_Move(Cursor_Pos("플레이어는 "), Order_y);
	setColor(12);
	cout << a;
	setColor(15);

	stod = "플레이어는" + stod;
	Cursor_Move(Cursor_Pos(stod), Order_y);
	cout << " 의 피해를 입었다!\n" << endl;
	Order_y++;
}
void Print(const char*s)
{
	Cursor_Move(Order_x, Order_y);
	cout << s;
	Order_y++;
	Order_x = Order_X;
}
void Print_Line(string s)
{
	Cursor_Move(Order_x, Order_y);
	cout << s;
	Order_x += s.length();
}
void clear()
{
	system("cls");
	Order_y = Order_Y;
}

void Order_Clear()
{
	for (int i = Order_Y; i < 30; i++)
	{
		for (int j = 0; j < Order_X - 2; j++)
		{
			Cursor_Move(j, i);
			cout << "ㅤ";
		}
	}
	Cursor_Move(0, 11);
}