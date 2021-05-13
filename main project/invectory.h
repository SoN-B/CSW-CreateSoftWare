#include <iostream> 
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;

// �κ��丮�� �� ������ "0"���� ǥ����

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

string drop_item(struct item item[]) {   //��ӵǴ� ������ ����
	srand((unsigned int)time(NULL));
	int n = rand() % 14;  //14�� item�迭 ũ��
	string drop_item = item[n].name;
	return drop_item;
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


void use_item(My_Character* character, string inventory[], struct item item[]) {
	// �������� ����� ��
	int n;

	cout << "�κ��丮 ���\n";
	for (int i = 0; i < 5; i++) { cout << i << " : " << inventory[i] << "\n"; }
	cout << "0~4�� ������ �ٸ� ���� �Է½� ������ ����� ��ҵ˴ϴ�\n";
	cout << "����� �������� ��ġ�� �Է����ּ���\n" << "��ġ : ";
	cin >> n;
	if (n >= 0 && n <= 4) {
		if (inventory[n] == "0") { cout << "�����Ͻ� ��ġ�� �������� �����ϴ�\n"; }
		else {
			for (int i = 0; i < 14; i++) {   //14�� item�迭 ũ��
				if (inventory[n] == item[i].name) {
					character->hp += item[i].hp;
					character->mp += item[i].mp;
					character->atk += item[i].atk;
					character->def += item[i].def;
					character->speed += item[i].speed;
					inventory[n] = "0";
					cout << item[i].name << "�� ����߽��ϴ�\n";
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
	else { cout << "������ ����� ��ҵǾ����ϴ�\n"; }
}


/*int main() {        //���� ����

	string inventory[5] = { "0","0","0","0","0" };  //�κ��丮, ���� �Լ��� �߰��ؾ� ��

													//���⼭���� ������ ���, �����Լ��� �߰��ؾ� ��
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
													//������� ������ ���


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