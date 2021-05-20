#pragma once
#pragma once
#include <string>
#include <iostream>
using namespace std;

typedef struct Monster {
    double Hp, Mp, Atk, Def, Speed;//���� ����(Speed)
    string Ettype; //������ -> normal,elite,boss
    string Kind; //����

    Monster(string Kind, double Hp = 0, double Mp = 0, double Atk = 0,
        double Def = 0, double Speed = 1, string Ettype = "normal") //default �Ű����� �ǳ�
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
        cout << "\n���� : " << Kind << " [" << Ettype << "] " << endl;
        cout << "HP : " << Hp << endl;
        cout << "MP : " << Mp << endl;
        cout << "ATK : " << Atk << endl;
        cout << "DEF : " << Def << endl;
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
}Monster;