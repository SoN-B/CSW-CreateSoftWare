#pragma once
#include <iostream> 
using namespace std;

string pick_up_item(string inventory, string item) {    //�������� �ֿ� ��
	int count = 0;
	int n;
	char c;
	for (int i = 0; i < 5; i++) {      //�κ��丮�� ������� �ִ��� Ȯ��
		if (inventory[i] == '0') { count++; }
	}
	if (count == 0) {    //�κ��丮�� ���� �� ���
		cout << "�κ��丮�� ���� á���ϴ�.\n";
		while (true) {
			cout << "������ �����۰� ��ü�ϽǰŸ� Y, �ƴϸ� N�� �����ּ���\n" << "�Է� : ";
			cin >> c;
			if (c == 'N') {
				cout << "�������� ���� �ʾҽ��ϴ�\n";
				break;
			}
			else if (c == 'Y') {
				cout << "��ü�� �������� ��ġ�� �Է����ּ���\n" << "�Է� : ";
				cin >> n;
				inventory[n] = item;
				break;
			}
			else { cout << "�ٽ� �Է����ּ���\n"; }
		}
	}
	else {     //�κ��丮�� �� ������ �ִ� ���
		while (true) {
			cout << "�κ��丮�� �� �� ��ġ�� �ν� �̴ϱ�?\n" << "��ġ �Է� : ";
			cin >> n;
			if (inventory[n] == '0') {
				inventory[n] = item;
				break;
			}
			else { cout << "�����Ͻ� ��ġ���� �̹� �������� �ֽ��ϴ�. �ٸ� ��ġ�� ������ �ֽʽÿ�\n"; }
		}
	}
}