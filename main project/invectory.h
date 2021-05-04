#pragma once
#include <iostream> 
using namespace std;

string pick_up_item(string inventory, string item) {    //아이템을 주울 때
	int count = 0;
	int n;
	char c;
	for (int i = 0; i < 5; i++) {      //인벤토리에 빈공간이 있는지 확인
		if (inventory[i] == '0') { count++; }
	}
	if (count == 0) {    //인벤토리가 가득 찬 경우
		cout << "인벤토리가 가득 찼습니다.\n";
		while (true) {
			cout << "기존의 아이템과 교체하실거면 Y, 아니면 N를 눌러주세요\n" << "입력 : ";
			cin >> c;
			if (c == 'N') {
				cout << "아이템을 줍지 않았습니다\n";
				break;
			}
			else if (c == 'Y') {
				cout << "교체할 아이템의 위치를 입력해주세요\n" << "입력 : ";
				cin >> n;
				inventory[n] = item;
				break;
			}
			else { cout << "다시 입력해주세요\n"; }
		}
	}
	else {     //인벤토리에 빈 공간이 있는 경우
		while (true) {
			cout << "인벤토리의 몇 번 위치에 두실 겁니까?\n" << "위치 입력 : ";
			cin >> n;
			if (inventory[n] == '0') {
				inventory[n] = item;
				break;
			}
			else { cout << "선택하신 위치에는 이미 아이템이 있습니다. 다른 위치를 선택해 주십시오\n"; }
		}
	}
}