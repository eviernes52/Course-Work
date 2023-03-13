/*
 Programmer: Emiliano Viernes Orozco

 Program name: InsertFunc.cpp

Date: 4-24-21

Version: 1.2

This is a c++ program that was designed to hold static stacks  of integers to push and pop said integers stack (10,20,30,40,50).
*/
#include <iostream> // cout
#include <string>
#include "IntStack.h"	//Linked lists header file

using namespace std;
//driver program
int main() {

	int AssignNum; //assinged numbers
	
	IntStack stack(5); // to hold 10 20 30 40 and 50
		//push
	cout << "The assigned numbers will now push" << endl;
		stack.push(10);
		cout << "pushing 10" << endl;
		stack.push(20);
		cout << "pushing 20" << endl;
		stack.push(30);
		cout << "pushing 30" << endl;
		stack.push(40);
		cout << "pushing 40" << endl;
		stack.push(50);
		cout << "pushing 50" << endl;

		//pop
		cout << "The assigned numbers will now pop" << endl;
		stack.pop(AssignNum);
		cout << AssignNum << endl;
		stack.pop(AssignNum);
		cout << AssignNum << endl;
		stack.pop(AssignNum);
		cout << AssignNum << endl;
		stack.pop(AssignNum);
		cout << AssignNum << endl;
		stack.pop(AssignNum);
		cout << AssignNum << endl;
}//end main





