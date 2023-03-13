#pragma once
#ifndef ProductionWorker_H
#define ProductionWorker_H
#include <iostream> // cout
#include <string>
#include <cmath> // for the math computation
#include <cstdlib> // exit function seen in textbook
#include "Employee.h"

using namespace std;

class ProductionWorker : public Employee 
{
protected:
	int shift;
	double hourly;
public:
	//default constructor meaning we inoke parent default
	ProductionWorker() : Employee()
	{
		shift = 0;
		hourly = 0;
	}

	////constructor 2 where inheritence allows the class to access name date and number
	//ProductionWorker(int employeeShift, double hourlyRate,string EmployeeName, int EmployeeNumber, int HireDate) : Employee ( EmployeeName,  EmployeeNumber,  HireDate)
	//{
	//	shift = employeeShift;
	//	hourly = hourlyRate;
	//}

	//mutators
	void setShift(int shft) const
	{
		cout << "The employee shift, enter one for day and 2 for night " << endl;
		cin >> shft;
		if (shft >= 1 && shft <= 2)
			shft = shift;
		else {
			cout << "\nPlease enter only 1 or 2\n";
			exit(EXIT_FAILURE);		// to exit program if number is not positive 
		}
	}

	void setHourly(double hr) const
	{
		cout << "The employee number " << endl;
		cin >> hr;
		if (hr >= 0)
			hr = hourly;
		else {
			cout << "\nPlease enter only positive numbers\n";
			exit(EXIT_FAILURE);		// to exit program if number is not positive 
		}
	}

	//accessor's 
	int getShift() const
	{
		return shift;
	}

	double getHourly() const
	{
		return hourly;
	}
};
#endif