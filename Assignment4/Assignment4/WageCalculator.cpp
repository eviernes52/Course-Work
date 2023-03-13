/*
Programmer: Emiliano Viernes Orozco

Test1

Visual Studio 2019 version 16.9.1

Windows 10 19042

11:57 pm 4/1/2021
*/

#include <iostream>
#include <iomanip> 
#include <string>
#include <cmath>

using namespace std;

int main()
{
	cout << fixed << showpoint << setprecision(5);
	string FirstName, LastName;
	char EmployeeCode;	// Employee Code
	double BasePay;
	string EmployeeDescription;
	char JobClass;
	char ServiceYrs;
	char eduCode;
	

	cout << "Welcome to Badwater Brewery's Employee Payment Calculator." << endl;

	cout << "\nPlease enter Employees First Name." << endl;
	cin >> FirstName;

	cout << "\nPlease enter Employees Last Name." << endl;
	cin >> LastName;

	cout << "\nPlease enter the Employee Code. S for Factory Worker, O for Office Worker, amd M for Management. " << endl;
	cin >> EmployeeCode;
		EmployeeCode = toupper(EmployeeCode);
		bool flagEmployeeCode = (EmployeeCode == 'S') || (EmployeeCode == 'O') || (EmployeeCode == 'M');

	cout << "\nPlease enter the Job Classification Level. Either 1 , 2 or , 3 " << endl;
	cin >> JobClass;
		JobClass = toupper(JobClass);
		bool flagJobClass = (JobClass == '1') || (JobClass == '2') || (JobClass == '3');


	cout << "\nPlease enter the Years of service with the company, with 50 being the limit." << endl;
		cin >> ServiceYrs;
		ServiceYrs = toupper(ServiceYrs);
		bool flagServiceYrs = (ServiceYrs <= 1 && ServiceYrs >= 50);


	cout << "\nPlease enter the level of Employee Education. With HS being HighSchool, JC Junior College, U Undergraduate, and GS Graduate School " << endl;
		cin >> eduCode;
		eduCode = toupper(eduCode);
		bool flagEduCode = (eduCode == 'HS') || (eduCode == 'JC') || (eduCode == 'U') || (eduCode == 'GS');


		if (flagEmployeeCode && flagServiceYrs && flagJobClass && flagEduCode)
		{
			double BasePay = 0.0; // set pay as 0 in order to let the functions modify the employee wage
			if (EmployeeCode == 'S') {
				BasePay = 800.95;
				EmployeeDescription = "Factor Worker";
			}

			else if (EmployeeCode == 'O') {
				BasePay = 1000.86;
				EmployeeDescription = "Office Worker";
			}

			else if (EmployeeCode == 'M') {
				BasePay = 1499.89;
				EmployeeDescription = "Management";
			}

			if (flagServiceYrs == '1') {

			}

			double incrJobClass = 0.0;
				if (JobClass == 1) {
					incrJobClass = BasePay * 0.05;
				}

				if (JobClass == 2) {
					incrJobClass = BasePay * 0.1;
				}

				if (JobClass == 3) {
					incrJobClass = BasePay * 0.2;
				}




			double incrServiceYrs = 0.0;
				if (ServiceYrs >= 1 && ServiceYrs <= 10) {
					incrServiceYrs = 0.05 * BasePay;
				}

				if (ServiceYrs > 10 && ServiceYrs <= 50) {
					incrServiceYrs = BasePay * 0.05 + ServiceYrs -10.00 * 0.01 * BasePay;
				}


			double increduCode = 0.0;
				if (eduCode == 'HS') {
					increduCode =  BasePay;
				}

				if (eduCode == 'JC') {
					increduCode = 0.05 * BasePay;
				}

				if (eduCode == 'U') {
					increduCode = 0.12 * BasePay;
				}

				if (eduCode == 'GS') {
					increduCode = 0.2 * BasePay;
				}

				double TotalPay = BasePay + increduCode + incrJobClass + incrServiceYrs;

				cout << "\nThank you " << FirstName << " " << LastName << " your job type is " << EmployeeDescription << " your total employee wage is $" << TotalPay << endl;

				cout << "\nThank you for using Badwater Brewery’s payment calculator, have a great day" << endl;	//End Program with user dismisal similar to greeting


		}	//end flag check

		else {
			cout << "\nThere seems to be a problem with one or more of the information codes you entered. Please try again." << endl;

			if (!flagEmployeeCode) 
			{
				cout << "\nThere was an error with the Employee code.";
			}
			if (!flagServiceYrs)
			{
				cout << "\nThere was an error with the Service code.";
			}
			if (!flagJobClass)
			{
				cout << "\nThere was an error with the Job Class code.";
			}
			if (!flagEduCode)
			{
				cout << "\nThere was an error with the Education code.";
			}
		}

}	//end main
