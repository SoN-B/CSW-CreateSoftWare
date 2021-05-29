#pragma once
#include <iostream>
#include "monster.h"
#include "inventory.h"
using namespace std;

typedef struct My_Character //�÷��̾� Ŭ����
{
	double Hp, Mp, Atk, Def, Speed, Level = 1, Exp = 0, Max_Exp = 100, Money = 0;

	My_Character(double Hp = 200, double Mp = 100, double Atk = 50, double Def = 5, double Speed = 1.5)
	{
		this->Hp = Hp;
		this->Mp = Mp;
		this->Atk = Atk;
		this->Def = Def;
		this->Speed = Speed;

	}

	void Get_Character_Info()//�÷��̾� ���� ��� 
	{
		cout << "\Level : " << Level << "\nMax Exp/Exp : "<< Max_Exp << "/" << Exp
			<< "\nHP : " << Hp << "\nMP: " << Mp << "\nATK: " << Atk << "\nDEF: " << Def 
			<<"\nMoney : " << Money << " Coin"<< endl;
		cout << "------------------------\n";
	}

	void Level_Plus()
	{
		this->Level += 1;
		this->Exp = this->Exp - this->Max_Exp;
		this->Max_Exp = this->Max_Exp + (this->Max_Exp * 0.5);
		this->Hp += 50;
		this->Mp += 25;
		this->Atk += 10;
		this->Def += 5;
		this->Speed += 0.1;
	}

	void Exp_Plus(double a)
	{
		this->Exp += a - rand() % 50;
	}
	void Pick_UP_Money(double a)
	{
		this->Money += a - rand() % 50;
	}
}My_Character;
My_Character SoNB;
My_Character* SoNB_P = &SoNB;

void Mob_Atk(Monster* Mob, My_Character* Character)
{
	double Damage = Mob->Atk - Character->Def;
	if (Damage < 0) Damage = 0;
	//�� ���ݷ�<�÷��̾� ���� ��� ���� ������ ��Ȳ ����

	Character->Hp -= Damage;
	cout << "��" << Mob->Kind << " �� ����!��" << endl;
	cout << "�÷��̾�� " << Damage << " �� ���ظ� �Ծ���!\n" << endl;
}

bool Skill_Menu(My_Character* Character, Monster* Mob, bool Atkflag);
bool Inventory_Menu();
void Atk_Menu(My_Character* Character, Monster* Mob)//�÷��̾��� �޴�
{
	int Choice; //�÷��̾� ���� ����
	bool Atkflag = true; //Atk_Menu �Լ� ����� ����
	double Damage; //�÷��̾��� ���� ������
	while (Atkflag)
	{
		cout << "������ �ұ�...\n1. ����\n2. ��ų\n3. ����\n4. ������\n5. �� ����\n6. ����" << endl; //�⺻ �޴�
		cin >> Choice;
		switch (Choice)
		{
		case 1: //�⺻����
			cout << "\n������ ������ ���մϴ�!!\n\n";
			Damage = Character->Atk - Mob->Def; //�÷��̾� ������ ��� (�÷��̾�Atk - ����def)
			if (Damage < 0) Damage = 0; //���ܻ���: ������ ������ ��� 0���� ���
			Mob->Hp -= Damage; //���� ������ ���
			cout << "���÷��̾��� ����!��" << endl;
			cout << "�÷��̾�� " << Damage << " �� ���ظ� ������!\n" << endl;
			Atkflag = false;
			break;
		case 2: //��ų���
			Atkflag = Skill_Menu(Character, Mob, Atkflag);
			break;
		case 3: //���濭��
			Atkflag = Inventory_Menu();
			break;
		case 4: //ĳ���� ���º���
			Character->Get_Character_Info();
			break;
		case 5: //���� ���º���
			Mob->Get_Info();
			break;
		case 6: //�̱���
			//����
			cout << "\n�������� ������ ���� ������ ����˴ϴ�...";
			exit(0);
			break;
		default: //�߸��� ���� �Է¹�����
			cout << "�ùٸ��� ���� �Է�" << endl;
			break;
		}
	}
}

bool Skill_Menu(My_Character* Character, Monster* Mob, bool Atkflag)
{
	int Skillmenu;//��ų ����
	string Skillcheck;//��ų ��� Ȯ��
	bool Skillflag = true;// Skill_Menu �Լ� ����� ����
	double Damage; // �÷��̾��� ���� ��ų ������
	while (Skillflag)
	{
		cout << "------------------------\n" << "SKILL MENU" << endl;
		cout << "1. �Ŀ� ������\n2. ������ DEATH\n0. �ڷΰ���" << endl;// ��ų �޴�
		cin >> Skillmenu;
		switch (Skillmenu)
		{
		case 1: //�Ŀ� ������ 
			cout << "\n���ݷ�: " << Character->Atk * 1.2 << "\nMP: 100\n����ұ�? (Y or else)" << endl;
			cin >> Skillcheck; //��ų��� ����Ȯ��
			if (Skillcheck == "Y") //��ų���
			{
				Character->Mp -= 20; //Mp �Ҹ�
				Damage = (Character->Atk * 1.5) - Mob->Def; //�÷��̾� ������ ��� (�÷��̾�Atk - ����def)
				if (Damage < 0) Damage = 0; //���ܻ���: ������ ������ ��� 0���� ���
				Mob->Hp -= Damage; //���� ������ ���
				cout << "\n��Po������weR!!��" << endl;
				cout << "�÷��̾�� " << Damage << " �� ���ظ� ������!\n" << endl;
				Skillflag = false; //Skill_Menu �Լ� ����
				return false; //Atkflag=false : Atk_Menu �Լ� ���� return
			}
			break;
		case 2: //������ ����
			cout << "\n���ݷ�: " << Character->Atk * 3 << " (def����)" << "\n-HP: 50%\n����ұ�? (Y or else)" << endl;
			cin >> Skillcheck;
			if (Skillcheck == "Y") //��ų��� ����Ȯ��
			{
				Character->Hp = Character->Hp / 2; //Hp�Ҹ�
				Damage = (Character->Atk * 3); //�÷��̾� ������ ��� (�÷��̾�Atk - ����def)
				if (Damage < 0) Damage = 0; //���ܻ���: ������ ������ ��� 0���� ���
				Mob->Hp -= Damage; //���� ������ ���
				cout << "\n��JJUGEM�� ����!!!��" << endl;
				cout << "�÷��̾�� " << Damage << " �� ���ظ� ������!\n" << endl;
				Skillflag = false; //Skill_Menu �Լ� ����
				return false; //Atkflag=false : Atk_Menu �Լ� ���� return
			}
			break;
		case 0: //�ڷΰ���
			cout << "------------------------\n";
			Skillflag = false; //Skill_Menu �Լ� ����
			return true; //Atkflag=ture : Atk_Menu �Լ� �̾���
			break;
		}
	}
}

void Use_Item(My_Character* Character, string* Inventory, string* Equipment_slot) {
	// �������� ����� ��
	int n;

	cout << "\n�κ��丮 ���\n";
	for (int i = 0; i < 5; i++) { cout << i << " : " << Inventory[i] << "\n"; }
	cout << "\n0~4�� ������ �ٸ� ���� �Է½� ������ ����� ��ҵ˴ϴ�\n";
	cout << "����� �������� ��ġ�� �Է����ּ���\n" << "��ġ : ";
	cin >> n;
	if (n >= 0 && n <= 4) {
		if (Inventory[n] == "0") { cout << "\n�����Ͻ� ��ġ�� �������� �����ϴ�\n\n"; }
		else {
			for (int i = 0; i < 14; i++) {   //14�� items �迭 ũ��
				if (Inventory[n] == Items[i].Name) {  //�Һ������ ���
					Character->Hp += Items[i].Hp;
					Character->Mp += Items[i].Mp;
					Character->Atk += Items[i].Atk;
					Character->Def += Items[i].Def;
					Character->Speed += Items[i].Speed;
					Inventory[n] = "0";
					cout << "\n" << Items[i].Name << "�� ����߽��ϴ�\n";
					cout << "hp : " << Character->Hp - Items[i].Hp << " -> " << Character->Hp << "\n";
					cout << "mp : " << Character->Mp - Items[i].Mp << " -> " << Character->Mp << "\n";
					cout << "atk : " << Character->Atk - Items[i].Atk << " -> " << Character->Atk << "\n";
					cout << "def : " << Character->Def - Items[i].Def << " -> " << Character->Def << "\n";
					cout << "speed : " << Character->Speed - Items[i].Speed << " -> " << Character->Speed << "\n\n";
					break;
				}
			}
			for (int i = 0; i < 15; i++) {   //15�� Equipments �迭 ũ��
				if (Inventory[n] == "0") { break; }//���� for������ �������� ����ߴٸ� �� for���� ������ ����
				if (Inventory[n] == Equipments[i].Name) {
					int Num = Equipments[i].Kind;
					if (Equipment_slot[Num] != "0") {//���â Ȯ��
						cout << "�����Ͻ� ���� ���� ������ ��� �̹� �����ϰ� �ֽ��ϴ�.\n";
						cout << "�������� ��� �����ϰ� �ٽ� �õ����ּ���\n";
						break;
					}
					else {    //��� ������ ����
						Equipment_slot[Num] == Gacha_Equipments[i].Name;
						Character->Hp += Equipments[i].Hp;
						Character->Mp += Equipments[i].Mp;
						Character->Atk += Equipments[i].Atk;
						Character->Def += Equipments[i].Def;
						Character->Speed += Equipments[i].Speed;
						Inventory[n] = "0";
						cout << "\n" << Equipments[i].Name << "�� �����߽��ϴ�\n";
						cout << "hp : " << Character->Hp - Equipments[i].Hp << " -> " << Character->Hp << "\n";
						cout << "mp : " << Character->Mp - Equipments[i].Mp << " -> " << Character->Mp << "\n";
						cout << "atk : " << Character->Atk - Equipments[i].Atk << " -> " << Character->Atk << "\n";
						cout << "def : " << Character->Def - Equipments[i].Def << " -> " << Character->Def << "\n";
						cout << "speed : " << Character->Speed - Equipments[i].Speed << " -> " << Character->Speed << "\n\n";
						break;
					}
				}
			}
			for (int i = 0; i < 5; i++) {   //5�� Gacha_Equipments �迭 ũ��
				if (Inventory[n] == "0") { break; }//���� for������ �������� ����ߴٸ� �� for���� ������ ����
				if (Inventory[n] == Gacha_Equipments[i].Name) {
					int Num = Gacha_Equipments[i].Kind;
					if (Equipment_slot[Num] != "0") {//���â Ȯ��
						cout << "�����Ͻ� ���� ���� ������ ��� �̹� �����ϰ� �ֽ��ϴ�.\n";
						cout << "�������� ��� �����ϰ� �ٽ� �õ����ּ���\n";
						break;
					}
					else {    //��í ��� ����
						Equipment_slot[Num] == Gacha_Equipments[i].Name;
						Character->Hp += Gacha_Equipments[i].Hp;
						Character->Mp += Gacha_Equipments[i].Mp;
						Character->Atk += Gacha_Equipments[i].Atk;
						Character->Def += Gacha_Equipments[i].Def;
						Character->Speed += Gacha_Equipments[i].Speed;
						Inventory[n] = "0";
						cout << "\n" << Gacha_Equipments[i].Name << "�� �����߽��ϴ�\n";
						cout << "hp : " << Character->Hp - Gacha_Equipments[i].Hp << " -> " << Character->Hp << "\n";
						cout << "mp : " << Character->Mp - Gacha_Equipments[i].Mp << " -> " << Character->Mp << "\n";
						cout << "atk : " << Character->Atk - Gacha_Equipments[i].Atk << " -> " << Character->Atk << "\n";
						cout << "def : " << Character->Def - Gacha_Equipments[i].Def << " -> " << Character->Def << "\n";
						cout << "speed : " << Character->Speed - Gacha_Equipments[i].Speed << " -> " << Character->Speed << "\n\n";
						break;
					}
				}
			}
		}
	}
	else { cout << "������ ����� ��ҵǾ����ϴ�\n"; }
}

void Take_Off_Equipment(My_Character* Character, string* Inventory, string* Equipment_slot) {
	//��� ������ ���� ���� �Լ�
	int Count = 0;
	int N;
	for (int I = 0; I < 5; I++) {      //�κ��丮�� ������� �ִ��� Ȯ��
		if (Inventory[I] == "0") { Count++; }
	}
	if (Count == 0) {    //�κ��丮�� ���� �� ���
		cout << "�κ��丮�� ���� á���ϴ�.\n";
		cout << "�κ��丮�� ��� �Ŀ� �ٽ� �õ����ּ���\n";
	}
	else {
		cout << "�������� ��� ������ ���\n";
		for (int I = 0; I < 5; I++) { cout << I << " : " << Equipment_slot[I] << endl; }
		cout << "------------------------\n";
		cout << "���� ������ �������� ��ȣ�� �Է����ּ���\n";
		cout << "0~4 �̿��� ���ڸ� �Է��ϸ� ��� ������ ��ҵ˴ϴ�.\n";
		cout << "�Է� : ";
		cin >> N;
		cout << endl;
		if (N < 0 && N > 4) { cout << "�����Ͻ� ��ġ�� �������� ��� �����ϴ�.\n"; }
		else if (N >= 0 && N <= 4) {
			if (Equipment_slot[N] == "0") { cout << "�����Ͻ� ��ġ�� �������� ��� �����ϴ�.\n"; }
			else {
				for (int J = 0; J < 15; J++) {//15�� Equipments �迭 ũ��
					if (Equipment_slot[N] == Equipments[J].Name) {//��� ������ ���� ����
						Pick_Up_Item(Inventory, Equipment_slot[N]);
						Character->Hp -= Equipments[J].Hp;
						Character->Mp -= Equipments[J].Mp;
						Character->Atk -= Equipments[J].Atk;
						Character->Def -= Equipments[J].Def;
						Character->Speed -= Equipments[J].Speed;
						Equipment_slot[N] == "0";
						cout << "\n" << Equipments[J].Name << "�� ���� �����߽��ϴ�\n";
						cout << "hp : " << Character->Hp + Equipments[J].Hp << " -> " << Character->Hp << "\n";
						cout << "mp : " << Character->Mp + Equipments[J].Mp << " -> " << Character->Mp << "\n";
						cout << "atk : " << Character->Atk + Equipments[J].Atk << " -> " << Character->Atk << "\n";
						cout << "def : " << Character->Def + Equipments[J].Def << " -> " << Character->Def << "\n";
						cout << "speed : " << Character->Speed + Equipments[J].Speed << " -> " << Character->Speed << "\n\n";
						break;
					}
				}
				for (int J = 0; J < 5; J++) {//5�� Gacha_Equipments �迭 ũ��
					if (Equipment_slot[N] == "0") { break; }//���� for������ ��� �����ߴٸ� �� for���� ������ ����
					if (Equipment_slot[N] == Gacha_Equipments[J].Name) {//��í ��� ���� ����
						Pick_Up_Item(Inventory, Equipment_slot[N]);
						Character->Hp -= Gacha_Equipments[J].Hp;
						Character->Mp -= Gacha_Equipments[J].Mp;
						Character->Atk -= Gacha_Equipments[J].Atk;
						Character->Def -= Gacha_Equipments[J].Def;
						Character->Speed -= Gacha_Equipments[J].Speed;
						Equipment_slot[N] == "0";
						cout << "\n" << Gacha_Equipments[J].Name << "�� ���� �����߽��ϴ�\n";
						cout << "hp : " << Character->Hp + Gacha_Equipments[J].Hp << " -> " << Character->Hp << "\n";
						cout << "mp : " << Character->Mp + Gacha_Equipments[J].Mp << " -> " << Character->Mp << "\n";
						cout << "atk : " << Character->Atk + Gacha_Equipments[J].Atk << " -> " << Character->Atk << "\n";
						cout << "def : " << Character->Def + Gacha_Equipments[J].Def << " -> " << Character->Def << "\n";
						cout << "speed : " << Character->Speed + Gacha_Equipments[J].Speed << " -> " << Character->Speed << "\n\n";
						break;
					}
				}
			}
		}
	}
}

bool Inventory_Menu()
{
	int Inventorymenu;
	bool Inventoryflag = true;
	int flag;
	while (Inventoryflag)
	{
		cout << "------------------------\n" << "INVENTORY MENU" << endl;
		cout << "1. ������ ���\n2. ������ ����\n3. �κ��丮 �ҷ�����\n0. �ڷΰ���\n";
		cin >> flag;
		switch (flag)
		{
		case 1:
			Use_Item(SoNB_P, Inventory, Equipment_slot);
			Inventoryflag = false;
			break;
		case 2:
			Item_List();
			break;
		case 3:
			Look_Inventory(Inventory);
			break;
		case 0:
			cout << "------------------------\n";
			Inventoryflag = false;
			return true;
			break;
		default:
			cout << "�ٽ� �Է��� �ּ���.";
			break;
		}
	}
}

void Monster_Die(My_Character* a, Monster* b)
{
	a->Pick_UP_Money(b->Money);
	SoNB_P->Exp_Plus(b->Exp);
	if (SoNB_P->Exp > SoNB_P->Max_Exp)
	{
		SoNB_P->Level_Plus();
	}
}

int Get_Money()
{
	return SoNB_P->Money;
}