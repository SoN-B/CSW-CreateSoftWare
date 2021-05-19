#include <iostream> 
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;

// 인벤토리의 빈 공간을 "0"으로 표현함

struct Item {
	string Name;
	double Hp, Mp, Atk, Def, Speed;
	Item(string Name, double Hp = 0, double Mp = 0, double Atk = 0,
		double Def = 0, double Speed = 0) {
		this->Name = Name;
		this->Hp = Hp;
		this->Mp = Mp;
		this->Atk = Atk;
		this->Def = Def;
		this->Speed = Speed;
	}
};

//----------------Hp
Item Red_portion = { "Red potion",10 };
Item Yellow_portion = { "Yellow potion",20 };
//----------------Mp
Item Blue_portion = { "Blue potion",0,10 };
Item Purple_portion = { "Purple potion",0,20 };
//----------------Atk
Item Carrot = { "Carrot",0,0,10 };
Item Protein = { "Protein",0,0,20 };
//----------------Def
Item Radish = { "Radish",0,0,0,5 };
Item Sugar = { "Sugar",0,0,0,10 };
//----------------Speed
Item Banana = { "Banana",0,0,0,0,0.5 };
Item Pear = { "Pear",0,0,0,0,1 };
//----------------Hp,Mp
Item Sweet_potato = { "Sweet potato",30,-10,0,0,0 };
Item Dew = { "Dew",-10,30,0,0,0 };
//----------------Atk,Def
Item Chili = { "Chili",0,0,30,-10,0 };
Item Tea = { "Tea",0,0,-10,30,0 };

Item Items[14] = { Red_portion,Yellow_portion,Blue_portion,Purple_portion
,Carrot ,Protein ,Radish ,Sugar ,Banana ,Pear ,Sweet_potato,Dew,Chili,Tea };

string Drop_Item() {
	srand((unsigned int)time(NULL));
	int I = rand() % 7;
	if (I < 5) {   //아이템 드랍 확률
		int N = rand() % 14;  //14는 Items배열 크기
		string Drop_Item = Items[N].Name;
		cout << "몬스터에게서 " << Drop_Item << "이 떨어졌다!!!\n";
		return Drop_Item;
	}
	return "";
}

void Item_List() {   //아이템 설명
	cout << "0.Red potion : Hp +10\n";
	cout << "1.Yellow potion : Hp +20\n";
	cout << "2.Blue potion : Mp +10\n";
	cout << "3.Purple potion : Mp +20\n";
	cout << "4.Carrot : Atk +10\n";
	cout << "5.Protein : Atk +20\n";
	cout << "6.Radish : Def +5\n";
	cout << "7.Sugar : Def +10\n";
	cout << "8.Banana : Speed +5\n";
	cout << "9.Pear : Speed +1\n";
	cout << "10.Sweet potato : Hp +30\n";
	cout << "                : Mp -10\n";
	cout << "11.Dew : Hp -10\n";
	cout << "       : Mp +30\n";
	cout << "12.Chili : Atk +30\n";
	cout << "         : Def -10\n";
	cout << "13.Tea : Atk -10\n";
	cout << "       : Def +30\n";
}

void Pick_Up_Item(string* Inventory, string Item_Name) { //아이템을 주울 때
	int Count = 0;
	int N;
	char C;
	for (int I = 0; I < 5; I++) {      //인벤토리에 빈공간이 있는지 확인
		if (Inventory[I] == "0") { Count++; }
	}
	if (Count == 0) {    //인벤토리가 가득 찬 경우
		cout << "인벤토리가 가득 찼습니다.\n";
		while (true) {
			cout << "인벤토리 목록\n";
			for (int I = 0; I < 5; I++) { cout << I << " : " << Inventory[I] << "\n"; }
			cout << "기존의 아이템과 교체하실거면 Y, 아니면 N를 입력해주세요\n" << "입력 : ";
			cin >> C;
			if (C == 'N') {
				cout << "아이템을 줍지 않았습니다\n";
				break;
			}
			else if (C == 'Y') {
				cout << "교체할 아이템의 위치를 입력해주세요\n" << "입력 : ";
				cin >> N;
				if (N >= 0 && N <= 4) {
					Inventory[N] = Item_Name;
					break;
				}
				else { cout << "다시 입력해주세요\n"; }
			}
			else { cout << "다시 입력해주세요\n"; }
		}
	}
	else {     //인벤토리에 빈 공간이 있는 경우
		while (true) {
			cout << "인벤토리 목록\n";
			for (int I = 0; I < 5; I++) { cout << I << " : " << Inventory[I] << "\n"; }
			cout << "인벤토리의 몇 번 위치에 두실 겁니까?\n" << "입력 : ";
			cin >> N;
			if (N >= 0 && N <= 4) {
				if (Inventory[N] == "0") {
					Inventory[N] = Item_Name;
					break;
				}
				else { cout << "선택하신 위치에는 이미 아이템이 있습니다. 다른 위치를 선택해 주십시오\n"; }
			}
			else { cout << "0~4의 숫자 중 하나를 입력해주세요\n"; }
		}
	}
}

void Look_Inventory(string Inventory[]) {    //인벤토리 불러오기
	cout << "인벤토리 목록\n";
	for (int I = 0; I < 5; I++) { cout << I << " : " << Inventory[I] << "\n"; }
}

void Swap_Item(string* Inventory) {     //인벤토리에 있는 아이템 위치 변경
	int N1, N2;
	string Temp;
	cout << "인벤토리 목록\n";
	for (int I = 0; I < 5; I++) { cout << I << " : " << Inventory[I] << "\n"; }

	cout << "0~4를 제외한 다른 숫자 입력시 위치 변경이 취소됩니다\n";
	cout << "위치를 변경할 아이템의 번호를 입력해주세요\n" << "입력 : ";
	cin >> N1;
	cout << "선택하신 아이템과 위치를 변경할 아이템의 번호를 입력해주세요\n" << "입력 : ";
	cin >> N2;
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
	int N;
	cout << "인벤토리 목록\n";
	for (int I = 0; I < 5; I++) { cout << I << " : " << Inventory[I] << "\n"; }
	cout << "0~4를 제외한 다른 숫자 입력시 위치 변경이 취소됩니다\n";
	cout << "버릴 아이템의 위치를 입력해주세요\n" << "입력 : ";
	cin >> N;
	if (N >= 0 && N <= 4) { Inventory[N] = "0"; }
	else { cout << "아이템 버리기가 취소되었습니다\n"; }
}