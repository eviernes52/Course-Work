#pragma once
#ifndef balancedParentheses_H
#define balancedParentheses_H
#include <iostream> // cout
#include <string> 
#include <cstdlib> // exit function

using namespace std;

//stack template
template <class T>
class balancedParen {
private:
	struct ParenNode {
		T value;
		ParenNode* next;
	};
	ParenNode* top;
public:
	//default constructor
	balancedParen() {
		top = nullptr;
	}

	//destructor for destroying the list of integers
	~balancedParen();

	//stack operators
	bool isEmpty(); // Checks if stack is empty which occurs when top is -1
	void pop(T &); // to pop the function
	void push(T);	//to push the function
};//end of class


//deconstructor 
template <class T>
balancedParen<T>::~balancedParen() {
	ParenNode* nodePtr, * nextNode;
	nodePtr = top;
	while (nodePtr != nullptr) 
	{
		nextNode = nodePtr->next;
		delete nodePtr;
		nodePtr = nextNode;
	}
}//end decontructor function

template <class T>
void balancedParen<T>::push(T paren) {
	ParenNode* newNode = nullptr;
	newNode = new ParenNode;
	newNode->value = paren;

	if (isEmpty()) 
	{
		top = newNode;
		newNode->next = nullptr;
	}
	else 
	{
		newNode->next = top;
		top = newNode;
	}
}

template <class T>
void balancedParen<T>::pop(T &paren) {
	ParenNode* temp = nullptr;

	if (isEmpty())
	{
		cout << "The stack is empty" <<endl;
	}
	else
	{
		paren = top->value;
		temp = top->next;
		delete top;
		top = temp;
	}
}

template <class T>
bool balancedParen<T>::isEmpty() {
	bool status;

	if (!top)
		status = true;
	else
		status = false;
	return status;	//returns false status
}
#endif