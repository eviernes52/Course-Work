#pragma once
#ifndef TestScores_H
#define TestScores_H
#include <iostream> // cout
#include <string> 
#include <cstdlib> // exit function
using namespace std;

class TestScores
{
private:
double scr;
public: 
class InvalidScore; //Empty class declaration
TestScores(int) {}		//default constructor
//prototype
void setScore(double);
double getAverage();
}//end class Test Scores

double TestScores::getAverage(){
	double scrSize =
		for (int count = 0; count > 100; count++) {
			scrSize = count;
		}
	scr / scrSize;
	
}//end getAverage member function




void TestScores::setScore(double s) {
	if (s >= 0 && s <= 100)
		scr = s;
	else
		throw InvalidScore();
}//end setScore member function



#endif