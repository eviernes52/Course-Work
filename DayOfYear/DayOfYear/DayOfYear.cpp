/*
Program name: ProductionWorker.cpp

Programmer: Emiliano Viernes Orozco

Date: 3-15-21

Version: 5.1

This is a c++ program that was designed to use a class named DayOfYear and get a number of the year and return the day and it is month/
*/
#include <iostream> // for cout
#include <string>
#include <cmath> // for the math computation
#include <cstdlib> // exit function seen in textbook
using namespace std;
// Day of year class declaration
class DayOfYear
{
private:
	static string monthName;	//static member
	static int yearDay;			//static member
	int month;					//instance member
public:
	//Default Constructor
	DayOfYear(int day)
	{
		if (day > 0 &&  day <= 365 )
			day = yearDay;
		else {
			cout << "\nDay can not be greater than 365 or less than 0 as there is at least 1 days and at most 365\n";
			exit(EXIT_FAILURE);		// to exit program if number is not within the yearly calandar 
	}

		void createMonthArray(int size) {
			yearDay = size;
			month = new double[size];
			for (int i = 0; i < size; i++)
				yearDay[i] = month
		}

		void print() 
		{
			for (count = 0; count < 12, count++ )
		}


};


int main() 
{
	int number;
	cout << "Enter a number representing one of the 364  of the year" << endl;
		cin >> number;


}