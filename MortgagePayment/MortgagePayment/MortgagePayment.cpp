/*
Program name: MortgagePayment.cpp

Programmer: Emiliano Viernes Orozco

Date: 3-7-21

Version: 4.3

This is a c++ program that was designed to create a calculator for a monthly payment on a home mortgage. By using a header file
to seperate the class from the main function this is achived. Everything is then called in in main.
*/
#include "Mortgage.h" // Needed for the Mortgage Class
#include <iostream> // cout
#include <string>
#include <iomanip>
#include <cmath> // for the math computation
#include <cstdlib> // exit function seen in textbook

using namespace std;

//Driver for Monthly class
int main() {
	Mortgage monthly;	//Define an instance of the Monthly class
	//calling my functions from object monthly in the morgage class
	cout << setprecision(2) << fixed; // setting my decimals to avoid the e+ in the results
	monthly.setTotalLoan();	//sets the principle
	monthly.setRate();		//sets the rate
	monthly.setTerm();		//sets the term
	//display the monthly mortgage and time on loan left
	monthly.display();
}