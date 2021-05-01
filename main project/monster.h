#pragma once
#include <string>
using namespace std;
typedef struct character {
  int hp;
  int mp;
  int atk;
  int def;
  string ettype;
  string enemykind;
  void init(string enemykind,int hp = 5000,int mp = 1250 ,int atk = 500,int def=250,string ettype = normal)
  {
    this->hp = hp;
    this-> mp = mp;
    this-> atk = atk;
    this-> def = def;
    this-> ettype = ettype;
    this-> enemykind = enemykind;
  }
};
