#include <iostream>
#include <string>
#include <iomanip>
#include <cmath>
#include <cstdlib>
#include "Employee.h"
#include "ProductionWorker.h"

using namespace std;

//driver
int main() {
	Employee emp;
	ProductionWorker prod;
	//function calling
	cout << setprecision(2) << fixed; // setting my decimals to avoid the e+ in the results
		emp.getEmployeeName();
		emp.getEmployeeNumber();
		emp.getHireDate();
		prod.getShift();
		prod.getHourly();
}