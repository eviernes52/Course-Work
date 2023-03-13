/*
 Programmer: Emiliano Viernes Orozco

 Program name: ProductionWorker.cpp

Date: 4-5-21

Version: 1.2

This is a c++ program that was designed to utalize linked lists to add an integer through a node to
the end of the linked list and then print out the nodes. 
*/

#include <iostream> // cout
#include <string>
#include "LinkedLists.h"	//Linked lists header file

using namespace std;
//driver program
int main() {

	NumberList List;

	//build data with basic ints by calling append 4 times
	List.appendNode(3);
	List.appendNode(4);
	List.appendNode(5);
	List.appendNode(6);
	
	List.displayNumbers();	//displays the list
}//end main