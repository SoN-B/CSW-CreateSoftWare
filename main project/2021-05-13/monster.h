#pragma once
#include <string>
#include <iostream> //+
using namespace std;

typedef struct Monster {
    double Hp, Mp, Atk, Def, Speed;//선공 선별(speed)
    string Ettype; //몹종류 -> normal,elite,boss
    string Kind; //종족

    Monster(string Kind, double Hp = 0, double Mp = 0, double Atk = 0,
        double Def = 0, double Speed = 1, string Ettype = "normal") //default 매개변수 맨끝
    {
        //ex) mob Slime_Normal = { "slime",100,20,10,5,"normal" };

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
        cout << "종족 : " << Kind << " [" << Ettype << "] " << endl;
        cout << "HP : " << Hp << endl;
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
        this->def += a;
    }
}mob;
