#pragma once
#include <iostream>
#include "monster.h"
#include "inventory.h"
using namespace std;

typedef struct My_Character //플레이어 클래스
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

    void Get_Character_Info()//플레이어 상태 출력 
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
    //몹 공격력<플레이어 방어력 경우 음수 나오는 상황 배제

    Character->Hp -= Damage;
    cout << "【" << Mob->Kind << " 의 공격!】" << endl;
    cout << "플레이어는 " << Damage << " 의 피해를 입었다!\n" << endl;
}

bool Skill_Menu(My_Character* Character, Monster* Mob, bool Atkflag);
bool Inventory_Menu();
void Atk_Menu(My_Character* Character, Monster* Mob)//플레이어턴 메뉴
{
    int Choice; //플레이어 선택 변수
    bool Atkflag = true; //Atk_Menu 함수 제어용 변수
    double Damage; //플레이어의 최종 데미지
    while (Atkflag)
    {
        cout << "무엇을 할까...\n1. 공격\n2. 스킬\n3. 가방\n4. 내상태\n5. 적 정보\n6. 도주" << endl; //기본 메뉴
        cin >> Choice;
        switch (Choice)
        {
        case 1: //기본공격
            cout << "\n적에게 공격을 가합니다!!\n\n";
            Damage = Character->Atk - Mob->Def; //플레이어 데미지 계산 (플레이어Atk - 몬스터def)
            if (Damage < 0) Damage = 0; //예외사항: 데미지 음수일 경우 0으로 계산
            Mob->Hp -= Damage; //최종 데미지 계산
            cout << "【플레이어의 공격!】" << endl;
            cout << "플레이어는 " << Damage << " 의 피해를 입혔다!\n" << endl;
            Atkflag = false;
            break;
        case 2: //스킬사용
            Atkflag = Skill_Menu(Character, Mob, Atkflag);
            break;
        case 3: //가방열기
            Atkflag = Inventory_Menu();
            break;
        case 4: //캐릭터 상태보기
            Character->Get_Character_Info();
            break;
        case 5: //몬스터 상태보기
            Mob->Get_Info();
            break;
        case 6: //미구현
            //도주
            cout << "\n던전에서 도망쳐 나와 게임이 종료됩니다...";
            exit(0);
            break;
        default: //잘못된 변수 입력받을시
            cout << "올바르지 않은 입력" << endl;
            break;
        }
    }
}

bool Skill_Menu(My_Character* Character, Monster* Mob, bool Atkflag)
{
    int Skillmenu;//스킬 선택
    string Skillcheck;//스킬 사용 확인
    bool Skillflag = true;// Skill_Menu 함수 제어용 변수
    double Damage; // 플레이어의 최종 스킬 데미지
    while (Skillflag)
    {
        cout << "------------------------\n" << "SKILL MENU" << endl;
        cout << "1. 파워 슬래시\n2. 죽음의 DEATH\n0. 뒤로가기" << endl;// 스킬 메뉴
        cin >> Skillmenu;
        switch (Skillmenu)
        {
        case 1: //파워 슬래시 
            cout << "\n공격력: " << Character->Atk * 1.2 << "\nMP: 100\n사용할까? (Y or else)" << endl;
            cin >> Skillcheck; //스킬사용 최종확인
            if (Skillcheck == "Y") //스킬사용
            {
                Character->Mp -= 20; //Mp 소모
                Damage = (Character->Atk * 1.5) - Mob->Def; //플레이어 데미지 계산 (플레이어Atk - 몬스터def)
                if (Damage < 0) Damage = 0; //예외사항: 데미지 음수일 경우 0으로 계산
                Mob->Hp -= Damage; //최종 데미지 계산
                cout << "\n【Po슬래시weR!!】" << endl;
                cout << "플레이어는 " << Damage << " 의 피해를 입혔다!\n" << endl;
                Skillflag = false; //Skill_Menu 함수 종료
                return false; //Atkflag=false : Atk_Menu 함수 종료 return
            }
            break;
        case 2: //죽음의 데스
            cout << "\n공격력: " << Character->Atk * 3 << " (def무시)" << "\n-HP: 50%\n사용할까? (Y or else)" << endl;
            cin >> Skillcheck;
            if (Skillcheck == "Y") //스킬사용 최종확인
            {
                Character->Hp = Character->Hp / 2; //Hp소모
                Damage = (Character->Atk * 3); //플레이어 데미지 계산 (플레이어Atk - 몬스터def)
                if (Damage < 0) Damage = 0; //예외사항: 데미지 음수일 경우 0으로 계산
                Mob->Hp -= Damage; //최종 데미지 계산
                cout << "\n【JJUGEM의 데스!!!】" << endl;
                cout << "플레이어는 " << Damage << " 의 피해를 입혔다!\n" << endl;
                Skillflag = false; //Skill_Menu 함수 종료
                return false; //Atkflag=false : Atk_Menu 함수 종료 return
            }
            break;
        case 0: //뒤로가기
            cout << "------------------------\n";
            Skillflag = false; //Skill_Menu 함수 종료
            return true; //Atkflag=ture : Atk_Menu 함수 이어짐
            break;
        }
    }
}

void Use_Item(My_Character* Character, string Inventory[]) {
    // 아이템을 사용할 때
    int n;

    cout << "\n인벤토리 목록\n";
    for (int i = 0; i < 5; i++) { cout << i << " : " << Inventory[i] << "\n"; }
    cout << "\n0~4를 제외한 다른 숫자 입력시 아이템 사용이 취소됩니다\n";
    cout << "사용할 아이템의 위치를 입력해주세요\n" << "위치 : ";
    cin >> n;
    if (n >= 0 && n <= 4) {
        if (Inventory[n] == "0") { cout << "\n선택하신 위치에 아이템이 없습니다\n\n"; }
        else {
            for (int i = 0; i < 14; i++) {   //14는 item배열 크기
                if (Inventory[n] == Items[i].Name) {
                    Character->Hp += Items[i].Hp;
                    Character->Mp += Items[i].Mp;
                    Character->Atk += Items[i].Atk;
                    Character->Def += Items[i].Def;
                    Character->Speed += Items[i].Speed;
                    Inventory[n] = "0";
                    cout << "\n" << Items[i].Name << "을 사용했습니다\n";
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
    else { cout << "아이템 사용이 취소되었습니다\n"; }
}

bool Inventory_Menu()
{
    int Inventorymenu;
    bool Inventoryflag = true;
    int flag;
    while (Inventoryflag)
    {
        cout << "------------------------\n" << "INVENTORY MENU" << endl;
        cout << "1. 아이템 사용\n2. 아이템 설명\n3. 인벤토리 불러오기\n0. 뒤로가기\n";
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
            cout << "다시 입력해 주세요.";
            break;
        }
    }
}