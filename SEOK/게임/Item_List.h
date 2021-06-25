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
Equipment Fabric_helmet = { "Fabric helmet", 12.5, 5, 0, 0, 0, 200, 0 };
Equipment Leather_helmet = { "Leather helmet", 25, 10, 0, 1, 0, 300 , 0 };
Equipment Wood_helmet = { "Wood helmet", 50, 15, 0, 2, -0.3, 500, 0 };
//----------------갑옷
Equipment Fabric_armor = { "Fabric armor", 15, 0, 0, 5, 0, 350, 1 };
Equipment Leather_armor = { "Leather armor", 30, 0, 0, 10, 0, 500, 1 };
Equipment Wood_armor = { "Wood armor", 60, 0, 0, 15, -0.5, 700, 1 };
//----------------무기
Equipment Fabric_sword = { "Fabric sword", 0, 0, 5, 0, 1, 400, 2 };
Equipment Leather_sword = { "Leather sword", 0, 0, 10, 0, 1, 500, 2 };
Equipment Wood_sword = { "Wood sword", 0, 0, 15, 0, 1, 800, 2 };
//----------------장갑
Equipment Fabric_gloves = { "Fabric gloves", 10, 10, 0, 0, 0.2, 100, 3 };
Equipment Leather_gloves = { "Leather gloves", 15, 15, 0, 0, 0.2, 250, 3 };
Equipment Wood_gloves = { "Wood gloves", 30, 30, 0, 0, 0.5, 450, 3 };
//----------------신발
Equipment Fabric_shoes = { "Fabric shoes", 0, 0, 0, 0, 0.2, 100, 4 };
Equipment Leather_shoes = { "Leather shoes", 0, 0, 0, 0, 0.3, 250, 4 };
Equipment Wood_shoes = { "Wood shoes", 0, 0, 0, 0, 0.5, 450, 4 };

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

Gacha_Equipment Bamboo_helmet = { "Bamboo helmet", 80, 50, 0, 10, 0, 0, 0 };
//----------------갑옷
Gacha_Equipment Bamboo_aromr = { "Bamboo armor", 100, 70, 0, 15, 0, 0, 1 };
//----------------무기
Gacha_Equipment Bamboo_spear = { "Bamboo spear", 0, 0, 15, 0, 0.3, 0, 2 };
//----------------장갑
Gacha_Equipment Bamboo_gloves = { "Bamboo gloves", 50, 100, 0, 0, 0, 0, 3 };
//----------------신발
Gacha_Equipment Bamboo_shoes = { "Bamboo shoes", 0, 0, 0, 0, 1, 0, 4 };

Gacha_Equipment Gacha_Equipments[5] = { Bamboo_helmet, Bamboo_aromr, Bamboo_spear,
Bamboo_gloves, Bamboo_shoes };

struct Item {
	string Name;
	double Hp, Mp, Atk, Def, Speed, Price;
	int Count;
	Item(string Name, double Hp = 0, double Mp = 0, double Atk = 0,
		double Def = 0, double Speed = 0, double Price = 0, int Count = 0) {
		this->Name = Name;
		this->Hp = Hp;
		this->Mp = Mp;
		this->Atk = Atk;
		this->Def = Def;
		this->Speed = Speed;
		this->Price = Price;
		this->Count = Count;
	}
};
//----------------소비 아이템
//----------------Hp
Item Red_portion = { "Red potion", 30, 0, 0, 0, 0, 150, 0 };
Item* Red_portion_p = &Red_portion;
Item Yellow_portion = { "Yellow potion", 50, 0, 0, 0, 0, 300, 0 };
Item* Yellow_portion_p = &Yellow_portion;
//----------------Mp
Item Blue_portion = { "Blue potion", 0, 25, 0, 0, 0, 150, 0 };
Item* Blue_portion_p = &Blue_portion;
Item Purple_portion = { "Purple potion", 0, 40, 0, 0, 0, 300, 0 };
Item* Purple_portion_p = &Purple_portion;
//----------------Atk
Item Carrot = { "Carrot", 0, 0, 5, 0, 0, 600, 0 };
Item* Carrot_p = &Carrot;
Item Protein = { "Protein", 0, 0, 10, 0, 0, 900, 0 };
Item* Protein_p = &Protein;
//----------------Def
Item Radish = { "Radish", 0, 0, 0, 5, 0, 350, 0 };
Item* Radish_p = &Radish;
Item Sugar = { "Sugar", 0, 0, 0, 10, 0, 600, 0 };
Item* Sugar_p = &Sugar;
//----------------Speed
Item Banana = { "Banana", 0, 0, 0, 0, 0.1, 300, 0 };
Item* Banana_p = &Banana;
Item Pear = { "Pear", 0, 0, 0, 0, 0.2, 600, 0 };
Item* Pear_p = &Pear;
//----------------Hp,Mp
Item Sweet_potato = { "Sweet potato", 60, -30, 0, 0, 0, 300, 0 };
Item* Sweet_potato_p = &Sweet_potato;
Item Dew = { "Dew", -30, 60, 0, 0, 0, 300, 0 };
Item* Dew_p = &Dew;
//----------------Atk,Def
Item Chili = { "Chili", 0, 0, 10, -5, 0, 300, 0 };
Item* Chili_p = &Chili;
Item Tea = { "Tea", 0, 0, -7, 10, 0, 300, 0 };
Item* Tea_p = &Tea;

Item Items[14] = { Red_portion,Yellow_portion,Blue_portion,Purple_portion
,Carrot ,Protein ,Radish ,Sugar ,Banana ,Pear ,Sweet_potato,Dew,Chili,Tea };

Item* Items_p[14] = { Red_portion_p,Yellow_portion_p,Blue_portion_p,Purple_portion_p
,Carrot_p ,Protein_p ,Radish_p ,Sugar_p ,Banana_p ,Pear_p ,Sweet_potato_p,Dew_p,Chili_p,Tea_p };
