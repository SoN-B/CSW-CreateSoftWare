#pragma once
#include <string>
using namespace std;
typedef struct character {
    int hp;
    int mp;
    int atk;
    int def;
    string ettype;  //�� ��ü�� Ÿ���� ��Ÿ��. �븻���̸� normal,����Ʈ ���̸� elite, �������̸� boss, �÷��̾�� player
    string kind;  //�� ��ü�� ������ ��Ÿ��.
    void init(string kind, string ettype = normal, int hp = 5000, int mp = 1250, int atk = 500, int def = 250)
    {// character ������ = {"������","normal",hp,mp,atk,def};
      //character ������_���� = {"������","boss",hp,mp,atk,def};
      //character ������_����Ʈ = {"������","elite",hp,mp,atk,def};

      //character player = {���,player,hp,mp,atk,def};
        this->hp = hp;
        this->mp = mp;
        this->atk = atk;
        this->def = def;
        this->ettype = ettype;
        this->kind = kind;
    }
    void GetInfo()
    {
        cout << "���� : " << kind << " [" << ettype << "] " << endl;
        cout << "HP : " << hp << endl;
    }
};