#pragma once
#include "monster.h"
#include <vector>
//[능력치부분]
//Normal * 1.5(stat) = Elite
//Normal * 2(stat) = Boss

mob Slime_Normal = { "slime_normal",100,0,10,5,"normal" };
mob Slime_elite = { "slime_elite",150,0,15,7.5,"elite" };
mob Slime_boss = { "slime_boss",200,0,20,10,"boss" };

mob Goblin_Normal = { "goblin_normal",120,0,12,8,"normal" };
mob Goblin_elite = { "goblin_elite",180,0,18,12,"elite" };
mob Goblin_boss = { "goblin_boss",240,0,24,16,"boss" };

mob Orc_Normal = { "orc_normal",150,0,15,12,"normal" };
mob Orc_elite = { "orc_elite",225,0,22.5,18,"normal" };
mob Orc_boss = { "orc_boss",300,0,30,24,"normal" };

vector<vector<mob>> map1 = { {Slime_Normal},{Slime_Normal,Slime_elite},
	{Goblin_Normal},{Goblin_Normal,Slime_elite},{Slime_boss} };

vector<vector<mob>> map2 = { {Slime_Normal,Goblin_Normal},{Slime_Normal,Slime_elite},
	{Goblin_Normal,Goblin_elite},{Goblin_Normal,Orc_Normal},{Goblin_boss} };
