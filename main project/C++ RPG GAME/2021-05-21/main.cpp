#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include "player.h"
#include "inventory.h"
#include "map.h"
using namespace std;

int Menu;
bool Flag = true; //do while�� Ż������

int main()
{//�޴� ����

    do {
        cout << "�� TEST BETA GAME ��\n\n" << "�޴��� ������ �ּ��� ~ !\n";
        cout << "\n1.���ӽ���\n2.���� ����\n3.���� ����\n";

        cin >> Menu;
        switch (Menu)
        {
        case 1:
            for (int i = 0; i < Map1.size(); i++)
            {
                for (int j = 0; j < Map1[i].size(); j++)
                {
                    cout << "------------------------\n" << Map1[i][j]->Kind << " �� ��Ÿ����!\n" << endl;//���� ����
                    Temp_Mob_P->Hp = Map1[i][j]->Hp;
                    Temp_Mob_P->Mp = Map1[i][j]->Mp;

                    while (true)//����
                    {
                        if (SoNB_P->Speed > Map1[i][j]->Speed)//���ǵ� �� 
                        {
                            Atk_Menu(SoNB_P, Map1[i][j]);//ĳ���� spd>mob spd �̹Ƿ� �÷��̾� ����
                            if (Map1[i][j]->Hp < 0)//���� �����
                            {
                                cout << "\n" << Map1[i][j]->Kind << " �� �����ƴ�!" << endl;
                                Map1[i][j]->Hp = Temp_Mob_P->Hp;
                                Map1[i][j]->Mp = Temp_Mob_P->Mp;
                                DropItem = Drop_Item();
                                if (DropItem != "") Pick_Up_Item(Inventory, DropItem);
                                break;
                            }
                            Mob_Atk(Map1[i][j], SoNB_P);
                            if (SoNB_P->Hp < 0) //���߿� ĳ���Ͱ� ����� ���ӿ��� 
                            {
                                cout << "Game over..." << endl;
                                i = Map1.size() - 1; //�ѹ��� i�� ���ε������� �÷��� ��øfor�� �ݺ�����
                                break;
                            }
                            cout << "------------------------\n";

                        }

                        else
                        {
                            Mob_Atk(Map1[i][j], SoNB_P);//mob spd> ĳ���� spd �̹Ƿ� mob ����
                            if (SoNB_P->Hp < 0)
                            {
                                cout << "Game over..." << endl;
                                i = Map1.size() - 1;
                                break;
                            }

                            Atk_Menu(SoNB_P, Map1[i][j]);
                            if (Map1[i][j]->Hp < 0)
                            {
                                cout << Map1[i][j]->Kind << " �� �����ƴ�!" << endl;
                                Map1[i][j]->Hp = Temp_Mob_P->Hp;
                                Map1[i][j]->Mp = Temp_Mob_P->Mp;
                                DropItem = Drop_Item();
                                if (DropItem != "") Pick_Up_Item(Inventory, DropItem);
                                break;
                            }
                            cout << "------------------------\n";
                        }
                    }
                }
            }
            if (SoNB_P->Hp > 0) cout << "Congratulations! Game clear!\n\n";
            Flag = false;
            break;
        case 2:
            cout << "------------------------\n";
            cout << "�� ������ ���� ���� �߿� �ִ� C++ ��� RPG�Դϴ�.\n\n";
            break;
        case 3:
            Flag = false;
            break;
        default:
            cout << "------------------------\n";
            cout << "�ùٸ� ���� �Է�" << endl;
            break;
        }
    } while (Flag); //�޴� ����(do while) 
}