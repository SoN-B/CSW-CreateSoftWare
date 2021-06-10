#pragma once
#include <iostream>
#include <Windows.h>
#include <conio.h>
#include "pc.h"
#define Order_X 64			//history�� �������ʴ� X ���ؼ�.
#define Order_Y 11			//history�� ������ �ʴ� Y ���ؼ�.
int Order_x = 64;			//history�� ���ϴ� X ���ؼ�.
int Order_y = 11;			//history�� ���ϴ� Y ���ؼ�.	history�� ������ �ϰ� �����.
CONSOLE_SCREEN_BUFFER_INFO CurInfo1;	//Ŀ���� ���� ��ǥ�� �����ϱ� ���� ����ü
CONSOLE_SCREEN_BUFFER_INFO CurInfo2;	//Ŀ���� �� ��ǥ�� �����ϱ� ���� ����ü	���� �κ��� ����� ���� ����,�� ��ǥ�̴�.
void Cursor_Pos_Start()	
{
	GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &CurInfo1); //Ŀ���� ��ǥ�� �����Ѵ�.
	//Ŀ���� x ��ǥ : CurInfo.X;		//Ŀ���� y ��ǥ : CurInfo.y;
}
void Cursor_Pos_End()
{
	GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &CurInfo2); //Ŀ���� ��ǥ�� �����Ѵ�.
}
void Combat_Ui(My_Character* Character, Monster* mob = NULL) //���� UI. 
{																						
	COORD cur;
	cur.X = 60;
	cur.Y = 0;
	for (int i = 0; i < 10; i++)
	{
		cur.Y = i;
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), cur); // �������� ���� â�� ������ ���γ׸� ��.
		cout << "��";
	}
	COORD cur2;
	cur2.X = 0;
	cur2.Y = cur.Y;
	for (int i = 0; i < 60; i++) //����â�� ���,history ĭ�� ������ ���� �׸�.
	{
		Cursor_Move(i, cur.Y);
		cout << "��";
	}
	if (mob != NULL)
	{
		mob->Get_Info_Right(); //������ ����â.
	}
	Character->Get_Character_Info_Left(); //ĳ������ ����â.
}
int Cursor_Pos(const char* s) //history�� ������ �Է��ϱ� ����, ���� �Է¹޴� X��ǥ�� ����ϴ� �Լ�.
{
	string str = s;
	int c = str.size();
	return Order_X + c;
}
int Cursor_Pos(string s)
{
	string str = s;
	int c = str.size(); //Cursor_pos�� string ��.
	return Order_X + c;
}														
void Cursor_Line() //history���� enter �κ�.
{
	Cursor_Move(Order_X, Order_y);												
	Order_y++;
}
void Player_Attack_Result(double a)	//�÷��̾��� ���� �� ��Ÿ��.
{
	string stod = to_string(a);
	Cursor_Move(Order_X, Order_y);
	setColor(10);
	cout << "���÷��̾��� ����!��";
	Order_y++;
	setColor(15);

	Cursor_Move(Order_X, Order_y);
	cout << "�÷��̾��";

	// Cursor_Move(Cursor_Pos("�÷��̾��"), Order_y);
	setColor(12);
	cout << stod;
	setColor(15);

	stod = "�÷��̾��" + stod;
	Cursor_Move(Cursor_Pos(stod), Order_y);
	cout << "�� ���ظ� ������!";
	Order_y+=2;
	Cursor_Move(Order_X, Order_y);
	Sleep(750);
}
void Monster_Attack_Result(Monster *Mob,double a) //monster�� ���� �κ�.
{
	string stod = to_string(a);
	Cursor_Move(Order_X, Order_y);
	setColor(10);
	cout << "��" << Mob->Kind << " �� ����!��" << endl;
	Order_y++;
	setColor(15);

	Cursor_Move(Order_X, Order_y);
	cout << "�÷��̾��";

	// Cursor_Move(Cursor_Pos("�÷��̾��"), Order_y);
	setColor(12);
	cout << stod;
	setColor(15);

	stod = "�÷��̾��" + stod;
	Cursor_Move(Cursor_Pos(stod), Order_y);
	cout << " �� ���ظ� �Ծ���!";
	Order_y+=2;
	Cursor_Move(Order_X, Order_y);
	Sleep(750);
}
void Print(const char*s) //history�� *s�� �����. �׸��� ���� ���.
{
	Cursor_Move(Order_x, Order_y);
	cout << s;
	Sleep(500);
	Order_y++;
	Order_x = Order_X;
}
void Print_Line(string s) // s��� string�� �� ��� ���� �ʰ� �ٷ� �ڿ� �Է��ϱ� ���� �Լ�.
{
	Cursor_Move(Order_x, Order_y);
	cout << s;
	Order_x += s.length();
}
void Print(string s) //print�� string ����.
{
	Cursor_Move(Order_x, Order_y);
	cout << s;
	Sleep(500);
	Order_y++;
	Order_x = Order_X;
}
void Print_Double(double a)	//double �ڷ����� ����ϱ� ���� �Լ�. �������� ����� �ϱ� �����̴�.
{ //�÷��̾��	55.000	�� �������� ������!
	string s = to_string(a);
	Print_Line(s);
}
void Print_blank()
{ //���� ���� �Լ�.
	Order_y += 1;
}
void clear() ///cmd�� ������ ��������.
{
	system("cls");
	Order_y = Order_Y;
}
void Order_Clear()//Orderĭ�� ���� �κ��� ����� ���� �Լ�.
{ //Ŀ���� ��ǥ�� ������ Curinfo1,2�� �̿��Ѵ�.
	int a = CurInfo1.dwCursorPosition.Y;
	int b = CurInfo2.dwCursorPosition.Y;
	for (int i = a; i <= b; i++)
	{
		for (int j = 0; j < Order_X-2; j= j + 2)
		{
			Cursor_Move(j, i);
			cout << "��";
		}
	}
	Cursor_Move(0, 0);
	Cursor_Move(0, a);
}
void Order_Clear2() //Order ĭ���� ���� ���� ����� ���� �Լ�.
{
	for (int i = Order_Y; i < 50; i++)
	{
		for (int j = 0; j < Order_X-2; j = j + 2)
		{
			Cursor_Move(j, i);
			cout << "��";
		}
	}
	Cursor_Move(0, 0);
	Cursor_Move(0, 11);
}