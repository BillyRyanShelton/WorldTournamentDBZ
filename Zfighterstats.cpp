/*********************************************************************
** Author:		Billy R. Shelton
** Date:		7/5/2018
** Description:  This is a source file which defines the functions
created in Zfighterstats.hpp.  This file contains character object 
definition functions.
*********************************************************************/

#include <iostream>
#include <string>
#include <vector>
#include "Barbarian.hpp"
#include "BlueMen.hpp"
#include "HarryPotter.hpp"
#include "Medusa.hpp"
#include "Monster.hpp"
#include "Vampire.hpp"
#include "Zfighterstats.hpp"
#include <time.h>
#include <stdlib.h>	
#include <stdio.h>
//#include <cstdlib>
//#include <windows.h>
#include <memory>
#include <iomanip>
#include <cmath>
//#include <fmod.h>
using std::setw;
using std::setprecision;
using std::string;
using std::cout;
using std::cin;




//player 1's monster choice
float player1InputValidation()
{
	cout << "Player 1: Which character do you choose? (1,2,...,14,15)\n";
	float C1;
	char firstChar;
	cin >> C1;
	firstChar = cin.peek();
	cout << firstChar;
	cin.clear();
	cin.ignore(100, '\n');

	while ((C1 < 1) || ((fmod(C1, 1) != 0)) || (firstChar != '\n') || (C1 > 15))
	{
		cout << "Try again player 1.  Which character do you choose? (1,2,...,14,15)\n";
		cin >> C1;
		firstChar = cin.peek();
		cin.clear();
		cin.ignore(100, '\n');
	}
	return C1;
}


//player 2's monster choice
float player2InputValidation()
{
	cout << "Player 2: Which character do you choose? (1,2,...,14,15)\n";
	float C2;
	char firstChar;
	cin >> C2;
	firstChar = cin.peek();
	cout << firstChar;
	cin.clear();
	cin.ignore(100, '\n');

	while ((C2 < 1) || (fmod(C2, 1) != 0) || (firstChar != '\n') || (C2 > 15))
	{
		cout << "Try again player 2.  Which character do you choose? (1,2,...,14,15)\n";
		cin >> C2;
		firstChar = cin.peek();
		cin.clear();
		cin.ignore(100, '\n');
	}
	return C2;
}

//asks the user how many fighters each player will have
float numFighterInputValidation()
{
	cout << "How many fighters will both players each have? (1,2,...,14,15)\n";
	float n1;
	char firstChar;
	cin >> n1;
	firstChar = cin.peek();
	cout << firstChar;
	cin.clear();
	cin.ignore(100, '\n');

	while ((n1 < 1) || (fmod(n1, 1) != 0) || (firstChar != '\n') || (n1 > 15))
	{
		cout << "Try again.  How many fighters will both players each have? (1,2,...,14,15)\n";
		cin >> n1;
		firstChar = cin.peek();
		cin.clear();
		cin.ignore(100, '\n');
	}
	return n1;
}



//explains game to users
void welcome()
{
	cout << "Welcome to the World Tournament Finals!\n\n";
	cout << "There are 15 choosable characters.\n";
	cout << "(1) Super Saiyan 3 Gotenks\n";
	cout << "(2) Frieza\n";
	cout << "(3) Kid Buu\n";
	cout << "(4) Super Saiyan 2 Vegeta\n";
	cout << "(5) Super Saiyan 3 Goku\n";
	cout << "(6) Yamcha\n";
	cout << "(7) Krillin\n";
	cout << "(8) Piccolo\n";
	cout << "(9) Gohan\n";
	cout << "(10) Trunks\n";
	cout << "(11) Goten\n";
	cout << "(12) Cell\n";
	cout << "(13) Master Roshi\n";
	cout << "(14) Legendary Super Saiyan Broly\n";
	cout << "(15) Android 18\n\n";

	cout << "Tournament Rules: This is a 1v1 fantasy league of the World Tournament.\n";
	cout << "Both playes are given an equal number of fighters.  Each player then\n";
	cout << "chooses their lineup order.  The tournment starts and each round \n";
	cout << "the characters battle in order of their line-up.  The rules for each round\n";
	cout << "are outlined below.\n\n";

	cout << "Rules per Round:  A random player goes first and for each turn the attacking\n";
	cout << "player rolls their dice to see their attack power for that turn.\n";
	cout << "Similarly, the defending player rolls their dice to see their defense\n";
	cout << "power for that turn.  Players alternate attacking and defending until\n";
	cout << "the first player loses all of their strength points.  The other player\n";
	cout << "wins that round!\n\n";


}





//this function simulates 1 single round of battle.   Both characters are entered in
//the winner is returned
Monster* roundFights(Monster* P1, Monster* P2)
{
	//randomly choose a player to go first  1 or 2
	int seed = (time(NULL));
	int pTurn = (rand() % 2) + 1;
	//cout << pTurn;

	//initiate game
	while (((P1->getStrength()) > 0) && ((P2->getStrength()) > 0))
	{
		//player 1's turn to attack
		if (pTurn == 1)
		{
			cout << "Player 1's turn.\n";
			cout << P1->getName() << " attack(s) " << P2->getName() << "\n";



			//calculate charm
			int charm = (rand() % 2) + 1;

			//if character 2 has a vampire(Gohan) and charm is successful
			if ((P2->getName() == "Gohan" && (charm == 1)))
			{
				cout << "Gohan dodged Player 2's attack.\n";

			}

			//if character 2 does not have a vampire proceed as normal
			else
			{
				//player 1 attacks and player 2 defends
				int damageDone = (P1->attackPlayer() - P2->defend());

				//if defense was able to block the attack no strength or armor is lost
				if (damageDone <= 0)
				{
					//nothing happens 
					cout << "No damage was done.\n";
				}

				//if damage is greater than defense
				else
				{
					//left over damage after armor is destroyed is applied to strength points
					if (damageDone > P2->getArmor())
					{
						P2->setStrength(P2->getStrength() - damageDone + P2->getArmor());
						//armor is destroyed
						P2->setArmor(0);
						cout << "Player 2's character now has " << P2->getStrength() << " strength point(s)\n";

						//for every 4 strength points lost the blue men(Super Saiyan 3 Gotenks) lose defense
						if (P2->getName() == "Super Saiyan 3 Gotenks")
						{
							P2->checkStrength();
						}

						//if Harry Potter(Goku, Cell Piccolo) dies once his strength is restored and doubled
						if (P2->getName() == "Super Saiyan 3 Goku" || "Cell" || "Piccolo")
						{
							P2->checkStrength();
						}

						//CHANGING UP CODE HERE SO WATCH OUT FOR ERRORS
						//if the strength of player 2's character is 0 or less the game is over
						if (P2->getStrength() <= 0)
						{
							cout << "\n";
							cout << P2->getName() << " lost!\n\n";

							if ((P2->getStrength() < (-300)) && (P1->getName() == "Super Saiyan 2 Vegeta"))
							{
								cout << "Vegeta's Big Bang Attack obliterated " << P2->getName() << "\n";
							}

							return P2;
						}
					}
					//armor is reduced or destroyed but no strength points are lost
					else if (damageDone <= P2->getArmor())
					{
						P2->setArmor((damageDone - P2->getArmor()));

						if (P2->getArmor() < 0)
						{
							P2->setArmor(0);
						}

						cout << "Player 2:  " << P2->getName() << "'s armor was reduced to " << P2->getArmor() << "\n";
					}
				}


			}
			pTurn = 2;
			cout << "\n";
		}





		//player 2's turn to attack
		else   // (pTurn == 2)
		{
			cout << "Player 2's turn.\n";
			cout << P2->getName() << " attack(s) " << P1->getName() << "\n";



			//calculate charm
			int charm = (rand() % 2) + 1;

			//if character 2 has a vampire(Gohan) and charm is successful
			if ((P1->getName() == "Gohan" && (charm == 1)))
			{
				cout << "Gohan dodged Player 2's attack.\n";

			}

			//if character 1 does not have a vampire proceed as normal
			else
			{
				//player 2 attacks and player 1 defends
				int damageDone = (P2->attackPlayer() - P1->defend());

				//if defense was able to block the attack no strength or armor is lost
				if (damageDone <= 0)
				{
					//nothing happens 
					cout << "No damage was done.\n";
				}

				//if damage is greater than defense
				else
				{
					//left over damage after armor is destroyed is applied to strength points
					if (damageDone > P1->getArmor())
					{
						P1->setStrength(P1->getStrength() - damageDone + P1->getArmor());
						//armor is destroyed
						P1->setArmor(0);
						cout << "Player 1's character now has " << P1->getStrength() << " strength point(s)\n";

						//for every 4 strength points lost the blue men(Super Saiyan 3 Gotenks) lose defense
						if (P1->getName() == "Super Saiyan 3 Gotenks")
						{
							P1->checkStrength();
						}

						//if Harry Potter(Cell, Goku, Piccolo) dies once his strength is restored and doubled
						if (P1->getName() == "Super Saiyan 3 Goku" || "Cell" || "Piccolo")
						{
							P1->checkStrength();
						}

						//CHANGING UP CODE HERE SO WATCH OUT FOR ERRORS
						//if the strength of player 1's character is 0 or less the game is over
						if (P1->getStrength() <= 0)
						{
							cout << "\n";
							cout << P1->getName() << " lost!\n";

							if ((P1->getStrength() < (-300)) && (P2->getName() == "Super Saiyan 2 Vegeta"))
							{
								cout << "Vegeta's Big Bang Attack obliterated " << P1->getName() << "\n";
							}
							return P1;
						}
					}
					//armor is reduced or destroyed but no strength points are lost
					else if (damageDone <= P1->getArmor())
					{
						P1->setArmor((damageDone - P1->getArmor()));

						if (P1->getArmor() < 0)
						{
							P1->setArmor(0);
						}

						cout << "Player 1:  " << P1->getName() << "'s armor was reduced to " << P1->getArmor() << "\n";
					}
				}


			}
			pTurn = 1;
			cout << "\n";
		}
	}
}



Monster* loserp2(Monster* P2)
{
	return P2;
}
