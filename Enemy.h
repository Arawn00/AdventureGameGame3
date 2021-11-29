#pragma once
#include <string>
#include <vector>

#ifndef ENEMY_H
#define ENEMY_H

using namespace std;


class Enemy
{
protected : 
	string mName;
	int mDamage;
	int mLifePoints;
	int minitiative;
	int mlevel;
public :
	Enemy(string name, int damage,int lifePoints,int initiative,int level,std::uint8_t myType);
	Enemy();
	~Enemy();

	string GetName();
	int GetDamage();
	int GetLifePoints();
	int GetInitiative();
	void AddLifePoints(int points);
	void RemoveLifePoints(int points);
	void DisplayEnemyLife();
	void SetDamage(int value);
};



#endif // !ENEMY_H