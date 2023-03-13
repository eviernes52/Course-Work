/*
Programmer: Emiliano Viernes Orozco

Assignment 5

Visual Studio 2019 version 16.9.4

Windows 10 19042

12:31 am 4/27/2021
*/
#include <iostream>
#include <string>
#include <fstream>
#include <cmath>
#include <iomanip> //set w
using namespace std;

int main() {
	//User Greeting 
	cout << "Welcome to El Camino College's Department Of Enviornmental Control's carbon footprint Calculator" << endl;
	cout << "We will  calculate the average carbon foot print levels of US cities" << endl;
	//User input file name
	cout << "Please enter the full file path for the input file:" << endl;
	string inputFileName;
	getline(cin, inputFileName);

	ifstream in(inputFileName);

	if (!in.is_open())
	{
		cout << "Failed to open file. Program will now exit. \nThank you for using EL Camino College's Software Engineering Lab. " << endl;
	}

	else
	{
		string outfileName;
		cout << "Enter full path to output file. " << endl;
		getline(cin, outfileName);
		ofstream out(outfileName, ios::app);

		if (!out.is_open())
		{
			cout << "Failed to open output file. " << endl;
		}
		else
		{
			out << "Welcome to El Camino College's Department Of Enviornmental Control's carbon footprint Calculator" << endl;
			out << "We will  calculate the average carbon foot print levels of US cities" << endl;
			cout << "******************************************************************************" << endl;
			out << "******************************************************************************" << endl;

			cout << setw(10) << left << "City";
			out << setw(10) << left << "City";
			cout << setw(15) << "Rounded Average Carbon FP";
			out << setw(15) << "Rounded Average Carbon FP";
			cout << setw(20) << right << "Fine ($) " << endl;
			out << setw(20) << right << "Fine ($) " << endl;

			cout << "******************************************************************************" << endl;
			out << "******************************************************************************" << endl;

			cout << fixed << showpoint << setprecision(2);
			out << fixed << showpoint << setprecision(2);

			int totalCities{0}; //total number of cities it the data
			double totalFine{ 0.0 }; // Total Fines collected for all cities
			double averageTests{ 0.0 };
			int roundedAverage{ 0 };
			double fine{0.0};
			int cityFineA{ 0 }; //fines of cities with carbon foot prints of 1 or under
			int cityFineB{ 0 }; //fines of cities with carbon foot prints of greater than 1 and under 3
			int cityFineC{ 0 };//fines of cities with carbon foot prints of greater than 3 and under 5
			int cityFineD{ 0 };//fines of cities with carbon foot prints of greater than 5 and under 7
			int cityFineF{ 0 };//fines of cities with carbon foot prints of greater than 7
			

			while (in.peek() != EOF) {
				totalCities++;
				string cityName;
				in >> cityName;
				int singleValue{ 0 };//sentinel 
				int numTests{ 0 };//carbon foot print
				int sum{ 0 };
				in >> singleValue; // reads for sentinel loop

				totalFine = (cityFineA * (0.0)) + (cityFineB * (1000000.00)) + (cityFineC * (2000000.00)) + (cityFineD * (3000000.00)) + (cityFineF * (4500000.00));


					while (singleValue >= 0) {
						sum += singleValue;
						numTests++;
						in >> singleValue;
					}//This ends the sentinel loop

				cout << endl;
				out << endl;
				if (numTests > 0) {
					averageTests = static_cast<double> (sum) / numTests;
					roundedAverage = static_cast<int> (averageTests + 0.5);
					
					if (roundedAverage <= 1)
					{
						
						 fine = 0.00;
						cityFineA++;
					}
					else if (roundedAverage > 1 && roundedAverage <= 3)
					{
						
						 fine = 1000000.00;
						cityFineB++;
					}
					else if (roundedAverage > 3 && roundedAverage <= 5)
					{
					
						 fine = 2000000.00;
						cityFineC++;
					}
					else if (roundedAverage > 5 && roundedAverage <= 7)
					{
					
						 fine = 3000000.00;
						cityFineD++;
					}
					else if (roundedAverage > 7)
					{
						
						 fine = 4500000.00;
						cityFineF++;
					}
					cout << setw(20) << left << cityName;
					out << setw(20) << left << cityName;
					cout << setw(25) << roundedAverage << setw(15) << fine << endl;
					out << setw(25) << roundedAverage << setw(15) << fine << endl;
					
				}
				else
				{
					cout << setw(20) << left << cityName;
					out << setw(20) << left << cityName;
					cout << setw(15) << "No value available for carbon FP. Fine not calculated. " << endl;
					out << setw(15) << "No value available for carbon FP. Fine not calculated. " << endl;
				}
			}// ends outer while loop
			cout << "******************************************************************************" << endl;
			out << "******************************************************************************" << endl;
		
			cout << setw(10) << "Total number of cities in the file: " << totalCities << endl;
			out << setw(10) << "Total number of cities in the file: " << totalCities << endl;
			cout << setw(15) << "Total fine collected: $" << totalFine << endl;
			out << setw(15) << "Total fine collected: $" << totalFine << endl;
			cout << "Thank you for using EL Camino College's Software Engineering Lab." << endl;
			out << "Thank you for using EL Camino College's Software Engineering Lab." << endl;
		}
		out.close();
	}
	in.close();
}//end main