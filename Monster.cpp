#pragma once
/*********************************************************************
** Author:		Billy R. Shelton
** Date:		7/5/2018
** Description:  This is a source file which defines the functions
created in the Monster.hpp file.
*********************************************************************/

#include <iostream>
#include <string>
#include "Monster.hpp"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
using std::string;
using std::cout;
using std::cin;
//default constructor
Monster::Monster()
{	//nothing
}
//virtual function used to check a monster's strength
void Monster::checkStrength()
{	//nothing
}

//user specified constructor
Monster::Monster(int attackIn, int defenseIn, int armorIn, int strengthIn)
{
	attack = attackIn;
	defense = defenseIn;
	armor = armorIn;
	strength = strengthIn;
}

//returns attack for character object
int Monster::getAttack()
{
	return attack;
}
//sets attack for character object
void Monster::setAttack(int attackIn)
{
	attack = attackIn;
}

//returns defense for character object
int Monster::getDefense()
{
	return defense;
}

//sets defense for character object
void Monster::setDefense(int defenseIn)
{
	defense = defenseIn;
}

//returns armor for character object
int Monster::getArmor()
{
	return armor;
}
//sets armor for character object
void Monster::setArmor(int armorIn)
{
	armor = armorIn;
}

//retruns strength for character object
int Monster::getStrength()
{
	return strength;
}
//sets armor for character object
void Monster::setStrength(int strengthIn)
{
	strength = strengthIn;
}
//retunrs name for character object
string Monster::getName()
{
	return name;
}
//returns a random attack int amount based on max possible attack
int Monster::attackPlayer()
{
	int outcome;
	if (attack == 0)
	{
		return 0;
	}
	else
	{
		outcome = (rand() % attack) + 1;													//cout << outcome << endl;									//cout << endl;
		return outcome;
	}
}
////returns a random defense int amount based on max possible defense
int Monster::defend()
{
	int outcome;
	if (defense == 0)
	{
		return 0;
	}
	else
	{
		outcome = (rand() % defense) + 1;													//cout << outcome << endl;									//cout << endl;
		return outcome;
	}
}

//sets the name for character object
void Monster::setName(std::string nameIn)
{
	name = nameIn;
}
