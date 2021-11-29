#include <iostream>
#include "Shop.h"
#include"Flags.h"
Shop::Shop(string name, string nameItems, int price)
{
	mName = name;
	mNameItems = nameItems;
	mprice = price;

}
	

Shop::Shop(){} // Constructeur 
Shop::~Shop(){} // Déstructeur 

string Shop::GetName()
{
	return mName;
}

string Shop::GetNameItems()
{
	return mNameItems;
}

int Shop::GetPrice()
{
	return mprice;
}

void Shop::AddtoShopInventory(Item item)
{
	shopInventoryVector.push_back(item);
}

void Shop::DisplayShopInventory()
{
	
		cout << "\n--------- Shop---------: \n";
		cout << "Welcome Traveller ! \n'";

		for (int itemShop = 0; itemShop < shopInventoryVector.size(); itemShop++)
		{
			cout << shopInventoryVector[itemShop].GetName() << '\n';
		}
}

void Shop::MerchantText(Character& buyer)
{
	string choiceMT ="";
	int shopChoice = 0;
	while (shopChoice == 0||shopChoice>=3)
	{
		cout << "\n Weeeelllllcoooooommmmmeeee , You want somehting' ?\n";
		choiceMT = "";
		cin >> choiceMT;
		
		
		cin >> shopChoice;

		switch (shopChoice) {
		case 1:
			if (buyer.GetCoins() >= 20)
			{
				cout << "\n Stranger, stranger, stranger, Now that’s a weapon!\n";
				buyer.AddToInventory(Item(" a sword", "a bandit sword ", 20, 1.0, true, true,CreaType::Weapon));
				buyer.RemoveCoins(20);
				cout << "\na Sword have been added to your inventory ";
			}
			else
			{
				cout << "sorry you don't have enough money ";
			}
			break;
		case 2:
			if (buyer.GetCoins() >= 30)
			{
				cout << "\n A wise choice, mate! Its ammo will penetrate just about anything\n";
				buyer.AddToInventory(Item(" Bow", "a curve bow", 30, 2, true, true,CreaType::Objects));
				buyer.RemoveCoins(30);
				cout << "\na Bow have been added to your inventory ";
			}
			else
			{
				cout << "sorry you don't have enough money ";
			}
			break;
		case 3:
			if (buyer.GetCoins() >= 50)
			{
				cout << "\n Stranger. What you need that for ? Going huntin an elephant ?\n ";
				buyer.AddToInventory(Item(" Axe", "a barbarian axe", 50, 5, true, true,CreaType::Weapon));
				buyer.RemoveCoins(50);
				cout << "\na Axe have been added to your inventory ";
			}
			else
			{
				cout << "sorry you don't have enough money ";
			}
			break;
			while (choiceMT == "yes");

			//default : 
				//if (shopChoice < 3)
				//{

				//}

		}
		

	}
}

void Shop::ShopSellText(Character& buyer)
{
	int shopSellChoice = 0;
	
	string choice = "";
	cout << "what do you want to sell ? ";
	do {
		do
		{
			shopSellChoice = 0;
			cin >> shopSellChoice;
			switch (shopSellChoice)
			{
			case 1:
				buyer.AddCoins(10);
				break;

			case 2:
				buyer.AddCoins(15);
				break;

			case 3:
				buyer.AddCoins(25);
				break;

			}
			/*cout << shopSellChoice << " between 0 and 3 ? " << ((shopSellChoice <= 0 || shopSellChoice > 3) ? "true" : "false")<<'\n';*/
		} while (shopSellChoice <= 0 || shopSellChoice > 3);
		cout << "Anything else ? yes or no ? ";
		choice = "";
		cin >> choice;
		
	} while (choice == "yes");
	
}

