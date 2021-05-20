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
        cout << "\nHP : " << Hp << "\nMP: " << Mp << "\nATK: " << Atk << "\nDEF: " << Def << endl;
        cout << "------------------------\n";
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

void Use_Item(My_Character* Character, string Inventory[]) {
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
            for (int i = 0; i < 14; i++) {   //14�� item�迭 ũ��
                if (Inventory[n] == Items[i].Name) {
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
        }
    }
    else { cout << "������ ����� ��ҵǾ����ϴ�\n"; }
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
            Use_Item(SoNB_P, Inventory);
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