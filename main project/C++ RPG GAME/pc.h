#pragma once
#include <iostream>
#include <conio.h>
#include <Windows.h>
#include "monster.h"
using namespace std;

typedef struct My_Character //플레이어 클래스
{
	double Hp, Mp, Atk, Def, Speed, Level = 1, Exp = 0, Max_Exp = 100, Money = 0;

	My_Character(double Hp = 200, double Mp = 100, double Atk = 20, double Def = 0,
		double Speed = 1, double Money = 1000)
	{
		this->Hp = Hp;
		this->Mp = Mp;
		this->Atk = Atk;
		this->Def = Def;
		this->Speed = Speed;
		this->Money = Money;
	}

	void Get_Character_Info()//플레이어 상태 출력 
	{
		setColor(8);
		cout << "\nLevel";
		setColor(15);
		cout << ": " << Level;

		setColor(6);
		cout << "\nMax Exp/Exp";
		setColor(15);
		cout << ": " << Max_Exp << "/" << Exp;

		setColor(4);
		cout << "\nHP";
		setColor(15);
		cout << ": " << Hp;

		setColor(9);
		cout << "\nMP";
		setColor(15);

		cout << " : " << Mp << "\nATK : " << Atk << "\nDEF : " << Def << "\nSPPED : " << Speed;

		setColor(14);
		cout << "\nMoney";
		setColor(15);

		cout << " : " << Money << " Coin" << endl;
	}

	void Level_Plus()
	{
		this->Level += 1;
		this->Exp = this->Exp - this->Max_Exp;
		this->Max_Exp = this->Max_Exp + (this->Max_Exp * 0.5);
		this->Hp += 20;
		this->Mp += 15;
		this->Atk += 10;
		this->Def += 5;
		this->Speed += 0.1;
	}

	void Exp_Plus(double a)
	{
		this->Exp += a - rand() % 50;
	}
	void Pick_UP_Money(double a)
	{
		this->Money += a - rand() % 50;
	}
	void Restat()
	{
		this->Hp = 200;
		this->Mp = 100;
		this->Atk = 50;
		this->Def = 5;
		this->Speed = 1.5;
		this->Level = 1;
		this->Exp = 0;
		this->Max_Exp = 100;
		this->Money = 0;
	}
	void Get_Character_Info_Left();
}My_Character;
My_Character SoNB;
My_Character * SoNB_P = &SoNB;
