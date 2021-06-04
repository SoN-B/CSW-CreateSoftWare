#pragma once
#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;

string Quest_slot[3] = { "0", "0", "0" };    // ����Ʈ â
class Quest {
public:
	string Goal, Kind;
	int Num;
	Quest(string Goal, string Kind, int Num) {  //Goal�� ����Ʈ ��ǥ
		this->Goal = Goal;
		this->Kind = Kind;
		this->Num = Num;
	}
};

Quest Fabric_collecter_n = { "Fabric collecter - Fabric ��� 5���� �κ��丮�� ��������", "main quest", 0 };
Quest Leather_collecter_n = { "Leather collecter - Leather ��� 5���� �κ��丮�� ��������", "main quest", 1 };
Quest Wood_collecter_n = { "Wood collecter - Wood ��� 5���� �κ��丮�� ��������", "main quest", 2 };
Quest Gacha_winner_n = { "Gacha_winner - Bamboo ��� 1���� �κ��丮�� ��������", "main quest", 3 };
Quest Dungeon_owner_n = { "Dungeon_owner - 8000���� ��� ������ �����ϼ���", "main quest", 4 };
Quest Miser_n = { "Miser - 2000���� ��� ���ڸ� ��������", "sub quest", 0 };
Quest Collecter_n = { "Collecter - �κ��丮�� �� ä��� ���ʽ��� ��������", "sub quest", 1 };
Quest Random_item_n = { "Random item - �Һ� �������� ������ ������������, ���� ������ ������ ��ٸ� ����� 5�踦 �帳�ϴ�.", "sub quest", 2 };
Quest Random_equipment_n = { "Random equipment - ��� �������� ������ ������������, ���� ������ ������ ��ٸ� ����� 5�踦 �帳�ϴ�.", "sub quest", 3 };
Quest Scholarship_n = { "Scholarship - ���� 5�� �޼��ϸ� ���б��� �帳�ϴ�.", "sub quest", 4 };

Quest Main_Quest[5] = { Fabric_collecter_n, Leather_collecter_n, Wood_collecter_n, Gacha_winner_n, Dungeon_owner_n };
Quest Sub_Quest[5] = { Miser_n, Collecter_n, Random_item_n, Random_equipment_n, Scholarship_n };

void Create_Quest(string* Quest_slot) {
	srand((unsigned int)time(NULL));
	int Main = rand() % 5;
	int Sub1 = rand() % 5;
	int Sub2 = rand() % 5;
	Quest_slot[0] = Main_Quest[Main].Goal;
	Quest_slot[1] = Sub_Quest[Sub1].Goal;
	Quest_slot[2] = Sub_Quest[Sub2].Goal;
}

void Look_Quest() {
	cout << "0�� ���� ����Ʈ, 1��2�� ���� ����Ʈ�Դϴ�.\n";
	cout << "���� ����Ʈ�� �Ϸ��ϸ� ������ Ŭ����ǰ� ���� ����Ʈ�� �Ϸ��ϸ� ������ �޽��ϴ�\n";
	cout << "����Ʈ ���\n";
	for (int J = 0; J < 3; J++) {
		cout << "------------------------\n";
		cout << J << " : " << Quest_slot[J] << "\n";
	}
}

void Fabric_Collecter() {
	int Count = 0;
	for (int I = 0; I < 5; I++) {
		if (Inventory[I].find("Fabric") == string::npos) {
			cout << "����Ʈ�� �Ϸ���� �ʾҽ��ϴ�\n";
			break;
		}
		else { Count++; }
	}
	if (Count == 5) {
		cout << "���� ����Ʈ�� �Ϸ�Ǿ����ϴ�\n";
		cout << "GAME CLEAR!!!\n";
	}
}

void Leather_Collecter() {
	int Count = 0;
	for (int I = 0; I < 5; I++) {
		if (Inventory[I].find("Leather") == string::npos) {
			cout << "����Ʈ�� �Ϸ���� �ʾҽ��ϴ�\n";
			break;
		}
		else { Count++; }
	}
	if (Count == 5) {
		cout << "���� ����Ʈ�� �Ϸ�Ǿ����ϴ�\n";
		cout << "GAME CLEAR!!!\n";
	}
}

void Wood_Collecter() {
	int Count = 0;
	for (int I = 0; I < 5; I++) {
		if (Inventory[I].find("Wood") == string::npos) {
			cout << "����Ʈ�� �Ϸ���� �ʾҽ��ϴ�\n";
			break;
		}
		else { Count++; }
	}
	if (Count == 5) {
		cout << "���� ����Ʈ�� �Ϸ�Ǿ����ϴ�\n";
		cout << "GAME CLEAR!!!\n";
	}
}

void Gacha_Winner() {
	int Count = 0;
	for (int I = 0; I < 5; I++) {
		if (Inventory[I].find("Fabric") != string::npos) {
			cout << "���� ����Ʈ�� �Ϸ�Ǿ����ϴ�\n";
			cout << "GAME CLEAR!!!\n";
			break;
		}
		else { Count++; }
	}
	if (Count == 5) {
		cout << "����Ʈ�� �Ϸ���� �ʾҽ��ϴ�\n";
	}
}

void Dungeon_Owner() {
	if (Money >= 8000) {
		cout << "���� ����Ʈ�� �Ϸ�Ǿ����ϴ�\n";
		cout << "GAME CLEAR!!!\n";
	}
	else { cout << "����Ʈ�� �Ϸ���� �ʾҽ��ϴ�\n"; }
}

bool Miser() {
	if (Money >= 2000) {
		cout << "���� ����Ʈ�� �Ϸ�Ǿ����ϴ�\n";
		cout << "�������� 1000���� �޾ҽ��ϴ�\n";
		Money += 1000;
		return true;
	}
	else { 
		cout << "����Ʈ�� �Ϸ���� �ʾҽ��ϴ�\n";
		return false;
	}
}

bool Collecter() {
	int Count = 0;
	for (int I = 0; I < 5; I++) {
		if (Inventory[I] == "0") {
			cout << "����Ʈ�� �Ϸ���� �ʾҽ��ϴ�\n";
			return false;
		}
		else { Count++; }
	}
	if (Count == 5) {
		cout << "���� ����Ʈ�� �Ϸ�Ǿ����ϴ�\n";
		cout << "�������� 1000���� �޾ҽ��ϴ�\n";
		Money += 1000;
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
	cout << "\n�κ��丮 ���\n";
	setColor(15);

	for (int I = 0; I < 5; I++) { cout << I << " : " << Inventory[I] << "\n"; }
	cout << "------------------------\n";
	cout << "���� ���ο��� �ǳ� �������� ���ڸ� �Է����ּ���\n";
	cout << "0~4 �̿��� ���ڸ� �Է��ϸ� ��ҵ˴ϴ�.\n";
	cout << "�Է� : ";
	cin >> N;
	cout << "------------------------\n";
	if (Inventory[N] == R_item) {
		cout << "���� ����Ʈ�� �Ϸ�Ǿ����ϴ�\n";
		cout << "�������� " << R_price * 5 << "���� �޾ҽ��ϴ�.\n";
		Money += R_price * 5;
		return true;
	}
	else {
		cout << "�̰� �ƴϾ�!!!\n";
		cout << "���� ������ ȭ�� �����ϴ�...\n";
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
	cout << "\n�κ��丮 ���\n";
	setColor(15);

	for (int I = 0; I < 5; I++) { cout << I << " : " << Inventory[I] << "\n"; }
	cout << "------------------------\n";
	cout << "���� ���ο��� �ǳ� �������� ���ڸ� �Է����ּ���\n";
	cout << "0~4 �̿��� ���ڸ� �Է��ϸ� ��ҵ˴ϴ�.\n";
	cout << "�Է� : ";
	cin >> N;
	cout << "------------------------\n";
	if (Inventory[N] == R_equipment) {
		cout << "���� ����Ʈ�� �Ϸ�Ǿ����ϴ�\n";
		cout << "�������� " << R_price * 5 << "���� �޾ҽ��ϴ�.\n";
		Money += R_price * 5;
		return true;
	}
	else {
		cout << "�̰� �ƴϾ�!!!\n";
		cout << "���� ������ ȭ�� �����ϴ�...\n";
		return false;
	}
}

bool Scholarship() {
	if (SoNB_P->Level >= 5) {
		cout << "���� ����Ʈ�� �Ϸ�Ǿ����ϴ�\n";
		cout << "�������� 1000���� �޾ҽ��ϴ�\n";
		Money += 1000;
		return true;
	}
	else {
		cout << "����Ʈ�� �Ϸ���� �ʾҽ��ϴ�\n";
		return false;
	}
}