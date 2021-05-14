#include <iostream> 
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;

// �κ��丮�� �� ������ "0"���� ǥ����

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
	if (i < 5) {   //������ ��� Ȯ��
		int n = rand() % 14;  //14�� item�迭 ũ��
		string drop_item = items[n].name;
		cout << "���Ϳ��Լ� " << drop_item << "�� ��������!!!\n";
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

void pick_up_item(string inventory[], string item_name) { //�������� �ֿ� ��
	int count = 0;
	int n;
	char c;
	for (int i = 0; i < 5; i++) {      //�κ��丮�� ������� �ִ��� Ȯ��
		if (inventory[i] == "0") { count++; }
	}
	if (count == 0) {    //�κ��丮�� ���� �� ���
		cout << "�κ��丮�� ���� á���ϴ�.\n";
		while (true) {
			cout << "�κ��丮 ���\n";
			for (int i = 0; i < 5; i++) { cout << i << " : " << inventory[i] << "\n"; }
			cout << "������ �����۰� ��ü�ϽǰŸ� Y, �ƴϸ� N�� �Է����ּ���\n" << "�Է� : ";
			cin >> c;
			if (c == 'N') {
				cout << "�������� ���� �ʾҽ��ϴ�\n";
				break;
			}
			else if (c == 'Y') {
				cout << "��ü�� �������� ��ġ�� �Է����ּ���\n" << "�Է� : ";
				cin >> n;
				if (n >= 0 && n <= 4) {
					inventory[n] = item_name;
					break;
				}
				else { cout << "�ٽ� �Է����ּ���\n"; }
			}
			else { cout << "�ٽ� �Է����ּ���\n"; }
		}
	}
	else {     //�κ��丮�� �� ������ �ִ� ���
		while (true) {
			cout << "�κ��丮 ���\n";
			for (int i = 0; i < 5; i++) { cout << i << " : " << inventory[i] << "\n"; }
			cout << "�κ��丮�� �� �� ��ġ�� �ν� �̴ϱ�?\n" << "�Է� : ";
			cin >> n;
			if (n >= 0 && n <= 4) {
				if (inventory[n] == "0") {
					inventory[n] = item_name;
					break;
				}
				else { cout << "�����Ͻ� ��ġ���� �̹� �������� �ֽ��ϴ�. �ٸ� ��ġ�� ������ �ֽʽÿ�\n"; }
			}
			else { cout << "0~4�� ���� �� �ϳ��� �Է����ּ���\n"; }
		}
	}
}

void look_inventory(string inventory[]) {    //�κ��丮 �ҷ�����
	cout << "�κ��丮 ���\n";
	for (int i = 0; i < 5; i++) { cout << i << " : " << inventory[i] << "\n"; }
}

void swap_item(string inventory[]) {     //�κ��丮�� �ִ� ������ ��ġ ����
	int n1, n2;
	string temp;
	cout << "�κ��丮 ���\n";
	for (int i = 0; i < 5; i++) { cout << i << " : " << inventory[i] << "\n"; }

	cout << "0~4�� ������ �ٸ� ���� �Է½� ��ġ ������ ��ҵ˴ϴ�\n";
	cout << "��ġ�� ������ �������� ��ȣ�� �Է����ּ���\n" << "�Է� : ";
	cin >> n1;
	cout << "�����Ͻ� �����۰� ��ġ�� ������ �������� ��ȣ�� �Է����ּ���\n" << "�Է� : ";
	cin >> n2;
	if (n1 >= 0 && n1 <= 4) {
		if (n2 >= 0 && n2 <= 4) {
			temp = inventory[n1];
			inventory[n1] = inventory[n2];
			inventory[n2] = temp;
		}
	}
	else { cout << "�������� ��ġ ������ ��ҵǾ����ϴ�\n"; }
}


void throw_away_item(string inventory[]) {       //�������� ���� ��
	int n;
	cout << "�κ��丮 ���\n";
	for (int i = 0; i < 5; i++) { cout << i << " : " << inventory[i] << "\n"; }
	cout << "0~4�� ������ �ٸ� ���� �Է½� ��ġ ������ ��ҵ˴ϴ�\n";
	cout << "���� �������� ��ġ�� �Է����ּ���\n" << "�Է� : ";
	cin >> n;
	if (n >= 0 && n <= 4) { inventory[n] = "0"; }
	else { cout << "������ �����Ⱑ ��ҵǾ����ϴ�\n"; }
}