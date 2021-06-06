#pragma once
#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;
//----------------퀘스트 완료 기능은 상점에 추가

string Quest_slot[3] = { "0", "0", "0" };    // 퀘스트 창
class Quest {
public:
	string Goal, Kind;
	int Num;
	Quest(string Goal, string Kind, int Num) {  //Goal은 퀘스트 목표
		this->Goal = Goal;
		this->Kind = Kind;
		this->Num = Num;
	}
};
//----------------메인 퀘스트
Quest Fabric_collecter_n = { "Fabric collecter - Fabric 장비 5개를 인벤토리에 모으세요", "main quest", 0 };
Quest Leather_collecter_n = { "Leather collecter - Leather 장비 5개를 인벤토리에 모으세요", "main quest", 1 };
Quest Wood_collecter_n = { "Wood collecter - Wood 장비 5개를 인벤토리에 모으세요", "main quest", 2 };
Quest Gacha_winner_n = { "Gacha_winner - Bamboo 장비 1개를 인벤토리에 모으세요", "main quest", 3 };
Quest Dungeon_owner_n = { "Dungeon_owner - 8000원을 모아 던전을 구매하세요", "main quest", 4 };
//----------------서브 퀘스트
Quest Miser_n = { "Miser - 2000원을 모아 이자를 받으세요", "sub quest", 0 };
Quest Collecter_n = { "Collecter - 인벤토리를 꽉 채우고 보너스를 받으세요", "sub quest", 1 };
Quest Random_item_n = { "Random item - 소비 아이템을 상점에 가져가보세요, 상점 주인의 마음에 든다면 통상가의 5배를 드립니다.", "sub quest", 2 };
Quest Random_equipment_n = { "Random equipment - 장비 아이템을 상점에 가져가보세요, 상점 주인의 마음에 든다면 통상가의 5배를 드립니다.", "sub quest", 3 };
Quest Scholarship_n = { "Scholarship - 레벨 5를 달성하면 장학금을 드립니다.", "sub quest", 4 };

Quest Main_Quest[5] = { Fabric_collecter_n, Leather_collecter_n, Wood_collecter_n, Gacha_winner_n, Dungeon_owner_n };
Quest Sub_Quest[5] = { Miser_n, Collecter_n, Random_item_n, Random_equipment_n, Scholarship_n };

void Create_Quest(string* Quest_slot) {   //퀘스트 창에 랜덤 퀘스트를 집어넣음
	srand((unsigned int)time(NULL));
	int Main = rand() % 5;
	int Sub1 = rand() % 5;
	int Sub2 = rand() % 5;
	Quest_slot[0] = Main_Quest[Main].Goal;
	Quest_slot[1] = Sub_Quest[Sub1].Goal;
	Quest_slot[2] = Sub_Quest[Sub2].Goal;
}

void Look_Quest() {   //퀘스트 
	cout << "0은 메인 퀘스트, 1과2는 서브 퀘스트입니다.\n";
	cout << "메인 퀘스트를 완료하면 게임이 클리어되고 서브 퀘스트를 완료하면 보상을 받습니다\n";
	cout << "퀘스트 목록\n";
	for (int J = 0; J < 3; J++) {
		cout << "------------------------\n";
		cout << J << " : " << Quest_slot[J] << "\n";
	}
}

void Fabric_Collecter() {
	int Count = 0;
	for (int I = 0; I < 5; I++) {
		if (Inventory[I].find("Fabric") == string::npos) {
			cout << "퀘스트가 완료되지 않았습니다\n";
			break;
		}
		else { Count++; }
	}
	if (Count == 5) {
		cout << "메인 퀘스트가 완료되었습니다\n";
		cout << "GAME CLEAR!!!\n";
	}
}

void Leather_Collecter() {
	int Count = 0;
	for (int I = 0; I < 5; I++) {
		if (Inventory[I].find("Leather") == string::npos) {
			cout << "퀘스트가 완료되지 않았습니다\n";
			break;
		}
		else { Count++; }
	}
	if (Count == 5) {
		cout << "메인 퀘스트가 완료되었습니다\n";
		cout << "GAME CLEAR!!!\n";
	}
}
//----------------퀘스트 
void Wood_Collecter() {
	int Count = 0;
	for (int I = 0; I < 5; I++) {
		if (Inventory[I].find("Wood") == string::npos) {
			cout << "퀘스트가 완료되지 않았습니다\n";
			break;
		}
		else { Count++; }
	}
	if (Count == 5) {
		cout << "메인 퀘스트가 완료되었습니다\n";
		cout << "GAME CLEAR!!!\n";
	}
}

void Gacha_Winner() {
	int Count = 0;
	for (int I = 0; I < 5; I++) {
		if (Inventory[I].find("Fabric") != string::npos) {
			cout << "메인 퀘스트가 완료되었습니다\n";
			cout << "GAME CLEAR!!!\n";
			break;
		}
		else { Count++; }
	}
	if (Count == 5) {
		cout << "퀘스트가 완료되지 않았습니다\n";
	}
}

void Dungeon_Owner() {
	if (SoNB_P->Money >= 8000) {
		cout << "메인 퀘스트가 완료되었습니다\n";
		cout << "GAME CLEAR!!!\n";
	}
	else { cout << "퀘스트가 완료되지 않았습니다\n"; }
}

bool Miser() {
	if (SoNB_P->Money >= 2000) {
		cout << "서브 퀘스트가 완료되었습니다\n";
		cout << "보상으로 1000원을 받았습니다\n";
		SoNB_P->Money += 1000;
		return true;
	}
	else { 
		cout << "퀘스트가 완료되지 않았습니다\n";
		return false;
	}
}

bool Collecter() {
	int Count = 0;
	for (int I = 0; I < 5; I++) {
		if (Inventory[I] == "0") {
			cout << "퀘스트가 완료되지 않았습니다\n";
			return false;
		}
		else { Count++; }
	}
	if (Count == 5) {
		cout << "서브 퀘스트가 완료되었습니다\n";
		cout << "보상으로 1000원을 받았습니다\n";
		SoNB_P->Money += 1000;
		return true;
	}
}

bool Random_Item() {
	srand((unsigned int)time(NULL));
	int N;
	int Num = rand() % 14;
	string R_item = Items[Num].Name;
	int R_price = Items[Num].Price;
	setColor(2);
	cout << "\n인벤토리 목록\n";
	setColor(15);

	for (int I = 0; I < 5; I++) { cout << I << " : " << Inventory[I] << "\n"; }
	cout << "------------------------\n";
	cout << "상점 주인에게 건낼 아이템의 숫자를 입력해주세요\n";
	cout << "0~4 이외의 숫자를 입력하면 취소됩니다.\n";
	cout << "입력 : ";
	cin >> N;
	cout << "------------------------\n";
	if (Inventory[N] == R_item) {
		cout << "서브 퀘스트가 완료되었습니다\n";
		cout << "보상으로 " << R_price * 5 << "원을 받았습니다.\n";
		SoNB_P->Money += R_price * 5;
		return true;
	}
	else {
		cout << "이게 아니야!!!\n";
		cout << "상점 주인이 화가 났습니다...\n";
		return false;
	}
}

bool Random_Equipment() {
	srand((unsigned int)time(NULL));
	int N;
	int Num = rand() % 15;
	string R_equipment = Equipments[Num].Name;
	int R_price = Equipments[Num].Price;
	setColor(2);
	cout << "\n인벤토리 목록\n";
	setColor(15);

	for (int I = 0; I < 5; I++) { cout << I << " : " << Inventory[I] << "\n"; }
	cout << "------------------------\n";
	cout << "상점 주인에게 건낼 아이템의 숫자를 입력해주세요\n";
	cout << "0~4 이외의 숫자를 입력하면 취소됩니다.\n";
	cout << "입력 : ";
	cin >> N;
	cout << "------------------------\n";
	if (Inventory[N] == R_equipment) {
		cout << "서브 퀘스트가 완료되었습니다\n";
		cout << "보상으로 " << R_price * 5 << "원을 받았습니다.\n";
		SoNB_P->Money += R_price * 5;
		return true;
	}
	else {
		cout << "이게 아니야!!!\n";
		cout << "상점 주인이 화가 났습니다...\n";
		return false;
	}
}

bool Scholarship() {
	if (SoNB_P->Level >= 5) {
		cout << "서브 퀘스트가 완료되었습니다\n";
		cout << "보상으로 1000원을 받았습니다\n";
		SoNB_P->Money += 1000;
		return true;
	}
	else {
		cout << "퀘스트가 완료되지 않았습니다\n";
		return false;
	}
}
