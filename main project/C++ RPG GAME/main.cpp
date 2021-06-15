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

        Sleep(700);
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
    if (Select != 1 && Select != 2 && Select != 3) return true;
    Map = Maps[Select - 1];
    system("cls");

    if (Map == Maps[0]) PlaySound(TEXT(".\\SoundTrack\\Map1.wav"), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP); //0번맵 음악
    if (Map == Maps[1]) PlaySound(TEXT(".\\SoundTrack\\Map2.wav"), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP); //1번맵 음악
    if (Map == Maps[2]) PlaySound(TEXT(".\\SoundTrack\\Map3.wav"), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP); //2번맵 음악

    while (Roomnum < Map.size())//방이 맵 끝까지 가면 던전 클리어
    {
        for (int Monsternum = 0; Monsternum < Map[Roomnum].size(); Monsternum++)//Monsternum=해당 방의 몬스터 수
        {
            Combat_Ui(SoNB_P, Map[Roomnum][Monsternum]);
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
                    //독뎀등 턴수에따른 데미지계산
                    Cursor_Move(58, 8);
                    cout << "※";        //player의 턴을 나타냄.
                    Cursor_Move(62, 8);
                    cout << "□";        //monster의 턴 끝남

                    Cursor_Move(0, 11);
                    Amvalue = Atk_Menu(SoNB_P, Map[Roomnum][Monsternum]);//플레이어 턴(선공)
                    if (Amvalue == 1) return true;
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
                    Cursor_Move(58, 8);
                    cout << "□";        //player의 턴 끝남.
                    Cursor_Move(62, 8);
                    cout << "※";        //monster의 턴을 나타냄.
                    Mob_Atk(Map[Roomnum][Monsternum], SoNB_P);//몬스터 턴(후공)
                    if (SoNB_P->Hp <= 0) //도중에 캐릭터가 사망시 게임오버 
                    {
                        cout << "Game over..." << endl;
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
                    if (SoNB_P->Hp <= 0) //도중에 캐릭터가 사망시 게임오버 
                    {
                        cout << "Game over..." << endl;
                        SoNB_P->Restat();
                        Roomnum = Map.size() - 1; //변수 i를 올려 for문 탈출
                        return false;
                        break;//while문 탈출: 전투끝
                    }

                    Amvalue = Atk_Menu(SoNB_P, Map[Roomnum][Monsternum]);//플레이어 턴 (후공)
                    if (Amvalue == 1) return true;
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
                    cout << "------------------------\n";
                    Turn++;
                }
            }
        }
        Roomnum = Empty_Room(SoNB_P, Roomnum);
    }
    if (SoNB_P->Hp > 0) cout << "\n\nDungeon clear!\n\n"; //맵을 모두 클리어시 던전 클리어
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

        Menu = Dungeon();
        system("cls");
        setColor(15);
        switch (Menu)
        {
        case 1:
            Gameflag = true;//메인메뉴 --> 맵선택(flase방지)
            while (Gameflag)
            {
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
