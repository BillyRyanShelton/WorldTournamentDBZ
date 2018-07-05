#pragma once
/*********************************************************************
** Author:		Billy R. Shelton
** Date:		7/5/2018
** Description:  This is a header file for the functions defined in
the Zfighterstats.cpp file.
*********************************************************************/

#ifndef ZFIGHTERSSTATS_HPP
#define ZFIGHTERSSTATS_HPP
#include <iostream>
#include <string>
#include <vector>
#include "Barbarian.hpp"
#include "BlueMen.hpp"
#include "HarryPotter.hpp"
#include "Medusa.hpp"
#include "Monster.hpp"
#include "Vampire.hpp"
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


void welcome();
float player1InputValidation();
float player2InputValidation();
float numFighterInputValidation();
Monster* roundFights(Monster* P1, Monster* P2);
Monster* loserp2(Monster* P2);

#endif
