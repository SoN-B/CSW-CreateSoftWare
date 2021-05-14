#include <iostream> 
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;

// 인벤토리의 빈 공간을 "0"으로 표현함

struct item {
	string name;
	double hp, mp, atk, def, speed;
	item(string name, double hp = 0, double mp = 0, double atk = 0,
		double def = 0, double speed = 0) {
		this->name = name;
		this->hp = hp;
		this->mp = mp;
		this->atk = atk;
		this->def = def;
		this->speed = speed;
	}
};

//----------------hp
item red_portion = { "red potion",10 };
item yellow_portion = { "yellow potion",20 };
//----------------mp
item blue_portion = { "blue potion",0,10 };
item purple_portion = { "purple potion",0,20 };
//----------------atk
item carrot = { "carrot",0,0,10 };
item protein = { "protein",0,0,20 };
//----------------def
item radish = { "radish",0,0,0,5 };
item sugar = { "sugar",0,0,0,10 };
//----------------speed
item banana = { "banana",0,0,0,0,0.5 };
item pear = { "pear",0,0,0,0,1 };
//----------------hp,mp
item sweet_potato = { "sweet potato",30,-10,0,0,0 };
item dew = { "dew",-10,30,0,0,0 };
//----------------atk,def
item chili = { "chili",0,0,30,-10,0 };
item tea = { "tea",0,0,-10,30,0 };

item items[14] = { red_portion,yellow_portion,blue_portion,purple_portion
,carrot ,protein ,radish ,sugar ,banana ,pear ,sweet_potato,dew,chili,tea };

string drop_item(item items[]) {
	srand((unsigned int)time(NULL));
	int i = rand() % 10;
	if (i < 5) {   //아이템 드랍 확률
		int n = rand() % 14;  //14는 item배열 크기
		string drop_item = items[n].name;
		cout << "몬스터에게서 " << drop_item << "이 떨어졌다!!!\n";
		return drop_item;
	}
}

void item_list() {
	cout << "0.red potion : hp +10\n";
	cout << "1.yellow potion : hp +20\n";
	cout << "2.blue potion : mp +10\n";
	cout << "3.purple potion : mp +20\n";
	cout << "4.carrot : atk +10\n";
	cout << "5.protein : atk +20\n";
	cout << "6.radish : def +5\n";
	cout << "7.sugar : def +10\n";
	cout << "8.banana : speed +5\n";
	cout << "9.pear : speed +1\n";
	cout << "10.sweet potato : hp +30\n";
	cout << "                : mp -10\n";
	cout << "11.dew : hp -10\n";
	cout << "       : mp +30\n";
	cout << "12.chili : atk +30\n";
	cout << "         : def -10\n";
	cout << "13.tea : atk -10\n";
	cout << "       : def +30\n";
}

void pick_up_item(string inventory[], string item_name) { //아이템을 주울 때
	int count = 0;
	int n;
	char c;
	for (int i = 0; i < 5; i++) {      //인벤토리에 빈공간이 있는지 확인
		if (inventory[i] == "0") { count++; }
	}
	if (count == 0) {    //인벤토리가 가득 찬 경우
		cout << "인벤토리가 가득 찼습니다.\n";
		while (true) {
			cout << "인벤토리 목록\n";
			for (int i = 0; i < 5; i++) { cout << i << " : " << inventory[i] << "\n"; }
			cout << "기존의 아이템과 교체하실거면 Y, 아니면 N를 입력해주세요\n" << "입력 : ";
			cin >> c;
			if (c == 'N') {
				cout << "아이템을 줍지 않았습니다\n";
				break;
			}
			else if (c == 'Y') {
				cout << "교체할 아이템의 위치를 입력해주세요\n" << "입력 : ";
				cin >> n;
				if (n >= 0 && n <= 4) {
					inventory[n] = item_name;
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
			for (int i = 0; i < 5; i++) { cout << i << " : " << inventory[i] << "\n"; }
			cout << "인벤토리의 몇 번 위치에 두실 겁니까?\n" << "입력 : ";
			cin >> n;
			if (n >= 0 && n <= 4) {
				if (inventory[n] == "0") {
					inventory[n] = item_name;
					break;
				}
				else { cout << "선택하신 위치에는 이미 아이템이 있습니다. 다른 위치를 선택해 주십시오\n"; }
			}
			else { cout << "0~4의 숫자 중 하나를 입력해주세요\n"; }
		}
	}
}

void look_inventory(string inventory[]) {    //인벤토리 불러오기
	cout << "인벤토리 목록\n";
	for (int i = 0; i < 5; i++) { cout << i << " : " << inventory[i] << "\n"; }
}

void swap_item(string inventory[]) {     //인벤토리에 있는 아이템 위치 변경
	int n1, n2;
	string temp;
	cout << "인벤토리 목록\n";
	for (int i = 0; i < 5; i++) { cout << i << " : " << inventory[i] << "\n"; }

	cout << "0~4를 제외한 다른 숫자 입력시 위치 변경이 취소됩니다\n";
	cout << "위치를 변경할 아이템의 번호를 입력해주세요\n" << "입력 : ";
	cin >> n1;
	cout << "선택하신 아이템과 위치를 변경할 아이템의 번호를 입력해주세요\n" << "입력 : ";
	cin >> n2;
	if (n1 >= 0 && n1 <= 4) {
		if (n2 >= 0 && n2 <= 4) {
			temp = inventory[n1];
			inventory[n1] = inventory[n2];
			inventory[n2] = temp;
		}
	}
	else { cout << "아이템의 위치 변경이 취소되었습니다\n"; }
}


void throw_away_item(string inventory[]) {       //아이템을 버릴 때
	int n;
	cout << "인벤토리 목록\n";
	for (int i = 0; i < 5; i++) { cout << i << " : " << inventory[i] << "\n"; }
	cout << "0~4를 제외한 다른 숫자 입력시 위치 변경이 취소됩니다\n";
	cout << "버릴 아이템의 위치를 입력해주세요\n" << "입력 : ";
	cin >> n;
	if (n >= 0 && n <= 4) { inventory[n] = "0"; }
	else { cout << "아이템 버리기가 취소되었습니다\n"; }
}