#include <iostream> 
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;

// 인벤토리의 빈 공간을 "0"으로 표현함

struct item {
	string name;
	double hp, mp, atk, def, speed;
	item(double hp = 0, double mp = 0, double atk = 0,
		double def = 0, double speed = 0) {
		this->hp = hp;
		this->mp = mp;
		this->atk = atk;
		this->def = def;
		this->speed = speed;
	}
};

string drop_item(struct item item[]) {   //드롭되는 아이템 결정
	srand((unsigned int)time(NULL));
	int n = rand() % 14;  //14는 item배열 크기
	string drop_item = item[n].name;
	return drop_item;
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


void use_item(My_Character* character, string inventory[], struct item item[]) {
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
				if (inventory[n] == item[i].name) {
					character->hp += item[i].hp;
					character->mp += item[i].mp;
					character->atk += item[i].atk;
					character->def += item[i].def;
					character->speed += item[i].speed;
					inventory[n] = "0";
					cout << item[i].name << "을 사용했습니다\n";
					cout << "hp : " << character->hp - item[i].hp << " -> " << character->hp << "\n";
					cout << "mp : " << character->mp - item[i].mp << " -> " << character->mp << "\n";
					cout << "atk : " << character->atk - item[i].atk << " -> " << character->atk << "\n";
					cout << "def : " << character->def - item[i].def << " -> " << character->def << "\n";
					cout << "speed : " << character->speed - item[i].speed << " -> " << character->speed << "\n";
					break;
				}
			}
		}
	}
	else { cout << "아이템 사용이 취소되었습니다\n"; }
}


/*int main() {        //예제 실행

	string inventory[5] = { "0","0","0","0","0" };  //인벤토리, 메인 함수에 추가해야 함

													//여기서부터 아이템 목록, 메인함수에 추가해야 함
	struct item item[14];
	item[0].name = "red potion";
	item[0].hp = 10;
	item[1].name = "yellow potion";
	item[1].hp = 20;

	item[2].name = "blue potion";
	item[2].mp = 10;
	item[3].name = "purple potion";
	item[3].mp = 20;

	item[4].name = "carrot";
	item[4].atk = 10;
	item[5].name = "protein";
	item[5].atk = 20;

	item[6].name = "radish";
	item[6].def = 10;
	item[7].name = "sugar";
	item[7].def = 20;

	item[8].name = "banana";
	item[8].speed = 10;
	item[9].name = "pear";
	item[9].speed = 20;

	item[10].name = "sweet_potato";
	item[10].hp = 30;
	item[10].mp = -10;
	item[11].name = "dew";
	item[11].hp = -10;
	item[11].mp = 30;

	item[12].name = "chili";
	item[12].atk = 30;
	item[12].def = -10;
	item[13].name = "tea";
	item[13].atk = -10;
	item[13].def = 30;
													//여기까지 아이템 목록


	string item_name = item[11].name;
	string item_name2 = item[12].name;

	pick_up_item(inventory, item_name);
	pick_up_item(inventory, item_name2);

	use_item(SoNB_P, inventory, item);
	use_item(SoNB_P, inventory, item);
	
	string a = drop_item(item);

	look_inventory(inventory);
}
*/