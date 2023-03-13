/*
Programmer: Emiliano Viernes Orozco

Assignment 2

Visual Studio 2019 version 16.9.0

Windows 10 19042

11:12 pm 3/2/2021
*/

#include <iostream>
#include <string>
#include <iomanip>
#include <cmath>

using namespace std;
				//decleration of variables
int main() {
	double P;	//Initial user deposit
	double r;	//Rate of interest annually
	double q;	//Number of times the compounding is done per year
	int n;	//Number of years left in deposit
	double A;	//Total accumulation of interest over time
	
	//printed message to greet user
	cout << "Greetings, CS banking welcomes you to our online banking program " << endl; // user friendly
	//data input

	cout << "\nTo start please enter your initial deposit. For example 1000.00" << endl;
	cin >> P;

	cout << "\nPlease enter your rate of interest annually for example 0.072" << endl;
	cin >> r;

	cout << "\nPlease enter the number of times compunding is done per year." << endl;
	cin >> q;

	cout << "\nPlease enter number of years the ammount was left in deposit" << endl;
	cin >> n;

	A = P * pow((1 + r / q), n * q);

	double totalPennies = static_cast<double>(A * 100);
	int roundedPennies = static_cast<int>(totalPennies + 0.5);
	int dollars = roundedPennies / 100;
	int cents = roundedPennies % 100;
	
	cout << "\nYour total accumulation due to compound interest ends up being " << dollars << " dollars and " << cents <<  " cents" << endl;
	cout << "\nThank you for banking with us and have a great day" << endl;
}