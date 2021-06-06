#pragma once
#pragma once
#include <string>
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <conio.h>
#include <Windows.h>
using namespace std;

void setColor(unsigned short text) {
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), text);
}
void Cursor_Move(double x, double y)
{
    COORD cur;
    cur.X = x;
    cur.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), cur);
}

typedef struct Monster {
    double Hp, Mp, Atk, Def, Speed, Exp = 0, Max_Exp = 100;//선공 선별(Speed)
    double Money = 100;
    double Level = 1;
    string Ettype; //몹종류 -> normal,elite,boss
    string Kind; //종족
    Monster(string Kind, string Ettype = "normal",double Hp = 0, double Mp = 0, double Atk = 0,
        double Def = 0, double Speed = 1, double Exp = 0, double Money = 0) //default 매개변수 맨끝
    {
        //ex) Monster Slime_Normal = { "slime",100,20,10,5,1,"normal" };

        this->Kind = Kind;
        this->Ettype = Ettype;
        this->Hp = Hp;
        this->Mp = Mp;
        this->Atk = Atk;
        this->Def = Def;
        this->Speed = Speed;
        this->Exp = Exp;
        this->Money = Money;
    }
    void Get_Info()
    {
        setColor(8);
        cout << "\n종족 ";
        setColor(15);
        cout <<": " << this->Kind << " [" << Ettype << "] " << endl;

        setColor(4);
        cout << "HP "; 
        setColor(15);
        cout << ": " << this->Hp << endl;

        setColor(9);
        cout << "MP "; 
        setColor(15);
        cout << ": " << this->Mp << endl;

        cout << "ATK : " << this->Atk << endl;
        cout << "DEF : " << this->Def << endl;
        cout << "SPEED : " << this->Speed << endl;
        cout << "------------------------\n";
    }
    void Hp_Plus(double a)
    {
        this->Hp += a;
    }
    void Mp_Plus(double a)
    {
        this->Mp += a;
    }
    void Atk_Plus(double a)
    {
        this->Atk += a;
    }
    void Def_Plus(double a)
    {
        this->Def += a;
    }
    void Speed_Plus(double a)
    {
        this->Speed += a;
    }
    void Get_Info_Right();
}Monster;
void Monster::Get_Info_Right()
{
    COORD cur;
    int i = 0;
    Cursor_Move(62, i);
    setColor(8);
    cout << "종족 ";
    setColor(15);
    cout << ": " << this->Kind << " [" << Ettype << "] ";

    i = i + 1;

    Cursor_Move(62, i);
    setColor(4);
    cout << "HP ";
    setColor(15);
    cout << ": " << this->Hp;

    i = i + 1;

    Cursor_Move(62, i);
    setColor(9);
    cout << "MP ";
    setColor(15);
    cout << ": " << this->Mp;

    i = i + 1;

    Cursor_Move(62, i);
    cout << "ATK : " << this->Atk;

    i = i + 1;

    Cursor_Move(62, i);
    cout << "DEF : " << this->Def << endl;

    i = i + 1;

    Cursor_Move(62, i);
    cout << "SPEED : " << this->Speed << endl;
}
void Randy()
{
    srand((unsigned int)time(NULL));
}
