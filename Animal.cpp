#include "Animal.h"

Animal::Animal(string name, int damage, int lifePoints, int initiative, int level, bool hunger, string breed, int value)
{
	mName = name;
	mDamage = damage;
	mLifePoints = lifePoints;
	minitiative = initiative;

	mIsHungry =hunger;
	mBreed = breed;
	mValue = value;
}	

Animal::Animal(){}

Animal::~Animal(){}

bool Animal::GetHunger()
{
	return mIsHungry;
}

string Animal::breed()
{
	return mBreed;
}

int Animal::value()
{
	return mValue;
}
