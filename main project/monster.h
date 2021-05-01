#pragma once
#include <string>
using namespace std;
typedef struct character {
  int hp;
  int mp;
  int atk;
  int def;
  string ettype;
  void init(int hp,int mp,int atk,int def,string ettype)
  {
    this->hp = hp;
    this-> mp = mp;
    this-> atk = atk;
    this-> def = def;
    this-> ettype = ettype;
  }
};
