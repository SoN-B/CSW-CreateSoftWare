#pragma once
#include <iostream>
#include <conio.h>
#include <Windows.h>
#include "monster.h"
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
		setColor(8);
		cout << "\nLevel";
		setColor(15);
		cout << ": " << Level;

		setColor(6);
		cout << "\nMax Exp/Exp";
		setColor(15);
		cout << ": " << Max_Exp << "/" << Exp;

		setColor(4);
		cout << "\nHP";
		setColor(15);
		cout << ": " << Hp;

		setColor(9);
		cout << "\nMP";
		setColor(15);

		cout << " : " << Mp << "\nATK : " << Atk << "\nDEF : " << Def << "\nSPPED : " << Speed;

		setColor(14);
		cout << "\nMoney";
		setColor(15);

		cout << " : " << Money << " Coin" << endl;
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
	void Restat()
	{
		this->Hp = 200;
		this->Mp = 100;
		this->Atk = 50;
		this->Def = 5;
		this->Speed = 1.5;
		this->Level = 1;
		this->Exp = 0;
		this->Max_Exp = 100;
		this->Money = 0;
	}
}My_Character;
My_Character SoNB;
My_Character* SoNB_P = &SoNB;

class Skill //��ų Ŭ����
{
public:
	string Skillname;
	double Usedhp, Usedmp, Healhp, Healmp, Multiples, Static;
	Skill()
	{
		Skillname = "";
	}
	Skill(string Skillname, double Usedhp, double Usedmp, double Healhp, double Healmp, double Multiples, double Static)
	{
		this->Skillname = Skillname; //��ų�̸�
		this->Usedhp = Usedhp; //���Ǵ� Hp
		this->Usedmp = Usedmp; //���Ǵ� Mp
		this->Healhp = Healhp; // ȿ���� �޴� Hp
		this->Healmp = Healmp; // ȿ���� �޴� Mp
		this->Multiples = Multiples; // ��� ������
		this->Static = Static; // ���������� 
	}
	void Use_Skill(My_Character* Character, Monster* Mob, Skill Skill);
	void Skill_Info(My_Character* Character, Skill Skill);
};

void Skill::Use_Skill(My_Character* Character, Monster* Mob, Skill Skill)//��ų ��� �Լ�
{
	double Damage = 0;//������ �ʱ�ȭ
	cout << "----------------\n��ų���! " << Skill.Skillname << endl;
	Character->Hp -= Skill.Usedhp;//ü�� �Ҹ�
	Character->Mp -= Skill.Usedmp;//���� �Ҹ�
	if (Skill.Healhp != 0)//ü�� ȸ��
	{
		Character->Hp += Skill.Healhp;//ü�� ȸ��
		cout << "�÷��̾�� " << Skill.Healhp << " �� ü���� ȸ���ߴ�!" << endl;
	}
	if (Skill.Healmp != 0)//���� ȸ��
	{
		Character->Hp += Skill.Healmp;//ü�� ȸ��
		cout << "�÷��̾�� " << Skill.Healmp << " �� ������ ȸ���ߴ�!" << endl;
	}
	if (Skill.Multiples != 0 || Skill.Static != 0)//���� ���� ���
	{
		if (Skill.Multiples != 0) { Damage = (Character->Atk * Skill.Multiples) - Mob->Def; }//��� ������ ���
		if (Skill.Static != 0) { Damage = Skill.Static - Mob->Def; }//���� ������ ���
		if (Damage < 0) { Damage = 0; }//���ܻ���: ������ ������ ��� 0���� ���
		Mob->Hp -= Damage;//���� ������ ���
		cout << "�÷��̾�� " << Damage << " �� �������� ������!" << endl;
	}
}

void Skill::Skill_Info(My_Character* Character, Skill Skill)//��ų ���� �Լ�
{//�ش� ��ų�� ���õ� ������ ����
	cout << "-------------------\n��ų: " << Skill.Skillname << endl;
	if (Skill.Usedhp != 0) {
		cout << "�Ҹ� HP: ";

		setColor(4);
		cout << Skill.Usedhp << endl;
		setColor(15);
	}
	if (Skill.Usedmp != 0) {
		cout << "�Ҹ� MP: ";

		setColor(9);
		cout << Skill.Usedmp << endl;
		setColor(15);
	}
	if (Skill.Healhp != 0) {
		cout << "ȸ�� HP: ";

		setColor(4);
		cout << Skill.Healhp << endl;
		setColor(15);
	}
	if (Skill.Healmp != 0) {
		cout << "ȸ�� MP: ";

		setColor(9);
		cout << Skill.Healmp << endl;
		setColor(15);
	}
	if (Skill.Multiples != 0)
	{
		cout << "������ ";

		setColor(12);
		cout << Character->Atk << " * " << Skill.Multiples;
		setColor(15);


		cout << " ��ŭ�� �������� ������.\n";
		cout << "���� ������: ";

		setColor(12);
		cout << Character->Atk * Skill.Multiples << endl;
		setColor(15);
	}
	if (Skill.Static != 0) {
		cout << "������ ";

		setColor(12);
		cout << Skill.Static;
		setColor(15);

		cout << " ��ŭ�� �������� ������." << endl;
	}
}
//���� ��ų ����
Skill Power_Slash("�Ŀ� ������", 0.0, 20.0, 0.0, 0.0, 1.2, 0.0);//����20�Ҹ�, ������1.2��
Skill Blood_Slash("���� ������", 100, 0, 0, 0, 0, 150);//ü��100�Ҹ�, 150������
Skill Mind_Fuel("ȸ������", 0, 30, 15, 0, 0, 0);//���� 30�Ҹ�, ü��15ȸ��
Skill Prayer("�⵵", 0, 0, 0, 20, 0, 0);//�Ҹ����, ����20ȸ��
//�÷��̾��� ��ųâ �⺻��
Skill Skill_Arry[4] = { Power_Slash,Blood_Slash,Mind_Fuel,Prayer };

void Mob_Atk(Monster* Mob, My_Character* Character)
{
	double Damage = Mob->Atk - Character->Def;
	if (Damage < 0) Damage = 0;
	//�� ���ݷ�<�÷��̾� ���� ��� ���� ������ ��Ȳ ����

	Character->Hp -= Damage;

	setColor(10);
	cout << "��" << Mob->Kind << " �� ����!��" << endl;
	setColor(15);

	cout << "�÷��̾�� ";

	setColor(12);
	cout << Damage;
	setColor(15);

	cout << " �� ���ظ� �Ծ���!\n" << endl;
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
		Choice = _getch()-48;
		switch (Choice)
		{
		case 1: //�⺻����
			setColor(12);
			cout << "\n������ ������ ���մϴ�!!\n\n";
			setColor(15);

			Damage = Character->Atk - Mob->Def; //�÷��̾� ������ ��� (�÷��̾�Atk - ����def)
			if (Damage < 0) Damage = 0; //���ܻ���: ������ ������ ��� 0���� ���
			Mob->Hp -= Damage; //���� ������ ���

			setColor(10);
			cout << "���÷��̾��� ����!��" << endl;
			setColor(15);

			cout << "�÷��̾�� ";

			setColor(12);
			cout << Damage;
			setColor(15);

			cout << " �� ���ظ� ������!\n" << endl;
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
			//Atkflag = false;
			cout << "\n�������� ������ ���ɴϴ�...";
			Sleep(2000);
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
		cout << "------------------------\n";

		setColor(10);
		cout << "SKILL MENU" << endl;
		setColor(15);

		for (int i = 0; i < 4; i++) { cout << i + 1 << ". " << Skill_Arry[i].Skillname << endl; }//��ųâ�� �ִ� ��ų�̸����� ���
		cout << "0. �ڷΰ���" << endl;//0�� �Է½� �ڷΰ��� ���
		cin >> Skillmenu;
		if (Skillmenu == 0)
		{
			cout << "------------------------\n";
			Skillflag = false; //Skill_Menu �Լ� ����
			return true; //Atk_Menu=true : �÷��̾� �� ����
		}
		if (Skillmenu >= 1 && Skillmenu <= 4)
		{
			Skill_Arry[Skillmenu - 1].Skill_Info(Character, Skill_Arry[Skillmenu - 1]);//��ų���� ���
			cout << Skill_Arry[Skillmenu - 1].Skillname << " �� ����ұ�? (Y or else)" << endl;
			cin >> Skillcheck; //��ų��� ����Ȯ��
			if (Skillcheck == "Y")//��ų ��� Ȯ�ν�
			{
				if (Character->Hp - Skill_Arry[Skillmenu - 1].Usedhp <= 0)//��ų ���� HP�� 0���ϰ� �Ǵ°�� ����
				{
					cout << "HP�� ���ڶ��ϴ�." << endl;
					Skillflag = false;//Skill_Menu �Լ� ����
					return true;//Atk_Menu=true : �÷��̾� �� ����
				}
				if (Character->Mp - Skill_Arry[Skillmenu - 1].Usedmp < 0)//��ų ���� MP�� 0�̸��� �Ǵ°�� ����
				{
					cout << "MP�� ���ڶ��ϴ�." << endl;
					Skillflag = false;//Skill_Menu �Լ� ����
					return true;//Atk_Menu=true : �÷��̾� �� ����
				}
				Skill_Arry[Skillmenu - 1].Use_Skill(Character, Mob, Skill_Arry[Skillmenu - 1]);//��ų���
				Skillflag = false; //Skill_Menu �Լ� ����
				return false; //Atk_Menu=false : �÷��̾� �� ����
			}
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
#pragma once
