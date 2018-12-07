#include "pch.h"
#include "Player.h"
#include "Locations.h"
#include "Game.h"
#include <iomanip>

// Funktion som skriver ut inventory.
void Player::inventory() {

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6); // gul f�rg
	cout << endl << "  �&�&�&�&�&�&�&�&�&�&�&�&�&�&�&�&�" << endl;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15); // vanlig textf�rg
	cout << "    Inventory:" << endl;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6); // gul f�rg
	cout << "  ---------------------------------" << endl;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15); // vanlig textf�rg
	// Skriver ut det som finns i vektorn "items", loopen g�r att allt i vektorn skrivs ut.
	for (unsigned int i = 0; i < items.size(); i++) 
	{

		cout << "    " << items[i] << endl;

	}
	cout << endl;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6); // gul f�rg
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6); // gul f�rg
	cout << "  �&�&�&�&�&�&�&�&�&�&�&�&�&�&�&�&�" << endl << endl;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15); // Avsluta med vanlig textf�rg
}

// Det som ska skrivas in i inventory fr�n f�rsta b�rjan.
void Player::startInventory()
{
	// skickar in 3 items i vektorn "items".
	items.push_back("Hairpin");
	items.push_back("Magic Harry Potter book");
	items.push_back("Nailfile");
}

// �ndrar de 3 f�rsta items till trasiga i inventoryn, beroende p� vilken som anv�nds. �ndras i vektorn "items".
int Player::pushBack(int x) {
	if (x == 1)
	{
		items[0] = "Broken Hairpin";
	}
	else if (x == 2)
	{
		items[1] = "Warped Harry Potter book";
	}
	else if (x == 3)
	{
		items[2] = "Dull Nailfile";
	}
	return 0;
}

// Ger spelaren items i inventory, beroende p� vilket item spelaren tar. L�ggs i vektorn "items".
void Player::giveItem(int a) {
	switch (a)
	{
	case 1:
		items.push_back("Scissors");
		break;
	case 2:
		items.push_back("Bloody Uniform");
		break;
	case 3:
		items.push_back("Clean uniform");
		break;
	case 4:
		items.push_back("Some coins ");
		break;
	default:
		break;
	}
}

// �ndrar spelarens uniform till REN, om spelaren tv�ttar den.
void Player::changeUniform() {

	items[4] = "Clean uniform";
}

// Tar bort coins fr�n inventoryn n�r dem �r slut. 
void Player::changeCoins()
{
	items.pop_back();
}

// Tar bort allt i inventoryn, allts� i vektorn "items" F�RUTOM de 3 f�rsta sakerna som spelaren har fr�n b�rjan.
void Player::ClearExtraItems()
{
	int count = items.size();
	if (count > 3)
	{
		for (int i = 0; i < count - 3; i++)
		{
			items.pop_back();

		}
	}
}

// Rensar ALLT i inventoryn vid Game Over.
void Player::clearVector()
{
	items.clear();
}


Player::Player()
{
}

Player::~Player()
{
}
