/*
 Programmer: Emiliano Viernes Orozco

 Program name: InsertFunc.cpp

Date: 4-24-21

Version: 3.3

This is a c++ program that was designed to use a dynamic stacks and linked list in order to analyze a string of characters and check if each right parenthesis
occuring match with the preceding left parentheses. This program will be used to determine of the undefined size string has a correctly
balanced set of parentheses.
*/
#include <iostream> // cout
#include <string>
#include "balancedParentheses.H"	//Linked lists header file

using namespace std;
//driver program
int main() {
	//create the stack
	int count;

	balancedParen<string> stack; 

	cout << "Please enter your text" << endl;
	string text;
		getline(cin, text);

		for (count = 0; count < text.length(); count++) 
		{

			if (text.length() == '(' || text.length() == '[' || text.length() == '{')
			{
				stack.push(text);
			}
			
			if (!stack.isEmpty()) {
				if (text == ')') {
					if (stack.top == ')') 
					{
						stack.pop();
					}
					else
					{
						return 0;
					}
				if (text == ']') {
					if (stack.top == ']')
					{
						stack.pop();
					}
					else
					{
						return 0;
					}

				if (text == '}') {
					if (stack.top == '}')
					{
						stack.pop();
					}
					else
					{
						return 0;
					}
				}

				if (count <= 0) {
					cout << "Balanced text";
				}

				else() {
					cout << "Unbalanced text";
				}

		} //no text isn't empty

			else {
			cout << "No text entered" << endl;
			return 0;
			}
}	//end main