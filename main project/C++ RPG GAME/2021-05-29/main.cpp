#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include "inventory.h"
#include "player.h"
#include "map.h"
using namespace std;

int Menu;
int Select;
bool Firstflag = true; //do while�� Ż������
bool Secondflag = true;
bool Thirdflag = true;

bool Menu1()
{
    cout << "------------------------\n";
    cout << "Map1   Map2   Map3\n";
    cin >> Select;
    Map = Maps[Select - 1];

    for (int i = 0; i < Map.size(); i++)
    {
        for (int j = 0; j < Map[i].size(); j++)
        {
            cout << "------------------------\n" << Map[i][j]->Kind << " �� ��Ÿ����!\n" << endl;//���� ����
            Temp_Mob_P->Hp = Map[i][j]->Hp;
            Temp_Mob_P->Mp = Map[i][j]->Mp;

            while (true)//����
            {
                if (SoNB_P->Speed > Map[i][j]->Speed)//���ǵ� �� 
                {
                    Atk_Menu(SoNB_P, Map[i][j]);//ĳ���� spd>mob spd �̹Ƿ� �÷��̾� ����
                    if (Map[i][j]->Hp < 0)//���� �����
                    {
                        cout << "\n" << Map[i][j]->Kind << " �� �����ƴ�!" << endl;
                        Monster_Die(SoNB_P, Map[i][j]);
                        Map[i][j]->Hp = Temp_Mob_P->Hp;
                        Map[i][j]->Mp = Temp_Mob_P->Mp;
                        DropItem = Drop_Item();
                        if (DropItem != "") Pick_Up_Item(Inventory, DropItem);
                        break;
                    }
                    Mob_Atk(Map[i][j], SoNB_P);
                    if (SoNB_P->Hp < 0) //���߿� ĳ���Ͱ� ����� ���ӿ��� 
                    {
                        cout << "Game over..." << endl;
                        i = Map.size() - 1; //�ѹ��� i�� ���ε������� �÷��� ��øfor�� �ݺ�����
                        return false;                
                        break;
                    }
                    cout << "------------------------\n";

                }

                else
                {
                    Mob_Atk(Map[i][j], SoNB_P);//mob spd> ĳ���� spd �̹Ƿ� mob ����
                    if (SoNB_P->Hp < 0)
                    {
                        cout << "Game over..." << endl;
                        i = Map.size() - 1;
                        return false;
                        break;
                    }

                    Atk_Menu(SoNB_P, Map[i][j]);
                    if (Map[i][j]->Hp < 0)
                    {
                        cout << Map[i][j]->Kind << " �� �����ƴ�!" << endl;
                        Monster_Die(SoNB_P, Map[i][j]);
                        Map[i][j]->Hp = Temp_Mob_P->Hp;
                        Map[i][j]->Mp = Temp_Mob_P->Mp;
                        DropItem = Drop_Item();
                        if (DropItem != "") Pick_Up_Item(Inventory, DropItem);
                        break;
                    }
                    cout << "------------------------\n";
                }
            }
        }
    }
    if (SoNB_P->Hp > 0) cout << "\n\nDungeon clear!\n\n";
    return true;
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
            Secondflag = true;//���θ޴� --> �ʼ���(flase����)
            while (Secondflag)
            {
                cout << "------------------------\n";
                cout << "1. �� ����\n2. ����\n3. ���θ޴�\n";
                cin >> Menu;
                switch (Menu)
                {
                case 1:
                    Secondflag = Menu1();
                    break;
                case 2:
                    Thirdflag = true;
                    while (Thirdflag) Thirdflag = Open_Store(Inventory);
                    break;
                case 3:
                    Secondflag = false;
                    cout << "------------------------\n";
                    break;
                default:
                    cout << "\n�ٽ� �Է��� �ּ���\n";
                    break;
                }
            }
            break;
        case 2:
            cout << "\n�� ������ ���� ���� �߿� �ִ� C++ ��� RPG�Դϴ�.\n";
            cout << "------------------------\n";
            break;
        case 3:
            Firstflag = false;
            break;
        default:
            cout << "------------------------\n";
            cout << "�ùٸ� ���� �Է�" << endl;
            break;
        }
    } while (Firstflag); //�޴� ����(do while)
}