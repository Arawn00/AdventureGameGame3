#pragma once
#include"Enemy.h"
#include <string> 
class Humanoid:public Enemy
{
private : 
	
	bool mfear;
	string mnationnality;
	int mgold;

public :

	
	Humanoid(string name, int damage, int lifePoints, int initiative, int level, bool fear, string nationnality, int gold);
	Humanoid();
	~Humanoid();

	bool GetFear();
	string GetNationnality();
	int GetGold();
};