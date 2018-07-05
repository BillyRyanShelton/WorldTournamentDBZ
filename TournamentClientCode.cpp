#pragma once
/*********************************************************************
** Author:		Billy R. Shelton
** Date:		7/5/2018
** Description:  The following program implements a 1v1 fantasy creature 
game.  The characters have different abilites and can use them when fighting
opponents.  The characters are derived from the tv show Dragonball Z.
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
#include "Queue.hpp"
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


int main()
{

	//introduction and explaination of game
	welcome();

	//number of fighters per player input validation
	float roundCount = numFighterInputValidation();

	//two queues are created to hold player 1 and 2's lineups
	Queue p1Lineup;
	Queue p2Lineup;

	//a queue is created to hold the losers of each round
	Queue LoserBracket;

	//tell user to enter their lineups
	cout << "Player 1 and Player 2 enter your character line-ups from first to last. \n\n";
	
	//set up player 1 and player 2's lineup
	for (int i = 0; i < roundCount; i++)
	{
		//ask for player 1's lineup
		
		int C1 = player1InputValidation();  //1-15
		if (C1 == 1)
		{
			BlueMen* P1 = new BlueMen;
			P1->setName("Super Saiyan 3 Gotenks");
			P1->setAttack(15);
			P1->setDefense(15);
			P1->setArmor(5);
			P1->setStrength(15);
			p1Lineup.addBack(P1);
			
		}
		else if (C1 == 2)
		{
			Barbarian* P2 = new Barbarian;
			P2->setName("Frieza");
			P2->setAttack(10);
			P2->setDefense(5);
			P2->setArmor(5);
			P2->setStrength(10);
			p1Lineup.addBack(P2);
			
		}
		else if (C1 == 3)
		{
			Barbarian* P3 = new Barbarian;
			P3->setName("Kid Buu");
			P3->setAttack(20);
			P3->setDefense(20);
			P3->setArmor(30);
			P3->setStrength(30);
			p1Lineup.addBack(P3);
		}
		else if (C1 == 4)
		{
			Medusa* P4 = new Medusa;
			P4->setName("Super Saiyan 2 Vegeta");
			P4->setAttack(15);
			P4->setDefense(10);
			P4->setArmor(5);
			P4->setStrength(15);
			p1Lineup.addBack(P4);
		}
		else if (C1 == 5)
		{
			HarryPotter* P5 = new HarryPotter;
			P5->setName("Super Saiyan 3 Goku");
			P5->setAttack(15);
			P5->setDefense(15);
			P5->setArmor(25);
			P5->setStrength(25);
			p1Lineup.addBack(P5);
		}
		else if (C1 == 6)
		{
			Barbarian* P6 = new Barbarian;
			P6->setName("Yamcha");
			P6->setAttack(5);
			P6->setDefense(2);
			P6->setArmor(1);
			P6->setStrength(5);
			p1Lineup.addBack(P6);
		}
		else if (C1 == 7)
		{
			Barbarian* P7 = new Barbarian;
			P7->setName("Krillin");
			P7->setAttack(5);
			P7->setDefense(3);
			P7->setArmor(3);
			P7->setStrength(5);
			p1Lineup.addBack(P7);
		}
		else if (C1 == 8)
		{
			HarryPotter* P8 = new HarryPotter;
			P8->setName("Piccolo");
			P8->setAttack(12);
			P8->setDefense(10);
			P8->setArmor(15);
			P8->setStrength(12);
			p1Lineup.addBack(P8);
		}
		else if (C1 == 9)
		{
			Vampire* P9 = new Vampire;
			P9->setName("Gohan");
			P9->setAttack(15);
			P9->setDefense(15);
			P9->setArmor(5);
			P9->setStrength(15);
			p1Lineup.addBack(P9);
		}
		else if (C1 == 10)
		{
			Barbarian* P10 = new Barbarian;
			P10->setName("Trunks");
			P10->setAttack(12);
			P10->setDefense(10);
			P10->setArmor(12);
			P10->setStrength(12);
			p1Lineup.addBack(P10);
		}
		else if (C1 == 11)
		{
			Barbarian* P11 = new Barbarian;
			P11->setName("Goten");
			P11->setAttack(12);
			P11->setDefense(10);
			P11->setArmor(12);
			P11->setStrength(12);
			p1Lineup.addBack(P11);
			
		}
		else if (C1 == 12)
		{
			HarryPotter* P12 = new HarryPotter;
			P12->setName("Cell");
			P12->setAttack(12);
			P12->setDefense(10);
			P12->setArmor(12);
			P12->setStrength(12);
			p1Lineup.addBack(P12);
			
		}
		else if (C1 == 13)
		{
			Barbarian* P13 = new Barbarian;
			P13->setName("Master Roshi");
			P13->setAttack(5);
			P13->setDefense(2);
			P13->setArmor(2);
			P13->setStrength(5);
			p1Lineup.addBack(P13);
		
		}
		else if (C1 == 14)
		{
			Barbarian* P14 = new Barbarian;
			P14->setName("Legendary Super Saiyan Broly");
			P14->setAttack(30);
			P14->setDefense(1);
			P14->setArmor(5);
			P14->setStrength(40);
			p1Lineup.addBack(P14);
			
		}
		else if (C1 == 15)
		{
			Barbarian* P15 = new Barbarian;
			P15->setName("Android 18");
			P15->setAttack(10);
			P15->setDefense(6);
			P15->setArmor(6);
			P15->setStrength(10);
			p1Lineup.addBack(P15);
			
		}

		//ask for player 2's lineup
		
		int C2 = player2InputValidation();  //1-15
		if (C2 == 1)
		{
			BlueMen* P16 = new BlueMen;
			P16->setName("Super Saiyan 3 Gotenks");
			P16->setAttack(15);
			P16->setDefense(15);
			P16->setArmor(5);
			P16->setStrength(15);
			p2Lineup.addBack(P16);
			
		}
		else if (C2 == 2)
		{
			Barbarian* P17 = new Barbarian;
			P17->setName("Frieza");
			P17->setAttack(10);
			P17->setDefense(5);
			P17->setArmor(5);
			P17->setStrength(10);
			p2Lineup.addBack(P17);
			
		}
		else if (C2 == 3)
		{
			Barbarian* P18 = new Barbarian;
			P18->setName("Kid Buu");
			P18->setAttack(20);
			P18->setDefense(20);
			P18->setArmor(30);
			P18->setStrength(30);
			p2Lineup.addBack(P18);
			
		}
		else if (C2 == 4)
		{
			Medusa* P19 = new Medusa;
			P19->setName("Super Saiyan 2 Vegeta");
			P19->setAttack(15);
			P19->setDefense(10);
			P19->setArmor(5);
			P19->setStrength(15);
			p2Lineup.addBack(P19);
			
		}
		else if (C2 == 5)
		{
			HarryPotter* P20 = new HarryPotter;
			P20->setName("Super Saiyan 3 Goku");
			P20->setAttack(15);
			P20->setDefense(15);
			P20->setArmor(25);
			P20->setStrength(25);
			p2Lineup.addBack(P20);
			
		}
		else if (C2 == 6)
		{
			Barbarian* P21 = new Barbarian;
			P21->setName("Yamcha");
			P21->setAttack(5);
			P21->setDefense(2);
			P21->setArmor(1);
			P21->setStrength(5);
			p2Lineup.addBack(P21);
			
		}
		else if (C2 == 7)
		{
			Barbarian* P22 = new Barbarian;
			P22->setName("Krillin");
			P22->setAttack(5);
			P22->setDefense(3);
			P22->setArmor(3);
			P22->setStrength(5);
			p2Lineup.addBack(P22);
			
		}
		else if (C2 == 8)
		{
			HarryPotter* P23 = new HarryPotter;
			P23->setName("Piccolo");
			P23->setAttack(12);
			P23->setDefense(10);
			P23->setArmor(15);
			P23->setStrength(12);
			p2Lineup.addBack(P23);
		
		}
		else if (C2 == 9)
		{
			Vampire* P24 = new Vampire;
			P24->setName("Gohan");
			P24->setAttack(15);
			P24->setDefense(15);
			P24->setArmor(5);
			P24->setStrength(15);
			p2Lineup.addBack(P24);
			
		}
		else if (C2 == 10)
		{
			Barbarian* P25 = new Barbarian;
			P25->setName("Trunks");
			P25->setAttack(12);
			P25->setDefense(10);
			P25->setArmor(12);
			P25->setStrength(12);
			p2Lineup.addBack(P25);
			
		}
		else if (C2 == 11)
		{
			Barbarian* P26 = new Barbarian;
			P26->setName("Goten");
			P26->setAttack(12);
			P26->setDefense(10);
			P26->setArmor(12);
			P26->setStrength(12);
			p2Lineup.addBack(P26);
			
		}
		else if (C2 == 12)
		{
			HarryPotter* P27 = new HarryPotter;
			P27->setName("Cell");
			P27->setAttack(12);
			P27->setDefense(10);
			P27->setArmor(12);
			P27->setStrength(12);
			p2Lineup.addBack(P27);
			
		}
		else if (C2 == 13)
		{
			Barbarian* P28 = new Barbarian;
			P28->setName("Master Roshi");
			P28->setAttack(5);
			P28->setDefense(2);
			P28->setArmor(2);
			P28->setStrength(5);
			p2Lineup.addBack(P28);
		
		}
		else if (C2 == 14)
		{
			Barbarian* P29 = new Barbarian;
			P29->setName("Legendary Super Saiyan Broly");
			P29->setAttack(30);
			P29->setDefense(1);
			P29->setArmor(5);
			P29->setStrength(40);
			p2Lineup.addBack(P29);
			
		}
		else if (C2 == 15)
		{
			Barbarian* P30 = new Barbarian;
			P30->setName("Android 18");
			P30->setAttack(10);
			P30->setDefense(6);
			P30->setArmor(6);
			P30->setStrength(10);
			p2Lineup.addBack(P30);
			
		}
	}


	//print out the lineups
	cout << "Here is player 1's lineup:\n";
	p1Lineup.displayQueue();

	cout << "\n";

	cout << "Here is player 2's lineup:\n";
	p2Lineup.displayQueue();
	
	int player1livesleft = roundCount;
	
	int player2livesleft = roundCount;
	
	//get front players from both queues
	for (int i= 0 ; i < 35; i++)
	//while(true)
	{
	
		//create two monster pointers to temporarily hold the next characters to fight
		Monster* player1Character;
		player1Character = p1Lineup.getFront();
		Monster* player2Character;
		player2Character = p2Lineup.getFront();

		//if neither have been removed yet they fight
		cout << "      ROUND " << (i + 1) << ": Fight!\n";
		cout << "-------------------------\n";
		Monster* currentCharacter;
		currentCharacter = roundFights(p1Lineup.getFront(), p2Lineup.getFront());

		//if player 1's character loses it is added to the loser's queue and the winner is added back to its list 
		if (player1Character->getName() == currentCharacter->getName())
		{
			LoserBracket.addBack(player1Character);		//player1's character is added to the loser bracket
			p2Lineup.addBack(player2Character);			//player2's character is added back to its lineup
			player1livesleft = player1livesleft - 1;	//player1 loses a character
		
		}
		
		//if player 2's character loses it is added to the loser's queue and the winner is added back to its list 
		else
		{
			LoserBracket.addBack(player2Character);		//player2's character is added to the loser bracket
			p1Lineup.addBack(player1Character);			//player1's character is added back to its lineup
			player2livesleft = player2livesleft - 1;	//player1 loses a character
		}
		


		//if the character to fight from player 1 is a removed monster then all4 of player 1's characters have died
		/*if (p1Lineup.getCount() < (p2Lineup.getCount()) && ((i+1) == (roundCount)))*/
		if(player1livesleft == 0)
		{
			cout << "\n\n";
			cout << "Player 2's Team Wins!\n";
			break;
		}
		//if the character to fight from player 2 is a removed monster then all of player 2's characters have died
		//else if (p2Lineup.getCount() < (p1Lineup.getCount()) && ((i+1) == (roundCount)))
		else if(player2livesleft == 0)
		{
			cout << "\n\n";
			cout << "Player 1's Team Wins!\n";
			break;
		}
		
		p1Lineup.removeFront();
		p2Lineup.removeFront();
	}
		
	//the losers are printed 	
	cout << "\n\n";
	cout << "     Losers \n";
	cout << "-------------------------\n";
	LoserBracket.displayQueue();

	cout << "Thanks for playing!\n";
	return 0;
}
