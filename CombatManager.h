#pragma once
#include <iostream>
#include <vector>
#include "Enemy.h"
#include "Character.h"

using namespace std;

#ifndef  COMBATMANAGER_H
#define COMBATMANAGER_H

class CombatManager
{
private: 
	vector <Enemy*> ListEnemyVector; // liste d'enemis 
	Character* player;

public : 

	CombatManager();//Constructeur 
	~CombatManager();// Destructeur 

	
	void AddEnemies(Enemy& enemy,int count=1);
	void DisplayEnemies();
	void Encounters(Character player);
	void EnemyAttack(Enemy& enemy,Character& player);
	void AddPlayer(Character& newplayer);
	void fight();
	
};

/*	Combat manager : 

sert à lancer 
et manager des combats qui utiliseront les ennemis créer dans le cpp, le player 
comment récup les ennemis du main et leurs caractéristiques et enfin les afficher 
pour intéragir avec le joueur ? 
gérer les tours 




ajouter constru destructeur 
constru : vecteur d'ennemi , private 

*/

#endif // ! COMBATMANAGER_H
