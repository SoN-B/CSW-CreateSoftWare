#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <Windows.h>
#include <conio.h>
#include "player.h"
#include "inventory.h"
#include "map.h"
using namespace std;

int Menu; //메인메뉴 선택 변수
int Select; //Map_Combat 함수 선택 변수
int Cancel; //게임설명 탈출용 변수 :0입력으로 탈출
bool Mainflag = true; //main함수 do while문 제어 변수
bool Gameflag = true; //do while문 내부 게임시작 제어 변수
bool Storeflag = true;//상점 제어 변수
//bool Fourthflag = true; //현재 사용안함

void GoToXy(int x, int y) //UI관련
{
    COORD Pos;
    Pos.X = 2 * x;
    Pos.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
}
void Dungeon() //DUNGEON 로고
{
    GoToXy(10, 10);
    cout << "DDDDD     UU       UU NNN      N	 GGGGGG    EEEEEEEE	OOOO	NNN      N";
    GoToXy(10, 11);
    cout << "DD    DD  UU       UU NNNN     N  GG      GG   EE	      OO    OO	NNNN     N";
    GoToXy(10, 12);
    cout << "DD     DD UU       UU NN NN    N  GG           EE	     OO      OO	NN NN    N";
    GoToXy(10, 13);
    cout << "DD      DDUU       UU NN  NN   N  GG   GGGGGG  EEEEEEEE OO        OONN  NN   N";
    GoToXy(10, 14);
    cout << "DD     DD UU       UU NN   NN  N  GG       GG  EE	     OO      OO	NN   NN  N";
    GoToXy(10, 15);
    cout << "DD    DD	UU    UU  NN    NN N	GG    GG   EE	      OO    OO	NN    NN N";
    GoToXy(10, 16);
    cout << "DDDDD         UUUU    NN     NNN	  GGGGG    EEEEEEEE	OOOO	NN     NNN";
    GoToXy(10, 17);
}
bool Map_Combat()//맵선택 및 전투
{
    system("cls");
    GoToXy(10, 15);
    cout << "Map1";
    GoToXy(27, 15);
    cout << "Map2";
    GoToXy(43, 15);
    cout << "Map3";
    GoToXy(0, 30);
    Select = _getch() - 48;
    Map = Maps[Select - 1];
    system("cls");

    for (int i = 0; i < Map.size(); i++)//i=선택한 맵의 크기(방의 수)
    {
        for (int j = 0; j < Map[i].size(); j++)//j=해당 방의 몬스터 수
        {
            cout << "------------------------\n";
            setColor(2);
            cout << Map[i][j]->Kind << " 가 나타났다!\n" << endl;//몬스터 등장
            setColor(15);

            Temp_Mob_P->Hp = Map[i][j]->Hp;
            Temp_Mob_P->Mp = Map[i][j]->Mp;

            while (true)//전투
            {
                if (SoNB_P->Speed > Map[i][j]->Speed)//스피드 비교: 플레이어선공
                {
                    Atk_Menu(SoNB_P, Map[i][j]);//플레이어 턴(선공)
                    if (Map[i][j]->Hp < 0)//몬스터 사망시
                    {
                        cout << "\n" << Map[i][j]->Kind << " 를 물리쳤다!" << endl;
                        Monster_Die(SoNB_P, Map[i][j]);
                        Map[i][j]->Hp = Temp_Mob_P->Hp;
                        Map[i][j]->Mp = Temp_Mob_P->Mp;
                        DropItem = Drop_Item();
                        if (DropItem != "") Pick_Up_Item(Inventory, DropItem);
                        break;//while문 탈출: 전투끝
                    }
                    Mob_Atk(Map[i][j], SoNB_P);//몬스터 턴(후공)
                    if (SoNB_P->Hp < 0) //도중에 캐릭터가 사망시 게임오버 
                    {
                        cout << "Game over..." << endl;
                        SoNB_P->Restat();
                        i = Map.size() - 1; // 변수 i를 올려 for문 탈출
                        return false; 
                        break;//while문 탈출: 전투끝
                    }
                    cout << "------------------------\n";

                }

                else//플레이어의 spd가 mob보다 낮은 경우: 플레이어 후공
                {
                    Mob_Atk(Map[i][j], SoNB_P);//몬스터 턴(선공)
                    if (SoNB_P->Hp < 0) //도중에 캐릭터가 사망시 게임오버 
                    {
                        cout << "Game over..." << endl;
                        SoNB_P->Restat();
                        i = Map.size() - 1; //변수 i를 올려 for문 탈출
                        return false; 
                        break;//while문 탈출: 전투끝
                    }

                    Atk_Menu(SoNB_P, Map[i][j]);//플레이어 턴 (후공)
                    if (Map[i][j]->Hp < 0) //몬스터 사망시
                    {
                        cout << Map[i][j]->Kind << " 를 물리쳤다!" << endl;
                        Monster_Die(SoNB_P, Map[i][j]);
                        Map[i][j]->Hp = Temp_Mob_P->Hp;
                        Map[i][j]->Mp = Temp_Mob_P->Mp;
                        DropItem = Drop_Item();
                        if (DropItem != "") Pick_Up_Item(Inventory, DropItem);
                        break;//while문 탈출: 전투끝
                    }
                    cout << "------------------------\n";
                }
            }
        }
    }
    if (SoNB_P->Hp > 0) cout << "\n\nDungeon clear!\n\n"; //맵을 모두 클리어시 던전 클리어
    return true; //던전클리어시 
}

int main()
{//메뉴 선택
    SetConsoleTitle(TEXT("C++ based RPG GAME"));

    do {
        system("cls");
        //cout << "【 TEST BETA GAME 】\n\n";
        setColor(12);
        Dungeon();
        setColor(15);


        GoToXy(25, 18);
        setColor(10);
        cout << "메뉴를 선택해 주세요 ~ !\n";
        setColor(15);
        GoToXy(27, 19);
        cout << "1.게임시작\n";
        GoToXy(27, 20);
        cout << "2.게임 설명\n";
        GoToXy(27, 21);
        cout << "3.게임 종료\n";

        Menu = _getch() - 48;
        system("cls");
        switch (Menu)
        {
        case 1:
            Gameflag = true;//메인메뉴 --> 맵선택(flase방지)
            while (Gameflag)
            {
                system("cls");
                GoToXy(10, 15);
                cout << "1. 맵 선택";
                GoToXy(27, 15);
                cout << "2. 상점";
                GoToXy(43, 15);
                cout << "3. 메인메뉴\n";
                GoToXy(0, 30);
                Menu = _getch() - 48;
                switch (Menu)
                {
                case 1:
                    Gameflag = Map_Combat();
                    break;
                case 2:
                    Storeflag = true;
                    system("cls");
                    while (Storeflag) Storeflag = Open_Store(Inventory);
                    break;
                case 3:
                    Gameflag = false;
                    GoToXy(0, 30);
                    break;
                default:
                    break;
                }
            }
            break;
        case 2:
            while (true)
            {
                cout << "\n이 게임은 현재 개발 중에 있는 C++ 기반 RPG입니다.\n('0'을 누르면 뒤로갑니다.)";
                Cancel = _getch() - 48;
                system("cls");
                if (Cancel == 0) break;
            }
            break;
        case 3:
            Mainflag = false;
            break;
        default:
            break;
        }
    } while (Mainflag); //메뉴 정석(do while)
}
