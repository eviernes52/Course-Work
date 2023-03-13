/*
 Programmer: Emiliano Viernes Orozco

 Program name: InsertFunc.cpp

Date: 4-28-21

Version: 1.0

This is a c++ program is a continuation of a previous lecture on stacks in which two functions called add and subtract were included, now the additional member functions
Mult (to multiply), Div(to divide), addALL(to add all), multALL(to multiply all)
*/
#include <iostream> // cout
#include <string>
#include "mathStack.h"	//Linked lists header file
#include "IntStack.h"

void mathStack::mult() {
	int num, product;
	pop(product);
	pop(num);

	product = product * num;
	push(product);
}

void mathStack::div() {
	int num, div;
	pop(div);
	pop(num);

	div = div / num;
	push(div);
}
void mathStack::addALL() {
	int num = 0, sumAll= 0;

	while (!isEmpty())
	{
		pop(num);
		sumAll += num;
	}
	push(sumAll);
}

void mathStack::multALL() {
	int num = 0, productAll = 1;

	while (!isEmpty())
	{
		pop(num);
		productAll *=  num;
	}
	push(productAll);
}





using namespace std;
//driver program
int main() {

	int catchElems; //catching elements 

	mathStack stack(10); // to hold integers
	
	//Pushes 2 and 4 onto the stack
	cout << "Pushing 2" << endl;
	stack.push(2);
	cout << "Pushing 4" << endl;
	stack.push(4);

	//multiply two values
	stack.mult();
	//pop the produce of the stack and display it/
	cout << "The produce is ";
	stack.pop(catchElems);
	cout << catchElems << endl << endl;



	//Pushes 2 and 8 onto the stack
	cout << "Pushing 2" << endl;
	stack.push(2);
	cout << "Pushing 8" << endl;
	stack.push(8);

	//multiply two values
	stack.div();
	//pop the produce of the stack and display it/
	cout << "The quotient is ";
	stack.pop(catchElems);
	cout << catchElems << endl << endl;



	//Pushes 7, 8, and 9 onto the stack
	cout << "Pushing 7" << endl;
	stack.push(7);
	cout << "Pushing 8" << endl;
	stack.push(8);
	cout << "Pushing 9" << endl;
	stack.push(9);

	//add all values
	stack.addALL();
	//pop the produce of the stack and display it/
	cout << "The sum of all numbers is ";
	stack.pop(catchElems);
	cout << catchElems << endl << endl;

	//Pushes 1, 2, and 3 onto the stack
	cout << "Pushing 1" << endl;
	stack.push(1);
	cout << "Pushing 2" << endl;
	stack.push(2);
	cout << "Pushing 3" << endl;
	stack.push(3);

	//add all values
	stack.multALL();
	//pop the produce of the stack and display it/
	cout << "The sum of all numbers is ";
	stack.pop(catchElems);
	cout << catchElems << endl << endl;


}//end main