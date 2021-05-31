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
bool Firstflag = true; //do while문 탈출조건
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
            cout << "------------------------\n" << Map[i][j]->Kind << " 가 나타났다!\n" << endl;//몬스터 등장
            Temp_Mob_P->Hp = Map[i][j]->Hp;
            Temp_Mob_P->Mp = Map[i][j]->Mp;

            while (true)//전투
            {
                if (SoNB_P->Speed > Map[i][j]->Speed)//스피드 비교 
                {
                    Atk_Menu(SoNB_P, Map[i][j]);//캐릭터 spd>mob spd 이므로 플레이어 선공
                    if (Map[i][j]->Hp < 0)//몬스터 사망시
                    {
                        cout << "\n" << Map[i][j]->Kind << " 를 물리쳤다!" << endl;
                        Monster_Die(SoNB_P, Map[i][j]);
                        Map[i][j]->Hp = Temp_Mob_P->Hp;
                        Map[i][j]->Mp = Temp_Mob_P->Mp;
                        DropItem = Drop_Item();
                        if (DropItem != "") Pick_Up_Item(Inventory, DropItem);
                        break;
                    }
                    Mob_Atk(Map[i][j], SoNB_P);
                    if (SoNB_P->Hp < 0) //도중에 캐릭터가 사망시 게임오버 
                    {
                        cout << "Game over..." << endl;
                        i = Map.size() - 1; //한번에 i를 끝인덱스까지 올려서 중첩for문 반복중지
                        return false;                
                        break;
                    }
                    cout << "------------------------\n";

                }

                else
                {
                    Mob_Atk(Map[i][j], SoNB_P);//mob spd> 캐릭터 spd 이므로 mob 선공
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
                        cout << Map[i][j]->Kind << " 를 물리쳤다!" << endl;
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
{//메뉴 선택

    do {
        cout << "【 TEST BETA GAME 】\n\n" << "메뉴를 선택해 주세요 ~ !\n";
        cout << "\n1.게임시작\n2.게임 설명\n3.게임 종료\n";

        cin >> Menu;
        switch (Menu)
        {
        case 1:
            Secondflag = true;//메인메뉴 --> 맵선택(flase방지)
            while (Secondflag)
            {
                cout << "------------------------\n";
                cout << "1. 맵 선택\n2. 상점\n3. 메인메뉴\n";
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
                    cout << "\n다시 입력해 주세요\n";
                    break;
                }
            }
            break;
        case 2:
            cout << "\n이 게임은 현재 개발 중에 있는 C++ 기반 RPG입니다.\n";
            cout << "------------------------\n";
            break;
        case 3:
            Firstflag = false;
            break;
        default:
            cout << "------------------------\n";
            cout << "올바른 숫자 입력" << endl;
            break;
        }
    } while (Firstflag); //메뉴 정석(do while)
}