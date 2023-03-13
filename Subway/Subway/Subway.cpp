/*
Programmer: Emiliano Viernes Orozco

Test 2

Visual Studio 2019 version 16.9.4

Windows 10 19042

7:49 pm 4/30/2021
*/


#include <iostream>
#include <iomanip>
#include <string>
#include <cmath>

using namespace std;
//constants, their values won't change through out the program
const double sixInch = 1.03;
const double twelveInch = 2.11;
const double eighteenInch = 3.39;
const double twoFeet = 4.11;
const double organicWheat = .1011;
const double multigrain = .1555;
const double organicMultigrain = .2012;
const double cheeseBase = 0.0;
const double artichokesBase = 0.50;
const double jalapenosBase = 0.25;
const double extraCheeseBase = 0.30;
const double cheesePercent = 0.0;
const double artichokesPercent = .101;
const double jalapenosPercent = .155;
const double extraCheesePercent = .113;
const double salesTax = 0.101;


int main() {
	string first;
	string last;
	cout << "Please enter your first name and last name in that order\n" << endl;
	cin >> first;
	cin >> last;

	cout << "Hello " << first << " " << last << endl;	
	cout << "\nHello Welcome to subway sandwich store\n " << endl;

	cout << "\nPlease enter the code for the size you would like your sub to be:\n [S]ix inches\n [T]welve inches\n [E]ighteen inches\n2[F]eet " << endl;
	char size = ' ';
	cin >> size;
	bool flag_size(size == 'S' || size == 'T' || size == 'E' || size == 'F');

	cout << "\nPlease enter the code for the bread you would like your sub to have\n [1] for white bread\n" 
		" [2] for Organic Wheat inches\n [3] for Multigrain\n [4] for Organic Multigrain " << endl;
	int breadType = 0;
	cin >> breadType;
	bool flag_bread(breadType == 1 || breadType == 2 || breadType == 3 || breadType == 4);

	cout << "\nPlease enter the code for the filling you would like your sub to have\n [1] for Cheese\n"
		" [2] for Atichokes\n [3] for Jalapenos\n [4] for Extra Cheese \n [5] for All of the above" << endl;
	int fillingType = 0;
	cin >> fillingType;
	bool flag_filling(fillingType == 1 || fillingType == 2 || fillingType == 3 || fillingType == 4 || fillingType == 5);

	if (flag_size && flag_bread && flag_filling) {
		double baseCost = 0.0;
		double totalCost = 0.0;

		if (size == 'S') {
			baseCost = sixInch;
		}
	
		else if (size == 'T') {
			baseCost = twelveInch;
		}

		else if (size == 'E') {
			baseCost = eighteenInch;
		}

		else if (size == 'F') {
			baseCost = twoFeet;
		}

	double breadExtra = 0.0;

	if (breadType == 1) {
		breadExtra = 0.0;	//no additional cost for white bread
	}

	else if (breadType == 2) {
		breadExtra = baseCost * organicWheat;
	}

	else if (breadType == 3) {
		breadExtra = baseCost * multigrain;
	}

	else if (breadType == 4) {
		breadExtra = baseCost * organicMultigrain;
	}

	double fillingExtra = 0.0;

	if (fillingType == 1) {
		fillingExtra = 0.0;	//no additional cost for white bread
	}

	else if (fillingType == 2) {
		fillingExtra = artichokesBase+ baseCost * artichokesPercent;
	}

	else if (fillingType == 3) {
		fillingExtra = jalapenosBase + baseCost * jalapenosPercent;
	}

	else if (fillingType == 4) {
		fillingExtra = extraCheeseBase + baseCost * extraCheesePercent;
	}

	else if (fillingType == 5) {
		fillingExtra = artichokesBase + baseCost * artichokesPercent + jalapenosBase + baseCost * jalapenosPercent +
		extraCheeseBase + baseCost * extraCheesePercent;
	}

	totalCost = (baseCost + breadExtra + fillingExtra) * (1 + salesTax);

	double costPennies = totalCost * 100; //raw penny cost

	int finalCostPennies = static_cast<int>(costPennies + 0.5);

	cout << "\nTotal cost for your subway sandwich is " << finalCostPennies /100 << " dollars and " << finalCostPennies % 100 << " cents" << endl;

	}//end if 

	else {
		cout << "\nWe are unable to process your order due to the following reasons" << endl;
		if (!flag_size) {
			cout << "Wrong sub size code was entered " << endl;
		}
		if (!flag_bread) {
			cout << "Wrong sub bread code was entered " << endl;
		}
		if (!flag_filling) {
			cout << "Wrong sub filling code was entered " << endl;
		}
		return 0;
	}

}//end main