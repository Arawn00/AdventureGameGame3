#pragma once
#include "Enemy.h"
#include <string>

class Animal :
    public Enemy
{

protected : 
    bool mIsHungry;
    string mBreed;
    int mValue;

public : 
    Animal(string name, int damage, int lifePoints, int initiative, int level, bool hunger, string breed, int value);
    Animal();
    ~Animal();

    bool GetHunger();
    string breed();
    int value();
};

