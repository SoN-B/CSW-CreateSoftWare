#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include "map.h"
#include "invectory.h"
using namespace std;

int Menu;
bool Flag = true; //do while문 탈출조건

typedef struct My_Character { //기본
	float hp, mp, atk, def, speed;

	My_Character(int hp = 200, int mp = 100, int atk = 50, int def = 30, int speed = 1.5)
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

void atkmenu(My_Character character, mob mob)//플레이어 공격 메뉴
{
	int choice;//선택
	bool atkFlag = true;//공격함수제어
	while (atkFlag)
	{
		cout << "무엇을 할까...\n1. 공격\n2. 스킬\n3. 가방\n4. 내상태\n5. 적 정보\n6. 도주" << endl; //메뉴
		cin >> choice;
		switch (choice)
		{
		case 1:
			//공격
			atkFlag = false;
			break;
		case 2:
			//스킬
			atkFlag = false;
			break;
		case 3:
			//인벤토리
			break;
		case 4:
			character.Get_Character_Info();
			break;
		case 5:
			mob.GetInfo();
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

void mobatk(mob mob, My_Character character)
{
	float damage=character.hp-(mob.atk - character.def);
	if (damage<0)//몹 공격력<플레이어 방어력 경우 음수 나오는 상황 배제
	{
		damage = 0;
	}
	character.hp -= damage;
	cout << mob.kind << " 의 공격!" << endl;
	cout << "플레이어는 " << damage << " 의 피해를 입었다!" << endl;
}

int main()
{//메뉴 선택
	My_Character SoNB;
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
					cout << map1[i][j].kind << " 가 나타났다!" << endl;//몬스터 등장
					while (true)//전투
					{
						if (SoNB.speed > map1[i][j].speed)//스피드 비교 
						{
							atkmenu(SoNB, map1[i][j]);//캐릭터 spd>mob spd 이므로 플레이어 선공
							if (map1[i][j].hp==0)//몬스터 사망시
							{
								cout << map1[i][j].kind << " 를 물리쳤다!" << endl;
								break;
							}
							mobatk(map1[i][j], SoNB);
							if (SoNB.hp == 0) //도중에 캐릭터가 사망시 게임오버 
							{
								cout << "Game over..." << endl;
								i = map1.size(); //한번에 i를 끝인덱스까지 올려서 중첩for문 반복중지
								break;
							}

						}

						else
						{
							mobatk(map1[i][j], SoNB);//mob spd> 캐릭터 spd 이므로 mob 선공
							if (SoNB.hp == 0) 							
							{
								cout << "Game over..." << endl;
								i = map1.size();
								break;
							}

							atkmenu(SoNB, map1[i][j]);
							if (map1[i][j].hp == 0)
							{
								cout << map1[i][j].kind << " 를 물리쳤다!" << endl;
								break;
							}
						}
					}
				}
				
			}
			if (!SoNB.hp == 0) cout << "Congratulations! Game clear!\n\n";
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
