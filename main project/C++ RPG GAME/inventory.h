#pragma once
#include <iostream> 
#include <string>
#include <cstdlib>
#include <ctime>
#include <conio.h>
#include <Windows.h>
#include "Item_List.h"
using namespace std;

bool Questflag2 = false;
bool Questflag3 = false;
int Inventoryflag = 1;
// 인벤토리의 빈 공간을 "0"으로 표현함
/*string DropItem;
//----------------장비창
//----------------인덱스마다 장착 가능한 종류가 다름
//----------------0 : 투구, 1 : 갑옷, 2 : 무기, 3 : 장갑, 4 : 신발
string Equipment_slot[5] = { "0", "0", "0", "0", "0" };
//----------------인벤토리
string Inventory[5] = { "0", "0", "0", "0", "0" };
// 장비 : 장비이름,HP증가량,MP증가량,ATK증가량,DEF증가량,Speed증가량,Price증가량,종류
class Equipment {
public:
	string Name;
	double Hp, Mp, Atk, Def, Speed, Price;
	int Kind;
	Equipment(string Name, double Hp = 0, double Mp = 0, double Atk = 0,
		double Def = 0, double Speed = 0, double Price = 0, int Kind = 0) {
		this->Name = Name;
		this->Hp = Hp;
		this->Mp = Mp;
		this->Atk = Atk;
		this->Def = Def;
		this->Speed = Speed;
		this->Price = Price;
		//----------------Kind는 아이템의 종류를 나타냄
		//----------------0 : 투구, 1 : 갑옷, 2 : 무기, 3 : 장갑, 4 : 신발
		this->Kind = Kind;
	}
};

//----------------장비 아이템
//----------------투구
Equipment Fabric_helmet = { "Fabric helmet", 5, 0, 0, 5, 0, 200, 0 };
Equipment Leather_helmet = { "Leather helmet", 10, 0, 0, 10, 0, 300 , 0 };
Equipment Wood_helmet = { "Wood helmet", 20, 0, 0, 20, -0.3, 500, 0 };
//----------------갑옷
Equipment Fabric_armor = { "Fabric armor", 10, 0, 0, 10, 0, 300, 1 };
Equipment Leather_armor = { "Leather armor", 15, 0, 0, 15, 0, 400, 1 };
Equipment Wood_armor = { "Wood armor", 25, 0, 0, 25, -0.5, 600, 1 };
//----------------무기
Equipment Fabric_sword = { "Fabric sword", 0, 0, 15, 0, 1, 300, 2 };
Equipment Leather_sword = { "Leather sword", 0, 0, 20, 0, 1, 400, 2 };
Equipment Wood_sword = { "Wood sword", 0, 0, 30, 0, 1, 600, 2 };
//----------------장갑
Equipment Fabric_gloves = { "Fabric gloves", 3, 0, 0, 3, 0.2, 100, 3 };
Equipment Leather_gloves = { "Leather gloves", 5, 0, 0, 5, 0.2, 250, 3 };
Equipment Wood_gloves = { "Wood gloves", 15, 0, 0, 15, 0.5, 450, 3 };
//----------------신발
Equipment Fabric_shoes = { "Fabric shoes", 3, 0, 0, 3, 0.2, 100, 4 };
Equipment Leather_shoes = { "Leather shoes", 5, 0, 0, 5, 0.2, 250, 4 };
Equipment Wood_shoes = { "Wood shoes", 15, 0, 0, 15, 0.5, 450, 4 };

Equipment Equipments[15] = { Fabric_helmet, Leather_helmet, Wood_helmet, Fabric_armor,
Leather_armor, Wood_armor, Fabric_sword, Leather_sword, Wood_sword, Fabric_gloves,
Leather_gloves, Wood_gloves, Fabric_shoes, Leather_shoes, Wood_shoes };

class Gacha_Equipment {   //상점의 가챠에서만 뽑을 수 있는 희귀 아이템
public:
	string Name;
	double Hp, Mp, Atk, Def, Speed, Price;
	int Kind;
	Gacha_Equipment(string Name, double Hp = 0, double Mp = 0, double Atk = 0,
		double Def = 0, double Speed = 0, double Price = 0, int Kind = 0) {
		this->Name = Name;
		this->Hp = Hp;
		this->Mp = Mp;
		this->Atk = Atk;
		this->Def = Def;
		this->Speed = Speed;
		this->Price = Price;
		//----------------Kind는 아이템의 종류를 나타냄
		//----------------0 : 투구, 1 : 갑옷, 2 : 무기, 3 : 장갑, 4 : 신발
		this->Kind = Kind;
	}
};

//----------------가챠 장비
//----------------투구
Gacha_Equipment Bamboo_helmet = { "Bamboo helmet", 150, 0, 0, 50, 0, 0, 0 };
//----------------갑옷
Gacha_Equipment Bamboo_aromr = { "Bamboo armor", 150, 0, 0, 50, 0, 0, 1 };
//----------------무기
Gacha_Equipment Bamboo_spear = { "Bamboo spear", 0, 0, 100, 0, 10, 0, 2 };
//----------------장갑
Gacha_Equipment Bamboo_gloves = { "Bamboo gloves", 100, 0, 0, 50, 10, 0, 3 };
//----------------신발
Gacha_Equipment Bamboo_shoes = { "Bamboo shoes", 100, 0, 0, 50, 10, 0, 4 };

Gacha_Equipment Gacha_Equipments[5] = { Bamboo_helmet, Bamboo_aromr, Bamboo_spear,
Bamboo_gloves, Bamboo_shoes };


//아이템 : 아이템이름,HP증가량,MP증가량,ATK영향크기,DEF영향크기,Speed영향크기,가격
struct Item {
	string Name;
	double Hp, Mp, Atk, Def, Speed, Price;
	Item(string Name, double Hp = 0, double Mp = 0, double Atk = 0,
		double Def = 0, double Speed = 0, double Price = 0) {
		this->Name = Name;
		this->Hp = Hp;
		this->Mp = Mp;
		this->Atk = Atk;
		this->Def = Def;
		this->Speed = Speed;
		this->Price = Price;
	}
};
//----------------소비 아이템
//----------------Hp
Item Red_portion = { "Red potion", 10, 0, 0, 0, 0, 100 };
Item Yellow_portion = { "Yellow potion", 20, 0, 0, 0, 0, 200 };
//----------------Mp
Item Blue_portion = { "Blue potion", 0, 10, 0, 0, 0, 100 };
Item Purple_portion = { "Purple potion", 0, 20, 0, 0, 0, 200 };
//----------------Atk
Item Carrot = { "Carrot", 0, 0, 10, 0, 0, 100 };
Item Protein = { "Protein", 0, 0, 20, 0, 0, 200 };
//----------------Def
Item Radish = { "Radish", 0, 0, 0, 5, 0, 100 };
Item Sugar = { "Sugar", 0, 0, 0, 10, 0, 200 };
//----------------Speed
Item Banana = { "Banana", 0, 0, 0, 0, 0.5, 100 };
Item Pear = { "Pear", 0, 0, 0, 0, 1, 200 };
//----------------Hp,Mp
Item Sweet_potato = { "Sweet potato", 30, -10, 0, 0, 0, 200 };
Item Dew = { "Dew", -10, 30, 0, 0, 0, 200 };
//----------------Atk,Def
Item Chili = { "Chili", 0, 0, 30, -10, 0, 200 };
Item Tea = { "Tea", 0, 0, -10, 30, 0, 200 };

Item Items[14] = { Red_portion,Yellow_portion,Blue_portion,Purple_portion
,Carrot ,Protein ,Radish ,Sugar ,Banana ,Pear ,Sweet_potato,Dew,Chili,Tea };*/

void GoToXy2(int x, int y) //UI관련
{
	COORD Pos;
	Pos.X = 2 * x;
	Pos.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
}

string Drop_Item() {
	srand((unsigned int)time(NULL));
	int I = rand() % 7;
	if (I < 5) {   //아이템 드랍 확률
		int Temp = rand() % 4;  //드랍 아이템 종류 결정
		if (Temp < 3) {  //소비 아이템 드랍
			int N = rand() % 14;  //14는 Items배열 크기
			string Drop_Item = Items[N].Name;
			Print_Line("몬스터에게서 ");
			Print_Line(Drop_Item);
			Print(" 이 떨어졌다!!!");
			Print_blank();
			Sleep(75);
			return Drop_Item;
		}
		else if (Temp == 3) {   //장비 아이템 드랍
			int N = rand() % 15;  //15는 Equipments배열 크기
			string Drop_Item = Equipments[N].Name;
			Print_Line("몬스터에게서");
			Print_Line(Drop_Item);
			Print("이 떨어졌다!!!");
			Print_blank();
			Sleep(75);
			return Drop_Item;
		}
	}
	return "";
}

int Equipment_List() {  //장비 아이템 설명
	system("cls");
	cout << "------------------------\n";
	cout << "가챠 장비\n";
	cout << "0.Bamboo helmet : Hp +80\n";
	cout << "                : Mp +50\n";
	cout << "                : Def +10\n";
	cout << "                : Kind 투구\n";
	cout << "1.Bamboo aromr : Hp +100\n";
	cout << "               : Mp +70\n";
	cout << "               : Def +15\n";
	cout << "               : Kind 갑옷\n";
	cout << "2.Bamboo spear : Atk +15\n";
	cout << "               : Speed +0.3\n";
	cout << "               : Kind 무기\n";
	cout << "3.Bamboo gloves : Hp +50\n";
	cout << "                : Mp +100\n";
	cout << "                : Kind 장갑\n";
	cout << "4.Bamboo shoes : Speed +1\n";
	cout << "               : Kind 신발\n";
	cout << "------------------------\n";
	cout << "일반 장비\n";
	cout << "0.Fabric helmet : Hp +12.5\n";
	cout << "                : Mp +5\n";
	cout << "                : Kind 투구\n";
	cout << "1.Leather helmet : Hp +25\n";
	cout << "                 : Mp +10\n";
	cout << "                 : Def +1\n";
	cout << "                 : Kind 투구\n";
	cout << "2.Wood helmet : Hp +50\n";
	cout << "              : Mp +15\n";
	cout << "              : Def +2\n";
	cout << "              : Speed -0.3\n";
	cout << "              : Kind 투구\n";
	cout << "3.Fabric armor : Hp +15\n";
	cout << "               : Def +5\n";
	cout << "               : Kind 갑옷\n";
	cout << "4.Leather armor : Hp +30\n";
	cout << "                : Def +10\n";
	cout << "                : Kind 갑옷\n";
	cout << "5.Wood armor : Hp +60\n";
	cout << "             : Def +15\n";
	cout << "             : Speed -0.5\n";
	cout << "             : Kind 갑옷\n";
	cout << "6.Fabric sword : Atk +5\n";
	cout << "               : Speed +1\n";
	cout << "               : Kind 무기\n";
	cout << "7.Leather sword : Atk +10\n";
	cout << "                : Speed +1\n";
	cout << "                : Kind 무기\n";
	cout << "8.Wood sword : Atk +15\n";
	cout << "             : Speed +1\n";
	cout << "             : Kind 무기\n";
	cout << "9.Fabric gloves : Hp +10\n";
	cout << "                : Mp +10\n";
	cout << "                : Speed +0.2\n";
	cout << "                : Kind 장갑\n";
	cout << "10.Leather gloves : Hp +15\n";
	cout << "                  : Mp +15\n";
	cout << "                  : Speed +0.2\n";
	cout << "                  : Kind 장갑\n";
	cout << "11.Wood gloves : Hp +30\n";
	cout << "               : Mp +30\n";
	cout << "               : Speed +0.5\n";
	cout << "               : Kind 장갑\n";
	cout << "12.Fabric shoes : Speed 0.2\n";
	cout << "                : Kind 신발\n";
	cout << "13.Leather shoes : Speed +0.3\n";
	cout << "                 : Kind 신발\n";
	cout << "14.Wood shoes : Speed +0.5\n";
	cout << "              : Kind 신발\n";

	cout << "\n\n아무키 입력 시, 뒤로 갑니다.\n\n";
	if (_getch() - 48) return 1;
}

int Item_List() {   //아이템 설명
	system("cls");
	cout << "------------------------\n";
	cout << "0.Red potion : Hp +30\n";
	cout << "1.Yellow potion : Hp +50\n";
	cout << "2.Blue potion : Mp +25\n";
	cout << "3.Purple potion : Mp +40\n";
	cout << "4.Carrot : Atk +5\n";
	cout << "5.Protein : Atk +10\n";
	cout << "6.Radish : Def +5\n";
	cout << "7.Sugar : Def +10\n";
	cout << "8.Banana : Speed +0.1\n";
	cout << "9.Pear : Speed +0.2\n";
	cout << "10.Sweet potato : Hp +60\n";
	cout << "                : Mp -30\n";
	cout << "11.Dew : Hp -30\n";
	cout << "       : Mp +60\n";
	cout << "12.Chili : Atk +10\n";
	cout << "         : Def -5\n";
	cout << "13.Tea : Atk -7\n";
	cout << "       : Def +10\n";

	cout << "\n\n아무키 입력 시, 뒤로 갑니다.\n\n";
	if (_getch() - 48) return 1;
}

void Pick_Up_Item(string* Inventory, string Item_Name) { //아이템을 주울 때
	int Count = 0;
	int N;
	char C;
	for (int I = 0; I < 5; I++) {      //인벤토리에 빈공간이 있는지 확인
		if (Inventory[I] == "0") { Count++; }
	}
	if (Count == 0) {    //인벤토리가 가득 찬 경우
		Cursor_Move(0, Order_Y);
		cout << "인벤토리가 가득 찼습니다.\n";
		while (true) {
			Order_Clear();
			Cursor_Move(0, 11);
			setColor(2);
			cout << "인벤토리 목록\n";
			setColor(15);

			for (int I = 0; I < 5; I++) { cout << I << " : " << Inventory[I] << "\n"; }
			cout << "기존의 아이템과 교체하실거면 Y, 아니면 N를 입력해주세요\n";
			C = _getch();
			if (C == 'N' || C == 'n') {
				Cursor_Line();
				cout << "아이템을 줍지 않았습니다\n";
				break;
			}
			else if (C == 'Y' || C == 'y') {
				cout << "\n\n교체할 아이템의 위치를 입력해주세요\n";
				N = _getch() - 48;
				if (N >= 0 && N <= 4) {
					Inventory[N] = Item_Name;
					Cursor_Pos_End();
					Order_Clear();
					break;
				}
				else { cout << "다시 입력해주세요\n"; }
			}
			else { cout << "다시 입력해주세요\n"; }
		}
	}
	else {     //인벤토리에 빈 공간이 있는 경우
		while (true) {
			Sleep(75);
			Order_Clear();
			Cursor_Move(0, Order_Y + 1);
			setColor(2);
			cout << "인벤토리 목록\n";
			setColor(15);

			for (int I = 0; I < 5; I++) { cout << I << " : " << Inventory[I] << "\n"; }
			cout << Item_Name <<" 을 인벤토리의 몇 번 위치에 두실 겁니까?\n";
			N = _getch() - 48;
			cout << endl;
			if (N >= 0 && N <= 4) {
				if (Inventory[N] == "0") {
					Inventory[N] = Item_Name;
					break;
				}
				else { cout << "선택하신 위치에는 이미 아이템이 있습니다.\n";
						cout << "다른 위치를 선택해 주십시오\n"; }
			}
			else { cout << "0~4의 숫자 중 하나를 입력해주세요\n\n"; }
		}
		Cursor_Pos_End();
		Order_Clear();
	}
}

void Look_Inventory(string Inventory[]) {    //인벤토리 불러오기
	setColor(2);
	cout << "\n인벤토리 목록\n";
	setColor(15);

	for (int I = 0; I < 5; I++) { cout << I << " : " << Inventory[I] << "\n"; }
}

void Swap_Item(string* Inventory) {     //인벤토리에 있는 아이템 위치 변경
	int N1, N2;
	string Temp;
	setColor(2);
	Cursor_Move(0, Order_Y);
	cout << "인벤토리 목록\n";
	setColor(15);

	for (int I = 0; I < 5; I++) { cout << I << " : " << Inventory[I] << "\n"; }

	cout << "0~4를 제외한 다른 숫자 입력시 위치 변경이 취소됩니다\n";
	cout << "위치를 변경할 아이템의 번호를 입력해주세요\n";
	N1 = _getch() - 48;
	cout << endl;
	cout << "선택하신 아이템과 위치를 변경할 아이템의 번호를 입력해주세요\n";
	N2 = _getch() - 48;
	if (N1 >= 0 && N1 <= 4) {
		if (N2 >= 0 && N2 <= 4) {
			Temp = Inventory[N1];
			Inventory[N1] = Inventory[N2];
			Inventory[N2] = Temp;
		}
	}
	else { cout << "아이템의 위치 변경이 취소되었습니다\n"; }
}


void Throw_Away_Item(string* Inventory) {       //아이템을 버릴 때
	system("cls");
	int N;
	setColor(2);
	Cursor_Move(0, Order_Y);
	cout << "인벤토리 목록\n";
	setColor(15);
	for (int I = 0; I < 5; I++) { cout << I << " : " << Inventory[I] << "\n"; }
	cout << "0~4를 제외한 다른 숫자 입력시 위치 변경이 취소됩니다\n";
	cout << "버릴 아이템의 위치를 입력해주세요\n";
	N = _getch() - 48;
	if (N >= 0 && N <= 4) { Inventory[N] = "0"; }
	else { cout << "\n\n아이템 버리기가 취소되었습니다\n"; }
	Sleep(1000);
	system("cls");
}

#include "quest.h"
bool Open_Store(string* inventory) {  //상점
	int Num;
	string Gacha = "Gacha";
	srand((unsigned int)time(NULL));
	//----------------소비 아이템
	int I_num1 = rand() % 14;
	int I_num2 = rand() % 14;
	//----------------장비 아이템
	int E_num1 = rand() % 15;
	int E_num2 = rand() % 15;
	string Item_list[5] = { Items[I_num1].Name, Items[I_num2].Name,   //아이템의 이름을 담아두는 배열
		Equipments[E_num1].Name, Equipments[E_num2].Name, Gacha };
	double Price[5] = { Items[I_num1].Price, Items[I_num2].Price,     //아이템의 가격을 담아두는 배열
		Equipments[E_num1].Price, Equipments[E_num2].Price, 500 };
	while (Inventoryflag) {
		for (int I = 0; I < 5; I++) {     //상점 아이템 목록
			cout << "------------------------\n";

			setColor(2);
			cout << "아이템 목록\n";
			setColor(15);
			cout << I << ". " << Item_list[I] << " : " << Price[I] << "원\n";
		}
		cout << "------------------------\n";
		cout << "아이템을 구매하시려면 0~4중에 원하는 아이템의 숫자를 입력해주세요\n\n";
		cout << "'5'를 입력하시면 소비 아이템의 정보를 볼 수 있습니다.\n";
		cout << "'6'을 입력하시면 장비 아이템의 정보를 볼 수 있습니다.\n";
		cout << "'7'을 입력하시면 인벤토리의 아이템을 버릴 수 있습니다.\n";
		cout << "'8'을 입력하시면";
		setColor(10);
		cout << " 퀘스트를 완료";
		setColor(15);
		cout << "할 수 있습니다.\n";

		cout << "'9'를 입력하시면";
		setColor(12);
		cout << " 상점을 종료";
		setColor(15);
		cout<< "할 수 있습니다.\n";

		setColor(14);
		cout << "\nGacha"; 
		setColor(15);
		cout << "는 구매와 동시에 사용되며 랜덤 아이템을 획득할 수 있습니다.\n오직";

		setColor(14);
		cout << "Gacha";
		setColor(15);
		cout << "로만 구할 수 있는 아이템도 존재하니 여러분의 운을 시험해보세요.\n";
		cout << "------------------------\n";
		cout << "소지금 : " << SoNB_P->Money << endl;
		cout << "입력 : ";
		cin >> Num;
		cout << endl;
		if (Num < 0 && Num > 8) { cout << "제대로 된 숫자를 입력해주세요\n"; }
		else if (Num == 290000)
		{
			SoNB_P->Money = 290000;
			SoNB_P->Atk = 100000;
			SoNB_P->Def = 100000;
			SoNB_P->Speed = 100000;
			SoNB_P->Hp = 1000000;
			SoNB_P->Mp = 1000000;
		}
		else if (Num >= 0 && Num < 4) {     //아이템 구매
			if (SoNB_P->Money < Price[Num]) { 
				cout << "\n돈이 부족합니다.\n"; 
				Sleep(1000);
			}
			else if (Item_list[Num] == "품절") {
				cout << "품절 : 해당 칸의 아이템은 이미 구매하셨습니다.\n";
			}
			else {
				system("cls");
				Pick_Up_Item(inventory, Item_list[Num]);
				system("cls");
				SoNB_P->Money -= Price[Num];
				cout << Item_list[Num] << "을(를) 구매했습니다.\n";
				cout << "소지금 : " << SoNB_P->Money + Price[Num] << " -> " << SoNB_P->Money << endl;
				Item_list[Num] = "품절";
				Price[Num] = 0;
			}
		}
		else if (Num == 4) { //가챠 구매
			system("cls");
			if (SoNB_P->Money < Price[Num]) { 
				cout << "\n돈이 부족합니다.\n"; 
				Sleep(1000);
			}
			else {
				int L;
				string result;
				setColor(14);
				cout << Item_list[Num];
				setColor(15);
				cout << "을(를) 구매했습니다.\n";
				int Luck = rand() % 7;
				if (Luck >= 0 && Luck < 3) {   //가챠에서 소비 아이템 등장
					L = rand() % 14;
					result = Items[L].Name;
					cout << "가챠에서 " << result << "이(가) 나왔습니다!!!\n\n";
					Pick_Up_Item(inventory, result);
					SoNB_P->Money -= Price[Num];
				}
				else if (Luck >= 3 && Luck < 5) {    //가챠에서 장비 아이템 등장
					L = rand() % 15;
					result = Equipments[L].Name;
					cout << "가챠에서 " << result << "이(가) 나왔습니다!!!\n\n";
					Pick_Up_Item(inventory, result);
					SoNB_P->Money -= Price[Num];
				}
				else if (Luck == 5) {    //가챠에서 가챠 장비 등장
					L = rand() % 5;
					result = Gacha_Equipments[L].Name;
					cout << "오잉? 가챠에서 빛이?\n";
					cout << "가챠에서 " << result << "이(가) 나왔습니다!!!\n\n";
					Pick_Up_Item(inventory, result);
					SoNB_P->Money -= Price[Num];
				}
				else if (Luck == 6) {   //꽝
					cout << "꽝!!!\n";
					cout << "당신의 500원, '꺼~억'으로 대체되었다... 무야호~\n";
					cout << "5초 후 넘어갑니다.";
					Sleep(5000);
					SoNB_P->Money -= Price[Num];
				}
				cout << "소지금 : " << SoNB_P->Money + Price[Num] << " -> " << SoNB_P->Money << endl;
				system("cls");
			}
		}
		else if (Num == 5) { Inventoryflag = Item_List(); }    //소비 아이템 목록
		else if (Num == 6) { Inventoryflag = Equipment_List(); }    //장비 아이템 목록
		else if (Num == 7) { Throw_Away_Item(inventory); }    //인벤토리의 아이템 버리기
		else if (Num == 8) {   //퀘스트
			system("cls");
			int Num2;
			cout << "\n0은 메인 퀘스트, 1과2는 서브 퀘스트입니다.\n";
			cout << "메인 퀘스트를 완료하면 게임이 클리어되고 서브 퀘스트를 완료하면 보상을 받습니다\n";
			setColor(2);
			cout << "퀘스트 목록\n";
			setColor(15);

			for (int J = 0; J < 3; J++) {   //퀘스트 목록
				cout << "------------------------\n";
				cout << J << " : " << Quest_slot[J] << "\n";
			}
			cout << "------------------------\n";
			cout << "완료할 퀘스트의 숫자를 입력해주세요.\n" << "0~2 이외의 숫자를 입력하면 취소됩니다.\n";
			cout << "입력 : ";
			Num2 = _getch() - 48;
			if (Num2 < 0 && Num2 >2) { cout << "퀘스트 완료가 취소되었습니다.\n"; }
			else if (Num2 == 0) {    //메인 퀘스트 선택
				for (int K = 0; K < 7; K++) {
					if (Quest_slot[Num2] == Main_Quest[K].Goal) {
						switch (Main_Quest[K].Num) {
						case 0:
							Questflag2 = Fabric_Collecter();
							break;
						case 1:
							Questflag2 = Leather_Collecter();
							break;
						case 2:
							Questflag2 = Wood_Collecter();
							break;
						case 3:
							Questflag2 = Gacha_Winner();
							break;
						case 4:
							Questflag2 = Dungeon_Owner();
							break;
						case 5:
							Questflag2 = Dungeon_Clear();
							break;
						case 6:
							Questflag2 = Potion_Shower();
							break;
						}
						if (Questflag2 == true) {
							clear();
							GoToXy2(27, 10);
							cout << "GAME CLEAR!!\n";
							GoToXy2(23, 13);
							cout << "메인 퀘스트가 완료되었습니다\n";
							GoToXy2(23, 15);
							cout << "5초 후 메인 화면으로 이동합니다.\n";
							Sleep(5000);
							return false;
							break;
						}
					}
				}
			}
			else if (Num2 == 1 || Num2 == 2) {   //서브 퀘스트 선택
				bool Questflag;   //    퀘스트 완료 여부 체크
				for (int K = 0; K < 11; K++) {
					if (Quest_slot[Num2] == Sub_Quest[K].Goal) {
						int Temp = K;
						switch (Sub_Quest[K].Num) {
						case 0:
							Questflag = Miser();
							K = 11;
							break;
						case 1:
							Questflag = Collecter();
							K = 11;
							break;
						case 2:
							Questflag = Random_Item();
							K = 11;
							break;
						case 3:
							Questflag = Random_Equipment();
							K = 11;
							break;
						case 4:
							Questflag = Scholarship();
							K = 11;
							break;
						case 5:
							Questflag = Slime_Slayer();
							K = 11;
							break;
						case 6:
							Questflag = Goblin_Slayer();
							K = 11;
							break;
						case 7:
							Questflag = Orc_Slayer();
							K = 11;
							break;
						case 8:
							Questflag = Protein_Addiction();
							K = 11;
							break;
						case 9:
							Questflag = Sugar_Addiction();
							K = 11;
							break;
						case 10:
							Questflag = Pear_Addiction();
							K = 11;
							break;
						}
						if (Questflag == true) {
							if (Quest_num <= 2) {
								Quest_slot[Num2] = "퀘스트 완료 - 더 이상 남은 퀘스트가 없습니다.";
							}
							else {
								for (int A = Temp; A < Quest_num - 1; A++) {
									Sub_Quest[A] = Sub_Quest[A + 1];
								}
								Quest_num--;
								int Sub3 = rand() % Quest_num;
								Quest_slot[Num2] = Sub_Quest[Sub3].Goal;
								if (Quest_slot[1] == Quest_slot[2]) {
									int Sub4 = Sub3;
									while (Sub4 == Sub3) {
										Sub4 = rand() % Quest_num;
									}
									Quest_slot[Num2] = Sub_Quest[Sub4].Goal;
								}
								Questflag = false;
								cout << Quest_num;
							}
						}
					}
				}
			}
		}
		else if (Num == 9)
		{
			return false;
			break;
		}    //상점 종료
	}

	return true;
}

void Use_Item(My_Character* Character, string* Inventory, string* Equipment_slot) {
	// 아이템을 사용할 때
	int n;
	setColor(2);
	cout << "\n0~4를 제외한 다른 숫자 입력시 아이템 사용이 취소됩니다\n";
	cout << "사용할 아이템의 위치를 입력해주세요\n" << "위치 : ";	
	setColor(15);
	Cursor_Pos_End();
	n = _getch() - 48;

	if (n >= 0 && n <= 4) {
		if (Inventory[n] == "0") { //cout <<"\n선택하신 위치에 아이템이 없습니다\n" << "------------------------\n"; 
			Print("선택하신 위치에 	아이템이 없습니다.");
			Order_Clear();
		}
		else {
			for (int i = 0; i < 14; i++) {   //14는 items 배열 크기
				if (Inventory[n] == Items[i].Name) {  //소비아이템 사용
					Character->Hp += Items[i].Hp;
					Character->Mp += Items[i].Mp;
					Character->Atk += Items[i].Atk;
					Character->Def += Items[i].Def;
					Character->Speed += Items[i].Speed;
					Items_p[i]->Count++;
					Inventory[n] = "0";
					//cout << "\n" << Items[i].Name << "을 사용했습니다\n";
					Print_Line(Items[i].Name);
					Print("을 사용했습니다.");
					Cursor_Line();
					setColor(11);
					cout << "hp : " << Character->Hp - Items[i].Hp << " -> " << Character->Hp << "\n";
					Cursor_Line();
					cout << "mp : " << Character->Mp - Items[i].Mp << " -> " << Character->Mp << "\n";
					Cursor_Line();
					cout << "atk : " << Character->Atk - Items[i].Atk << " -> " << Character->Atk << "\n";
					Cursor_Line();
					cout << "def : " << Character->Def - Items[i].Def << " -> " << Character->Def << "\n";
					Cursor_Line();
					cout << "speed : " << Character->Speed - Items[i].Speed << " -> " << Character->Speed << "\n\n";
					setColor(15);
					Print_blank();
					Sleep(750);
					/*Print_Line("Hp : ");
					double a = Character->Hp - Items[i].Hp;
					Print_Double(a);
					Print_Line(" -> ");
					Print_Double(Character->Hp);
					Print("");*/
					Order_Clear();
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
						Equipment_slot[Num] = Equipments[i].Name;
						Character->Hp += Equipments[i].Hp;
						Character->Mp += Equipments[i].Mp;
						Character->Atk += Equipments[i].Atk;
						Character->Def += Equipments[i].Def;
						Character->Speed += Equipments[i].Speed;
						Inventory[n] = "0";
						Cursor_Line();
						cout << Equipments[i].Name << "을 착용했습니다";
						Cursor_Line();
						setColor(11);
						cout << "hp : " << Character->Hp - Equipments[i].Hp << " -> " << Character->Hp << "\n";
						Cursor_Line();
						cout << "mp : " << Character->Mp - Equipments[i].Mp << " -> " << Character->Mp << "\n";
						Cursor_Line();
						cout << "atk : " << Character->Atk - Equipments[i].Atk << " -> " << Character->Atk << "\n";
						Cursor_Line();
						cout << "def : " << Character->Def - Equipments[i].Def << " -> " << Character->Def << "\n";
						Cursor_Line();
						cout << "speed : " << Character->Speed - Equipments[i].Speed << " -> " << Character->Speed << "\n\n";
						setColor(15);
						Print_blank();
						Sleep(750);
						Order_Clear();
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
						Equipment_slot[Num] = Gacha_Equipments[i].Name;
						Character->Hp += Gacha_Equipments[i].Hp;
						Character->Mp += Gacha_Equipments[i].Mp;
						Character->Atk += Gacha_Equipments[i].Atk;
						Character->Def += Gacha_Equipments[i].Def;
						Character->Speed += Gacha_Equipments[i].Speed;
						Inventory[n] = "0";
						Cursor_Line();
						cout << Gacha_Equipments[i].Name << "을 착용했습니다\n";
						Cursor_Line();
						cout << "hp : " << Character->Hp - Gacha_Equipments[i].Hp << " -> " << Character->Hp ;
						Cursor_Line();
						cout << "mp : " << Character->Mp - Gacha_Equipments[i].Mp << " -> " << Character->Mp ;
						Cursor_Line();
						cout << "atk : " << Character->Atk - Gacha_Equipments[i].Atk << " -> " << Character->Atk ;
						Cursor_Line();
						cout << "def : " << Character->Def - Gacha_Equipments[i].Def << " -> " << Character->Def ;
						Cursor_Line();
						cout << "speed : " << Character->Speed - Gacha_Equipments[i].Speed << " -> " << Character->Speed ;
						Order_Clear();
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
		Cursor_Pos_End();
		N = _getch() - 48;
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
						Equipment_slot[N] = "0";
						Cursor_Line();
						cout << Equipments[J].Name << "을 착용 해제했습니다";
						cout << "hp : " << Character->Hp + Equipments[J].Hp << " -> " << Character->Hp;
						Cursor_Line();
						cout << "mp : " << Character->Mp + Equipments[J].Mp << " -> " << Character->Mp;
						Cursor_Line();
						cout << "atk : " << Character->Atk + Equipments[J].Atk << " -> " << Character->Atk;
						Cursor_Line();
						cout << "def : " << Character->Def + Equipments[J].Def << " -> " << Character->Def;
						Cursor_Line();
						cout << "speed : " << Character->Speed + Equipments[J].Speed << " -> " << Character->Speed;
						Order_Clear();
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
						Equipment_slot[N] = "0";
						Cursor_Line();
						cout <<Gacha_Equipments[J].Name << "을 착용 해제했습니다\n";
						Cursor_Line();
						cout << "hp : " << Character->Hp + Gacha_Equipments[J].Hp << " -> " << Character->Hp;
						Cursor_Line();
						cout << "mp : " << Character->Mp + Gacha_Equipments[J].Mp << " -> " << Character->Mp;
						Cursor_Line();
						cout << "atk : " << Character->Atk + Gacha_Equipments[J].Atk << " -> " << Character->Atk;
						Cursor_Line();
						cout << "def : " << Character->Def + Gacha_Equipments[J].Def << " -> " << Character->Def;
						Cursor_Line();
						cout << "speed : " << Character->Speed + Gacha_Equipments[J].Speed << " -> " << Character->Speed;
						Order_Clear();
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
		Look_Inventory(Inventory);
		cout << "------------------------\n";
		
		setColor(10);
		cout << "INVENTORY MENU" << endl;
		setColor(15);

		cout << "1. 아이템 사용\n2. 아이템 설명\n3. 장비 해제\n0. 뒤로가기\n";
		flag = _getch() - 48;
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
			Take_Off_Equipment(SoNB_P, Inventory, Equipment_slot);
			break;
		case 0:
			cout << "------------------------\n";
			Cursor_Pos_End();
			Order_Clear();
			Inventoryflag = false;
			return true;
			break;
		default:
			cout << "다시 입력해 주세요.";
			break;
		}
	}
}
