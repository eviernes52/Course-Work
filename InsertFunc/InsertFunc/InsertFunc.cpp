/*
 Programmer: Emiliano Viernes Orozco

 Program name: InsertFunc.cpp

Date: 4-11-21

Version: 1.3

This is a c++ program that was designed to utalize linked lists to to rearrange the nodes in the list so that their order is reversed
and then print out the nodes.
*/

#include <iostream> // cout
#include <string>
#include "Inserfunction.h"	//Linked lists header file

using namespace std;
//driver program
int main() {

	NumberList List;

	//build data with basic ints by calling append 4 times
	List.appendNode(3);
	List.appendNode(4);
	List.appendNode(5);
	List.appendNode(6);

	//inset a data filled node into the linked list 
	List.insertNode(7);

	//reverse the nodes in the linked list
	List.reverseNode();

	List.displayNumbers();	//displays the list

}//end main







