/*
Programmer: Emiliano Viernes Orozco

Test1

Visual Studio 2019 version 16.9.1

Windows 10 19042

11:39 pm 3/23/2021
*/

#include <iostream>
#include <string> 
#include <iomanip> // set precision
#include <cmath>	//math related computations

using namespace std;
//decleration of variables
int main() {
	int A, B, C;	//first three integers
	int D;			 // this is the discriminant

	//printed message to greet user
	cout << "Welcome to El Camino’s computer science department’s Quadratic Solver " << endl; // user friendly

	cout << "\nPlease enter the 3 integers in this exact format with spacing in between each number" << endl;
	//data input
	cin >> A;
	cin >> B;
	cin >> C;

	if (A == 0 && B != 0 ) 
	{
		cout << "This appears to be a linear equation instead of a quadratic but we will still proceed." << endl;
		
		double xPos = ((-1.0*C)/B);

		cout << fixed << showpoint << setprecision(4) << scientific << "The one real soultion is " << xPos << endl;
		
	}
	else if (A == 0 && B == 0) {
		cout << "\nThis appears to not be an algebraic equation, the program will now terminate please try again." << endl;
	}
	else {
		D = (B * B)- 4 * A * C;
		if (D > 0)
		{
			double xPos = (-B + sqrt(B * B - 4 * A * C)) / (2.0 *A);

			double xNeg = (-B - sqrt(B * B - 4 * A * C)) / (2.0 *A);

			cout << fixed << showpoint << setprecision(4) << scientific << "The two real solutions are " << xPos << " and " << xNeg << endl;
		}
		else if (D == 0)
		{
			double xPos = (-B + sqrt(B * B - 4 * A * C)) / (2.0 *A);
				
				cout << fixed << showpoint << setprecision(4) << scientific << "The real solution is " << xPos << endl;
		}	
		
		else if (D < 0) 
		{
			double xPos = (-B + sqrt(B * B - 4 * A * C)) / (2.0 * A);

			double xNeg = (-B - sqrt(B * B - 4 * A * C)) / (2.0 * A);

			cout << fixed << showpoint << setprecision(4) << scientific << "The two imaginary solutions are " << xPos << "*I"<< "\n and " << xNeg << "*I" << endl;

		}
	
	}

	cout << "\nThank you for using El Caminos Quadratic Calculator have a great day." << endl;
} 