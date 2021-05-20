#pragma once
#include <iostream> 
#include <string>
#include <cstdlib>
#include <ctime>
#include "player.h"
using namespace std;
// �κ��丮�� �� ������ "0"���� ǥ����
string DropItem;

//typedef struct My_Character;
struct Item {
	string Name;
	double Hp, Mp, Atk, Def, Speed;
	Item(string Name, double Hp = 0, double Mp = 0, double Atk = 0,
		double Def = 0, double Speed = 0) {
		this->Name = Name;
		this->Hp = Hp;
		this->Mp = Mp;
		this->Atk = Atk;
		this->Def = Def;
		this->Speed = Speed;
	}
};

//----------------Hp
Item Red_portion = { "Red potion",10 };
Item Yellow_portion = { "Yellow potion",20 };
//----------------Mp
Item Blue_portion = { "Blue potion",0,10 };
Item Purple_portion = { "Purple potion",0,20 };
//----------------Atk
Item Carrot = { "Carrot",0,0,10 };
Item Protein = { "Protein",0,0,20 };
//----------------Def
Item Radish = { "Radish",0,0,0,5 };
Item Sugar = { "Sugar",0,0,0,10 };
//----------------Speed
Item Banana = { "Banana",0,0,0,0,0.5 };
Item Pear = { "Pear",0,0,0,0,1 };
//----------------Hp,Mp
Item Sweet_potato = { "Sweet potato",30,-10,0,0,0 };
Item Dew = { "Dew",-10,30,0,0,0 };
//----------------Atk,Def
Item Chili = { "Chili",0,0,30,-10,0 };
Item Tea = { "Tea",0,0,-10,30,0 };

Item Items[14] = { Red_portion,Yellow_portion,Blue_portion,Purple_portion
,Carrot ,Protein ,Radish ,Sugar ,Banana ,Pear ,Sweet_potato,Dew,Chili,Tea };
string Inventory[5] = { "Red potion","Red potion","Purple potion","Purple potion","0" };

string Drop_Item() {
	srand((unsigned int)time(NULL));
	int I = rand() % 7;
	if (I < 5) {   //������ ��� Ȯ��
		int N = rand() % 14;  //14�� Items�迭 ũ��
		string Drop_Item = Items[N].Name;
		cout << "\n------------���Ϳ��Լ� " << Drop_Item << "��(��) ��������!!!------------\n";
		return Drop_Item;
	}
	return "";
}

void Item_List() {   //������ ����
	cout << "------------------------\n";
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
		if (Inventory[I] == "0") Count++;
	}
	if (Count == 0) {    //�κ��丮�� ���� �� ���
		cout << "�κ��丮�� ���� á���ϴ�.\n\n";
		while (true) {
			cout << "�κ��丮 ���\n";
			for (int I = 0; I < 5; I++) { cout << I << " : " << Inventory[I] << "\n"; }
			cout << "\n������ �����۰� ��ü�ϽǰŸ� Y, �ƴϸ� N�� �Է����ּ���\n" << "�Է� : ";
			cin >> C;
			if (C == 'N') {
				cout << "�������� ���� �ʾҽ��ϴ�\n";
				break;
			}
			else if (C == 'Y') {
				cout << "\n��ü�� �������� ��ġ�� �Է����ּ���\n" << "�Է� : ";
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
				else { cout << "�����Ͻ� ��ġ���� �̹� �������� �ֽ��ϴ�. �ٸ� ��ġ�� ������ �ֽʽÿ�\n\n"; }
			}
			else { cout << "0~4�� ���� �� �ϳ��� �Է����ּ���\n"; }
		}
	}
}

void Look_Inventory(string Inventory[]) {    //�κ��丮 �ҷ�����
	cout << "\n�κ��丮 ���\n";
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