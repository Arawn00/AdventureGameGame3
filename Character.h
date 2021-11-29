#pragma once
#include <string>
#include <vector>
#include "Item.h"
#include "Enemy.h"
#ifndef CHARACTER_H
#define CHARACTER_H



using namespace std;

class Character {
private:
	string mName;
	int mstrenght;
	int mDex;
	int mConstitution;
	int mIntelligence;
	int mWisdom;
	int mCharisma;
	int mMaxLife;
	int mLifePoints;
	vector <Item> myInventoryVector;
	float mcoins = 50.0;

public:
	Character(string name, int maxLife, int f, int d, int c, int i, int w, int ch);
	Character();
	~Character();
	string GetName();
	int GetForce();
	int GetDex();
	int GetConstit();
	int GetIntell();
	int GetWisdom();
	int GetCharisma();
	int GetLifePoints();
	float GetCoins();

	void SetForce(int value);
	void SetDex(int value);
	void SetConstit(int value);
	void SetIntell(int value);
	void SetWisdom(int value);
	void SetCharisma(int value);
	void SetCoins(int coins);
	void Heal(int points);
	void Hurt(int points);
	void MakeDamage(Enemy& enemy);
	void SetLifePoints(int value);

	void DisplaySumUp();
	void DisplayLife();

	//inventory
	void AddToInventory(Item item);
	void RemoveToInventory(Item item);
	void DisplayInventory();
	void DisplayCoins();
	void RemoveCoins(float coins);
	void AddCoins(float coins);
};



#endif // !1
