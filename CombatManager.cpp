#include <string>
#include <iostream>
#include "CombatManager.h"
#include"Enemy.h"
#include <cstdlib>
#include "Character.h"


CombatManager::CombatManager()
{
}

CombatManager::~CombatManager()
{
}

void CombatManager::AddEnemies(Enemy& enemy,int count)
{
	for (int i = 0; i < count; i++)
	{
		ListEnemyVector.push_back(&enemy);
	}
}
void CombatManager::DisplayEnemies()
{
	// vecteur // 
	cout << "---------Combat---------"<<'\n';

	cout << "you encountered some enemies !\n ";
	for (int enemy = 0; enemy < ListEnemyVector.size(); enemy++)
	{
		cout << ListEnemyVector[enemy]->GetName() << '\n';
		
	}
	cout << "There are" << ListEnemyVector.size() <<"ennemies" << "\n What are you going to do ?'\n' ";
	
}

void CombatManager::AddPlayer(Character& newplayer)
{
	player = &newplayer;
}

void CombatManager::Encounters(Character player)
{
	// détérminer les choix que le joueur peut entreprendre comme : attaquer ou fuir 

	string playerCombatChoice = "";
	int combatChoice=false;
	cout << "\n Attack " << "  Flee \n";
	///cin >> combatChoice;
	while (combatChoice != true)
	{
		///Méthode switch 
		/*switch (combatChoice)
		{
			case 1 : 
			cout << "you attempt to flee ";
			combatChoice = false;
			break;
			case 2: 
				cout << "you fight";
				// mettre des dégats 

				combatChoice = true;
				break;
		}*/
		///Méthode if 
		cin >> playerCombatChoice;
		if (playerCombatChoice == "Attack")
		{
			 cout << "you fight \n";
			 combatChoice = true;
			 //  dégats
			// Enemy enemy;
			 //player.MakeDamage(enemy);
			 //enemy.RemoveLifePoints(10);

		}
		else
		{
			cout << "you attempt to flee \n";
			combatChoice = false;

			//faire un rand pour la fuite 
			int maxFleeChance = 100;
			srand(time(0));
			maxFleeChance = rand() % maxFleeChance;
			cout << "the random number is " <<" " << maxFleeChance;
			if (maxFleeChance > 50)
			{
				cout << "\n you ran away with success ";
			}
			else 
			{
				cout << "\n you stumble and fail to escape";
				// ennemi fais des dégats lourd 
				player.Hurt(20);

			}
			
		}

	}
	
	
	
}

void CombatManager::EnemyAttack(Enemy& enemy,Character& player)
{
	cout <<enemy.GetName()<<" inflige "<< enemy.GetDamage() << " de degats ";
	player.Hurt(enemy.GetDamage()); // Combien de dégats ? 
}




void CombatManager::fight()
{
	//Faire un combat au tour par tour où tout les ennemies attaque en même temps
	//puis le joueur
	//implémenter ces fonctions dans une fonctions de tour appeler dans le main .



	// for // 
	for (int i = 0; i < ListEnemyVector.size(); i++)// selectioner ennemie à l'emplacement i 
	{
		ListEnemyVector.at(i)->DisplayEnemyLife();
		// Enemies attack player
		EnemyAttack(*ListEnemyVector.at(i), *player);
		//Player attack specific ennemies 
		player->MakeDamage(*ListEnemyVector.at(i));
		ListEnemyVector.at(i)->DisplayEnemyLife();
		
	}


}