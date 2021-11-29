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
Item::Item()									// constructeur : Un constructeur est, en programmation orient�e objet, une fonction particuli�re appel�e lors de l'instanciation. 
												//Elle permet d'allouer la m�moire n�cessaire � l'objet et d'initialiser ses attributs. 
{}
Item::~Item(){}									//le destructeur d'une classe est une m�thode sp�ciale lanc�e lors de la destruction d'un objet afin de r�cup�rer les ressources 
												//(principalement la m�moire vive) r�serv�e dynamiquement lors de l'instanciation de l'objet. Alors qu'il peut exister plusieurs constructeurs, il ne peut exister qu'un seul destructeur. 

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