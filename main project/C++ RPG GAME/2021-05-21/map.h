#pragma once
#include "monster.h"
#include <vector>
//[기본 설정 스텟 설정]
//Normal * 1.5(stat) = Elite
//Normal * 2(stat) = Boss
// 종족,Hp,Mp,Atk,Def,Spd,Exp,Money,Type 순
Monster Temp_Mob = { "temp",0,0,0,0,0,"temp" };
Monster* Temp_Mob_P = &Temp_Mob;

Monster Slime_Normal = { "slime_normal",100,0,10,5,1,5,10,"normal" };
Monster* Slime_Normal_P = &Slime_Normal;
Monster Slime_Elite = { "slime_elite",150,0,15,7.5,1.5,7.5,15,"elite" };
Monster* Slime_Elite_P = &Slime_Elite;
Monster Slime_Boss = { "slime_boss",200,0,20,10,2,10,25,"boss" };
Monster* Slime_Boss_P = &Slime_Boss;

Monster Goblin_Normal = { "goblin_normal",120,0,12,8,1.2,7,15,"normal" };
Monster* Goblin_Normal_P = &Goblin_Normal;
Monster Goblin_Elite = { "goblin_elite",180,0,18,12,1.8,10,20,"elite" };
Monster* Goblin_Elite_P = &Goblin_Elite;
Monster Goblin_Boss = { "goblin_boss",240,0,24,16,2.4,13,30,"boss" };
Monster* Goblin_Boss_P = &Goblin_Boss;

Monster Orc_Normal = { "orc_normal",150,0,15,12,1.5,15,20,"normal" };
Monster* Orc_Normal_P = &Orc_Normal;
Monster Orc_Elite = { "orc_elite",225,0,22.5,18,2.25,20,25,"elite" };
Monster* Orc_Elite_P = &Orc_Elite;
Monster Orc_Boss = { "orc_boss",300,0,30,24,3,30,35,"boss" };
Monster* Orc_Boss_P = &Orc_Boss;

vector<vector<Monster*>> Map;//Temp_Map

vector<vector<Monster*>> Map1 = { {Slime_Normal_P},{Slime_Normal_P,Slime_Elite_P},
	{Goblin_Normal_P},{Goblin_Normal_P,Slime_Elite_P},{Slime_Boss_P} };

vector<vector<Monster*>> Map2 = { {Slime_Normal_P,Goblin_Normal_P},{Slime_Normal_P,Slime_Elite_P},
	{Goblin_Normal_P,Goblin_Elite_P},{Goblin_Normal_P,Orc_Normal_P},{Goblin_Boss_P} };

vector<vector<vector<Monster*>>> Maps = { Map1,Map2 };//맵들을 넣어놓는 벡터배열