#pragma once
#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include "map.h"
using namespace std;

int Quest_num = 11;
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
Quest Dungeon_clear_n = { "Dungeon_clear - 오크 킹을 1번 이상 잡으세요", "main quest", 5 };
Quest Potion_shower_n = { "Potion_shower - 4 종류의 모든 포션을 각각 1번 이상 사용하세요", "main quest", 6 };
//----------------서브 퀘스트
Quest Miser_n = { "Miser - 2000원을 모아 이자를 받으세요", "sub quest", 0 };
Quest Collecter_n = { "Collecter - 인벤토리를 꽉 채우고 보너스를 받으세요", "sub quest", 1 };
Quest Random_item_n = { "Random item - 소비 아이템을 상점에 가져가보세요, 상점 주인의 마음에 든다면 통상가의 5배를 드립니다.", "sub quest", 2 };
Quest Random_equipment_n = { "Random equipment - 장비 아이템을 상점에 가져가보세요, 상점 주인의 마음에 든다면 통상가의 5배를 드립니다.", "sub quest", 3 };
Quest Scholarship_n = { "Scholarship - 레벨 5를 달성하면 장학금을 드립니다.", "sub quest", 4 };
Quest Slime_slayer_n = { "Slime slayer - 슬라임을 3번 이상 잡으세요", "sub quest", 5 };
Quest Goblin_slayer_n = { "Goblin slayer - 고블린을 3번 이상 잡으세요", "sub quest", 6 };
Quest Orc_slayer_n = { "Orc slayer - 오크를 3번 이상 잡으세요", "sub quest", 7 };
Quest Protein_addiction_n = { "Protein addiction - Protein을 2번 이상 사용하세요", "sub quest", 8 };
Quest Sugar_addiction_n = { "Sugar addiction - Sugar를 2번 이상 사용하세요", "sub quest", 9 };
Quest Pear_addiction_n = { "Pear addiction - Pear를 2번 이상 사용하세요", "sub quest", 10 };

Quest Main_Quest[7] = { Fabric_collecter_n, Leather_collecter_n, Wood_collecter_n,
Gacha_winner_n, Dungeon_owner_n, Dungeon_clear_n, Potion_shower_n };
Quest Sub_Quest[11] = { Miser_n, Collecter_n, Random_item_n, Random_equipment_n, Scholarship_n,
Slime_slayer_n, Goblin_slayer_n, Orc_slayer_n, Protein_addiction_n, Sugar_addiction_n, Pear_addiction_n };

void Create_Quest(string* Quest_slot) {   //퀘스트 창에 랜덤 퀘스트를 집어넣음
	srand((unsigned int)time(NULL));
	if (Quest_num > 2) {
		int Main = rand() % 7;
		Quest_slot[0] = Main_Quest[Main].Goal;
		int Sub1 = rand() % Quest_num;
		Quest_slot[1] = Sub_Quest[Sub1].Goal;
		Quest Temp = Sub_Quest[Sub1];
		for (int I = Sub1; I < Quest_num - 1; I++) {
			Sub_Quest[I] = Sub_Quest[I + 1];
		}
		Quest_num--;
		int Sub2 = rand() % Quest_num;
		Quest_slot[2] = Sub_Quest[Sub2].Goal;
		for (int I = 10; I > Sub1; I--) {
			Sub_Quest[I] = Sub_Quest[I - 1];
		}
		Sub_Quest[Sub1] = Temp;
		Quest_num++;
	}
}

void Look_Quest() {   //퀘스트 
	cout << "------------------------\n";
	cout << "0은 메인 퀘스트, 1과2는 서브 퀘스트입니다.\n";
	cout << "메인 퀘스트를 완료하면 게임이 클리어되고 서브 퀘스트를 완료하면 보상을 받습니다\n";
	setColor(2);
	cout << "퀘스트 목록\n";
	setColor(15);
	for (int J = 0; J < 3; J++) {
		cout << "------------------------\n";
		cout << J << " : " << Quest_slot[J] << "\n";
	}
	cout << "------------------------\n";
	if (Quest_slot[0] == Main_Quest[5].Goal) {
		cout << "현재 오크 킹을 " << Orc_Boss_P->Count << "번 잡았습니다.\n";
		cout << "------------------------\n";
	}
	else if (Quest_slot[0] == Main_Quest[6].Goal) {
		cout << "현재 Red potion을 " << Red_portion_p->Count << "번 사용했습니다.\n";
		cout << "현재 Yellow potion을 " << Yellow_portion_p->Count << "번 사용했습니다.\n";
		cout << "현재 Blue potion을 " << Blue_portion_p->Count << "번 사용했습니다.\n";
		cout << "현재 Purple potion을 " << Purple_portion_p->Count << "번 사용했습니다.\n";
		cout << "------------------------\n";
	}

	if (Quest_slot[1] == Sub_Quest[5].Goal || Quest_slot[2] == Sub_Quest[5].Goal) {
		cout << "현재 슬라임을 " << Slime_Normal_P->Count << "번 잡았습니다.\n";
		cout << "------------------------\n";
	}
	else if (Quest_slot[1] == Sub_Quest[6].Goal || Quest_slot[2] == Sub_Quest[6].Goal) {
		cout << "현재 고블린을 " << Goblin_Normal_P->Count << "번 잡았습니다.\n";
		cout << "------------------------\n";
	}
	else if (Quest_slot[1] == Sub_Quest[7].Goal || Quest_slot[2] == Sub_Quest[7].Goal) {
		cout << "현재 오크를 " << Orc_Normal_P->Count << "번 잡았습니다.\n";
		cout << "------------------------\n";
	}
	else if (Quest_slot[1] == Sub_Quest[8].Goal || Quest_slot[2] == Sub_Quest[8].Goal) {
		cout << "현재 Protein을 " << Protein_p->Count << "번 사용했습니다.\n";
		cout << "------------------------\n";
	}
	else if (Quest_slot[1] == Sub_Quest[9].Goal || Quest_slot[2] == Sub_Quest[9].Goal) {
		cout << "현재 Sugar를 " << Sugar_p->Count << "번 사용했습니다.\n";
		cout << "------------------------\n";
	}
	else if (Quest_slot[1] == Sub_Quest[10].Goal || Quest_slot[2] == Sub_Quest[10].Goal) {
		cout << "현재 Pear를 " << Pear_p->Count << "번 사용했습니다.\n";
		cout << "------------------------\n";
	}
}
//----------------메인 퀘스트 
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
		if (Inventory[I].find("Bamboo") != string::npos) {
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

void Dungeon_Clear() {
	if (Orc_Boss_P->Count >= 1) {
		cout << "메인 퀘스트가 완료되었습니다\n";
		cout << "GAME CLEAR!!!\n";
	}
	else {
		cout << "퀘스트가 완료되지 않았습니다\n";
		cout << "현재 오크 킹을 " << Orc_Boss_P->Count << "번 잡았습니다.\n";
	}
}

void Potion_Shower() {
	if (Red_portion_p->Count >= 1 && Yellow_portion_p->Count >= 1
		&& Blue_portion_p->Count >= 1 && Purple_portion_p->Count >= 1) {
		cout << "메인 퀘스트가 완료되었습니다\n";
		cout << "GAME CLEAR!!!\n";
	}
	else {
		cout << "퀘스트가 완료되지 않았습니다\n";
		cout << "현재 Red potion을 " << Red_portion_p->Count << "번 사용했습니다.\n";
		cout << "현재 Yellow potion을 " << Yellow_portion_p->Count << "번 사용했습니다.\n";
		cout << "현재 Blue potion을 " << Blue_portion_p->Count << "번 사용했습니다.\n";
		cout << "현재 Purple potion을 " << Purple_portion_p->Count << "번 사용했습니다.\n";
	}
}
//----------------서브 퀘스트 
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
	N = _getch() - 48;
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
	N = _getch() - 48;
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

bool Slime_Slayer() {
	if (Slime_Normal_P->Count >= 3) {
		cout << "서브 퀘스트가 완료되었습니다\n";
		cout << "보상으로 1000원을 받았습니다\n";
		SoNB_P->Money += 1000;
		return true;
	}
	else {
		cout << "퀘스트가 완료되지 않았습니다\n";
		cout << "현재 슬라임을 " << Slime_Normal_P->Count << "번 잡았습니다.\n";
		return false;
	}
}

bool Goblin_Slayer() {
	if (Goblin_Normal_P->Count >= 3) {
		cout << "서브 퀘스트가 완료되었습니다\n";
		cout << "보상으로 1000원을 받았습니다\n";
		SoNB_P->Money += 1000;
		return true;
	}
	else {
		cout << "퀘스트가 완료되지 않았습니다\n";
		cout << "현재 고블린을 " << Goblin_Normal_P->Count << "번 잡았습니다.\n";
		return false;
	}
}

bool Orc_Slayer() {
	if (Orc_Normal_P->Count >= 3) {
		cout << "서브 퀘스트가 완료되었습니다\n";
		cout << "보상으로 1000원을 받았습니다\n";
		SoNB_P->Money += 1000;
		return true;
	}
	else {
		cout << "퀘스트가 완료되지 않았습니다\n";
		cout << "현재 오크를 " << Orc_Normal_P->Count << "번 잡았습니다.\n";
		return false;
	}
}

bool Protein_Addiction() {
	if (Protein_p->Count >= 2) {
		cout << "서브 퀘스트가 완료되었습니다\n";
		cout << "보상으로 1000원을 받았습니다\n";
		SoNB_P->Money += 1000;
		return true;
	}
	else {
		cout << "퀘스트가 완료되지 않았습니다\n";
		cout << "현재 Protein을 " << Protein_p->Count << "번 사용했습니다.\n";
		return false;
	}
}

bool Sugar_Addiction() {
	if (Sugar_p->Count >= 2) {
		cout << "서브 퀘스트가 완료되었습니다\n";
		cout << "보상으로 1000원을 받았습니다\n";
		SoNB_P->Money += 1000;
		return true;
	}
	else {
		cout << "퀘스트가 완료되지 않았습니다\n";
		cout << "현재 Sugar를 " << Sugar_p->Count << "번 사용했습니다.\n";
		return false;
	}
}

bool Pear_Addiction() {
	if (Pear_p->Count >= 2) {
		cout << "서브 퀘스트가 완료되었습니다\n";
		cout << "보상으로 1000원을 받았습니다\n";
		SoNB_P->Money += 1000;
		return true;
	}
	else {
		cout << "퀘스트가 완료되지 않았습니다\n";
		cout << "현재 Pear를 " << Pear_p->Count << "번 사용했습니다.\n";
		return false;
	}
}
