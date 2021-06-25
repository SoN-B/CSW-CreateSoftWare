#pragma once
#include <iostream>
#include <Windows.h>
#include <conio.h>
#include "pc.h"
using namespace std;
#define Order_X 64			//history의 변하지않는 X 기준선.
#define Order_Y 11			//history의 변하지 않는 Y 기준선.
int Order_x = 64;			//history의 변하는 X 기준선.
int Order_y = 11;			//history의 변하는 Y 기준선.	history의 역할을 하게 만든다.
CONSOLE_SCREEN_BUFFER_INFO CurInfo1;	//커서의 시작 좌표를 저장하기 위한 구조체
CONSOLE_SCREEN_BUFFER_INFO CurInfo2;	//커서의 끝 좌표를 저장하기 위한 구조체	일정 부분을 지우기 위한 시작,끝 좌표이다.

void Cursor_Pos_Start()	
{
	GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &CurInfo1); //커서의 좌표를 저장한다.
	//커서의 x 좌표 : CurInfo.X;		//커서의 y 좌표 : CurInfo.y;
}
void Cursor_Pos_End()
{
	GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &CurInfo2); //커서의 좌표를 저장한다.
}

void Monster_Clear()
{
	for (int i = 0; i < 8; i++)
	{
		for (int j = 60; j < 90; j=j+2)
		{
			Cursor_Move(j, i);
			cout << "ㅤ";
			//cout <<j; 
			//cout << "□";
		}
	}
}
void Player_Clear()
{
	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 58; j= j +2)
		{
			Cursor_Move(j,i);
			cout << "ㅤ";
			//cout << j;
			//cout << "□";
		}
	}
}

void Status_Reset()
{
	Monster_Clear();
	Player_Clear();
}
void History_Clear()
{
	for (int i = Order_Y; i < 32; i++)
	{
		for (int j = Order_X; j < 100; j++)
		{
			Cursor_Move(j, i);
			cout << "ㅤ";
		}
	}
}
void History_Reset()
{
	if (Order_y > 30)
	{
		History_Clear();
		Order_y = Order_Y;
	}

}
void Combat_Ui(My_Character* Character, Monster* mob = NULL) //전투 UI. 
{	
	Sleep(100);
	Status_Reset();
	COORD cur;
	cur.X = 60;
	cur.Y = 0;
	for (int i = 0; i < 10; i++)
	{
		cur.Y = i;
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), cur); // 내정보와 몬스터 창을 나누는 세로네모 선.
		cout << "■";
	}
	COORD cur2;
	cur2.X = 0;
	cur2.Y = cur.Y;
	Sleep(100);
	for (int i = 0; i < 115; i++) //정보창과 명령,history 칸을 나누는 가로 네모선.
	{
		Cursor_Move(i, cur.Y);
		cout << "■";
	}
	if (mob != NULL)
	{
		Sleep(50);
		mob->Get_Info_Right(); //몬스터의 정보창.
		Sleep(50);
	}
	Sleep(50);
	Character->Get_Character_Info_Left(); //캐릭터의 정보창.
	Sleep(50);
}
int Cursor_Pos(const char* s) //history에 한줄을 입력하기 위해, 다음 입력받는 X좌표를 계산하는 함수.
{
	string str = s;
	int c = str.size();
	return Order_X + c;
}
int Cursor_Pos(string s)
{
	string str = s;
	int c = str.size(); //Cursor_pos의 string 형.
	return Order_X + c;
}														
void Cursor_Line() //history에서 enter 부분.
{
	Cursor_Move(Order_X, Order_y);												
	Order_y++;
}
void Player_Attack_Result(double a)	//플레이어의 공격 을 나타냄.
{
	string stod = to_string(a);
	Cursor_Move(Order_X, Order_y);
	setColor(10);
	cout << "【플레이어의 공격!】";
	Order_y++;
	setColor(15);

	Cursor_Move(Order_X, Order_y);
	cout << "플레이어는";

	// Cursor_Move(Cursor_Pos("플레이어는"), Order_y);
	setColor(12);
	cout << stod;
	setColor(15);

	stod = "플레이어는" + stod;
	Cursor_Move(Cursor_Pos(stod), Order_y);
	cout << "의 피해를 입혔다!";
	Order_y+=2;
	History_Reset();
	Cursor_Move(Order_X, Order_y);
	Sleep(50);

}
void Monster_Attack_Result(Monster *Mob,double a) //monster의 공격 부분.
{
	string stod = to_string(a);
	Cursor_Move(Order_X, Order_y);
	setColor(10);
	cout << "【" << Mob->Kind << "의 공격!】" << endl;
	Order_y++;
	setColor(15);

	Cursor_Move(Order_X, Order_y);
	cout << "플레이어는";

	// Cursor_Move(Cursor_Pos("플레이어는"), Order_y);
	setColor(12);
	cout << stod;
	setColor(15);

	stod = "플레이어는" + stod;
	Cursor_Move(Cursor_Pos(stod), Order_y);
	cout << " 의 피해를 입었다!";
	Order_y+=2;
	History_Reset();
	Cursor_Move(Order_X, Order_y);
	Sleep(750);
}
void Print(const char*s) //history에 *s를 출력함. 그리고 한줄 띄움.
{
	Cursor_Move(Order_x, Order_y);
	cout << s;
	Sleep(500);
	Order_y++;
	Order_x = Order_X;
}
void Print_Line(string s) // s라는 string을 줄 띄움 하지 않고 바로 뒤에 입력하기 위한 함수.
{
	Cursor_Move(Order_x, Order_y);
	cout << s;
	Order_x += s.length();
}
void Print(string s) //print의 string 버젼.
{
	Cursor_Move(Order_x, Order_y);
	cout << s;
	Sleep(500);
	Order_y++;
	Order_x = Order_X;
}
void Print_Double(double a)	//double 자료형을 출력하기 위한 함수. 연속적인 출력을 하기 위함이다.
{ //플레이어는	55.000	의 데미지를 입혔다!
	string s = to_string(a);
	Print_Line(s);
}
void Print_blank()
{ //한줄 띄우는 함수.
	Order_y += 1;
}
void clear() ///cmd를 완전히 지워버림.
{
	system("cls");
	Order_y = Order_Y;
}
void Order_Clear()//Order칸의 일정 부분을 지우기 위한 함수.
{ //커서의 좌표를 저장한 Curinfo1,2를 이용한다.
	int a = CurInfo1.dwCursorPosition.Y;
	int b = CurInfo2.dwCursorPosition.Y;
	for (int i = a; i <= b; i++)
	{
		for (int j = 0; j < Order_X-2; j= j + 2)
		{
			Cursor_Move(j, i);
			cout << "ㅤ";
		}
	}
	Cursor_Move(0, 0);
	Cursor_Move(0, a);
}
void Order_Clear2() //Order 칸에서 많은 수를 지우기 위한 함수.
{
	for (int i = Order_Y; i < 50; i++)
	{
		for (int j = 0; j < Order_X-2; j = j + 2)
		{
			Cursor_Move(j, i);
			cout << "ㅤ";
		}
	}
	Cursor_Move(0, 0);
	Cursor_Move(0, 11);
}

void Level_Plus_Show(My_Character *a,My_Character b)
{
	Cursor_Move(30,0);
	setColor(14);
	cout << "Level UP!!!";

	Cursor_Move(30, 1);
	setColor(4);
	cout << "HP";
	setColor(15);
	cout << " : "<< a->Hp;
	setColor(14);
	cout << " -> ";
	setColor(12);
	cout << b.Hp;
	setColor(15);

	Cursor_Move(30, 2);
	setColor(1);
	cout << "MP";
	setColor(15);
	cout << " : " << a->Mp;
	setColor(14);
	cout << " -> ";
	setColor(9);
	cout << b.Mp;
	setColor(15);

	Cursor_Move(30, 3);
	setColor(15);
	cout << "ATK";
	setColor(15);
	cout << " : " << a->Atk;
	setColor(14);
	cout << " -> ";
	setColor(15);
	cout << b.Atk;

	Cursor_Move(30, 4);
	setColor(15);
	cout << "DEF" << " : " << a->Def;
	setColor(14);
	cout << " -> ";
	setColor(15);
	cout << b.Def;

	Cursor_Move(30, 5);
	setColor(15);
	cout << "SPEED" << " : " << a->Speed;
	setColor(14);
	cout << " -> ";
	setColor(15);
	cout << b.Speed;
	//스킬얻기 추가필요
}
void Player_Turn()
{
	Sleep(50);
	Cursor_Move(58, 8);
	cout << "※";        //player의 턴을 나타냄.
	Cursor_Move(62, 8);
	cout << "□";        //monster의 턴 끝남
	Sleep(50);
}
void Monster_Turn()
{
	Sleep(50);
	Cursor_Move(58, 8);
	cout << "□";        //player의 턴 끝남.
	Cursor_Move(62, 8);
	cout << "※";
	Sleep(50);
}
void Map_Show(int Roomnum,int Mapsize)
{
	Cursor_Move(30,10);
	int i = 0;
	for(i; i < Mapsize;i++)
	{
		if( i < Roomnum )
		{
			cout << "●";
		}
		else if( i == Roomnum)
		{
			cout << "◎";
			if(Roomnum == Mapsize-1)
			{
				break;
			}
		}
		else 
		{
			cout << "○";
			if (i == Mapsize-1)
			{
				break;
			}
		}
		cout << "ㅡ";
	}
}