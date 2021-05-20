#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include "player.h"
#include "inventory.h"
#include "map.h"
using namespace std;

int Menu;
bool Flag = true; //do while문 탈출조건

int main()
{//메뉴 선택

    do {
        cout << "【 TEST BETA GAME 】\n\n" << "메뉴를 선택해 주세요 ~ !\n";
        cout << "\n1.게임시작\n2.게임 설명\n3.게임 종료\n";

        cin >> Menu;
        switch (Menu)
        {
        case 1:
            for (int i = 0; i < Map1.size(); i++)
            {
                for (int j = 0; j < Map1[i].size(); j++)
                {
                    cout << "------------------------\n" << Map1[i][j]->Kind << " 가 나타났다!\n" << endl;//몬스터 등장
                    Temp_Mob_P->Hp = Map1[i][j]->Hp;
                    Temp_Mob_P->Mp = Map1[i][j]->Mp;

                    while (true)//전투
                    {
                        if (SoNB_P->Speed > Map1[i][j]->Speed)//스피드 비교 
                        {
                            Atk_Menu(SoNB_P, Map1[i][j]);//캐릭터 spd>mob spd 이므로 플레이어 선공
                            if (Map1[i][j]->Hp < 0)//몬스터 사망시
                            {
                                cout << "\n" << Map1[i][j]->Kind << " 를 물리쳤다!" << endl;
                                Map1[i][j]->Hp = Temp_Mob_P->Hp;
                                Map1[i][j]->Mp = Temp_Mob_P->Mp;
                                DropItem = Drop_Item();
                                if (DropItem != "") Pick_Up_Item(Inventory, DropItem);
                                break;
                            }
                            Mob_Atk(Map1[i][j], SoNB_P);
                            if (SoNB_P->Hp < 0) //도중에 캐릭터가 사망시 게임오버 
                            {
                                cout << "Game over..." << endl;
                                i = Map1.size() - 1; //한번에 i를 끝인덱스까지 올려서 중첩for문 반복중지
                                break;
                            }
                            cout << "------------------------\n";

                        }

                        else
                        {
                            Mob_Atk(Map1[i][j], SoNB_P);//mob spd> 캐릭터 spd 이므로 mob 선공
                            if (SoNB_P->Hp < 0)
                            {
                                cout << "Game over..." << endl;
                                i = Map1.size() - 1;
                                break;
                            }

                            Atk_Menu(SoNB_P, Map1[i][j]);
                            if (Map1[i][j]->Hp < 0)
                            {
                                cout << Map1[i][j]->Kind << " 를 물리쳤다!" << endl;
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
            cout << "이 게임은 현재 개발 중에 있는 C++ 기반 RPG입니다.\n\n";
            break;
        case 3:
            Flag = false;
            break;
        default:
            cout << "------------------------\n";
            cout << "올바른 숫자 입력" << endl;
            break;
        }
    } while (Flag); //메뉴 정석(do while) 
}