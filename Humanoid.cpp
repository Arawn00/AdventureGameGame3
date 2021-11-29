#include <string>
#include <iostream>
#include "Humanoid.h"


Humanoid::Humanoid(string name, int damage, int lifePoints, int initiative, int level, bool fear, string nationnality, int gold)
{
	mName = name;
	mDamage = damage;
	mLifePoints = lifePoints;
	minitiative = initiative;

	mfear = fear;
	mnationnality = nationnality;
	mgold = gold;
}
Humanoid::Humanoid(){}
Humanoid::~Humanoid(){}

bool Humanoid::GetFear()
{
	return mfear;
}

string Humanoid::GetNationnality()
{
	return mnationnality;
}

int Humanoid::GetGold()
{
	return mgold;
}
