#pragma once
#ifndef ClassDate_H
#define ClassDate_H
#include <iostream> // cout
#include <string> 
#include <cstdlib> // exit function
using namespace std;

class Date
{
private:
	int day;
	int month;
	int year;
public:
	class InvalidScore {};
	TestScores()
	{
		Score = 0;
	}
	//prototype
	void setScore(int);
	void getScore();
}//end class Test Scores



void TestScores::setScore(int s) {
	if (s >= 0 && s <= 100)
		Score = s;
	else
		throw InvalidScore();
}//end setScore member function



void TestScores::getScore() {

}//end setScore member function



#endif