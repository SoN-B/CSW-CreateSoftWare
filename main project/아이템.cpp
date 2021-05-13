#include <iostream> 
#include <string>

using namespace std;

typedef struct My_Character { //�⺻
	double hp, mp, atk, def, speed;

	My_Character(double hp = 200, double mp = 100, double atk = 50,
		double def = 30, double speed = 1.5)
	{
		this->hp = hp;
		this->mp = mp;
		this->atk = atk;
		this->def = def;
		this->speed = speed;
	}

	void Get_Character_Info()//�÷��̾� ���� ��� 
	{
		cout << "HP : " << hp << "\nMP: " << mp << "\n���ݷ�: " << atk << "\n����: " << def << endl;
	}
}My_Character;

My_Character SoNB;
My_Character* SoNB_P = &SoNB;

void use_item(My_Character* character, string inventory[], int inventory_num[]) {
	int n;
	char q;
	cout << "�κ��丮 ���\n";
	for (int i = 0; i < 5; i++) { cout << i << " : " << inventory[i] << "\n"; }
	cout << "0~4�� ������ �ٸ� ���� �Է½� ������ ����� ��ҵ˴ϴ�\n";
	cout << "����� �������� ��ġ�� �Է����ּ���\n" << "��ġ : ";
	cin >> n;
	if (n >= 0 && n <= 4) {
		if (inventory[n] == "0") { cout << "�����Ͻ� ��ġ�� �������� �����ϴ�\n"; }
		else {
			switch (inventory_num[n]) {
			case 0:
				cout << "red potion : hp +20\n";
				character->hp += 20;
				break;
			case 1:
				cout << "orange potion : hp +40\n";
				character->hp += 40;
				break;
			case 2:
				cout << "blue potion : mp +20\n";
				character->mp += 20;
				break;
			case 3:
				cout << "purple potion : mp +40\n";
				character->mp += 40;
				break;
			}
			inventory[n] = "0";
			inventory_num[n] = -1;
			cout << "hp : " << character->hp << endl;
			cout << "mp : " << character->mp << endl;
		}
	}
}

int main() {
	int q;
	string item_list[4] = { "red potion", "orange potion", "blue potion", "purple potion" };
	string inventory[5] = { "0","0","0","0","0" };
	int inventory_num[5] = { -1,-1,-1,-1,-1 };

	q = 2;
	inventory[0] = item_list[q];
	inventory_num[0] = q;
	use_item(SoNB_P, inventory, inventory_num);
}