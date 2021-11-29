#include <iostream>
#include "Character.h"
using namespace std;

Character::Character(string name, int maxLife, int f, int d, int c, int i, int w, int ch) {
	mName = name;
	mMaxLife = maxLife;
	mLifePoints = maxLife;
	mstrenght = f;
	mDex = d;
	mConstitution = c;
	mIntelligence = i;
	mWisdom = w;
	mCharisma = ch;
}

Character::Character()
{
}

Character::~Character() {}

string Character::GetName() {
	return mName;
}
int Character::GetForce() {
	return mstrenght;
}
int Character::GetDex() {
	return mDex;
}
int Character::GetConstit() {
	return mConstitution;
}
int Character::GetIntell() {
	return mIntelligence;
}
int Character::GetWisdom() {
	return mWisdom;
}
int Character::GetCharisma() {
	return mCharisma;
}
int Character::GetLifePoints() {
	return mLifePoints;
}
float Character::GetCoins()
{
	return mcoins;
}

void Character::SetForce(int value) { mstrenght = value; }
void Character::SetDex(int value) { mDex = value; }
void Character::SetConstit(int value) { mConstitution = value; }
void Character::SetIntell(int value) { mIntelligence = value; }
void Character::SetWisdom(int value) { mWisdom = value; }
void Character::SetCharisma(int value) { mCharisma = value; }
void Character::SetCoins(int coins){}
void Character::SetLifePoints(int value) { mLifePoints = value; }

void Character::Heal(int points)

{
	mLifePoints = min((mLifePoints+points), mMaxLife);

}
void Character::Hurt(int points)
{
	mLifePoints = max((mLifePoints-points), 0);
	if (mLifePoints == 0)
	{
		cout << "\nyou are dead"<<mName;
	}
	else
	{
		DisplayLife();
	}
}

void Character::MakeDamage(Enemy& enemy)
{
	enemy.RemoveLifePoints(3);
	cout << mName << " inflicted 3 damage points to " << enemy.GetName() << endl;
}





void Character::DisplaySumUp() {
	
	cout << mName << "has the following caracteristics:\n";
	cout << "Max HP : " << mMaxLife << '\n';
	cout << "Strenght : " << mstrenght << '\n';
	cout << "Dexterity : " << mDex << '\n';
	cout << "Constitution : " << mConstitution << '\n';
	cout << "Int : " << mIntelligence << '\n';
	cout << "Wisdom : " << mWisdom << '\n';
	cout << "Charisma : " << mCharisma << '\n';

}

void Character::DisplayLife()
{
	cout <<endl << "Vous avez " << mLifePoints<<" PV" << endl;
}

void Character::AddToInventory(Item item)
{
	myInventoryVector.push_back(item);
}
void Character::RemoveToInventory(Item item)
{
	myInventoryVector.pop_back();
}
void Character::DisplayInventory()
{
	cout << "\n--------- Your Inventory ---------: \n";
	for (int item = 0; item < myInventoryVector.size(); item++)
	{
		cout << myInventoryVector[item].GetName()<<'\n';
	}
	DisplayCoins();
	
}

void Character::DisplayCoins()
{
	cout << "you have " << mcoins << " coins\n";
}

void Character::RemoveCoins(float coins)
{
	mcoins -= coins;
	cout << ",you now have " << mcoins << " coins\n";
}

void Character::AddCoins(float coins)
{
	mcoins += coins;
	cout << "you now have " << mcoins << "coins`\n";
}

