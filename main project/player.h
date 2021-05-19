#pragma once
#include <iostream>
#include "monster.h"
#include "inventory.h"
using namespace std;

typedef struct My_Character //�÷��̾� Ŭ����
{
    double Hp, Mp, Atk, Def, Speed;

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
        cout << "HP : " << Hp << "\nMP: " << Mp << "\n���ݷ�: " << Atk << "\n����: " << Def << endl;
    }
}My_Character;

void Atk_Menu(My_Character* Character, mob* Mob)//�÷��̾��� �޴�
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
            cout << "\n������ ������ ���մϴ�!!\n";
            Damage = Character->Atk - Mob->def; //�÷��̾� ������ ��� (�÷��̾�Atk - ����def)
            if (Damage < 0) Damage = 0; //���ܻ���: ������ ������ ��� 0���� ���
            Mob->hp -= Damage; //���� ������ ���
            cout << "�÷��̾��� ����!" << endl;
            cout << "�÷��̾�� " << Damage << " �� ���ظ� ������!" << endl;
            Atkflag = false;
            break;
        case 2: //��ų���
            Atkflag = Skill_Menu(Character, Mob, Atkflag);
            break;
        case 3: //���濭��
            Atkflag = inventorymenu();
            break;
        case 4: //ĳ���� ���º���
            Character->Get_Character_Info();
            break;
        case 5: //���� ���º���
            Mob->GetInfo();
            break;
        case 6: //�̱���
            //����
            break;
        default: //�߸��� ���� �Է¹�����
            cout << "�ùٸ��� ���� �Է�" << endl;
            break;
        }
    }
}

bool Skill_Menu(My_Character* Character, mob* Mob, bool Atkflag)
{
    int Skillmenu;//��ų ����
    string Skillcheck;//��ų ��� Ȯ��
    bool Skillflag = true;// Skill_Menu �Լ� ����� ����
    double Damage; // �÷��̾��� ���� ��ų ������
    while (Skillflag)
    {
        cout << "SKILL MENU" << endl;
        cout << "1. �Ŀ� ������\n2. ������ DEATH\n0. �ڷΰ���" << endl;// ��ų �޴�
        cin >> Skillmenu;
        switch (Skillmenu)
        {
        case 1: //�Ŀ� ������ 
            cout << "���ݷ�: " << Character->Atk * 1.2 << "\nMP: 100\n����ұ�? (Y or else)" << endl;
            cin >> Skillcheck; //��ų��� ����Ȯ��
            if (Skillcheck == "Y") //��ų���
            {
                Character->Mp -= 20; //Mp �Ҹ�
                Damage = (Character->Atk * 1.5) - Mob->def; //�÷��̾� ������ ��� (�÷��̾�Atk - ����def)
                if (Damage < 0) Damage = 0; //���ܻ���: ������ ������ ��� 0���� ���
                Mob->hp -= Damage; //���� ������ ���
                cout << "Po������weR!!" << endl;
                cout << "�÷��̾�� " << Damage << " �� ���ظ� ������!" << endl;
                Skillflag = false; //Skill_Menu �Լ� ����
                return false; //Atkflag=false : Atk_Menu �Լ� ���� return
            }
            break;
        case 2: //������ ����
            cout << "���ݷ�: " << Character->Atk * 3 << " (def����)" << "\n-HP: 50%\n����ұ�? (Y or else)" << endl;
            cin >> Skillcheck;
            if (Skillcheck == "Y") //��ų��� ����Ȯ��
            {
                Character->Hp = Character->Hp / 2; //Hp�Ҹ�
                Damage = (Character->Atk * 3); //�÷��̾� ������ ��� (�÷��̾�Atk - ����def)
                if (Damage < 0) Damage = 0; //���ܻ���: ������ ������ ��� 0���� ���
                Mob->hp -= Damage; //���� ������ ���
                cout << "JJUGEM�� ����!!!" << endl;
                cout << "�÷��̾�� " << Damage << " �� ���ظ� ������!" << endl;
                Skillflag = false; //Skill_Menu �Լ� ����
                return false; //Atkflag=false : Atk_Menu �Լ� ���� return
            }
            break;
        case 0: //�ڷΰ���
            Skillflag = false; //Skill_Menu �Լ� ����
            return true; //Atkflag=ture : Atk_Menu �Լ� �̾���
            break;
        }
    }
}