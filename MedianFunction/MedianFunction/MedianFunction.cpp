/*
Program name: MedianFunction.cpp

Programmer: Emiliano Viernes Orozco

Date: 2-27-21

Version: 3.0

This is a c++ program that was designed to determine the median of an arry of integers and the median 
of an integer  that indicates the number of  elements in an array, both by using pointer notation.
*/

#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

double showMedian(int[], const int);

int main() {
	const int SIZE = 10;	//array size set to 10 can be made into an if else with count and using a variable like q so it could have a user determined ammount
	int numbers[SIZE];		//integer array
	int count;				// counter to check on array number

	//getting user input with a set ammount of array size
	cout << "Please enter " << SIZE << " numbers" << endl;
	for (count = 0; count < SIZE; count++)
		cin >> *(numbers + count);
	double median = showMedian(numbers, SIZE);

	cout << "The Median is  " << median << endl;
}

double showMedian(int array[], const int SIZE)
{
	double median = 0.0;

	if (SIZE % 2 != 0)	// checks if array is even or odd as there is a different process for both
	{
		median = *(array + (SIZE / 2));

	}
	else
	{				//passed by pointers
		median = (*(array + ((SIZE - 1) / 2)) + *(array + (SIZE / 2))) / 2.0;
	}

	return median;
}