#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include "map.h"
#include "inventory.h"
using namespace std;

int Menu;
bool Flag = true; //do while문 탈출조건

typedef struct My_Character { //기본
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

    void Get_Character_Info()//플레이어 상태 출력 
    {
        cout << "HP : " << hp << "\nMP: " << mp << "\n공격력: " << atk << "\n방어력: " << def << endl;
    }
}My_Character;

My_Character SoNB;
My_Character* SoNB_P = &SoNB;

string inventory[5] = { "red potion","red potion","purple potion","purple potion","0" };

void use_item(My_Character* character, string inventory[]) {
    // 아이템을 사용할 때
    int n;

    cout << "인벤토리 목록\n";
    for (int i = 0; i < 5; i++) { cout << i << " : " << inventory[i] << "\n"; }
    cout << "0~4를 제외한 다른 숫자 입력시 아이템 사용이 취소됩니다\n";
    cout << "사용할 아이템의 위치를 입력해주세요\n" << "위치 : ";
    cin >> n;
    if (n >= 0 && n <= 4) {
        if (inventory[n] == "0") { cout << "선택하신 위치에 아이템이 없습니다\n"; }
        else {
            for (int i = 0; i < 14; i++) {   //14는 item배열 크기
                if (inventory[n] == items[i].name) {
                    character->hp += items[i].hp;
                    character->mp += items[i].mp;
                    character->atk += items[i].atk;
                    character->def += items[i].def;
                    character->speed += items[i].speed;
                    inventory[n] = "0";
                    cout << items[i].name << "을 사용했습니다\n";
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
    else { cout << "아이템 사용이 취소되었습니다\n"; }
}

bool skillmenu(My_Character* character, mob* mob, bool atkFlag);
void atkmenu(My_Character* character, mob* mob)//플레이어 공격 메뉴
{
    int choice;//선택
    bool atkFlag = true;//공격함수제어

    double damage;
    while (atkFlag)
    {
        cout << "무엇을 할까...\n1. 공격\n2. 스킬\n3. 가방\n4. 내상태\n5. 적 정보\n6. 도주" << endl; //메뉴
        cin >> choice;
        switch (choice)
        {
        case 1:
            cout << "\n적에게 공격을 가합니다!!\n";
            damage = character->atk - mob->def;
            if (damage < 0) damage = 0;

            mob->hp -= damage;
            cout << "플레이어의 공격!" << endl;
            cout << "플레이어는 " << damage << " 의 피해를 입혔다!" << endl;
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
            //도주
            break;
        default:
            cout << "올바르지 않은 입력" << endl;
            break;
        }
    }

}
bool skillmenu(My_Character* character, mob* mob, bool atkFlag)
{
    int skill_menu;//스킬 선택
    string YN;//스킬 사용 확인
    bool SkillFlag = true;// 스킬메뉴 함수 제어
    double damage;
    while (SkillFlag)
    {
        cout << "SKILL MENU" << endl;
        cout << "1. 파워 슬래시\n2. 스킬2번\n0. 뒤로가기" << endl;
        cin >> skill_menu;
        switch (skill_menu)//스킬
        {
        case 1:
            cout << "공격력: " << character->atk * 1.2 << "\nMP: 100\n사용할까? (Y or else)" << endl;
            cin >> YN;
            if (YN == "Y")
            {
                character->mp -= 20;
                damage = (character->atk * 1.5) - mob->def;
                if (damage < 0) damage = 0;

                mob->hp -= damage;
                cout << "Po슬래시weR!!" << endl;
                cout << "플레이어는 " << damage << " 의 피해를 입혔다!" << endl;
                SkillFlag = false;
                return false;
            }
            break;
        case 2:
			cout << "공격력: "<<character->atk * 3<<" (def무시)"<<"\n-HP: 50%\n사용할까? (Y or else)" << endl;
			cin >> YN;
			if (YN == "Y")
			{
				character->hp = character->hp / 2;
				damage = (character->atk * 3);
				if (damage < 0) damage = 0;

				mob->hp -= damage;
				cout << "JJUGEM의 데스!!!" << endl;
				cout << "플레이어는 " << damage << " 의 피해를 입혔다!" << endl;
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
    //몹 공격력<플레이어 방어력 경우 음수 나오는 상황 배제

    character->hp -= damage;
    cout << mob->kind << " 의 공격!" << endl;
    cout << "플레이어는 " << damage << " 의 피해를 입었다!" << endl;
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
            for (int i = 0; i < map1.size(); i++)
            {
                for (int j = 0; j < map1[i].size(); j++)
                {
                    cout << map1[i][j]->kind << " 가 나타났다!" << endl;//몬스터 등장
                    Temp_mob_P->hp = map1[i][j]->hp;
                    Temp_mob_P->mp = map1[i][j]->mp;

                    while (true)//전투
                    {
                        if (SoNB_P->speed > map1[i][j]->speed)//스피드 비교 
                        {
                            atkmenu(SoNB_P, map1[i][j]);//캐릭터 spd>mob spd 이므로 플레이어 선공
                            if (map1[i][j]->hp < 0)//몬스터 사망시
                            {
                                cout << map1[i][j]->kind << " 를 물리쳤다!" << endl;
                                map1[i][j]->hp = Temp_mob_P->hp;
                                map1[i][j]->mp = Temp_mob_P->mp;
                                break;
                            }
                            mobatk(map1[i][j], SoNB_P);
                            if (SoNB_P->hp < 0) //도중에 캐릭터가 사망시 게임오버 
                            {
                                cout << "Game over..." << endl;
                                i = map1.size() - 1; //한번에 i를 끝인덱스까지 올려서 중첩for문 반복중지
                                break;
                            }

                        }

                        else
                        {
                            mobatk(map1[i][j], SoNB_P);//mob spd> 캐릭터 spd 이므로 mob 선공
                            if (SoNB_P->hp < 0)
                            {
                                cout << "Game over..." << endl;
                                i = map1.size() - 1;
                                break;
                            }

                            atkmenu(SoNB_P, map1[i][j]);
                            if (map1[i][j]->hp < 0)
                            {
                                cout << map1[i][j]->kind << " 를 물리쳤다!" << endl;
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
            cout << "이 게임은 현재 개발 중에 있는 C++ 기반 RPG입니다.\n\n";
            break;
        case 3:
            Flag = false;
            break;
        default:
            cout << "올바른 숫자 입력" << endl;
            break;
        }
    } while (Flag); //메뉴 정석(do while) 
}
