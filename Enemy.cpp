#include <string>
#include <iostream>
#include "Enemy.h"


Enemy::Enemy(string name, int damage, int lifePoint,int initiative, int level, std::uint8_t myType)
{
	mName = name;
	mDamage = damage;
	mLifePoints = lifePoint;
	minitiative = initiative;
}
Enemy::Enemy(){}

Enemy::~Enemy() {}


string Enemy::GetName()
{
	return mName;
}

int Enemy::GetDamage()
{
	return mDamage;
}

int Enemy::GetLifePoints()
{
	return mLifePoints;
}

int Enemy::GetInitiative()
{
	return minitiative;
}



void Enemy::AddLifePoints(int points)
{
	mLifePoints += points;
}

void Enemy::RemoveLifePoints(int points)
{
	mLifePoints -= points;
}

void Enemy::DisplayEnemyLife()
{
	cout << mName << " have " << mLifePoints << " PV" << endl;
}

void Enemy::SetDamage(int value) { mDamage = value; }

