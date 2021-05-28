#pragma once
#pragma once
#include <string>
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

typedef struct Monster {
    double Hp, Mp, Atk, Def, Speed, Exp = 0, Max_Exp = 100;//선공 선별(Speed)
    double Money = 100;
    double Level = 1;
    string Ettype; //몹종류 -> normal,elite,boss
    string Kind; //종족
    Monster(string Kind, double Hp = 0, double Mp = 0, double Atk = 0,
        double Def = 0, double Speed = 1, double Exp = 1, double Money = 10, string Ettype = "normal") //default 매개변수 맨끝
    {
        //ex) Monster Slime_Normal = { "slime",100,20,10,5,1,"normal" };

        this->Kind = Kind;
        this->Hp = Hp;
        this->Mp = Mp;
        this->Atk = Atk;
        this->Def = Def;
        this->Speed = Speed;
        this->Ettype = Ettype;
        this->Exp = Exp + rand() % 6 - 2.5;
        this->Money = Money + rand() % 6 - 2.5;
    }
    void Get_Info()
    {
        cout << "\n종족 : " << this->Kind << " [" << Ettype << "] " << endl;
        cout << "HP : " << this->Hp << endl;
        cout << "MP : " << this->Mp << endl;
        cout << "ATK : " << this->Atk << endl;
        cout << "DEF : " << this->Def << endl;
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
    void Money_Plus(double a)
    {
        this->Money += a;
    }
}Monster;
void Randy()
{
    srand((unsigned int)time(NULL));
}