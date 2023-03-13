/*
 Programmer: Emiliano Viernes Orozco

 Program name: InventoryStack.cpp

Date: 5-3-21

Version: 2.2

This is a c++ program is a stack based application that usees user input to obtain serialNumber manufacture dat and lot number
for parts, it then allows users to insert or remove the inputed part on a stack.
*/
#include <iostream> // cout
#include <string>
#include "InventoryStack.h"	//Linked lists header file
using namespace std;

const int  addPart = 1; //pushes part
const int  removePart = 2; //pops part on list
const int  quit = 3;	// quits the program

//proto types
void menu (int &);
void pushItem(InventoryStack<int> &);
void popItem(InventoryStack<int> &);

//driver program
int main()
{
	int choice; //catching elements 
	InventoryStack<int> stack; // to hold integers

	do {
		//get user choice
		menu(choice);
		if (choice != quit)
		{
			switch (choice)
			{
			case addPart:
				pushItem(stack);
				break;
			case removePart:
				popItem(stack);
			}
		}
	} while (choice != quit);
		return 0;
	} //end main

	void menu(int& choice) 
	{
		cout << "Hello welcome to El Camino's Automotive Parts" << endl;//user greeting
		cout << "If you wish to add or retrive a part you must enter all the vital information"
			<< addPart
			<< " Add a part to the inventory\n "
			<< removePart
			<< " \nRemove a part from the inventory "
			<< quit
			<< " \nExit the program " << endl;
			cin >> choice;

			while (choice < addPart || choice > quit)
			{
				cout << "Please input one of the given options" << endl;
				cin >> choice;
			}
	}

	void pushItem(InventoryStack<int>& stack)
	{
		int serialNumber;
		cout << "Enter the part's serial number "; 
		cin >> serialNumber;
		stack.push(serialNumber);

		int manufactDate;
		cout << "Enter the part's manufacture date ";
		cin >> manufactDate;
		stack.push(manufactDate);

		int LotNum;
		cout << "Enter the part's lot number ";
		cin >> LotNum;
		stack.push(LotNum);
	}

	void popItem(InventoryStack<int>& stack)
	{
		int serialNumber;
	
		stack.pop(serialNumber);
		if (serialNumber)
			cout << "Part " << serialNumber << " has been removed " << endl;
	}
