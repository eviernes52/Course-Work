#pragma once
#ifndef Inserfunction_H
#define Inserfunction_H
#include <iostream> // cout
#include <string> 
#include <cstdlib> // exit function

using namespace std;

class NumberList {
private:
	struct NodeList
	{
		int sum;
		struct NodeList* next;
	};

	NodeList* head;

public:
	//default constructor
	NumberList()
	{
		head = nullptr;
	}

	//funcs
	void appendNode(int);	//append node means to add the node to the end of the list
	void insertNode(int); // insert a node where ever needed to
	void reverseNode(); // reverses the node 
	void displayNumbers() const;	//to display the number list

//destructor destroying the list
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
	NodeList* newNode;
	NodeList* nodePtr;

	newNode = new NodeList;
	newNode->sum = m;
	newNode->next = nullptr;

	if (!head)
			head = newNode;
	else
	{
		nodePtr = head;
		while (nodePtr->next)
			nodePtr = nodePtr->next;
		nodePtr->next = newNode;
	}
} //end append function

void NumberList::insertNode(int newnum) // to insert a node in the middle of the list 
{
	NodeList* newNode;
	NodeList* nodePtr;
	NodeList* previousNode = nullptr;

	newNode = new NodeList;
	newNode->sum = newnum;

	if (!head)
		{
			head = newNode;
			newNode->next = nullptr;
		}
	else
	{
		nodePtr = head;
		previousNode = nullptr;

		while (nodePtr != nullptr && nodePtr->sum < newnum)
		{
			previousNode = nodePtr;
			nodePtr = nodePtr->next;
		}

		if (previousNode == nullptr)
		{
			head = newNode;
			newNode->next = nodePtr;
		}
		else {
			previousNode->next = newNode;
			newNode->next = nodePtr;
		}
	}
}

 void NumberList::reverseNode() //to rearrange the nodes in the list so that their order is reversed
{
	NodeList* prev = nullptr;
	NodeList* curr = head;
	NodeList* next = nullptr;
	
	while (head != nullptr) 
	{
		next = head->next;
		head->next = prev;
		prev = head;
		head = next;
	}
}

 void NumberList::displayNumbers() const
 {
	 NodeList* nodePtr;

	 nodePtr = head;

	 while (nodePtr)
	 {
		 cout << nodePtr->sum << endl;
		 nodePtr = nodePtr->next;
	 }
 }//end display function
#endif