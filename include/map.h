﻿#pragma once
#include "monster.h"
#include <vector>
//[기본 설정 스텟 설정]
//Normal * 1.5(stat) = Elite
//Normal * 2(stat) = Boss

Monster Temp_Mob = { "temp","temp",0,0,0,0,0,0,0,0 };
Monster* Temp_Mob_P = &Temp_Mob;

Monster Slime_Normal = { "슬라임","normal",100,0,20,5,1,55,50,0 };
Monster* Slime_Normal_P = &Slime_Normal;
Monster Slime_Elite = { "가시 슬라임","elite",150,0,35,7.5,1.5 ,82.5,80,0 };
Monster* Slime_Elite_P = &Slime_Elite;
Monster Slime_Boss = { "킹 슬라임","boss",200,0,50,10,2 ,110,120,0 };
Monster* Slime_Boss_P = &Slime_Boss;

Monster Goblin_Normal = { "고블린","normal",120,0,35,8,1.2,70,60,0 };
Monster* Goblin_Normal_P = &Goblin_Normal;
Monster Goblin_Elite = { "핏빛 고블린","elite",180,0,50,12,1.8,105,80,0 };
Monster* Goblin_Elite_P = &Goblin_Elite;
Monster Goblin_Boss = { "고블린 킹","boss",240,0,70,16,2.4 ,140,150,0 };
Monster* Goblin_Boss_P = &Goblin_Boss;

Monster Orc_Normal = { "오크","normal",150,0,50,12,1.5 ,95,90,0 };
Monster* Orc_Normal_P = &Orc_Normal;
Monster Orc_Elite = { "광란의 오크","normal",225,0,65,18,2.25 ,130,110,0 };
Monster* Orc_Elite_P = &Orc_Elite;
Monster Orc_Boss = { "오크 킹","normal",300,0,100,24,3,200,250,0 };
Monster* Orc_Boss_P = &Orc_Boss;

vector<vector<Monster*>> Map;//Temp_Map

vector<vector<Monster*>> Map1 = { {Slime_Normal_P},{Slime_Normal_P,Slime_Elite_P},
	{Goblin_Normal_P},{Goblin_Normal_P,Slime_Elite_P},{Slime_Boss_P} };

vector<vector<Monster*>> Map2 = { {Slime_Normal_P,Goblin_Normal_P},{Slime_Normal_P,Slime_Elite_P},
	{Goblin_Normal_P,Goblin_Elite_P},{Goblin_Normal_P,Orc_Normal_P},{Goblin_Boss_P} };

vector<vector<Monster*>> Map3 = { {Goblin_Normal_P},{Goblin_Normal_P,Goblin_Elite_P},{Orc_Normal_P},
	{Orc_Normal_P,Orc_Elite_P},{Orc_Boss_P} };

vector<vector<Monster*>> Testmap = { {Slime_Normal_P} };

vector<vector<vector<Monster*>>> Maps = { Map1,Map2,Map3,Testmap };//맵들을 넣어놓는 벡터배열
