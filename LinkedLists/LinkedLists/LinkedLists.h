#pragma once
#ifndef LinkedLists_H
#define LinkedLists_H
#include <iostream> // cout
#include <string> 
#include <cstdlib> // exit function

using namespace std;

class NumberList {
private:
	struct NodeList 
	{
		int sum; //value
		struct NodeList* next;
	};

	NodeList* head;

public:
	//default constr
		NumberList()
		{
			head = nullptr;
		}

		//funcs
		void appendNode(int);	//append node means to add the node to the end of the list
		void displayNumbers() const;	//to display the number list
		
	//destroying the list
	~NumberList()
	{
		NodeList* nodePtr;
		NodeList* nextNode;
		nodePtr = head;

		while (nodePtr != nullptr)
		{
			nextNode = nodePtr->next;
			delete nodePtr;
			nodePtr = nextNode;
		}
	}
};//end of class

		void NumberList::appendNode(int m)	// append node means to add the node to the end of the list
		{
			Node* n = new Node;
			Node* curr;


			n->sum = m;
			n->next = NULL;

			if (head != NULL)
			{
				curr = head;
				while (curr->next != NULL)
				{
					curr = curr->next;	//go forward while not null
				}
				curr->next = n;	//points to node with value and null at the end
			}
			else
			{
				head = n; //point head to new node instead of dirrectly to null
			}
		} //end append function



		void NumberList::displayNumbers() const 
		{
			NumberList* nodePtr;

			nodePtr = head;

			while (nodePtr)
			{
				cout << nodePtr->sum << endl;
				nodePtr = nodePtr->next;
			}
		}//end display function

#endif