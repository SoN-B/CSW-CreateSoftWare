#include <iostream>
#include "map.h"
using namespace std;

int Menu;
bool Flag = true; //do while문 탈출조건

struct My_Character { //기본
	float hp, mp, atk, def, speed;

	My_Character(int hp = 200, int mp = 100, int atk = 50, int def = 30, int speed = 1.5)
	{
		this->hp = hp;
		this->mp = mp;
		this->atk = atk;
		this->def = def;
		this->speed = speed;
	}
};

int main()
{//메뉴 선택
	My_Character SoNB;

	do {
		cout << "【 TEST BETA GAME 】\n\n" << "메뉴를 선택해 주세요 ~ !\n";
		cout << "\n1.게임시작\n2.게임 설명\n3.게임 종료\n";
		
		cin >> Menu;
		switch (Menu)
		{
		case 1:
			for (int i = 0; i < map1.size(); i++) {
				for (int j = 0; j < map1[i].size(); j++) {
					if (SoNB.hp == 0) { //도중에 캐릭터가 사망시 게임오버
						cout << "Game over...";
						i = map1.size(); //한번에 i를 끝인덱스까지 올려서 중첩for문 반복중지
						break;
					}

					/*
					여기에 전투 부분 구현
					*/
				}
			}

			if (!SoNB.hp == 0) cout << "Congratulations! Game clear!\n\n";
			break;
		case 2:
			cout << "이 게임은 현재 개발 중에 있는 C++ 기반 RPG입니다.\n\n";
			break;
		case 3:
			Flag = false;
			break;
		}
	} while (Flag); //메뉴 정석(do while)
}
