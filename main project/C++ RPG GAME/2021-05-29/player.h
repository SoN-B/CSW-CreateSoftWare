#pragma once
#include <iostream>
#include "monster.h"
using namespace std;

typedef struct My_Character //플레이어 클래스
{
	double Hp, Mp, Atk, Def, Speed, Level = 1, Exp = 0, Max_Exp = 100, Money = 0;

	My_Character(double Hp = 200, double Mp = 100, double Atk = 50, double Def = 5, 
		double Speed = 1.5, double Money = 1000)
	{
		this->Hp = Hp;
		this->Mp = Mp;
		this->Atk = Atk;
		this->Def = Def;
		this->Speed = Speed;
		this->Money = Money;
	}

	void Get_Character_Info()//플레이어 상태 출력 
	{
		cout << "\Level : " << Level << "\nMax Exp/Exp : "<< Max_Exp << "/" << Exp
			<< "\nHP : " << Hp << "\nMP: " << Mp << "\nATK: " << Atk << "\nDEF: " << Def 
			<<"\nMoney : " << Money << " Coin"<< endl;
		cout << "------------------------\n";
	}

	void Level_Plus()
	{
		this->Level += 1;
		this->Exp = this->Exp - this->Max_Exp;
		this->Max_Exp = this->Max_Exp + (this->Max_Exp * 0.5);
		this->Hp += 50;
		this->Mp += 25;
		this->Atk += 10;
		this->Def += 5;
		this->Speed += 0.1;
	}

	void Exp_Plus(double a)
	{
		this->Exp += a - rand() % 50;
	}
	void Pick_UP_Money(double a)
	{
		this->Money += a - rand() % 50;
	}
	void Restat()
	{
		this->Hp = 200;
		this->Mp = 100;
		this->Atk = 50;
		this->Def = 5;
		this->Speed = 1.5;
		this->Level = 1;
		this->Exp = 0;
		this->Max_Exp = 100;
		this->Money = 0;
	}
}My_Character;
My_Character SoNB;
My_Character* SoNB_P = &SoNB;

class Skill //스킬 클래스
{
public:
    string Skillname;
    double Usedhp, Usedmp, Healhp, Healmp, Multiples, Static;
    Skill()
    {
        Skillname = "";
    }
    Skill(string Skillname,double Usedhp,double Usedmp,double Healhp,double Healmp,double Multiples, double Static)
    {
        this->Skillname = Skillname; //스킬이름
        this->Usedhp = Usedhp; //사용되는 Hp
        this->Usedmp = Usedmp; //사용되는 Mp
        this->Healhp = Healhp; // 효과로 받는 Hp
        this->Healmp = Healmp; // 효과로 받는 Mp
        this->Multiples = Multiples; // 배수 데미지
        this->Static = Static; // 고정데미지 
    }
    void Use_Skill(My_Character* Character, Monster* Mob, Skill Skill);
    void Skill_Info(My_Character* Character, Skill Skill);
};

void Skill::Use_Skill(My_Character* Character, Monster* Mob, Skill Skill)//스킬 사용 함수
{
    double Damage=0;//데미지 초기화
    cout << "----------------\n스킬사용! " << Skill.Skillname << endl;
    Character->Hp -= Skill.Usedhp;//체력 소모
    Character->Mp -= Skill.Usedmp;//마나 소모
    if (Skill.Healhp != 0 )//체력 회복
    {
        Character->Hp += Skill.Healhp;//체력 회복
        cout << "플레이어는 " << Skill.Healhp << " 의 체력을 회복했다!" << endl;
    }
	if (Skill.Healmp != 0)//마나 회복
	{
		Character->Hp += Skill.Healmp;//체력 회복
		cout << "플레이어는 " << Skill.Healmp << " 의 마나를 회복했다!" << endl;
	}
    }
    if (Skill.Multiples != 0 || Skill.Static != 0)//공격 관련 경우
    {
        if (Skill.Multiples != 0) { Damage = (Character->Atk * Skill.Multiples) - Mob->Def; }//배수 데미지 계산
        if (Skill.Static != 0) { Damage = Skill.Static - Mob->Def; }//고정 데미지 계산
        if (Damage < 0) { Damage = 0; }//예외사항: 데미지 음수일 경우 0으로 계산
        Mob->Hp -= Damage;//최종 데미지 계산
        cout << "플레이어는 " << Damage << " 의 데미지를 입혔다!" << endl;
    }
}

void Skill::Skill_Info(My_Character* Character, Skill Skill)//스킬 정보 함수
{//해당 스킬에 관련된 정보만 전달
    cout << "-------------------\n스킬: " << Skill.Skillname << endl;
    if (Skill.Usedhp != 0) { cout << "소모 HP: " << Skill.Usedhp << endl; }
    if (Skill.Usedmp != 0) { cout << "소모 MP: " << Skill.Usedmp << endl; }
    if (Skill.Healhp != 0) { cout << "회복 HP: " << Skill.Healhp << endl; }
    if (Skill.Healmp != 0) { cout << "회복 MP: " << Skill.Healmp << endl; }
    if (Skill.Multiples != 0) 
    { 
        cout << "적에게 " << Character->Atk << " * " << Skill.Multiples << " 만큼의 데미지를 입힌다.\n현재 데미지: " << Character->Atk * Skill.Multiples << endl;
    }
    if (Skill.Static != 0) { cout << "적에게 " << Skill.Static << " 만큼의 데미지를 입힌다." << endl; }
}
//이하 스킬 구현
Skill Power_Slash("파워 슬래시", 0.0, 20.0, 0.0, 0.0, 1.2, 0.0);//마나20소모, 데미지1.2배
Skill Blood_Slash("블러드 슬래시", 100, 0, 0, 0, 0, 150);//체력100소모, 150데미지
Skill Mind_Fuel("회광반조", 0, 30, 15, 0, 0, 0);//마나 30소모, 체력15회복
Skill Prayer("기도", 0, 0, 0, 20, 0, 0);//소모없음, 마나20회복
//플레이어의 스킬창 기본값
Skill Skill_Arry[4] = { Power_Slash,Blood_Slash,Mind_Fuel,Prayer };

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
		for (int i = 0; i < 4; i++) { cout << i + 1 << ". " << Skill_Arry[i].Skillname << endl; }// 스킬 메뉴
		cout << "0. 뒤로가기" << endl;
		cin >> Skillmenu;
		if (Skillmenu == 0)
		{
			cout << "------------------------\n";
			Skillflag = false; //Skill_Menu 함수 종료
			return true; //Atkflag=ture : Atk_Menu 함수 이어짐
		}
		if (Skillmenu >= 1 && Skillmenu <= 4)
		{
			Skill_Arry[Skillmenu - 1].Skill_Info(Character, Skill_Arry[Skillmenu - 1]);//스킬정보 출력
			cout << Skill_Arry[Skillmenu - 1].Skillname << " 를 사용할까? (Y or else)" << endl;
			cin >> Skillcheck; //스킬사용 최종확인
			if (Skillcheck == "Y")//스킬 사용 확인시
			{
				Skill_Arry[Skillmenu - 1].Use_Skill(Character, Mob, Skill_Arry[Skillmenu - 1]);//스킬사용
				Skillflag = false; //Skill_Menu 함수 종료
				return false; //Atkflag=false : Atk_Menu 함수 종료 return
			}
		}
	}
}

void Monster_Die(My_Character* a, Monster* b)
{
	a->Pick_UP_Money(b->Money);
	SoNB_P->Exp_Plus(b->Exp);
	if (SoNB_P->Exp > SoNB_P->Max_Exp)
	{
		SoNB_P->Level_Plus();
	}
}

int Get_Money()
{
	return SoNB_P->Money;
}
