#pragma once
/*********************************************************************
** Author:		Billy R. Shelton
** Date:		7/5/2018
** Description:  This is a source file which defines the functions
created in the HarryPotter.hpp file.
*********************************************************************/

#include <iostream>
#include <string>
#include "HarryPotter.hpp"
using std::string;
using std::cout;
using std::cin;

//default constructor
HarryPotter::HarryPotter()
{
	name = "Harry Potter";
	attack = 12;
	defense = 12;
	armor = 0;
	strength = 10;
}
//user specified constructor
HarryPotter::HarryPotter(int attackIn, int defenseIn, int armorIn, int strengthIn)
{
	name = "Harry Potter";
	attack = attackIn;
	defense = defenseIn;
	armor = armorIn;
	strength = strengthIn;
}
void HarryPotter::checkStrength()
{
	if (strength <= 0 && livesLeft == 1)
	{
		setStrength(20);

		if (name == "Super Saiyan 3 Goku")
		{
			cout << "Goku took a sensu bean to regain his strength.\n\n";
		}
		else if (name == "Piccolo")
		{
			cout << "Piccolo regrew his limb.  He's not out yet.\n\n";
		}
		else
		{
			cout << "Cell regrew his body.";
		}
		livesLeft = 0;
	}
}
