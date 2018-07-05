#pragma once
/*********************************************************************
** Author:		Billy R. Shelton
** Date:		7/5/2018
** Description:		This is a header file for a doubly-linked 
circular structure contained within a class.
*********************************************************************/

#ifndef QUEUE_HPP
#define QUEUE_HPP
#include "Queue.hpp"
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
#include <iostream>

//doubly linked circular list
class Queue
{
	private:
		typedef struct QueueNode 
		{
			Monster* data;
			QueueNode* next;
			QueueNode* previous;
		}* QPtr;

		QPtr front;
		QPtr back;
		int count = 0;
		int count2 = 0;

	public:
		Queue();
		//~Queue();
		void addBack(Monster*);
		Monster* getFront();
		void removeFront();
		void displayQueue();
		int getCount();
		
};

#endif
