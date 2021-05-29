#pragma once
#pragma once
#include <string>
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

typedef struct Monster {
    double Hp, Mp, Atk, Def, Speed, Exp = 0, Max_Exp = 100;//���� ����(Speed)
    double Money = 100;
    double Level = 1;
    string Ettype; //������ -> normal,elite,boss
    string Kind; //����
    Monster(string Kind, string Ettype = "normal",double Hp = 0, double Mp = 0, double Atk = 0,
        double Def = 0, double Speed = 1, double Exp = 0, double Money = 0) //default �Ű����� �ǳ�
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
        cout << "\n���� : " << this->Kind << " [" << Ettype << "] " << endl;
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
}Monster;

void Randy()
{
    srand((unsigned int)time(NULL));
}