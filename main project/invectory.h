#include <iostream> 
#include <string>
using namespace std;

// �κ��丮�� �� ������ "0"���� ǥ����
// �κ��丮�� 0~4�� 5�� ������ ���� �迭�� ����

							//������
							//������ ���� ������ �ؿ� ����
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


void pick_up_item(string inventory[], string item) { //�������� �ֿ� ��
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
			cout << "������ �����۰� ��ü�ϽǰŸ� Y, �ƴϸ� N�� �����ּ���\n" << "�Է� : ";
			cin >> c;
			if (c == 'N') {
				cout << "�������� ���� �ʾҽ��ϴ�\n";
				break;
			}
			else if (c == 'Y') {
				cout << "��ü�� �������� ��ġ�� �Է����ּ���\n" << "�Է� : ";
				cin >> n;
				if (n >= 0 && n <= 4) {
					inventory[n] = item;
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
			if (inventory[n] == "0") {
				inventory[n] = item;
				break;
			}
			else { cout << "�����Ͻ� ��ġ���� �̹� �������� �ֽ��ϴ�. �ٸ� ��ġ�� ������ �ֽʽÿ�\n"; }
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


void use_item(string inventory[], struct My_Character SoNB, struct hp_item hp_item[], struct mp_item mp_item[],
	struct atk_item atk_item[], struct def_item def_item[], struct spd_item spd_item[],
	struct hp_mp_item hp_mp_item[], struct atk_def_item atk_def_item[]) {		//�������� ����� ��

	int n;
	cout << "�κ��丮 ���\n";
	for (int i = 0; i < 5; i++) { cout << i << " : " << inventory[i] << "\n"; }
	cout << "0~4�� ������ �ٸ� ���� �Է½� ������ ����� ��ҵ˴ϴ�\n";
	cout << "����� �������� ��ġ�� �Է����ּ���\n" << "��ġ : ";
	cin >> n;
	if (n >= 0 && n <= 4) {
		if (inventory[n] == "0") { cout << "�����Ͻ� ��ġ�� �������� �����ϴ�\n"; }
		else {
			int i = 0;
			while (true) {
				if (inventory[n] == hp_item[i].name) {
					cout << "���� hp : " << hp << "\n";
					hp += hp_item[i].hp;
					inventory[n] = "0";
					cout << "���� hp : " << hp << "\n";
					break;
				}
				else if (inventory[n] == mp_item[i].name) {
					cout << "���� mp : " << mp << "\n";
					mp += mp_item[i].mp;
					inventory[n] = "0";
					cout << "���� mp : " << mp << "\n";
					break;
				}
				else if (inventory[n] == atk_item[i].name) {
					cout << "���� atk : " << atk << "\n";
					atk += atk_item[i].atk;
					inventory[n] = "0";
					cout << "���� atk : " << atk << "\n";
					break;
				}
				else if (inventory[n] == def_item[i].name) {
					cout << "���� def : " << def << "\n";
					def += def_item[i].def;
					inventory[n] = "0";
					cout << "���� def : " << def << "\n";
					break;
				}
				else if (inventory[n] == spd_item[i].name) {
					cout << "���� spd : " << spd << "\n";
					spd += spd_item[i].spd;
					inventory[n] = "0";
					cout << "���� spd : " << spd << "\n";
					break;
				}
				else if (inventory[n] == hp_mp_item[i].name) {
					cout << "���� hp : " << hp << "\n";
					cout << "���� mp : " << mp << "\n";
					hp += hp_mp_item[i].hp;
					mp += hp_mp_item[i].mp;
					inventory[n] = "0";
					cout << "���� hp : " << hp << "\n";
					cout << "���� mp : " << mp << "\n";
					break;
				}
				else if (inventory[n] == atk_def_item[i].name) {
					cout << "���� atk : " << atk << "\n";
					cout << "���� def : " << def << "\n";
					atk += atk_def_item[i].atk;
					def += atk_def_item[i].def;
					inventory[n] = "0";
					cout << "���� atk : " << atk << "\n";
					cout << "���� def : " << def << "\n";
					break;
				}
				i++;
			}
		}
	}
}


/*int main() {          //�׽�Ʈ

	string inventory[5] = { "0","0","0","0","0" };		//�κ��丮
														//���� �Լ��� �߰��ؾ� ��


												//������ ���μ���
												//���� �Լ��� �߰��ؾ� ��
												//�뷱���� ������� �ʰ� ���� ���� �׽�Ʈ�� ������

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
	atk_def_item[1].def = 30;					//��������� ������
												//�ؿ��� �Ű� �� �ʿ� ����(���� �Լ� �߰� X)



	string item = mp_item[1].name;
	string item2 = atk_def_item[0].name;

	pick_up_item(inventory, item);
	pick_up_item(inventory, item2);

	use_item(inventory, SoNB, hp_item, mp_item, atk_item, def_item, spd_item, hp_mp_item, atk_def_item, );
	use_item(inventory, SoNB, hp_item, mp_item, atk_item, def_item, spd_item, hp_mp_item, atk_def_item);

	look_inventory(inventory);
}*/