#pragma once
#pragma once
#include <string>
#include <iostream>
using namespace std;

typedef struct Monster {
    double Hp, Mp, Atk, Def, Speed, Exp = 0, Max_Exp = 100;//선공 선별(Speed)
    double Money = 100;
    double Level = 1;
    string Ettype; //몹종류 -> normal,elite,boss
    string Kind; //종족

    Monster(string Kind, double Hp = 0, double Mp = 0, double Atk = 0,
        double Def = 0, double Speed = 1, string Ettype = "normal") //default 매개변수 맨끝
    {
        //ex) Monster Slime_Normal = { "slime",100,20,10,5,1,"normal" };

        this->Kind = Kind;
        this->Hp = Hp;
        this->Mp = Mp;
        this->Atk = Atk;
        this->Def = Def;
        this->Speed = Speed;
        this->Ettype = Ettype;
    }

    void Get_Info()
    {
        cout << "\n종족 : " << this->Kind << " [" << Ettype << "] " << endl;
        cout << "Level : " << this->Level << endl;
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
    void Level_Up()
    {
        this->Level += 1;
        this->Max_Exp = this->Max_Exp + (this->Max_Exp * 0.5);
        this->Hp += 50;
        this->Mp += 25;
        this->Atk += 10;
        this->Def += 5;
        this->Speed += 0.1;
        this->Exp = 0;
    }
    void Exp_Edit(double a)
    {
        this->Exp += a;
    }
}Monster;