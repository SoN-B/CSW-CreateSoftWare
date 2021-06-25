#pragma once
#include <iostream>
#include <conio.h>
#include <Windows.h>
#include <vector>
#include "Ui.h"
#include "inventory.h"
using namespace std;


void My_Character::Get_Character_Info_Left()
{
	Cursor_Move(0, 0);
	setColor(8);
	cout << "Level";
	setColor(15);
	cout << ": " << Level;

	setColor(6);
	cout << "\nMax Exp/Exp";
	setColor(15);
	cout << ": " << Max_Exp << "/" << Exp;

	setColor(4);
	cout << "\nHP";
	setColor(15);
	cout << ": " << Hp;

	setColor(9);
	cout << "\nMP";
	setColor(15);

	cout << " : " << Mp << "\nATK : " << Atk << "\nDEF : " << Def << "\nSPEED : " << Speed;

	setColor(14);
	cout << "\nMoney";
	setColor(15);

	cout << " : " << Money << " Coin" << endl << endl;
}

class Skill //스킬 클래스
{
public:
	string Skillname;
	double Usedhp, Usedmp, Healhp, Healmp, Multiples, Static,Turn;
	Skill()
	{
		Skillname = "";
	}
	Skill(string Skillname, double Usedhp, double Usedmp, double Healhp, double Healmp, double Multiples, double Static,int Turn)
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
	void Skill_Change(My_Character* Character, Skill Skill);
};

void Skill::Use_Skill(My_Character* Character, Monster* Mob, Skill Skill)//스킬 사용 함수
{
	double Damage = 0;//데미지 초기화
	//cout << "----------------\n스킬사용! " << Skill.Skillname << endl;
	setColor(14);
	Print_Line("스킬사용! ");
	setColor(15);
	Print_Line(Skill.Skillname);
	Print("!");
	Character->Hp -= Skill.Usedhp;//체력 소모
	Character->Mp -= Skill.Usedmp;//마나 소모
	if (Skill.Healhp != 0)//체력 회복
	{
		Character->Hp += Skill.Healhp;//체력 회복
		Print_Line("플레이어는 ");
		setColor(10);
		Print_Double(Skill.Healhp);
		setColor(15);
		Print(" 의 체력을 회복했다!");
	}
	if (Skill.Healmp != 0)//마나 회복
	{
		Character->Mp += Skill.Healmp;//체력 회복
		//cout << "플레이어는 " << Skill.Healmp << " 의 마나를 회복했다!" << endl;
		Print_Line("플레이어는 ");
		setColor(9);
		Print_Double(Skill.Healmp);
		setColor(15);
		Print(" 의 마나를 회복했다!");
	}
	if (Skill.Multiples != 0 || Skill.Static != 0)//공격 관련 경우
	{
		if (Skill.Multiples != 0) { Damage = (Character->Atk * Skill.Multiples) - Mob->Def; }//배수 데미지 계산
		if (Skill.Static != 0) { Damage = Skill.Static - Mob->Def; }//고정 데미지 계산
		if (Damage < 0) { Damage = 0; }//예외사항: 데미지 음수일 경우 0으로 계산
		Mob->Hp -= Damage;//최종 데미지 계산
		//cout << "플레이어는 " << Damage << " 의 데미지를 입혔다!" << endl;
		Print_Line("플레이어는 ");
		setColor(12);
		Print_Double(Damage);
		setColor(15);
		Print(" 의 데미지를 입혔다!");
		Print_blank();
	}
}

void Skill::Skill_Info(My_Character* Character, Skill Skill)//스킬 정보 함수
{//해당 스킬에 관련된 정보만 전달
	cout << "-------------------\n스킬: " << Skill.Skillname << endl;
	if (Skill.Usedhp != 0) {
		cout << "소모 HP: ";

		setColor(4);
		cout << Skill.Usedhp << endl;
		setColor(15);
	}
	if (Skill.Usedmp != 0) {
		cout << "소모 MP: ";

		setColor(9);
		cout << Skill.Usedmp << endl;
		setColor(15);
	}
	if (Skill.Healhp != 0) {
		cout << "회복 HP: ";

		setColor(4);
		cout << Skill.Healhp << endl;
		setColor(15);
	}
	if (Skill.Healmp != 0) {
		cout << "회복 MP: ";

		setColor(9);
		cout << Skill.Healmp << endl;
		setColor(15);
	}
	if (Skill.Multiples != 0)
	{
		cout << "적에게 ";

		setColor(12);
		cout << Character->Atk << " * " << Skill.Multiples;
		setColor(15);


		cout << " 만큼의 데미지를 입힌다.\n";
		cout << "현재 데미지: ";

		setColor(12);
		cout << Character->Atk * Skill.Multiples << endl;
		setColor(15);
	}
	if (Skill.Static != 0) {
		cout << "적에게 ";

		setColor(12);
		cout << Skill.Static;
		setColor(15);

		cout << " 만큼의 데미지를 입힌다." << endl;
	}
}
//이하 스킬 구현

//	 skill 변수("스킬이름",사용hp,사용mp,상승Hp,상승Mp,데미지계수,데미지)
Skill GOD_ATK("한방딜",0, 0, 0, 0, 0, 500, 0);
Skill Power_Slash("파워 슬래시", 0, 20, 0.0, 0.0, 1.2, 0.0, 0);//마나20소모, 데미지1.2배
Skill Blood_Slash("블러드 슬래시", 100, 0, 0, 0, 0, 150, 0);//체력100소모, 150데미지
Skill Mind_Fuel("회광반조", 0, 30, 15, 0, 0, 0, 0);//마나 30소모, 체력15회복
Skill Prayer("기도", 0, 0, 0, 20, 0, 0, 0);//소모없음, 마나20회복
Skill Fire_bolt("파이어볼트", 0, 15, 0, 0, 0, 75, 0);//마나15소모, 75데미지, 2레벨 해금
Skill Power_Slash2("파워 슬래시Ⅱ", 0, 50, 0, 0, 1.35, 0, 0);//마나50소모, 1.35배 데미지, 3레벨 해금
//플레이어의 스킬창 기본값

Skill Skill_Array[4] = { Power_Slash,GOD_ATK,Mind_Fuel,Prayer };
vector<Skill>Skill_Tree = { Power_Slash,Blood_Slash,Mind_Fuel,Prayer };//스킬트리

void Mob_Atk(Monster* Mob, My_Character* Character)
{
	Monster_Turn();
	Sleep(75);
	double Damage = Mob->Atk - Character->Def;
	if (Damage < 0) Damage = 0;
	//몹 공격력<플레이어 방어력 경우 음수 나오는 상황 배제

	Character->Hp -= Damage;
	Monster_Attack_Result(Mob, Damage);
	//Status_Reset();
	Combat_Ui(Character, Mob);
}

bool Skill_Menu(My_Character* Character, Monster* Mob, bool Atkflag);
bool Inventory_Menu();
int Atk_Menu(My_Character* Character, Monster* Mob)//플레이어턴 메뉴
{
	int Choice; //플레이어 선택 변수
	bool Atkflag = true; //Atk_Menu 함수 제어용 변수
	double Damage; //플레이어의 최종 데미지
	while (Atkflag)
	{
		//Cursor_Pos_Start();
		Cursor_Pos_Start();
		Cursor_Move(0, Order_Y);
		cout << "무엇을 할까...\n1. 공격\n2. 스킬\n3. 가방\n4. 퀘스트\n5. 도주" << endl; //기본 메뉴
		Choice = _getch()-48;
		switch (Choice)
		{
		case 1: //기본공격
			setColor(12);
			Print("적에게 공격을 가합니다.!");
			setColor(15);
			Print_blank();

			Damage = Character->Atk - Mob->Def; //플레이어 데미지 계산 (플레이어Atk - 몬스터def)
			if (Damage < 0) Damage = 0; //예외사항: 데미지 음수일 경우 0으로 계산
			Mob->Hp -= Damage; //최종 데미지 계산
			Player_Attack_Result(Damage);
			Atkflag = false;
			break;
		case 2: //스킬사용
			Atkflag = Skill_Menu(Character, Mob, Atkflag);
			break;
		case 3: //가방열기
			Atkflag = Inventory_Menu();
			break;
		case 4: //진행중인 퀘스트
			Look_Quest();
			break;
		case 5: //도주
			Print("던전에서 도망쳐 나옵니다...");
			Sleep(2000);
			return 1;
			break;
		default: //잘못된 변수 입력받을시
			Print("올바르지 않은 입력");
			Cursor_Pos_End();
			Order_Clear();
			break;
		}
	}
	//여기에 Player의 UI랑 monster의 UI 갱신 부분이 들어가야함.
	//Status_Reset();
	Combat_Ui(Character, Mob);
}

bool Skill_Menu(My_Character* Character, Monster* Mob, bool Atkflag)
{
	int Skillmenu;//스킬 선택
	string Skillcheck;//스킬 사용 확인
	bool Skillflag = true;// Skill_Menu 함수 제어용 변수
	double Damage; // 플레이어의 최종 스킬 데미지
	while (Skillflag)
	{
		setColor(10);
		cout << "SKILL MENU" << endl;
		setColor(15);

		for (int i = 0; i < 4; i++) { cout << i + 1 << ". " << Skill_Array[i].Skillname << endl; }//스킬창에 있는 스킬이름들을 출력
		cout << "0. 뒤로가기" << endl;//0번 입력시 뒤로가기 출력
		Skillmenu = _getch() - 48;

		if (Skillmenu == 0)
		{
			Order_Clear2();
			Skillflag = false; //Skill_Menu 함수 종료
			return true; //Atkflag=true : 플레이어 턴 유지
		}
		if (Skillmenu >= 1 && Skillmenu <= 4)
		{
			Skill_Array[Skillmenu - 1].Skill_Info(Character, Skill_Array[Skillmenu - 1]);//스킬정보 출력
			cout << Skill_Array[Skillmenu - 1].Skillname << " 를 사용할까? (Y or else)" << endl;
			Skillcheck = _getch();
			Cursor_Pos_End();
			if (Skillcheck == "Y" || Skillcheck == "y")//스킬 사용 확인시
			{
				if (Character->Hp - Skill_Array[Skillmenu - 1].Usedhp <= 0)//스킬 사용시 HP가 0이하가 되는경우 방지
				{
					setColor(12);
					Print("HP가 모자랍니다.");
					setColor(15);
					Print_blank();
					Order_Clear2();
					Skillflag = false;//Skill_Menu 함수 종료
					return true;//Atkflag=true : 플레이어 턴 유지
				}
				if (Character->Mp - Skill_Array[Skillmenu - 1].Usedmp < 0)//스킬 사용시 MP가 0미만이 되는경우 방지
				{
					setColor(12);
					Print("MP가 모자랍니다.");
					setColor(15);
					Print_blank();
					Order_Clear2();
					Skillflag = false;//Skill_Menu 함수 종료
					return true;//Atkflag=true : 플레이어 턴 유지
				}
				Skill_Array[Skillmenu - 1].Use_Skill(Character, Mob, Skill_Array[Skillmenu - 1]);//스킬사용
				Order_Clear();
				Skillflag = false; //Skill_Menu 함수 종료
				return false; //Atkflag=false : 플레이어 턴 종료
			}
			else
			{
				Order_Clear();
				Skillflag = false;
				return true;
			}
		}
	}
}

int Empty_Room(My_Character* Character,int Roomnum)
{
	string Skillcheck;//스킬 선택 확인
	int Choice; //플레이어 선택 변수
	bool Roomflag = true; //Empty_Room 함수 제어용 변수
	int Skillmenu = 0;;//스킬 선택
	while (Roomflag)
	{
		Order_Clear();
		Cursor_Move(0, Order_Y);
		Cursor_Pos_Start();
		cout << "무엇을 할까...\n1. 다음방으로 이동\n2. 스킬설정\n3. 가방\n4. 퀘스트\n5. 도주" << endl; //기본 메뉴
		Cursor_Pos_End();
		Choice = _getch() - 48;
		switch (Choice)
		{
		case 1: //다음 방으로 이동
			Print("다음방으로 이동합니다...");
			Sleep(1000);
			clear();
			Roomnum++;
			Order_Clear();
			Roomflag = false;
			return Roomnum;
			break;
		case 2: //스킬관련 미완
			setColor(10);
			cout << "SKILL MENU" << endl;
			setColor(15);

			for (int i = 0; i < 4; i++) { cout << i + 1 << ". " << Skill_Array[i].Skillname << endl; }//스킬창에 있는 스킬이름들을 출력
			cout << "0. 뒤로가기" << endl;//0번 입력시 뒤로가기 출력
			Skillmenu = _getch() - 48;
			if (Skillmenu == 0)
			{
				Order_Clear2();
				break;
			}
			if (Skillmenu >= 1 && Skillmenu <= 4)
			{
				Order_Clear2();
				Skill_Array[Skillmenu - 1].Skill_Info(Character,Skill_Array[Skillmenu-1]);
				cout << "교체하시겟습니까?(Y or else)" <<endl;
				Skillcheck = _getch();
				if (Skillcheck == "Y" || Skillcheck == "y")
				{
					for (int Skillint = 0; Skillint < Skill_Tree.size(); Skillint++) { cout << Skillint + 1 << ". " << Skill_Tree[Skillint].Skillname << endl; }
					cout << "교체할 스킬을 선택" << endl;
					Skillmenu = _getch() - 48;
					//미완성 
				}
			}	
			break;
		case 3: //가방열기
			Inventory_Menu();
			break;
		case 4: //진행중인 퀘스트
			Look_Quest();
			break;
		case 5: //도주
			Print("던전에서 도망쳐 나옵니다...");
			Sleep(2000);
			return -1;
			break;
		default: //잘못된 변수 입력받을시
			Print("올바르지 않은 입력");
			Cursor_Pos_End();
			Order_Clear();
			break;
		}
	}
}

void Monster_Die(My_Character* a, Monster* b)
{
	a->Pick_UP_Money(b->Money);
	SoNB_P->Exp_Plus(b->Exp);
	Combat_Ui(a, b);
	if (SoNB_P->Exp > SoNB_P->Max_Exp)
	{
		My_Character Temp_P;
		memcpy(&Temp_P, a, sizeof(struct My_Character));
		Temp_P.Level_Plus();
		Level_Plus_Show(SoNB_P, Temp_P);
		SoNB_P->Level_Plus();
	}
}

int Get_Money()
{
	return SoNB_P->Money;
}
