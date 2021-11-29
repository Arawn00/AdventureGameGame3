// FirstLectureGame3C++.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.
//

#include <iostream>
#include "Character.h"
#include "Item.h"
#include "Shop.h"
#include "Enemy.h"
#include "CombatManager.h"
#include "Humanoid.h"
#include "Animal.h"
#include <map>
#include "Flags.h"
using namespace std ;


int main()
{
	// display my question 
	cout << "What's your name traveller ? ";
	string playerName;
	cin >> playerName; // store the user input in the variable player name 
	Character player = Character(playerName, 100, 5, 5, 5, 5, 5, 5);

	CombatManager  combatManager;
	Item sword = Item("a sword", "a bandit sword ", 12, 1.0, true, true, CreaType::Weapon);
	Item axe = Item("a sword", "a bandit sword ", 20, 1.0, true, true, CreaType::Objects);
	Shop shop = Shop("Weapon Shop", "sword", 10);

	// enemies 
	Enemy bandit("Bandit", 5, 10, 3, 1, CreaType::Human);
	Enemy undead("Undead", 7, 7, 7, 2, CreaType::Undead);

	//classe hérité 

	Humanoid orc = Humanoid();
	Animal loup = Animal();

	// map 
	std::map<Enemy*, int> MyEnemyMap; // create a new map

	MyEnemyMap[&bandit] = 4; // create a new entry with a unique key 
	MyEnemyMap[&bandit]; // retournez la valeur de bandit (bandit est une clé , ( 4 ) 
	MyEnemyMap[&orc] = 2;
	MyEnemyMap[&loup] = 1;


	// FLAG 



	// Iterator / /!\
		 
	//std::map<Enemy,int>::iterator iteMap;
	//for (std::map<Enemy,int>::iterator iteMap  = MyEnemyMap.begin(); iteMap != MyEnemyMap.end(); iteMap++)
	{
		// iterator -> first = key 
	//	cout << "The value " << iteMap->second << "is bound to key " << iteMap->first << endl;
		// iterator->second = value  
	}

	cout << "hello " << playerName << " nice, to meet you\n"; // display a message with the provided name 
	int age;
	cout << "how old are you in real life ?";
	cin >> age;
	if (age < 18)
	{
		cout << "sorry you can't play";
		return 1;
	}
	else
	{
		int strenght = 0;
		int dex = 0;
		int constit = 0;
		int intellect = 0;
		int wisdom = 0;
		int charisma = 0;
		int totalPoint = 20;
		int pointJ;
		int maxHp = 20;

		while (totalPoint != 0)
		{
			cout << "Let's play !\n " << "I'm going to ask some question , \n these question define your future class \n careful you only have 20 points ! ";

			cout << " \nhow much HP (constitution) do you have ? ";
			cin >> pointJ;
			totalPoint -= pointJ;
			maxHp = pointJ;
			cout << "You have " << pointJ << " HP";
			cout << " you still have " << totalPoint << " of points to invest ";

			cout << "Define your statistics : \nhow much strenght do you have ? ";
			cin >> pointJ;
			totalPoint -= pointJ;
			strenght = pointJ;
			cout << "You have " << pointJ << " strenght";
			cout << " you still have " << totalPoint << " of points to invest ";

			cout << "\nhow much Dexterity do you have ? ";
			cin >> pointJ;
			totalPoint -= pointJ;
			dex = pointJ;
			cout << "You have " << pointJ << " Dexterity";
			cout << " you still have " << totalPoint << " of points to invest ";


			cout << " \nhow much intellect ? ";
			cin >> pointJ;
			totalPoint -= pointJ;
			intellect = pointJ;
			cout << "you have " << pointJ << "  intellect";
			cout << " you still have " << totalPoint << " of points to invest ";

			cout << "\nhow much wisdom do you have ? ";
			cin >> pointJ;
			totalPoint -= pointJ;
			wisdom = pointJ;
			cout << "You have " << pointJ << " wisdom";
			cout << " you still have " << totalPoint << " of points to invest ";

			cout << " \n you have  " << totalPoint << " Charisma\n\n";
			charisma = pointJ;



			break;
		}
		player = Character(playerName, maxHp, strenght, dex, constit, intellect, wisdom, charisma);
		if (charisma > strenght && charisma > intellect)
		{
			cout << "So you are a Bard \n";


		}
		else if (strenght > charisma && strenght > intellect)
		{
			cout << "So you are a warrior \n";
		}
		else if (intellect > charisma && intellect > strenght)
		{
			cout << "So you are a wizard \n";
		}
		player.DisplaySumUp();
		player.DisplayLife();
		player.Hurt(5);
		player.Heal(15);
		axe.DisplayItem();
		player.DisplayInventory(); // afficher inventaire 
		player.AddToInventory(axe);
		player.AddToInventory(Item("Shield", "a round shield", 20, 3, true, true, CreaType::Weapon)); // add item to inventory.
		player.DisplayCoins();
		shop.ShopSellText(player);
		shop.AddtoShopInventory(axe);
		shop.AddtoShopInventory(Item("Bow", "a curve bow", 30, 2, true, true, CreaType::Weapon)); // add item to the shop
		shop.AddtoShopInventory(Item("Axe", "a barbarian axe", 50, 5, true, true, CreaType::Weapon));
		shop.DisplayShopInventory();
		shop.MerchantText(player);

		int playerAnswer;
		cout << "you want something else ? ";

		cin >> playerAnswer;
		switch (playerAnswer) {
		case 1:
			shop.MerchantText(player);

		case 2:
			cout << " Is that all, stranger?";

		}

		int playerAnswer2;
		while (true)
		{
			cout << "what do you want to do ?	1) Exit Shop /2) Sell items / 3) Show Inventory ";
			cin >> playerAnswer2;
			if (playerAnswer2 == 1)
			{
				cout << "You are now in the street ";
				playerAnswer2 = false;


				break;
			}
			if (playerAnswer2 == 2)
			{
				cout << "What are you sellin ? ";
				playerAnswer2 = false;
				shop.ShopSellText(player);
				break;
			}
			if (playerAnswer2 == 3)
			{
				player.DisplayInventory();
				playerAnswer2 = true;
			}
			else
			{
				cout << "please answer ";
				playerAnswer2 = true;
			}
		}


		player.DisplayCoins();


		// Display enemies 
		combatManager.AddEnemies(bandit, 1);
		combatManager.AddEnemies(undead, 1);
		combatManager.AddPlayer(player);
		combatManager.DisplayEnemies();
		combatManager.Encounters(player);
		combatManager.fight();

		// overload d'operator ( 
		if (axe > sword)
		{
			cout << "je suis plus cher";
		}


	}
}
		
	
//}

	