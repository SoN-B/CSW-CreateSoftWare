#pragma once
#include "monster.h"
#include <vector>
//[기본 설정 스텟 설정]
//Normal * 1.5(stat) = Elite
//Normal * 2(stat) = Boss

Monster Temp_Mob = { "temp","temp",0,0,0,0,0 };
Monster* Temp_Mob_P = &Temp_Mob;

Monster Slime_Normal = { "slime_normal","normal",100,0,10,5,1,100,100 };
Monster* Slime_Normal_P = &Slime_Normal;
Monster Slime_Elite = { "slime_elite","elite",150,0,15,7.5,1.5 ,150,150};
Monster* Slime_Elite_P = &Slime_Elite;
Monster Slime_Boss = { "slime_boss","boss",200,0,20,10,2 ,200,200};
Monster* Slime_Boss_P = &Slime_Boss;

Monster Goblin_Normal = { "goblin_normal","normal",120,0,12,8,1.2,120,120 };
Monster* Goblin_Normal_P = &Goblin_Normal;
Monster Goblin_Elite = { "goblin_elite","elite",180,0,18,12,1.8,180,180 };
Monster* Goblin_Elite_P = &Goblin_Elite;
Monster Goblin_Boss = { "goblin_boss","boss",240,0,24,16,2.4 ,240,240};
Monster* Goblin_Boss_P = &Goblin_Boss;

Monster Orc_Normal = { "orc_normal","normal",150,0,15,12,1.5 ,150,150};
Monster* Orc_Normal_P = &Orc_Normal;
Monster Orc_Elite = { "orc_elite","normal",225,0,22.5,18,2.25 ,225,225};
Monster* Orc_Elite_P = &Orc_Elite;
Monster Orc_Boss = { "orc_boss","normal",300,0,30,24,3,300,300 };
Monster* Orc_Boss_P = &Orc_Boss;

vector<vector<Monster*>> Map;//Temp_Map

vector<vector<Monster*>> Map1 = { {Slime_Normal_P},{Slime_Normal_P,Slime_Elite_P},
	{Goblin_Normal_P},{Goblin_Normal_P,Slime_Elite_P},{Slime_Boss_P} };

vector<vector<Monster*>> Map2 = { {Slime_Normal_P,Goblin_Normal_P},{Slime_Normal_P,Slime_Elite_P},
	{Goblin_Normal_P,Goblin_Elite_P},{Goblin_Normal_P,Orc_Normal_P},{Goblin_Boss_P} };

vector<vector<Monster*>> Map3 = { {Slime_Normal_P} };

vector<vector<vector<Monster*>>> Maps = { Map1,Map2,Map3 };//맵들을 넣어놓는 벡터배열
