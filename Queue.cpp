#pragma once
/*********************************************************************
** Author:		Billy R. Shelton
** Date:		7/5/2018
** Description:		This is an implemenation file for a doubly-linked
circular structure contained within a class.
*********************************************************************/

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
using std::string;
using std::cout;
using std::cin;

//Queue::Queue()
//{ front = NULL; }


//adds a monster pointer to the queue
void Queue::addBack(Monster* dataIn)
{
	//only 1 node
	if (count == 0)
	{	
		//base case when only 1 node, it points to itself

		//node is created
		QPtr Q = new QueueNode;

		//data is initialized by user
		Q->data = dataIn;
		
		Q->previous = Q;

		front = Q;
		back = Q;
		
		//counter 
		count++;
		count2++;
	}
	//2 nodes or more
	else if (count >= 1)
	{
		//MUST BE IN THIS ORDER
		//(1)node is created
		QPtr Q1 = new QueueNode;
		Q1->data = dataIn;

		Q1->previous = back;
		back->next = Q1;
		back = Q1;
		back->next = front;
		front->previous = back;
		
		count++;
		count2++;
	}

}



//returns the front monster from the list
Monster* Queue::getFront()
{
	if (front == NULL)
	{
		cout << "Error.  The Queue is empty.\n\n";
		return 0;
	}
	else
	{
		//return data inside the front pointer
		return (front->data);
	}
}

//removes monster by simply changing the front to the next one behind it
void Queue::removeFront()
{
	/*if (front == NULL)
	{
		cout << "Error.  The Queue is empty.\n\n";
	}
	else*/ if(count >=2)
	{
		//sets the front object to have a unique name
		//front->data->setName("Removed Monster");

		//the front Queue node is moved to the node it points next to
		front = front->next;
		count--;
	}
	else
	{
		count--;
		front = front;
	}
}


//The queue of numbers monsters is displayed
void Queue::displayQueue()
{	
	if (front == NULL)
	{
		cout << "Error.  The Queue is empty.\n\n";
	}
	else
	{
		QPtr current = front;
		for (int i = 0; i < count; i++)
		{
			//if (current->data->getName() != ("Removed Monster"))
			//{
			cout << current->data->getName() << "\n";
			//}
			current = (current->next);
		}
	}

	cout << "\n\n";
}


Queue::Queue()
{
	front = NULL;
	back = NULL;	
}

//This destroys the queue
/*ueue::~Queue()
{
	delete[] front;
}*/


int Queue::getCount()
{
	return count;
}
