#pragma once
#include <string>
#include <iostream> //+
using namespace std;

typedef struct mob {
    float hp, mp, atk, def, speed;//선공 선별(speed)
    string ettype; //몹종류 -> normal,elite,boss
    string kind; //종족

    mob(string kind, float hp = 0, float mp = 0, float atk = 0,
        float def = 0, float speed = 1, string ettype = "normal") //default 매개변수 맨끝
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
        cout << "종족 : " << kind << " [" << ettype << "] " << endl;
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
