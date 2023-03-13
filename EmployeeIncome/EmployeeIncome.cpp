/*
Programmer: Emiliano Viernes Orozco

EmployeeIncome.cpp

Visual Studio 2019 version 16.9.4

Windows 10 19042

11:51 pm 5/11/2021
*/
#include <iostream> 
#include <iomanip>
#include <string>
#include <cmath> //just in case for further calculations regarding salary
using namespace std;

//function prototypes
void greeting();
double getUserData(double& /*outgoing*/payRate, string& /*outgoing*/ firstName, string& /*outgoing*/lastName, bool& /*outgoing*/ healthPlan);
double getGrossSalary(double hoursWorked, double payRate);
double getTaxWitheld(double GrossSalary);
double getNetSalary(double grossSalary, double taxWitheld, bool HealthPlan, string& HealthPlanStatusMessage);
void printResults(const string& firstName, const string& lastName, double hoursWorked, double payRate, double grossSalary, double taxWitheld, double netSalary, const string& HealthPlanStatus);
void goodbye();


void greeting() //greets user
{
	cout << "Greetings and welcome to El Camino College's Salary Calculator" << endl;
	cout << "\nThis Program is dedicated to calculating the finaces behind an employee's salary including tax and\nhealth care deductions.\n"<< endl;
}

//get user first and last, hours worked and their enrollment option
double getUserData(double& /*outgoing*/payRate, string& /*outgoing*/ firstName, string& /*outgoing*/lastName, bool& /*outgoing*/ healthPlan) 
{
	double hoursWorked; // gets returned as said by ioaa so first we declare as double since can be 44.5 hours etc...
	cout << "To participate please enter your first name: ";
	cin >> firstName;
	cout << "Now please enter your last name: ";
	cin >> lastName;
	cout << "Please enter hours worked (positive numbers only):" << endl;
	cin >> hoursWorked;
	cout << "Please enter the pay rate(postive numbers only) if pay rate is 12 dollars 30 cents please enter like this 12.30:" << endl;
	cin >> payRate;
	cout << "Please enter whether you'd like to enroll in a health plan, press 1 if not press 0 [zero]" << endl;
	cin >> healthPlan;
	return hoursWorked;	//must be returned since instructions stated to declare locally
	cout << "--------------------------------------------------------------------------------------------------------------------------------------"<< endl;
	//return healthPlan;	//can only return by return everything else is returned by reference see as they have ampersands
}

//get hours worked and multiply by payrate to find the initial wages earned 
double getGrossSalary(double hoursWorked, double payRate) //calculates initial wage earned
{
	double grossSalary;
	if (hoursWorked <= 40) {
		grossSalary = hoursWorked * payRate;		//single return at end
		return grossSalary;
	}

	else {									//learned to not finish with if else statements and instead just put else{}
		grossSalary = ((hoursWorked - 40) * ( 1.5 * payRate)) + (40 * payRate); // 1.5 multiplied for overtime bonus
		return grossSalary;
	}
}

double getTaxWitheld(double GrossSalary) // calculates the ammount taxes 
{
	double TaxWitheld;
	TaxWitheld = GrossSalary * 0.071; //0.0071 multiplied by gross salary is 7.1 percent
	return TaxWitheld;
}

double getNetSalary(double grossSalary, double taxWitheld, bool HealthPlan, string& HealthPlanStatusMessage)
{	
	double netSalary;
		//taxWitheld = grossSalary * 0.071;	//without declaring a new double one can do taxWitheld = grossSalary * 0.071; but not sure if this option was better or allowed
		netSalary = grossSalary - taxWitheld;
		//corrected error only one return allowed 
		if (HealthPlan == 1) {
			if (netSalary >= 200) { // checks if the cost of health care makes employee eligeble
				netSalary -= 200; //take away the 200 for the health care
				HealthPlanStatusMessage = "Congrats employee qualifies for medical coverage and has succesfully enrolled in our plan";
			}
			else {
				HealthPlanStatusMessage = "Unfortunatly you do not qualify for health plan benifts based on your net salary";
				HealthPlan = false; HealthPlanStatusMessage;
			}
		}
			else
		{
		HealthPlanStatusMessage = "Employee didn't choose to enroll in a health plan";
				HealthPlan = 0; HealthPlanStatusMessage;
		}
	//then netsalary is returned
	return netSalary;
}

//only first and last are passed by reference, everything else is strictly passed by value
void printResults(const string& firstName, const string& lastName, double hoursWorked, double payRate, double grossSalary, double taxWitheld, double netSalary, const string& HealthPlanStatus) 
{
	cout << setprecision(2) <<fixed; // my set precision function for getting decimal places to match dollar values
	cout << "\nHere are the Employee payroll details." << endl;	//greeting for output
	cout << "Name: " << firstName << " " << lastName << endl;			//first last combined reference
	cout << "Hours Worked: " << hoursWorked << endl;	
	cout << "Hourly Pay Rate: $" << payRate << endl;
	cout << "Gross Salary: $" << grossSalary << endl;
	cout << "Tax witheld: $" << taxWitheld << endl;
	cout <<  HealthPlanStatus << endl;	//health plan status also reference no need for cout as it already has a string message attached
	cout << "Employee net salary: $" << netSalary << endl;
}

void goodbye() //cout was allowed as function said only no user input was allowed to be taken. No return needed.
{
	cout << "-----------------------------------------------------------------" << endl;
	cout << "Thank you for using El Camino's Salary Calculator.\n" << endl;
	cout << "Always welcome to come back but for now have a great day." << endl;
}

//lastly int main as seen in ioaa put last *normally should be on top and functions in a header* 

int main() //main function
{
	//decleration of variables used not universal will need to be passed as parameters 
	double payRate, hoursWorked, grossSalary, taxWitheld, netSalary; // doubles used for calculations 
	string firstName, lastName, HealthPlanStatusMessage; //local variables to store string values
	bool healthPlan; //boolean to store the weather to reduce health plan amount

	greeting();

	hoursWorked = getUserData(payRate, firstName, lastName, healthPlan);

	grossSalary = getGrossSalary(hoursWorked, payRate);

	taxWitheld = getTaxWitheld(grossSalary);

	netSalary = getNetSalary(grossSalary, taxWitheld, healthPlan, HealthPlanStatusMessage);

	printResults(firstName, lastName, hoursWorked, payRate, grossSalary, taxWitheld, netSalary, HealthPlanStatusMessage);

	goodbye();
}//end main