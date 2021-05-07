#include <iostream> 
#include <string>
using namespace std;

// 인벤토리의 빈 공간을 "0"으로 표현함
// 인벤토리를 0~4의 5개 공간을 가진 배열로 구현

							//아이템
							//아이템 세부 설정은 밑에 있음
struct hp_item {
	string name;
	int hp;
	hp_item() {}
};

struct mp_item {
	string name;
	int mp;
	mp_item() {}
};

struct atk_item {
	string name;
	int atk;
	atk_item() {}
};

struct def_item {
	string name;
	int def;
	def_item() {}
};

struct spd_item {
	string name;
	int spd;
	spd_item() {}
};

struct hp_mp_item {
	string name;
	int hp;
	int mp;
	hp_mp_item() {}
};

struct atk_def_item {
	string name;
	int atk;
	int def;
	atk_def_item() {}
};


void pick_up_item(string inventory[], string item) { //아이템을 주울 때
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
			cout << "기존의 아이템과 교체하실거면 Y, 아니면 N를 눌러주세요\n" << "입력 : ";
			cin >> c;
			if (c == 'N') {
				cout << "아이템을 줍지 않았습니다\n";
				break;
			}
			else if (c == 'Y') {
				cout << "교체할 아이템의 위치를 입력해주세요\n" << "입력 : ";
				cin >> n;
				if (n >= 0 && n <= 4) {
					inventory[n] = item;
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
			if (inventory[n] == "0") {
				inventory[n] = item;
				break;
			}
			else { cout << "선택하신 위치에는 이미 아이템이 있습니다. 다른 위치를 선택해 주십시오\n"; }
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

	cout << "0~4를 제외한 다른 문자 입력시 위치 변경이 취소됩니다\n";
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
	cout << "0~4를 제외한 다른 문자 입력시 위치 변경이 취소됩니다\n";
	cout << "버릴 아이템의 위치를 입력해주세요\n" << "입력 : ";
	cin >> n;
	if (n >= 0 && n <= 4) { inventory[n] = "0"; }
	else { cout << "아이템 버리기가 취소되었습니다\n"; }

}


void use_item(string inventory[], struct My_Character SoNB, struct hp_item hp_item[], struct mp_item mp_item[],
	struct atk_item atk_item[], struct def_item def_item[], struct spd_item spd_item[],
	struct hp_mp_item hp_mp_item[], struct atk_def_item atk_def_item[]) {		//아이템을 사용할 때

	int n;
	cout << "인벤토리 목록\n";
	for (int i = 0; i < 5; i++) { cout << i << " : " << inventory[i] << "\n"; }
	cout << "0~4를 제외한 다른 문자 입력시 아이템 사용이 취소됩니다\n";
	cout << "사용할 아이템의 위치를 입력해주세요\n" << "위치 : ";
	cin >> n;
	if (n >= 0 && n <= 4) {
		if (inventory[n] == "0") { cout << "선택하신 위치에 아이템이 없습니다\n"; }
		else {
			int i = 0;
			while (true) {
				if (inventory[n] == hp_item[i].name) {
					cout << "기존 hp : " << hp << "\n";
					hp += hp_item[i].hp;
					inventory[n] = "0";
					cout << "현재 hp : " << hp << "\n";
					break;
				}
				else if (inventory[n] == mp_item[i].name) {
					cout << "기존 mp : " << mp << "\n";
					mp += mp_item[i].mp;
					inventory[n] = "0";
					cout << "현재 mp : " << mp << "\n";
					break;
				}
				else if (inventory[n] == atk_item[i].name) {
					cout << "기존 atk : " << atk << "\n";
					atk += atk_item[i].atk;
					inventory[n] = "0";
					cout << "현재 atk : " << atk << "\n";
					break;
				}
				else if (inventory[n] == def_item[i].name) {
					cout << "기존 def : " << def << "\n";
					def += def_item[i].def;
					inventory[n] = "0";
					cout << "현재 def : " << def << "\n";
					break;
				}
				else if (inventory[n] == spd_item[i].name) {
					cout << "기존 spd : " << spd << "\n";
					spd += spd_item[i].spd;
					inventory[n] = "0";
					cout << "현재 spd : " << spd << "\n";
					break;
				}
				else if (inventory[n] == hp_mp_item[i].name) {
					cout << "기존 hp : " << hp << "\n";
					cout << "기존 mp : " << mp << "\n";
					hp += hp_mp_item[i].hp;
					mp += hp_mp_item[i].mp;
					inventory[n] = "0";
					cout << "현재 hp : " << hp << "\n";
					cout << "현재 mp : " << mp << "\n";
					break;
				}
				else if (inventory[n] == atk_def_item[i].name) {
					cout << "기존 atk : " << atk << "\n";
					cout << "기존 def : " << def << "\n";
					atk += atk_def_item[i].atk;
					def += atk_def_item[i].def;
					inventory[n] = "0";
					cout << "현재 atk : " << atk << "\n";
					cout << "현재 def : " << def << "\n";
					break;
				}
				i++;
			}
		}
	}
}


/*int main() {          //테스트

	string inventory[5] = { "0","0","0","0","0" };		//인벤토리
														//메인 함수에 추가해야 함


												//아이템 세부설정
												//메인 함수에 추가해야 함
												//밸런스를 고려하지 않고 대충 만든 테스트용 아이템

	struct hp_item hp_item[2];
	hp_item[0].name = "red potion";
	hp_item[0].hp = 10;
	hp_item[1].name = "yellow potion";
	hp_item[1].hp = 20;

	struct mp_item mp_item[2];
	mp_item[0].name = "blue potion";
	mp_item[0].mp = 10;
	mp_item[1].name = "purple potion";
	mp_item[1].mp = 20;

	struct atk_item atk_item[2];
	atk_item[0].name = "carrot";
	atk_item[0].atk = 10;
	atk_item[1].name = "protein";
	atk_item[1].atk = 20;

	struct def_item def_item[2];
	def_item[0].name = "radish";
	def_item[0].def = 10;
	def_item[1].name = "sugar";
	def_item[1].def = 20;

	struct spd_item spd_item[2];
	spd_item[0].name = "banana";
	spd_item[0].spd = 10;
	spd_item[1].name = "pear";
	spd_item[1].spd = 20;

	struct hp_mp_item hp_mp_item[2];
	hp_mp_item[0].name = "sweet_potato";
	hp_mp_item[0].hp = 30;
	hp_mp_item[0].mp = -10;
	hp_mp_item[1].name = "dew";
	hp_mp_item[1].hp = -10;
	hp_mp_item[1].mp = 30;

	struct atk_def_item atk_def_item[2];
	atk_def_item[0].name = "chili";
	atk_def_item[0].atk = 30;
	atk_def_item[0].def = -10;
	atk_def_item[1].name = "tea";
	atk_def_item[1].atk = -10;
	atk_def_item[1].def = 30;					//여기까지가 아이템
												//밑에는 신경 쓸 필요 없음(메인 함수 추가 X)



	string item = mp_item[1].name;
	string item2 = atk_def_item[0].name;

	pick_up_item(inventory, item);
	pick_up_item(inventory, item2);

	use_item(inventory, SoNB, hp_item, mp_item, atk_item, def_item, spd_item, hp_mp_item, atk_def_item, );
	use_item(inventory, SoNB, hp_item, mp_item, atk_item, def_item, spd_item, hp_mp_item, atk_def_item);

	look_inventory(inventory);
}*/