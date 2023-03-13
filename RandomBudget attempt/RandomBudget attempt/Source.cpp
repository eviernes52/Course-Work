/*
Program name: MonthlyBudget.cpp

Programmer: Emiliano Viernes Orozco

Date: 2-20-21

Version: 2.1

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
//Function prototype / call
void getInfo(Budget &);
void showInfo(Budget &);
void displayBudgetDifferences(Budget&);

int main() {
	Budget	Month; //mth = monthly budget 1 mth2= = monthly budget 2 etc...
	
	getInfo(Month);	// function get the user info 
	showInfo(Month);	// function get the users total monthly budget and determines if over or under budget
	displayBudgetDifferences(Month);

}
		

	void getInfo(Budget &mth)	//mth = month 1. mth 2 = month 2
	{
	//get housing cost 
		cout << "Enter your housing cost ";
		cin >> mth.housing;
		//get utilities cost 
		cout << "Enter your utilities cost ";
		cin >> mth.utilities;
		//get householdExpenses cost 
		cout << "Enter your House hold expenses cost ";
		cin >> mth.householdExpenses;
		//get transportation cost 
		cout << "Enter your transportation cost ";
		cin >> mth.transportation;
		//get food cost 
		cout << "Enter your food cost ";
		cin >> mth.food;
		//get medical cost 
		cout << "Enter your medical cost ";
		cin >> mth.medical;
		//get insurance cost 
		cout << "Enter your insurance cost ";
		cin >> mth.insurance;
		//get entertainment cost 
		cout << "Enter your entertainment cost ";
		cin >> mth.entertainment;
		//get clothing cost 
		cout << "Enter your clothing cost ";
		cin >> mth.clothing;
		//get misc cost 
		cout << "Enter your misc cost ";
		cin >> mth.misc;
	}
	
	void showInfo(Budget &mth)
	{
		const double monthlyBudget = 1420;	//the monthly budget we were given since its a set budget that doesn't change no needs to change this

		double monthlyTotal = mth.housing + mth.utilities + mth.householdExpenses + mth.transportation + mth.food + mth.medical + mth.insurance
			+ mth.entertainment + mth.clothing + mth.misc;


		//Display the budget data
		cout << "\nYour total Budget was $" << monthlyBudget << endl;
		//if else statements for total over and underbudget
		if (monthlyTotal > monthlyBudget) {
			cout << "\nYou spent $" << monthlyTotal << "\nYou are over your total Budget of $" << monthlyBudget << " by $" << monthlyTotal - monthlyBudget << endl;
		}

		else if (monthlyBudget > monthlyTotal) {
			cout << "\nYou spent $" << monthlyTotal << "\nYou are under your total Budget of $" << monthlyBudget << " by $" << monthlyBudget - monthlyTotal << endl;
		}

		else {
			cout << "\nYou spent $" << monthlyTotal << "\nYou spent exactly all your total Budget of $" << monthlyBudget << endl;
		}
	}

	void displayBudgetDifferences(Budget& mth)	// function for over and under budget
	{	//if else statements for catagory over and underbudget, program didn't specify whether to list the ammount or not so it was easier to just od alot of if else 
		if (mth.housing > 500) {
			cout << "\nYou are over budget in Housing" << endl;
		}
		else cout << "\nYou are under budget in Housing" << endl;
		if (mth.utilities > 150) {
			cout << "\nYou are over budget in Utilities" << endl;
		}
		else cout << "\nYou are under budget in Utilities" << endl;
		if (mth.householdExpenses > 65) {
			cout << "\nYou are over budget in Household Expenses " << endl;
		}
		else cout << "\nYou are under budget in Household Expenses " << endl;
		if (mth.transportation > 50) {
			cout << "\nYou are over budget in Transportation" << endl;
		}
		else cout << "\nYou are under budget in Transportation" << endl;
		if (mth.food > 250) {
			cout << "\nYou are over budget in Food" << endl;
		}
		else cout << "\nYou are under budget in Food" << endl;
		if (mth.medical > 30) {
			cout << "\nYou are over budget in Medical" << endl;
		}
		else cout << "\nYou are under budget in Medical" << endl;
		if (mth.insurance > 100) {
			cout << "\nYou are over budget in Insurance" << endl;
		}
		else cout << "\nYou are under budget in Insurance" << endl;
		if (mth.entertainment > 150) {
			cout << "\nYou are over budget in Entertainment" << endl;
		}
		else cout << "\nYou are under budget in Entertainment" << endl;
		if (mth.clothing > 75) {
			cout << "\nYou are over budget in Clothing" << endl;
		}
		else cout << "\nYou are under budget in Clothing" << endl;
		if (mth.entertainment > 50) {
			cout << "\nYou are over budget in MISC" << endl;
		}
		else cout << "\nYou are under budget in Misc" << endl;
	}