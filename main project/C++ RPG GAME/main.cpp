#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <Windows.h>
#include <conio.h>
#include <mmsystem.h>
#include "map.h"
#include "player.h"
using namespace std;
#pragma comment(lib,"winmm.lib") //음악 사용관련

int Menu; //메인메뉴 선택 변수
int Select; //Map_Combat 함수 선택 변수
int Cancel; //게임설명 탈출용 변수 :0입력으로 탈출
int Amvalue; //Atk_Menu의 리턴값
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
int Dungeon() //DUNGEON 로고
{
    int _kbhit(void);
    int Num;
    int ColorNum = 11;
    while (true)
    {
        if (_kbhit()) { //키보드 눌렸는지 확인
            Num = _getch() - 48;
            break;
        }

		if (Questflag3 == true) {
			GoToXy(26, 5);
			cout << "C L E A R E D ! !";
		}

        setColor(++ColorNum);
        if (ColorNum == 15) ColorNum = 0;

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

        Sleep(715);
    }
    return Num;
}
bool Map_Combat()//맵선택 및 전투
{
    int Roomnum = 0;//방번호
    system("cls");
    GoToXy(10, 15);
    cout << "Ⅰ. 늪 지대";
    GoToXy(27, 15);
    cout << "Ⅱ. 고블린 마을";
    GoToXy(43, 15);
    cout << "Ⅲ. 오크 진지";
    GoToXy(25, 27);
    cout << "아무키 입력 시, 뒤로 갑니다.";
    GoToXy(0, 30);
    Select = _getch() - 48;
    if (Select != 1 && Select != 2 && Select != 3 && Select != 4) return true;
    Map = Maps[Select - 1];
    system("cls");
    History_Reset2();
    if (Map == Maps[0]) PlaySound(TEXT(".\\SoundTrack\\Map1.wav"), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP); //0번맵 음악
    if (Map == Maps[1]) PlaySound(TEXT(".\\SoundTrack\\Map2.wav"), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP); //1번맵 음악
    if (Map == Maps[2]) PlaySound(TEXT(".\\SoundTrack\\Map3.wav"), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP); //2번맵 음악

    while (Roomnum < Map.size())//방이 맵 끝까지 가면 던전 클리어
    {
        for (int Monsternum = 0; Monsternum < Map[Roomnum].size(); Monsternum++)//Monsternum=해당 방의 몬스터 수
        {
            Sleep(100);
            Combat_Ui(SoNB_P, Map[Roomnum][Monsternum]);
            Map_Show(Roomnum, Map.size());
            setColor(2);
            Print_Line(Map[Roomnum][Monsternum]->Kind);
            Print("이(가) 나타났다!");
            setColor(15);
            Print_blank();
            Sleep(1000);

            Temp_Mob_P->Hp = Map[Roomnum][Monsternum]->Hp;
            Temp_Mob_P->Mp = Map[Roomnum][Monsternum]->Mp;
            int Turn = 0; //전투 턴 초기화
            while (true)//전투
            {
                if (SoNB_P->Speed > Map[Roomnum][Monsternum]->Speed)//스피드 비교: 플레이어선공
                {
                    Cursor_Move(0, 11);
                    Amvalue = Atk_Menu(SoNB_P, Map[Roomnum][Monsternum]);//플레이어 턴(선공)
                    if (Amvalue == 1) {
                        Map[Roomnum][Monsternum]->Hp = Temp_Mob_P->Hp;
                        Map[Roomnum][Monsternum]->Mp = Temp_Mob_P->Mp;
                        return true;
                    }
                    if (Map[Roomnum][Monsternum]->Hp <= 0)//몬스터 사망시
                    {
                        Print_Line(Map[Roomnum][Monsternum]->Kind);
                        Print(" 를 물리쳤다!");
                        Print_blank();
                        Monster_Die(SoNB_P, Map[Roomnum][Monsternum]);
                        Map[Roomnum][Monsternum]->Hp = Temp_Mob_P->Hp;
                        Map[Roomnum][Monsternum]->Mp = Temp_Mob_P->Mp;
						Map[Roomnum][Monsternum]->Count++;
                        DropItem = Drop_Item();
                        if (DropItem != "")
                        {
                            Order_Clear2();
                            Pick_Up_Item(Inventory, DropItem);
                        }
                        break;//while문 탈출: 전투끝
                    }
                    Mob_Atk(Map[Roomnum][Monsternum], SoNB_P);//몬스터 턴(후공)
                    if (SoNB_P->Hp <= 0) //도중에 캐릭터가 사망시 게임오버 
                    {
                        system("cls");
                        GoToXy(27, 15);
                        cout << "Game over..." << endl;
                        Sleep(3000);
                        SoNB_P->Restat();
                        Roomnum = Map.size() - 1; // 변수 i를 올려 for문 탈출
                        return false;
                        break;//while문 탈출: 전투끝
                    }
                    Cursor_Move(62, 8);
                    Cursor_Move(0, 11);  //order창으로.
                    Turn++;
                }

                else//플레이어의 spd가 mob보다 낮은 경우: 플레이어 후공
                {
                    //독뎀등 데미지
                    Mob_Atk(Map[Roomnum][Monsternum], SoNB_P);//몬스터 턴(선공)
                    Sleep(1000);
                    if (SoNB_P->Hp <= 0) //도중에 캐릭터가 사망시 게임오버 
                    {
                        system("cls");
                        GoToXy(27, 15);
                        cout << "Game over..." << endl;
                        Sleep(3000);
                        SoNB_P->Restat();
                        Roomnum = Map.size() - 1; //변수 i를 올려 for문 탈출
                        return false;
                        break;//while문 탈출: 전투끝
                    }

                    Amvalue = Atk_Menu(SoNB_P, Map[Roomnum][Monsternum]);//플레이어 턴 (후공)
                    if (Amvalue == 1) {
                        Map[Roomnum][Monsternum]->Hp = Temp_Mob_P->Hp;
                        Map[Roomnum][Monsternum]->Mp = Temp_Mob_P->Mp;
                        return true;
                    }
                    if (Map[Roomnum][Monsternum]->Hp <= 0) //몬스터 사망시
                    {
                        Print_Line(Map[Roomnum][Monsternum]->Kind);
                        Print(" 를 물리쳤다!");
                        Monster_Die(SoNB_P, Map[Roomnum][Monsternum]);
                        Map[Roomnum][Monsternum]->Hp = Temp_Mob_P->Hp;
                        Map[Roomnum][Monsternum]->Mp = Temp_Mob_P->Mp;
						Map[Roomnum][Monsternum]->Count++;
                        DropItem = Drop_Item();
                        if (DropItem != "") Pick_Up_Item(Inventory, DropItem);
                        break;//while문 탈출: 전투끝
                    }
                    Turn++;
                }
                Combat_Ui(SoNB_P, Map[Roomnum][Monsternum]);
            }
        }
        Roomnum = Empty_Room(SoNB_P, Roomnum);
    }
    if (SoNB_P->Hp > 0) {
        system("cls");
        GoToXy(27, 15);
        cout << "Dungeon clear!!!";
        Sleep(3000);
    }//맵을 모두 클리어시 던전 클리어
    PlaySound(NULL, 0, 0); //음악 종료
    return true; //던전클리어시 
}

int main()
{//메뉴 선택
    SetConsoleTitle(TEXT("C++ based RPG GAME"));

    do {
		Create_Quest(Quest_slot);
        PlaySound(NULL, 0, 0); //음악 초기화(종료)
        PlaySound(TEXT(".\\SoundTrack\\Main.wav"), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP); //초기화면 음악 ON
        system("cls");
        //cout << "【 TEST BETA GAME 】\n\n";
        GoToXy(23, 18);
        setColor(10);
        cout << "!!! ~ 메뉴를 선택해 주세요 ~ !!!\n";
        setColor(15);
        GoToXy(27, 19);
        cout << "1.게임 시작\n";
        GoToXy(27, 20);
        cout << "2.게임 설명\n";
        GoToXy(27, 21);
        cout << "3.게임 종료\n";

        Menu = Dungeon();
        system("cls");
        setColor(15);
        switch (Menu)
        {
        case 1:
            Gameflag = true;//메인메뉴 --> 맵선택(flase방지)
            while (Gameflag)
            {
				if (Questflag2 == true) {
					Gameflag = false;
					Questflag2 = false;
					Questflag3 = true;
					break;
				}

                PlaySound(NULL, 0, 0); //음악 초기화(종료)
                PlaySound(TEXT(".\\SoundTrack\\Village.wav"), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP); //메인메뉴 음악 ON

                system("cls");
                GoToXy(10, 15);
                cout << "1. 맵 선택";
                GoToXy(27, 15);
                cout << "2. 상점 & 퀘스트";
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
                    PlaySound(NULL, 0, 0); //음악 초기화(종료)
                    PlaySound(TEXT(".\\SoundTrack\\Store.wav"), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP); //상점 음악 ON
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
                cout << "DUNGEON은 C++ 기반 RPG game입니다.\n";
                cout << "\n<";
                setColor(10);
                cout << "맵 & 전투방식";
                setColor(15);
                cout << "> ";
                cout << "\n총 3개의 맵으로 구성되어, 맵 상의 몬스터들과 전투해 나가는 방식입니다.\n";
                cout << "하나의 맵은 총 5개의 방으로 이루어져 각각 1~2마리의 몬스터가 등장합니다.\n";
                cout << "마지막 5번째 방에는 보스가 등장합니다.\n\n";

                cout << "전투는 간단하게 공격, 스킬 메뉴를 선택하여 진행합니다.\n";
                cout << "캐릭터, 몬스터 스텟인 SPEED는 선제공격의 결정 요소가 됩니다.\n";
                cout << "(즉, SPEED 스텟이 더 높은 쪽이 선제공격을 가져갑니다.)\n";
                cout << "\n전투도중 가방 내에서 소비 아이템을 사용하거나 도주함으로써, 위험한 상황을 모면할 수 있습니다.\n\n";

                cout << "<";
                setColor(10);
                cout << "인벤토리 & 상점";
                setColor(15);
                cout << ">";
                cout << "\n몬스터는 사망 시에, 아이템을 드랍하게 되는데 드랍한 아이템을 가방에 보관할 수 있으며,\n";
                cout << "가방은 최대 5개의 아이템(소비&장비)만을 수용합니다. 장비는 가방 내에서 착용&해제가 가능합니다.\n\n";
                cout << "상점에서는 총 5개의 아이템이 진열되는데, 5번째 아이템은 Gacha(가챠)로 랜덤 뽑기가 가능합니다.\n\n";

                cout << "<";
                setColor(10);
                cout << "클리어 조건";
                setColor(15);
                cout << ">";
                cout << "\n모든 메인 퀘스트 클리어 시, 게임도 클리어 됩니다. 다만, 캐릭터 사망 시 게임오버 됩니다.\n";
                cout << "퀘스트 완료는 '상점 & 퀘스트'에서 할 수 있습니다.\n\n";

                cout << "'0'을 누르면 뒤로갑니다.";
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
