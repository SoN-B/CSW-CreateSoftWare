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
        cout << "HP : " << Hp << "\nMP: " << Mp << "\n공격력: " << Atk << "\n방어력: " << Def << endl;
    }
}My_Character;

void Atk_Menu(My_Character* Character, mob* Mob)//플레이어턴 메뉴
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
            cout << "\n적에게 공격을 가합니다!!\n";
            Damage = Character->Atk - Mob->def; //플레이어 데미지 계산 (플레이어Atk - 몬스터def)
            if (Damage < 0) Damage = 0; //예외사항: 데미지 음수일 경우 0으로 계산
            Mob->hp -= Damage; //최종 데미지 계산
            cout << "플레이어의 공격!" << endl;
            cout << "플레이어는 " << Damage << " 의 피해를 입혔다!" << endl;
            Atkflag = false;
            break;
        case 2: //스킬사용
            Atkflag = Skill_Menu(Character, Mob, Atkflag);
            break;
        case 3: //가방열기
            Atkflag = inventorymenu();
            break;
        case 4: //캐릭터 상태보기
            Character->Get_Character_Info();
            break;
        case 5: //몬스터 상태보기
            Mob->GetInfo();
            break;
        case 6: //미구현
            //도주
            break;
        default: //잘못된 변수 입력받을시
            cout << "올바르지 않은 입력" << endl;
            break;
        }
    }
}

bool Skill_Menu(My_Character* Character, mob* Mob, bool Atkflag)
{
    int Skillmenu;//스킬 선택
    string Skillcheck;//스킬 사용 확인
    bool Skillflag = true;// Skill_Menu 함수 제어용 변수
    double Damage; // 플레이어의 최종 스킬 데미지
    while (Skillflag)
    {
        cout << "SKILL MENU" << endl;
        cout << "1. 파워 슬래시\n2. 죽음의 DEATH\n0. 뒤로가기" << endl;// 스킬 메뉴
        cin >> Skillmenu;
        switch (Skillmenu)
        {
        case 1: //파워 슬래시 
            cout << "공격력: " << Character->Atk * 1.2 << "\nMP: 100\n사용할까? (Y or else)" << endl;
            cin >> Skillcheck; //스킬사용 최종확인
            if (Skillcheck == "Y") //스킬사용
            {
                Character->Mp -= 20; //Mp 소모
                Damage = (Character->Atk * 1.5) - Mob->def; //플레이어 데미지 계산 (플레이어Atk - 몬스터def)
                if (Damage < 0) Damage = 0; //예외사항: 데미지 음수일 경우 0으로 계산
                Mob->hp -= Damage; //최종 데미지 계산
                cout << "Po슬래시weR!!" << endl;
                cout << "플레이어는 " << Damage << " 의 피해를 입혔다!" << endl;
                Skillflag = false; //Skill_Menu 함수 종료
                return false; //Atkflag=false : Atk_Menu 함수 종료 return
            }
            break;
        case 2: //죽음의 데스
            cout << "공격력: " << Character->Atk * 3 << " (def무시)" << "\n-HP: 50%\n사용할까? (Y or else)" << endl;
            cin >> Skillcheck;
            if (Skillcheck == "Y") //스킬사용 최종확인
            {
                Character->Hp = Character->Hp / 2; //Hp소모
                Damage = (Character->Atk * 3); //플레이어 데미지 계산 (플레이어Atk - 몬스터def)
                if (Damage < 0) Damage = 0; //예외사항: 데미지 음수일 경우 0으로 계산
                Mob->hp -= Damage; //최종 데미지 계산
                cout << "JJUGEM의 데스!!!" << endl;
                cout << "플레이어는 " << Damage << " 의 피해를 입혔다!" << endl;
                Skillflag = false; //Skill_Menu 함수 종료
                return false; //Atkflag=false : Atk_Menu 함수 종료 return
            }
            break;
        case 0: //뒤로가기
            Skillflag = false; //Skill_Menu 함수 종료
            return true; //Atkflag=ture : Atk_Menu 함수 이어짐
            break;
        }
    }
}