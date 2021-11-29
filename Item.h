#pragma once
#include <iostream>
#include <string>
#include "Iitem.h"

using namespace std;

class Item :public Iitem{
private:
	string mName;
	string mDescription;
	int mPrice;
	float mWeight;
	bool mStackable;
	bool mSellable;

public :
	// constructeur / destructeur 

	Item(string name, string description, int price, float weight, bool stackable, bool sellable, std::uint8_t myType);
	Item();
	~Item();
	string GetName();
	string GetDescription();
	int GetPrice();
	float GetWeight();
	bool GetStackable();
	bool GetSellable();
	void DisplayItem();

// comparer le prix de 2 items overload supérieur et inférieur 
// récupérer le prix 
// récup l'autre prix 
// comparer les valeurs de l'int price 
	bool operator>(Item const& otherObject)const
	{
		if (this->mPrice>otherObject.mPrice) return true;
		if (this->mPrice<otherObject.mPrice) return false;
	}
};

