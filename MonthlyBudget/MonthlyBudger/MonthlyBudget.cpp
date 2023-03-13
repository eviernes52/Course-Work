/*
Program name: MonthlyBudget.cpp

Programmer: Emiliano Viernes Orozco

Date: 2-20-21

Version: 2.0

This is a c++ program that was designed to create a monthly budget for a student and
catagorize the budget efficently. Than the budget should notify the student whether they're  overbudget or under budget for every catagory.
As well as stating wheter they're over or under the total budget.
*/

#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

// In this struct i put all the data types and variables 
struct Budget
{ // everything in here is a double since it's a budget and will be stated with relations to currancy
	double housing;
	double utilities;
	double householdExpenses;
	double transportation;
	double food;
	double medical;
	double insurance;
	double entertainment;
	double clothing;
	double misc;
};

// this is the function prototype 
//void get item uses a refernce parameter
void getData(Budget &p) {	// asks the user for information to store in the structure.
	//get housing cost 
	cout << "Enter your housing cost";
	cin >> p.housing;
	//get utilities cost 
	cout << "Enter your utilities cost";
	cin >> p.utilities;
	//get householdExpenses cost 
	cout << "Enter your House hold expenses cost";
	cin >> p.householdExpenses;
	//get transportation cost 
	cout << "Enter your transportation cost";
	cin >> p.transportation;
	//get food cost 
	cout << "Enter your food cost";
	cin >> p.food;
	//get medical cost 
	cout << "Enter your medical cost";
	cin >> p.medical;
	//get insurance cost 
	cout << "Enter your insurance cost";
	cin >> p.insurance;
	//get entertainment cost 
	cout << "Enter your entertainment cost";
	cin >> p.entertainment;
	//get clothing cost 
	cout << "Enter your clothing cost";
	cin >> p.clothing;
	//get misc cost 
	cout << "Enter your misc cost";
	cin >> p.misc;
}

int main() {
	//local variable declaration

	cout << (4 + 3 * 5) << endl;

	cout << ((4 + 3) * 5) << endl;

	cout << (4 * 5 % 3 + 2) << endl;

	cout << (4 * (5 / 3) + 2) << endl;

	cout << (1 / 2) << "\n";

	cout << (1 % 2) << "\n";


}


/*
int main() {

	//local variable declaration
	movie titanic = { "Titanic" , "Steven", 1999, 113 }; // my first movie variable
	movie ripley = { "TheTalantedMrRipley" , "Arthur", 1995, 120 };

	//my first film
	cout << "Title: " << titanic.title << endl;
	cout << "Director: " << titanic.director << endl;
	cout << "Year Released: " << titanic.yearReleased << endl;
	cout << "Running Time: " << titanic.runningTime << "\n" << endl; // \n seperating the two films

}*/ 
