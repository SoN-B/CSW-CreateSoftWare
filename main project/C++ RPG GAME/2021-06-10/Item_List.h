#include <iostream> 
#include <string>
#include <cstdlib>
#include <ctime>
#include <conio.h>
#include <Windows.h>
using namespace std;
string DropItem;
//----------------장비창
//----------------인덱스마다 장착 가능한 종류가 다름
//----------------0 : 투구, 1 : 갑옷, 2 : 무기, 3 : 장갑, 4 : 신발
string Equipment_slot[5] = { "0", "0", "0", "0", "0" };
//----------------인벤토리
string Inventory[5] = { "0", "0", "0", "0", "0" };
// 장비 : 장비이름,HP증가량,MP증가량,ATK증가량,DEF증가량,Speed증가량,Price증가량,종류
class Equipment {
public:
	string Name;
	double Hp, Mp, Atk, Def, Speed, Price;
	int Kind;
	Equipment(string Name, double Hp = 0, double Mp = 0, double Atk = 0,
		double Def = 0, double Speed = 0, double Price = 0, int Kind = 0) {
		this->Name = Name;
		this->Hp = Hp;
		this->Mp = Mp;
		this->Atk = Atk;
		this->Def = Def;
		this->Speed = Speed;
		this->Price = Price;
		//----------------Kind는 아이템의 종류를 나타냄
		//----------------0 : 투구, 1 : 갑옷, 2 : 무기, 3 : 장갑, 4 : 신발
		this->Kind = Kind;
	}
};

//----------------장비 아이템
//----------------투구
Equipment Fabric_helmet = { "Fabric helmet", 5, 0, 0, 5, 0, 200, 0 };
Equipment Leather_helmet = { "Leather helmet", 10, 0, 0, 10, 0, 300 , 0 };
Equipment Wood_helmet = { "Wood helmet", 20, 0, 0, 20, -0.3, 500, 0 };
//----------------갑옷
Equipment Fabric_armor = { "Fabric armor", 10, 0, 0, 10, 0, 300, 1 };
Equipment Leather_armor = { "Leather armor", 15, 0, 0, 15, 0, 400, 1 };
Equipment Wood_armor = { "Wood armor", 25, 0, 0, 25, -0.5, 600, 1 };
//----------------무기
Equipment Fabric_sword = { "Fabric sword", 0, 0, 15, 0, 1, 300, 2 };
Equipment Leather_sword = { "Leather sword", 0, 0, 20, 0, 1, 400, 2 };
Equipment Wood_sword = { "Wood sword", 0, 0, 30, 0, 1, 600, 2 };
//----------------장갑
Equipment Fabric_gloves = { "Fabric gloves", 3, 0, 0, 3, 0.2, 100, 3 };
Equipment Leather_gloves = { "Leather gloves", 5, 0, 0, 5, 0.2, 250, 3 };
Equipment Wood_gloves = { "Wood gloves", 15, 0, 0, 15, 0.5, 450, 3 };
//----------------신발
Equipment Fabric_shoes = { "Fabric shoes", 3, 0, 0, 3, 0.2, 100, 4 };
Equipment Leather_shoes = { "Leather shoes", 5, 0, 0, 5, 0.2, 250, 4 };
Equipment Wood_shoes = { "Wood shoes", 15, 0, 0, 15, 0.5, 450, 4 };

Equipment Equipments[15] = { Fabric_helmet, Leather_helmet, Wood_helmet, Fabric_armor,
Leather_armor, Wood_armor, Fabric_sword, Leather_sword, Wood_sword, Fabric_gloves,
Leather_gloves, Wood_gloves, Fabric_shoes, Leather_shoes, Wood_shoes };
#pragma once


class Gacha_Equipment {   //상점의 가챠에서만 뽑을 수 있는 희귀 아이템
public:
	string Name;
	double Hp, Mp, Atk, Def, Speed, Price;
	int Kind;
	Gacha_Equipment(string Name, double Hp = 0, double Mp = 0, double Atk = 0,
		double Def = 0, double Speed = 0, double Price = 0, int Kind = 0) {
		this->Name = Name;
		this->Hp = Hp;
		this->Mp = Mp;
		this->Atk = Atk;
		this->Def = Def;
		this->Speed = Speed;
		this->Price = Price;
		//----------------Kind는 아이템의 종류를 나타냄
		//----------------0 : 투구, 1 : 갑옷, 2 : 무기, 3 : 장갑, 4 : 신발
		this->Kind = Kind;
	}
};

Gacha_Equipment Bamboo_helmet = { "Bamboo helmet", 150, 0, 0, 50, 0, 0, 0 };
//----------------갑옷
Gacha_Equipment Bamboo_aromr = { "Bamboo armor", 150, 0, 0, 50, 0, 0, 1 };
//----------------무기
Gacha_Equipment Bamboo_spear = { "Bamboo spear", 0, 0, 100, 0, 10, 0, 2 };
//----------------장갑
Gacha_Equipment Bamboo_gloves = { "Bamboo gloves", 100, 0, 0, 50, 10, 0, 3 };
//----------------신발
Gacha_Equipment Bamboo_shoes = { "Bamboo shoes", 100, 0, 0, 50, 10, 0, 4 };

Gacha_Equipment Gacha_Equipments[5] = { Bamboo_helmet, Bamboo_aromr, Bamboo_spear,
Bamboo_gloves, Bamboo_shoes };

struct Item {
	string Name;
	double Hp, Mp, Atk, Def, Speed, Price;
	Item(string Name, double Hp = 0, double Mp = 0, double Atk = 0,
		double Def = 0, double Speed = 0, double Price = 0) {
		this->Name = Name;
		this->Hp = Hp;
		this->Mp = Mp;
		this->Atk = Atk;
		this->Def = Def;
		this->Speed = Speed;
		this->Price = Price;
	}
};
//----------------소비 아이템
//----------------Hp
Item Red_portion = { "Red potion", 10, 0, 0, 0, 0, 100 };
Item Yellow_portion = { "Yellow potion", 20, 0, 0, 0, 0, 200 };
//----------------Mp
Item Blue_portion = { "Blue potion", 0, 10, 0, 0, 0, 100 };
Item Purple_portion = { "Purple potion", 0, 20, 0, 0, 0, 200 };
//----------------Atk
Item Carrot = { "Carrot", 0, 0, 10, 0, 0, 100 };
Item Protein = { "Protein", 0, 0, 20, 0, 0, 200 };
//----------------Def
Item Radish = { "Radish", 0, 0, 0, 5, 0, 100 };
Item Sugar = { "Sugar", 0, 0, 0, 10, 0, 200 };
//----------------Speed
Item Banana = { "Banana", 0, 0, 0, 0, 0.5, 100 };
Item Pear = { "Pear", 0, 0, 0, 0, 1, 200 };
//----------------Hp,Mp
Item Sweet_potato = { "Sweet potato", 30, -10, 0, 0, 0, 200 };
Item Dew = { "Dew", -10, 30, 0, 0, 0, 200 };
//----------------Atk,Def
Item Chili = { "Chili", 0, 0, 30, -10, 0, 200 };
Item Tea = { "Tea", 0, 0, -10, 30, 0, 200 };

Item Items[14] = { Red_portion,Yellow_portion,Blue_portion,Purple_portion
,Carrot ,Protein ,Radish ,Sugar ,Banana ,Pear ,Sweet_potato,Dew,Chili,Tea };
