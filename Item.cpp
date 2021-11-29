#include <iostream>
#include "Item.h"


using namespace std;

Item::Item(string name,string description, int price, float weight, bool stackable, bool sellable, std::uint8_t myType)
{
	mName = name;
	mDescription = description;
	mPrice = price;
	mWeight = weight;
	mStackable = stackable;
	mSellable = sellable;
	
}
Item::Item()									// constructeur : Un constructeur est, en programmation orientée objet, une fonction particulière appelée lors de l'instanciation. 
												//Elle permet d'allouer la mémoire nécessaire à l'objet et d'initialiser ses attributs. 
{}
Item::~Item(){}									//le destructeur d'une classe est une méthode spéciale lancée lors de la destruction d'un objet afin de récupérer les ressources 
												//(principalement la mémoire vive) réservée dynamiquement lors de l'instanciation de l'objet. Alors qu'il peut exister plusieurs constructeurs, il ne peut exister qu'un seul destructeur. 

string Item::GetName()
{
	return mName;
}

string Item::GetDescription()
{
	return mDescription;
}

int Item::GetPrice() 
{
	return mPrice;
}
float Item::GetWeight()
{
	return mWeight;
}
bool Item::GetStackable()
{
	return mStackable;
}
bool Item::GetSellable()
{
	return mSellable;
}

void Item::DisplayItem()
{
	cout << "Item : " << mName << " is " << mDescription << "it costs " << mPrice << " and weights " << mWeight << '\n';
}

//Template 
template <class T>
void bubbleSort(T a[], int n) {
	for (int i = 0; i < n - 1; i++)
		for (int j = n - 1; i < j; j--)
			if (a[j < a[j - 1]])
				swap(a[j], a[j - 1]);
}