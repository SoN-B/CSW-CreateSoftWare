#pragma once
#include <string>
#include <iostream> //+
using namespace std;

struct mob {
    int hp, mp, atk, def;
    string ettype; //몹종류 -> normal,elite,boss
    string kind; //종족

    mob(string kind, int hp, int mp, int atk, int def, string ettype = "normal") //default 매개변수 맨끝
    {
        //ex) mob Slime_Normal = { "slime",100,20,10,5,"normal" };

        this->kind = kind;
        this->hp = hp;
        this->mp = mp;
        this->atk = atk;
        this->def = def;
        this->ettype = ettype;
    }

    void GetInfo()
    {
        cout << "종족 : " << kind << " [" << ettype << "] " << endl;
        cout << "HP : " << hp << endl;
    }
};

