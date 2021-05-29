#pragma once
#include <iostream>
#include "monster.h"
#include "inventory.h"
using namespace std;

typedef struct My_Character //플레이어 클래스
{
	double Hp, Mp, Atk, Def, Speed, Level = 1, Exp = 0, Max_Exp = 100, Money = 0;

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

void Use_Item(My_Character* Character, string* Inventory, string* Equipment_slot) {
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
			for (int i = 0; i < 14; i++) {   //14는 items 배열 크기
				if (Inventory[n] == Items[i].Name) {  //소비아이템 사용
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
			for (int i = 0; i < 15; i++) {   //15는 Equipments 배열 크기
				if (Inventory[n] == "0") { break; }//앞의 for문에서 아이템을 사용했다면 이 for문을 돌리지 않음
				if (Inventory[n] == Equipments[i].Name) {
					int Num = Equipments[i].Kind;
					if (Equipment_slot[Num] != "0") {//장비창 확인
						cout << "선택하신 장비와 같은 종류의 장비를 이미 착용하고 있습니다.\n";
						cout << "착용중인 장비를 해제하고 다시 시도해주세요\n";
						break;
					}
					else {    //장비 아이템 착용
						Equipment_slot[Num] == Gacha_Equipments[i].Name;
						Character->Hp += Equipments[i].Hp;
						Character->Mp += Equipments[i].Mp;
						Character->Atk += Equipments[i].Atk;
						Character->Def += Equipments[i].Def;
						Character->Speed += Equipments[i].Speed;
						Inventory[n] = "0";
						cout << "\n" << Equipments[i].Name << "을 착용했습니다\n";
						cout << "hp : " << Character->Hp - Equipments[i].Hp << " -> " << Character->Hp << "\n";
						cout << "mp : " << Character->Mp - Equipments[i].Mp << " -> " << Character->Mp << "\n";
						cout << "atk : " << Character->Atk - Equipments[i].Atk << " -> " << Character->Atk << "\n";
						cout << "def : " << Character->Def - Equipments[i].Def << " -> " << Character->Def << "\n";
						cout << "speed : " << Character->Speed - Equipments[i].Speed << " -> " << Character->Speed << "\n\n";
						break;
					}
				}
			}
			for (int i = 0; i < 5; i++) {   //5는 Gacha_Equipments 배열 크기
				if (Inventory[n] == "0") { break; }//앞의 for문에서 아이템을 사용했다면 이 for문을 돌리지 않음
				if (Inventory[n] == Gacha_Equipments[i].Name) {
					int Num = Gacha_Equipments[i].Kind;
					if (Equipment_slot[Num] != "0") {//장비창 확인
						cout << "선택하신 장비와 같은 종류의 장비를 이미 착용하고 있습니다.\n";
						cout << "착용중인 장비를 해제하고 다시 시도해주세요\n";
						break;
					}
					else {    //가챠 장비 착용
						Equipment_slot[Num] == Gacha_Equipments[i].Name;
						Character->Hp += Gacha_Equipments[i].Hp;
						Character->Mp += Gacha_Equipments[i].Mp;
						Character->Atk += Gacha_Equipments[i].Atk;
						Character->Def += Gacha_Equipments[i].Def;
						Character->Speed += Gacha_Equipments[i].Speed;
						Inventory[n] = "0";
						cout << "\n" << Gacha_Equipments[i].Name << "을 착용했습니다\n";
						cout << "hp : " << Character->Hp - Gacha_Equipments[i].Hp << " -> " << Character->Hp << "\n";
						cout << "mp : " << Character->Mp - Gacha_Equipments[i].Mp << " -> " << Character->Mp << "\n";
						cout << "atk : " << Character->Atk - Gacha_Equipments[i].Atk << " -> " << Character->Atk << "\n";
						cout << "def : " << Character->Def - Gacha_Equipments[i].Def << " -> " << Character->Def << "\n";
						cout << "speed : " << Character->Speed - Gacha_Equipments[i].Speed << " -> " << Character->Speed << "\n\n";
						break;
					}
				}
			}
		}
	}
	else { cout << "아이템 사용이 취소되었습니다\n"; }
}

void Take_Off_Equipment(My_Character* Character, string* Inventory, string* Equipment_slot) {
	//장비 아이템 착용 해제 함수
	int Count = 0;
	int N;
	for (int I = 0; I < 5; I++) {      //인벤토리에 빈공간이 있는지 확인
		if (Inventory[I] == "0") { Count++; }
	}
	if (Count == 0) {    //인벤토리가 가득 찬 경우
		cout << "인벤토리가 가득 찼습니다.\n";
		cout << "인벤토리를 비운 후에 다시 시도해주세요\n";
	}
	else {
		cout << "착용중인 장비 아이템 목록\n";
		for (int I = 0; I < 5; I++) { cout << I << " : " << Equipment_slot[I] << endl; }
		cout << "------------------------\n";
		cout << "착용 해제할 아이템의 번호를 입력해주세요\n";
		cout << "0~4 이외의 숫자를 입력하면 장비 해제가 취소됩니다.\n";
		cout << "입력 : ";
		cin >> N;
		cout << endl;
		if (N < 0 && N > 4) { cout << "선택하신 위치에 착용중인 장비가 없습니다.\n"; }
		else if (N >= 0 && N <= 4) {
			if (Equipment_slot[N] == "0") { cout << "선택하신 위치에 착용중인 장비가 없습니다.\n"; }
			else {
				for (int J = 0; J < 15; J++) {//15는 Equipments 배열 크기
					if (Equipment_slot[N] == Equipments[J].Name) {//장비 아이템 착용 해제
						Pick_Up_Item(Inventory, Equipment_slot[N]);
						Character->Hp -= Equipments[J].Hp;
						Character->Mp -= Equipments[J].Mp;
						Character->Atk -= Equipments[J].Atk;
						Character->Def -= Equipments[J].Def;
						Character->Speed -= Equipments[J].Speed;
						Equipment_slot[N] == "0";
						cout << "\n" << Equipments[J].Name << "을 착용 해제했습니다\n";
						cout << "hp : " << Character->Hp + Equipments[J].Hp << " -> " << Character->Hp << "\n";
						cout << "mp : " << Character->Mp + Equipments[J].Mp << " -> " << Character->Mp << "\n";
						cout << "atk : " << Character->Atk + Equipments[J].Atk << " -> " << Character->Atk << "\n";
						cout << "def : " << Character->Def + Equipments[J].Def << " -> " << Character->Def << "\n";
						cout << "speed : " << Character->Speed + Equipments[J].Speed << " -> " << Character->Speed << "\n\n";
						break;
					}
				}
				for (int J = 0; J < 5; J++) {//5는 Gacha_Equipments 배열 크기
					if (Equipment_slot[N] == "0") { break; }//앞의 for문에서 장비를 해제했다면 이 for문을 돌리지 않음
					if (Equipment_slot[N] == Gacha_Equipments[J].Name) {//가챠 장비 착용 해제
						Pick_Up_Item(Inventory, Equipment_slot[N]);
						Character->Hp -= Gacha_Equipments[J].Hp;
						Character->Mp -= Gacha_Equipments[J].Mp;
						Character->Atk -= Gacha_Equipments[J].Atk;
						Character->Def -= Gacha_Equipments[J].Def;
						Character->Speed -= Gacha_Equipments[J].Speed;
						Equipment_slot[N] == "0";
						cout << "\n" << Gacha_Equipments[J].Name << "을 착용 해제했습니다\n";
						cout << "hp : " << Character->Hp + Gacha_Equipments[J].Hp << " -> " << Character->Hp << "\n";
						cout << "mp : " << Character->Mp + Gacha_Equipments[J].Mp << " -> " << Character->Mp << "\n";
						cout << "atk : " << Character->Atk + Gacha_Equipments[J].Atk << " -> " << Character->Atk << "\n";
						cout << "def : " << Character->Def + Gacha_Equipments[J].Def << " -> " << Character->Def << "\n";
						cout << "speed : " << Character->Speed + Gacha_Equipments[J].Speed << " -> " << Character->Speed << "\n\n";
						break;
					}
				}
			}
		}
	}
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
			Use_Item(SoNB_P, Inventory, Equipment_slot);
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