#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include "map.h"
#include "inventory.h"
using namespace std;

int Menu;
bool Flag = true; //do while�� Ż������

typedef struct My_Character { //�⺻
    double hp, mp, atk, def, speed;

    My_Character(double hp = 200, double mp = 100, double atk = 50,
        double def = 5, double speed = 1.5)
    {
        this->hp = hp;
        this->mp = mp;
        this->atk = atk;
        this->def = def;
        this->speed = speed;
    }

    void Get_Character_Info()//�÷��̾� ���� ��� 
    {
        cout << "HP : " << hp << "\nMP: " << mp << "\n���ݷ�: " << atk << "\n����: " << def << endl;
    }
}My_Character;

My_Character SoNB;
My_Character* SoNB_P = &SoNB;

string inventory[5] = { "red potion","red potion","purple potion","purple potion","0" };

void use_item(My_Character* character, string inventory[]) {
    // �������� ����� ��
    int n;

    cout << "�κ��丮 ���\n";
    for (int i = 0; i < 5; i++) { cout << i << " : " << inventory[i] << "\n"; }
    cout << "0~4�� ������ �ٸ� ���� �Է½� ������ ����� ��ҵ˴ϴ�\n";
    cout << "����� �������� ��ġ�� �Է����ּ���\n" << "��ġ : ";
    cin >> n;
    if (n >= 0 && n <= 4) {
        if (inventory[n] == "0") { cout << "�����Ͻ� ��ġ�� �������� �����ϴ�\n"; }
        else {
            for (int i = 0; i < 14; i++) {   //14�� item�迭 ũ��
                if (inventory[n] == items[i].name) {
                    character->hp += items[i].hp;
                    character->mp += items[i].mp;
                    character->atk += items[i].atk;
                    character->def += items[i].def;
                    character->speed += items[i].speed;
                    inventory[n] = "0";
                    cout << items[i].name << "�� ����߽��ϴ�\n";
                    cout << "hp : " << character->hp - items[i].hp << " -> " << character->hp << "\n";
                    cout << "mp : " << character->mp - items[i].mp << " -> " << character->mp << "\n";
                    cout << "atk : " << character->atk - items[i].atk << " -> " << character->atk << "\n";
                    cout << "def : " << character->def - items[i].def << " -> " << character->def << "\n";
                    cout << "speed : " << character->speed - items[i].speed << " -> " << character->speed << "\n";
                    break;
                }
            }
        }
    }
    else { cout << "������ ����� ��ҵǾ����ϴ�\n"; }
}

bool skillmenu(My_Character* character, mob* mob, bool atkFlag);
void atkmenu(My_Character* character, mob* mob)//�÷��̾� ���� �޴�
{
    int choice;//����
    bool atkFlag = true;//�����Լ�����

    double damage;
    while (atkFlag)
    {
        cout << "������ �ұ�...\n1. ����\n2. ��ų\n3. ����\n4. ������\n5. �� ����\n6. ����" << endl; //�޴�
        cin >> choice;
        switch (choice)
        {
        case 1:
            cout << "\n������ ������ ���մϴ�!!\n";
            damage = character->atk - mob->def;
            if (damage < 0) damage = 0;

            mob->hp -= damage;
            cout << "�÷��̾��� ����!" << endl;
            cout << "�÷��̾�� " << damage << " �� ���ظ� ������!" << endl;
            atkFlag = false;
            break;
        case 2:
            atkFlag = skillmenu(character, mob, atkFlag);
            break;
        case 3:
            use_item(SoNB_P,inventory);
            break;
        case 4:
            character->Get_Character_Info();
            break;
        case 5:
            mob->GetInfo();
            break;
        case 6:
            //����
            break;
        default:
            cout << "�ùٸ��� ���� �Է�" << endl;
            break;
        }
    }

}
bool skillmenu(My_Character* character, mob* mob, bool atkFlag)
{
    int skill_menu;//��ų ����
    string YN;//��ų ��� Ȯ��
    bool SkillFlag = true;// ��ų�޴� �Լ� ����
    double damage;
    while (SkillFlag)
    {
        cout << "SKILL MENU" << endl;
        cout << "1. �Ŀ� ������\n2. ��ų2��\n0. �ڷΰ���" << endl;
        cin >> skill_menu;
        switch (skill_menu)//��ų
        {
        case 1:
            cout << "���ݷ�: " << character->atk * 1.2 << "\nMP: 100\n����ұ�? (Y or else)" << endl;
            cin >> YN;
            if (YN == "Y")
            {
                character->mp -= 20;
                damage = (character->atk * 1.5) - mob->def;
                if (damage < 0) damage = 0;

                mob->hp -= damage;
                cout << "Po������weR!!" << endl;
                cout << "�÷��̾�� " << damage << " �� ���ظ� ������!" << endl;
                SkillFlag = false;
                return false;
            }
            break;
        case 2:
            cout << "��ų 2���� ����\n����ұ�? (Y or else)" << endl;
            cin >> YN;
            if (YN == "Y")
            {
                //��ų 2�� ���
                SkillFlag = false;
                return false;
            }
            break;
        case 0:
            SkillFlag = false;
            return true;
            break;
        }
    }
}

void mobatk(mob* mob, My_Character* character)
{
    double damage = mob->atk - character->def;
    if (damage < 0) damage = 0;
    //�� ���ݷ�<�÷��̾� ���� ��� ���� ������ ��Ȳ ����

    character->hp -= damage;
    cout << mob->kind << " �� ����!" << endl;
    cout << "�÷��̾�� " << damage << " �� ���ظ� �Ծ���!" << endl;
}

int main()
{//�޴� ����

    do {
        cout << "�� TEST BETA GAME ��\n\n" << "�޴��� ������ �ּ��� ~ !\n";
        cout << "\n1.���ӽ���\n2.���� ����\n3.���� ����\n";

        cin >> Menu;
        switch (Menu)
        {
        case 1:
            for (int i = 0; i < map1.size(); i++)
            {
                for (int j = 0; j < map1[i].size(); j++)
                {
                    cout << map1[i][j]->kind << " �� ��Ÿ����!" << endl;//���� ����
                    Temp_mob_P->hp = map1[i][j]->hp;
                    Temp_mob_P->mp = map1[i][j]->mp;

                    while (true)//����
                    {
                        if (SoNB_P->speed > map1[i][j]->speed)//���ǵ� �� 
                        {
                            atkmenu(SoNB_P, map1[i][j]);//ĳ���� spd>mob spd �̹Ƿ� �÷��̾� ����
                            if (map1[i][j]->hp < 0)//���� �����
                            {
                                cout << map1[i][j]->kind << " �� �����ƴ�!" << endl;
                                map1[i][j]->hp = Temp_mob_P->hp;
                                map1[i][j]->mp = Temp_mob_P->mp;
                                break;
                            }
                            mobatk(map1[i][j], SoNB_P);
                            if (SoNB_P->hp < 0) //���߿� ĳ���Ͱ� ����� ���ӿ��� 
                            {
                                cout << "Game over..." << endl;
                                i = map1.size() - 1; //�ѹ��� i�� ���ε������� �÷��� ��øfor�� �ݺ�����
                                break;
                            }

                        }

                        else
                        {
                            mobatk(map1[i][j], SoNB_P);//mob spd> ĳ���� spd �̹Ƿ� mob ����
                            if (SoNB_P->hp < 0)
                            {
                                cout << "Game over..." << endl;
                                i = map1.size() - 1;
                                break;
                            }

                            atkmenu(SoNB_P, map1[i][j]);
                            if (map1[i][j]->hp < 0)
                            {
                                cout << map1[i][j]->kind << " �� �����ƴ�!" << endl;
                                map1[i][j]->hp = Temp_mob_P->hp;
                                map1[i][j]->mp = Temp_mob_P->mp;
                                break;
                            }
                        }
                    }
                }
            }
            if (SoNB_P->hp > 0) cout << "Congratulations! Game clear!\n\n";
            Flag = false;
            break;
        case 2:
            cout << "�� ������ ���� ���� �߿� �ִ� C++ ��� RPG�Դϴ�.\n\n";
            break;
        case 3:
            Flag = false;
            break;
        default:
            cout << "�ùٸ� ���� �Է�" << endl;
            break;
        }
    } while (Flag); //�޴� ����(do while) 
}