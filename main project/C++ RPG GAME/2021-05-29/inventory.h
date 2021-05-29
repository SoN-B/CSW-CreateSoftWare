#pragma once
#include <iostream> 
#include <string>
#include <cstdlib>
#include <ctime>
#include "player.h"

double Money = 1300;
using namespace std;
// �κ��丮�� �� ������ "0"���� ǥ����
string DropItem;
//----------------���â
//----------------�ε������� ���� ������ ������ �ٸ�
//----------------0 : ����, 1 : ����, 2 : ����, 3 : �尩, 4 : �Ź�
string Equipment_slot[5] = { "0", "0", "0", "0", "0" };
//----------------�κ��丮
string Inventory[5] = { "0", "0", "0", "0", "0" };

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
		//----------------Kind�� �������� ������ ��Ÿ��
		//----------------0 : ����, 1 : ����, 2 : ����, 3 : �尩, 4 : �Ź�
		this->Kind = Kind;
	}
};

//----------------��� ������
//----------------����
Equipment Fabric_helmet = { "Fabric helmet", 5, 0, 0, 5, 0, 200, 0 };
Equipment Leather_helmet = { "Leather helmet", 10, 0, 0, 10, 0, 300 , 0 };
Equipment Wood_helmet = { "Wood helmet", 20, 0, 0, 20, -0.3, 500, 0 };
//----------------����
Equipment Fabric_armor = { "Fabric armor", 10, 0, 0, 10, 0, 300, 1 };
Equipment Leather_armor = { "Leather armor", 15, 0, 0, 15, 0, 400, 1 };
Equipment Wood_armor = { "Wood armor", 25, 0, 0, 25, -0.5, 600, 1 };
//----------------����
Equipment Fabric_sword = { "Fabric sword", 0, 0, 15, 0, 1, 300, 2 };
Equipment Leather_sword = { "Leather sword", 0, 0, 20, 0, 1, 400, 2 };
Equipment Wood_sword = { "Wood sword", 0, 0, 30, 0, 1, 600, 2 };
//----------------�尩
Equipment Fabric_gloves = { "Fabric gloves", 3, 0, 0, 3, 0.2, 100, 3 };
Equipment Leather_gloves = { "Leather gloves", 5, 0, 0, 5, 0.2, 250, 3 };
Equipment Wood_gloves = { "Wood gloves", 15, 0, 0, 15, 0.5, 450, 3 };
//----------------�Ź�
Equipment Fabric_shoes = { "Fabric shoes", 3, 0, 0, 3, 0.2, 100, 4 };
Equipment Leather_shoes = { "Leather shoes", 5, 0, 0, 5, 0.2, 250, 4 };
Equipment Wood_shoes = { "Wood shoes", 15, 0, 0, 15, 0.5, 450, 4 };

Equipment Equipments[15] = { Fabric_helmet, Leather_helmet, Wood_helmet, Fabric_armor,
Leather_armor, Wood_armor, Fabric_sword, Leather_sword, Wood_sword, Fabric_gloves,
Leather_gloves, Wood_gloves, Fabric_shoes, Leather_shoes, Wood_shoes };

class Gacha_Equipment {   //������ ��í������ ���� �� �ִ� ��� ������
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
		//----------------Kind�� �������� ������ ��Ÿ��
		//----------------0 : ����, 1 : ����, 2 : ����, 3 : �尩, 4 : �Ź�
		this->Kind = Kind;
	}
};

//----------------��í ���
//----------------����
Gacha_Equipment Bamboo_helmet = { "Bamboo helmet", 150, 0, 0, 50, 0, 0, 0 };
//----------------����
Gacha_Equipment Bamboo_aromr = { "Bamboo armor", 150, 0, 0, 50, 0, 0, 1 };
//----------------����
Gacha_Equipment Bamboo_spear = { "Bamboo spear", 0, 0, 100, 0, 10, 0, 2 };
//----------------�尩
Gacha_Equipment Bamboo_gloves = { "Bamboo gloves", 100, 0, 0, 50, 10, 0, 3 };
//----------------�Ź�
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
//----------------�Һ� ������
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

string Drop_Item() {
	srand((unsigned int)time(NULL));
	int I = rand() % 7;
	if (I < 5) {   //������ ��� Ȯ��
		int Temp = rand() % 4;  //��� ������ ���� ����
		if (Temp < 3) {  //�Һ� ������ ���
			int N = rand() % 14;  //14�� Items�迭 ũ��
			string Drop_Item = Items[N].Name;
			cout << "���Ϳ��Լ� " << Drop_Item << "�� ��������!!!\n";
			return Drop_Item;
		}
		else if (Temp == 3) {   //��� ������ ���
			int N = rand() % 15;  //15�� Equipments�迭 ũ��
			string Drop_Item = Equipments[N].Name;
			cout << "���Ϳ��Լ� " << Drop_Item << "�� ��������!!!\n";
			return Drop_Item;
		}
	}
	return "";
}

void Equipment_List() {  //��� ������ ����
	cout << "------------------------\n";
	cout << "��í ���\n";
	cout << "0.Bamboo helmet : Hp +150\n";
	cout << "                : Def +50\n";
	cout << "                : Kind ����\n";
	cout << "1.Bamboo aromr : Hp +150\n";
	cout << "               : Def +50\n";
	cout << "               : Kind ����\n";
	cout << "2.Bamboo spear : Atk +100\n";
	cout << "               : Speed +10\n";
	cout << "               : Kind ����\n";
	cout << "3.Bamboo gloves : Hp +100\n";
	cout << "                : Def +50\n";
	cout << "                : Speed +10\n";
	cout << "                : Kind �尩\n";
	cout << "4.Bamboo shoes : Hp +100\n";
	cout << "               : Def +50\n";
	cout << "               : Speed +10\n";
	cout << "               : Kind �Ź�\n";
	cout << "------------------------\n";
	cout << "�Ϲ� ���\n";
	cout << "0.Fabric helmet : Hp +5\n";
	cout << "                : Def +5\n";
	cout << "                : Kind ����\n";
	cout << "1.Leather helmet : Hp +10\n";
	cout << "                 : Def +10\n";
	cout << "                 : Kind ����\n";
	cout << "2.Wood helmet : Hp +20\n";
	cout << "              : Def +20\n";
	cout << "              : Speed -0.3\n";
	cout << "              : Kind ����\n";
	cout << "3.Fabric armor : Hp +10\n";
	cout << "               : Def +10\n";
	cout << "               : Kind ����\n";
	cout << "4.Leather armor : Hp +15\n";
	cout << "                : Def +15\n";
	cout << "                : Kind ����\n";
	cout << "5.Wood armor : Hp +25\n";
	cout << "             : Def +25\n";
	cout << "             : Speed -0.5\n";
	cout << "             : Kind ����\n";
	cout << "6.Fabric sword : Atk +15\n";
	cout << "               : Speed +1\n";
	cout << "               : Kind ����\n";
	cout << "7.Leather sword : Atk +20\n";
	cout << "                : Speed +1\n";
	cout << "                : Kind ����\n";
	cout << "8.Wood sword : Atk +30\n";
	cout << "             : Speed +1\n";
	cout << "             : Kind ����\n";
	cout << "9.Fabric gloves : Hp +3\n";
	cout << "                : Def +3\n";
	cout << "                : Speed +0.2\n";
	cout << "                : Kind �尩\n";
	cout << "10.Leather gloves : Hp +5\n";
	cout << "                  : Def +5\n";
	cout << "                  : Speed +0.2\n";
	cout << "                  : Kind �尩\n";
	cout << "11.Wood gloves : Hp +15\n";
	cout << "               : Def +15\n";
	cout << "               : Speed +0.5\n";
	cout << "               : Kind �尩\n";
	cout << "12.Fabric shoes : Hp +3\n";
	cout << "                : Def +3\n";
	cout << "                : Speed +0.2\n";
	cout << "                : Kind �Ź�\n";
	cout << "13.Leather shoes : Hp +5\n";
	cout << "                 : Def +5\n";
	cout << "                 : Speed +0.2\n";
	cout << "                 : Kind �Ź�\n";
	cout << "14.Wood shoes : Hp +15\n";
	cout << "              : Def +15\n";
	cout << "              : Speed +0.5\n";
	cout << "              : Kind �Ź�\n";
}

void Item_List() {   //������ ����
	cout << "0.Red potion : Hp +10\n";
	cout << "1.Yellow potion : Hp +20\n";
	cout << "2.Blue potion : Mp +10\n";
	cout << "3.Purple potion : Mp +20\n";
	cout << "4.Carrot : Atk +10\n";
	cout << "5.Protein : Atk +20\n";
	cout << "6.Radish : Def +5\n";
	cout << "7.Sugar : Def +10\n";
	cout << "8.Banana : Speed +5\n";
	cout << "9.Pear : Speed +1\n";
	cout << "10.Sweet potato : Hp +30\n";
	cout << "                : Mp -10\n";
	cout << "11.Dew : Hp -10\n";
	cout << "       : Mp +30\n";
	cout << "12.Chili : Atk +30\n";
	cout << "         : Def -10\n";
	cout << "13.Tea : Atk -10\n";
	cout << "       : Def +30\n";
}

void Pick_Up_Item(string* Inventory, string Item_Name) { //�������� �ֿ� ��
	int Count = 0;
	int N;
	char C;
	for (int I = 0; I < 5; I++) {      //�κ��丮�� ������� �ִ��� Ȯ��
		if (Inventory[I] == "0") { Count++; }
	}
	if (Count == 0) {    //�κ��丮�� ���� �� ���
		cout << "�κ��丮�� ���� á���ϴ�.\n";
		while (true) {
			cout << "�κ��丮 ���\n";
			for (int I = 0; I < 5; I++) { cout << I << " : " << Inventory[I] << "\n"; }
			cout << "������ �����۰� ��ü�ϽǰŸ� Y, �ƴϸ� N�� �Է����ּ���\n" << "�Է� : ";
			cin >> C;
			if (C == 'N') {
				cout << "�������� ���� �ʾҽ��ϴ�\n";
				break;
			}
			else if (C == 'Y') {
				cout << "��ü�� �������� ��ġ�� �Է����ּ���\n" << "�Է� : ";
				cin >> N;
				if (N >= 0 && N <= 4) {
					Inventory[N] = Item_Name;
					break;
				}
				else { cout << "�ٽ� �Է����ּ���\n"; }
			}
			else { cout << "�ٽ� �Է����ּ���\n"; }
		}
	}
	else {     //�κ��丮�� �� ������ �ִ� ���
		while (true) {
			cout << "�κ��丮 ���\n";
			for (int I = 0; I < 5; I++) { cout << I << " : " << Inventory[I] << "\n"; }
			cout << "�κ��丮�� �� �� ��ġ�� �ν� �̴ϱ�?\n" << "�Է� : ";
			cin >> N;
			if (N >= 0 && N <= 4) {
				if (Inventory[N] == "0") {
					Inventory[N] = Item_Name;
					break;
				}
				else { cout << "�����Ͻ� ��ġ���� �̹� �������� �ֽ��ϴ�. �ٸ� ��ġ�� ������ �ֽʽÿ�\n"; }
			}
			else { cout << "0~4�� ���� �� �ϳ��� �Է����ּ���\n"; }
		}
	}
}

void Look_Inventory(string Inventory[]) {    //�κ��丮 �ҷ�����
	cout << "�κ��丮 ���\n";
	for (int I = 0; I < 5; I++) { cout << I << " : " << Inventory[I] << "\n"; }
}

void Swap_Item(string* Inventory) {     //�κ��丮�� �ִ� ������ ��ġ ����
	int N1, N2;
	string Temp;
	cout << "�κ��丮 ���\n";
	for (int I = 0; I < 5; I++) { cout << I << " : " << Inventory[I] << "\n"; }

	cout << "0~4�� ������ �ٸ� ���� �Է½� ��ġ ������ ��ҵ˴ϴ�\n";
	cout << "��ġ�� ������ �������� ��ȣ�� �Է����ּ���\n" << "�Է� : ";
	cin >> N1;
	cout << "�����Ͻ� �����۰� ��ġ�� ������ �������� ��ȣ�� �Է����ּ���\n" << "�Է� : ";
	cin >> N2;
	if (N1 >= 0 && N1 <= 4) {
		if (N2 >= 0 && N2 <= 4) {
			Temp = Inventory[N1];
			Inventory[N1] = Inventory[N2];
			Inventory[N2] = Temp;
		}
	}
	else { cout << "�������� ��ġ ������ ��ҵǾ����ϴ�\n"; }
}


void Throw_Away_Item(string* Inventory) {       //�������� ���� ��
	int N;
	cout << "�κ��丮 ���\n";
	for (int I = 0; I < 5; I++) { cout << I << " : " << Inventory[I] << "\n"; }
	cout << "0~4�� ������ �ٸ� ���� �Է½� ��ġ ������ ��ҵ˴ϴ�\n";
	cout << "���� �������� ��ġ�� �Է����ּ���\n" << "�Է� : ";
	cin >> N;
	if (N >= 0 && N <= 4) { Inventory[N] = "0"; }
	else { cout << "������ �����Ⱑ ��ҵǾ����ϴ�\n"; }
}

bool Open_Store(string* inventory) {  //����
	int Num;
	string Gacha = "Gacha";
	srand((unsigned int)time(NULL));
	//----------------�Һ� ������
	int I_num1 = rand() % 14;
	int I_num2 = rand() % 14;
	//----------------��� ������
	int E_num1 = rand() % 15;
	int E_num2 = rand() % 15;
	string Item_list[5] = { Items[I_num1].Name, Items[I_num2].Name,   //�������� �̸��� ��Ƶδ� �迭
		Equipments[E_num1].Name, Equipments[E_num2].Name, Gacha };
	double Price[5] = { Items[I_num1].Price, Items[I_num2].Price,     //�������� ������ ��Ƶδ� �迭
		Equipments[E_num1].Price, Equipments[E_num2].Price, 500 };
	while (true) {
		for (int I = 0; I < 5; I++) {     //���� ������ ���
			cout << "------------------------\n";
			cout << "������ ���\n";
			cout << I << ". " << Item_list[I] << " : " << Price[I] << "��\n";
		}
		cout << "------------------------\n";
		cout << "�������� �����Ͻ÷��� 0~4�߿� ���ϴ� �������� ���ڸ� �Է����ּ���\n";
		cout << "5�� �Է��Ͻø� �Һ� �������� ������ �� �� �ֽ��ϴ�.\n";
		cout << "6�� �Է��Ͻø� ��� �������� ������ �� �� �ֽ��ϴ�.\n";
		cout << "7�� �Է��Ͻø� �κ��丮�� �������� ���� �� �ֽ��ϴ�.\n";
		cout << "8�� �Է��Ͻø� ������ ������ �� �ֽ��ϴ�.\n";
		cout << "Gacha�� ���ſ� ���ÿ� ���Ǹ� ���� �������� ȹ���� �� �ֽ��ϴ�.\n";
		cout << "���� Gacha�θ� ���� �� �ִ� �����۵� �����ϴ� �������� ���� �����غ�����.\n";
		cout << "------------------------\n";
		cout << "�Է� : ";
		cin >> Num;
		cout << endl;
		if (Num < 0 && Num > 8) { cout << "����� �� ���ڸ� �Է����ּ���\n"; }
		else if (Num >= 0 && Num < 4) {     //������ ����
			if (Money < Price[Num]) { cout << "���� �����մϴ�.\n"; }
			else {
				Pick_Up_Item(inventory, Item_list[Num]);
				Money -= Price[Num];
				cout << Item_list[Num] << "��(��) �����߽��ϴ�.\n";
				cout << "������ : " << Money + Price[Num] << " -> " << Money << endl;
				Item_list[Num] = "0";
				Price[Num] = 0;
			}
		}
		else if (Num == 4) {    //��í ����
			if (Money < Price[Num]) { cout << "���� �����մϴ�.\n"; }
			else {
				int L;
				string result;
				cout << Item_list[Num] << "��(��) �����߽��ϴ�.\n";
				int Luck = rand() % 7;
				if (Luck >= 0 && Luck < 3) {   //��í���� �Һ� ������ ����
					L = rand() % 14;
					result = Items[L].Name;
					cout << "��í���� " << result << "��(��) ���Խ��ϴ�!!!";
					Pick_Up_Item(inventory, result);
					Money -= Price[Num];
				}
				else if (Luck >= 3 && Luck < 5) {    //��í���� ��� ������ ����
					L = rand() % 15;
					result = Equipments[L].Name;
					cout << "��í���� " << result << "��(��) ���Խ��ϴ�!!!";
					Pick_Up_Item(inventory, result);
					Money -= Price[Num];
				}
				else if (Luck == 5) {    //��í���� ��í ��� ����
					L = rand() % 5;
					result = Gacha_Equipments[L].Name;
					cout << "����? ��í���� ����?\n";
					cout << "��í���� " << result << "��(��) ���Խ��ϴ�!!!";
					Pick_Up_Item(inventory, result);
					Money -= Price[Num];
				}
				else if (Luck == 6) {   //��
					cout << "����� 500��, '��~��'���� ��ü�Ǿ���... ����ȣ~\n";
				}
				cout << "������ : " << Money + Price[Num] << " -> " << Money << endl;
			}
		}
		else if (Num == 5) { Item_List(); }    //�Һ� ������ ���
		else if (Num == 6) { Equipment_List(); }    //��� ������ ���
		else if (Num == 7) { Throw_Away_Item(inventory); }    //�κ��丮�� ������ ������
		else if (Num == 8)
		{
			return false;
			break;
		}    //���� ����
	}

	return true;
}