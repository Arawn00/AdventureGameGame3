#pragma once
#include <string>
#include <vector>
#include "Item.h"
#include"Character.h"
#ifndef SHOP_H
#define SHOP_H

using namespace std;

class Shop
{
private : 
	string mName; // nom du shop 
	string mNameItems;// nom des items 
	int mprice;// prix des produits 
	vector <Item> shopInventoryVector; // liste de produits 


public :
	Shop(string name, string nameItems, int price);
	Shop();
	~Shop();

	string GetName();
	string GetNameItems();
	int GetPrice();

	//void SetName(string name);
	//void SetNameItems(string nameItems);
	//void SetPrice(int price);

	void AddtoShopInventory(Item item);
	void DisplayShopInventory();
	void MerchantText(Character& buyer);
	void ShopSellText(Character& buyer);


};



	









#endif // !SHOP_H
