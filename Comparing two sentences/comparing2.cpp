/*
 Programmer: Emiliano Viernes Orozco

 Program name: comparing2.cpp

Date: 5-23-21

Version: 1.2

This is a c++ program that was designed to use the queue function to get user input of the first user sentence and then compare it to the size of the user's second sentance to check if both sentances were the same as it calculates their exact sizes and characters used. As if one 
single char called letter to represent individual letters is off, it won't get popped, and if it doesn't get popped and doesn't pass the isempty check, then no match sentences.
*/
#include <iostream>
#include <iomanip>
#include <queue>
#include <string>

using namespace std;

int main() 
{ 
    string sentence1, sentence2;

    cout << "Greetings and welcome to El Camino's Sentence Identifier\n" << endl;
	cout << "Please insert your first sentence: ";
     getline(cin, sentence1);

     cout << "Please insert your second sentence: ";
    getline(cin, sentence2);

   queue<char> firstsentence;
    for (char letter : sentence1) firstsentence.push(letter);

   queue<char> secondsentence;
    for (char letter : sentence2) secondsentence.push(letter);

    while (!firstsentence.empty() && !secondsentence.empty() && firstsentence.front() == secondsentence.front())
    {
        firstsentence.pop();
        secondsentence.pop();
    }

    if (firstsentence.empty() && secondsentence.empty())
    {
       cout << "Sentences are the same" << endl;
    }
    else
    {
        cout << "Sentences are different" << endl;
    }
}//end main