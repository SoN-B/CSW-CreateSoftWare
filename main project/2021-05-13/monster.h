#pragma once
#include <string>
#include <iostream> //+
using namespace std;

typedef struct mob {
    double hp, mp, atk, def, speed;//���� ����(speed)
    string ettype; //������ -> normal,elite,boss
    string kind; //����

    mob(string kind, double hp = 0, double mp = 0, double atk = 0,
        double def = 0, double speed = 1, string ettype = "normal") //default �Ű����� �ǳ�
    {
        //ex) mob Slime_Normal = { "slime",100,20,10,5,"normal" };

        this->kind = kind;
        this->hp = hp;
        this->mp = mp;
        this->atk = atk;
        this->def = def;
        this->speed = speed;
        this->ettype = ettype;
    }

    void GetInfo()
    {
        cout << "���� : " << kind << " [" << ettype << "] " << endl;
        cout << "HP : " << hp << endl;
    }
    void hp_plus(double a)
    {
        this->hp += a;
    }
    void mp_plus(double a)
    {
        this->mp += a;
    }
    void atk_plus(double a)
    {
        this->atk += a;
    }
    void def_plus(double a)
    {
        this->def += a;
    }
}mob;