/*
Program name: doSomething.cpp

Programmer: Emiliano Viernes Orozco

Date: 3-1-21

Version: 1.0

This is a c++ program that was designed to hold a class called TestScores that has member variables holding three test scores. This class includes a constructor, accessor, and mutator functions.
*/

#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

class TestScores {
	private:
		double testScore_1;
		double testScore_2;
		double testScore_3;

	public:
		// default constructor 
		void Scores(double score1, double score2, double score3)
		{
			 testScore_1 = score1;
			 testScore_2 = score2;
			 testScore_3 = score3;
		}

		void setFirstScore(double score1) 
		{
			testScore_1 = score1;
		}

		void setSecondScore(double score2)
		{
			testScore_2 = score2;
		}

		void setThirdScore(double score3)
		{
			testScore_3 = score3;
		}

		//to find the average of the 3 test scores
		double getAverage()
		{
			double average;
			average = (testScore_1 + testScore_2 + testScore_3) / 3;
			return average;
		}

};



int main() {	//test score variable doubles
	double testScore_1;
	double testScore_2;
	double testScore_3;

	TestScores exam1;

	//gather user input dirrectly through cin
	cout << "Enter your first test score. " << endl;	
	cin >> testScore_1;

	cout << "Enter your second test score. " << endl;	
	cin >> testScore_2;

	cout << "Enter your third test score. " << endl;	
	cin >> testScore_3;

	exam1.Scores(testScore_1, testScore_2, testScore_3);

	cout << "The test score average is " << exam1.getAverage() << endl;	//void display wasn't working therefore displayed exam1 average into output

}