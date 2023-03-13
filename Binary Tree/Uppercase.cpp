/*
 Programmer: Emiliano Viernes Orozco

 Program name: Uppercase.cpp

Date: 5-16-21

Version: 1.4

This is a c++ program that was designed to use the queue function to get user input of a sentance and then output the same exact sentance by pushing and poping
in order to get the exact same sentence but instead all letters in the string are replaced with an uppercase version
*/
#include <iostream>
#include <iomanip>
#include <string>
#include <queue>
#include <cctype>

using namespace std;

int main() 
{
	string sentence;
	//define a queue object this time a char
	queue<char> SentQueue; //queue of chars
	char sent;
	cout << "Welcome to El Camino's CAPS setter program please input a sentence of your choice\n" << endl;
	string upper;
	getline(cin, sentence);	// get line for string of og sentence 
	cout << "Pushing your sentance\n" << endl;
		for (int i = 0; i <sentence.size();i++) {
			SentQueue.push(sentence.at(i));
		}
		cout << "popping sentence\n" << endl;
		do 
		{
			sent = toupper(SentQueue.front());
			SentQueue.pop();
			upper.push_back(sent); // thrown back into queue to be outputted
		} 		
		
		while (!SentQueue.empty());
	
		//output results
		cout << upper << endl;
}