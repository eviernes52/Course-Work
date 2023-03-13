#pragma once
#ifndef IntStack_H
#define IntStack_H
#include <iostream> // cout
#include <string> 
#include <cstdlib> // exit function

using namespace std;

class IntStack {
private:
	int* stackArray;
	int stackSize;
	int top;
public:
	//default constructor
	IntStack(int);

	//copy constructor
	IntStack(const IntStack&);

	//destructor for destroying the list of integers
	~IntStack();

	//stack operators
	bool isFull() const;	//Checks if stack is full which occurs when stackSize is -1
	bool isEmpty() const; // Checks if stack is empty which occurs when top is -1
	void pop(int&); // to pop the function
	void push(int);	//to push the function

};//end of class

	//const
IntStack::IntStack(int size) {
	stackArray = new int[size];
	stackSize = size;
	top = -1;
} //end append function

//copy const
IntStack::IntStack(const IntStack& obj) {
	if (obj.stackSize > 0)
		stackArray = new int[obj.stackSize];
	else
		stackArray = nullptr;

	stackSize = obj.stackSize;

	for (int count = 0; count < stackSize; count++)
		stackArray[count] = obj.stackArray[count];

	top = obj.top;
} //end copy constructor function

//deconstructor 
IntStack::~IntStack() {
	delete[] stackArray;
}//end decontructor function

void IntStack::push(int num) {
	if (isFull())
	{
		cout << "Stack is full";
	}
	else
	{
		top++;
		stackArray[top] = num;
	}
}


void IntStack::pop(int& num) {
	if (isEmpty())
	{
		cout << "Stack is empty";
	}
	else
	{
		num = stackArray[top];
		top--;
	}
}

bool IntStack::isFull() const {
	bool status;

	if (top == stackSize - 1)
		status = true;
	else
		status = false;
	return status;
}

bool IntStack::isEmpty() const {
	bool status;

	if (top == -1)
		status = true;
	else
		status = false;
	return status;
}
#endif