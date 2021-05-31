#pragma once
#include <iostream>
#include "monster.h"
#include "inventory.h"
using namespace std;

typedef struct My_Character //�÷��̾� Ŭ����
{
	double Hp, Mp, Atk, Def, Speed, Level = 1, Exp = 0, Max_Exp = 100, Money = 0;

	My_Character(double Hp = 200, double Mp = 100, double Atk = 50, double Def = 5, 
		double Speed = 1.5, double Money = 1000)
	{
		this->Hp = Hp;
		this->Mp = Mp;
		this->Atk = Atk;
		this->Def = Def;
		this->Speed = Speed;
		this->Money = Money;
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