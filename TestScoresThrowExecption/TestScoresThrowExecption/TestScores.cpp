#include <iostream>
#include <iomanip>
#include <string>
#include "TestScores.h"
using namespace std;


int main() 
{
	int scr[100];

	//creation of object
	TestScores grade1; //array grades of student 1

	//get grades from array
	cout << "Welcome To El Camino's Test Grade Calculator\n" << endl;
	cout << "Please enter your 5 class test grades so an average score can be calculated " << endl;
		for (int i = 0; i < size; i++)
		cin >> scr[i];

		for (int count = 0; count < 100; count++) {
			cout << "A total of " << count << "exams were taken by you " << endl;
		}
	try
	{
		grade1.setScore(scr);
		cout << "Score is: " << grade1.setScore() <<endl;
		cout << "The average of your test scores was" << grade1.getAverage() << endl;
	}

	catch (TestScores::InvalidScore) 
	{
		cout << "Error: Score cannot be bellow 0% or above 100%. \n" << endl;
	}
	cout << "El camino thank's you for using our program, have a nice day." << endl;
	return 0;
}// end main




//int scr[7];
//cout << "Greetings, Please Enter your 5 test scores: " << endl;
//for (int i = 0; i < size; i++) {
//	cin >> scr[i];
//}
//
//try {
//
//}
//
//throw {
//
//}
//
//catch{
//
//}
