#pragma once
#ifndef InventoryStack_H
#define InventoryStack_H
#include <iostream> // cout
#include <string> 
#include <cstdlib> // exit function
using namespace std;
template <class T>
class IntStack {
private:
	struct stackNode {
		T value;
		stackNode* next;
	};
	stackNode* top;
public:
	//default constructor
	IntStack() {
		top == nullptr;
	}

	//destructor for destroying the list of integers
	~IntStack();

	//stack operators no isFull needed as is dynamic
	bool isEmpty(); // Checks if stack is empty which occurs when top is -1
	void pop(T&); // to pop the function
	void push(T);	//to push the function
};//end of class

	//const
template <class T>
IntStack<T>::~IntStack() {
	stackNode* nodePtr, * nextNode;

	nodePtr = top;

	while (nodePtr != nullptr) {
		nextNode = nodePtr->next;
		delete nodePtr;
		nodePtr = nextNode;
	}
}


template <class T>
void IntStack<T>::push(T item) {
	stackNode* nextNode = nullptr;
	newNode = new stackNode;
	newNode->value = item;

	if (isEmpty()) {
		top = newNode;
		newNode->next = nullptr;
	}
	else {
		newNode->next = top;
		top = newNode;
	}
}

template <class T>
void IntStack<T>::pop(T& item) {
	stackNode* temp = nullptr;
	if (isEmpty()) {
		cout << "Empty stack" << endl;
	}
	else {
		item = top->value;
		temp = top->next;
		delete  top;
		top = temp;
	}
}

template <class T>
bool IntStack<T>::isEmpty() {
	bool status;
	if (!top)
		status = true;
	else
		status = false;
	return status;
}

#endif
