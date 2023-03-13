#pragma once
#ifndef Employee_H
#define Employee_H
#include <iostream> // cout
#include <string>
#include <cmath> // for the math computation
#include <cstdlib> // exit function seen in textbook

using namespace std;
//the base class
class Employee
{
protected:
	string name;	//employee name
	int number;		// employee number
	int	date;		// employee date
public:
	// default constructor
	Employee() {
		name = "";
		number = 0;
		date = 0;
	}

	// constructor
	Employee(string EmployeeName, int EmployeeNumber, int HireDate) {
		name = EmployeeName;
		number = EmployeeNumber;
		date = HireDate;
	}

	//mutator function
	void setName(string EmployeeName)
	{
		cout << "The employee name " << endl;
		cin >> EmployeeName;
		if (EmployeeName >= "")
			name = EmployeeName;
		else {
			cout << "\nFailed to enter an employee name\n";
			exit(EXIT_FAILURE);		// to exit program if number is not positive 
		}

	}
	
	void setNumber(int EmployeeNumber)
	{
		cout << "The employee number " << endl;
		cin >> EmployeeNumber;
		if (EmployeeNumber >= 0)
			number = EmployeeNumber;
		else 
		{
			cout << "\nPlease enter a positive employee number\n";
			exit(EXIT_FAILURE);		// to exit program if number is not positive 
		}

	}

	void setDate(int HireDate)
	{
		cout << "The employee hire date " << endl;
		cin >> HireDate;
		if (HireDate >= 0)
			date = HireDate;
		else 
		{
			cout << "\nEmployee hire date must be positive\n";
			exit(EXIT_FAILURE);		// to exit program if number is not positive 
		}

	}

	//Accessors / getter functions
	string getEmployeeName() const {
		return name;
	}

	int getEmployeeNumber() const {
		return number;
	}

	int getHireDate() {	
		return date;
	}
};
#endif