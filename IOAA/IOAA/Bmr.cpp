/*
Programmer: Emiliano Viernes Orozco

Assignment 1

Visual Studio 2019 version 16.8 

Windows 10 19042

4:49 pm 2/26/2021
*/

#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

int main() {
	double weight;
	double height;
	int		age;
	double	caloriesBurnt;
	double	bmr;				//bmr double used for calculations
	double activityFactor;
	
	cout << "In regard to the various health issues arising in the world many are stuck at home" << endl;
	cout << "This program will calculate how many calories you have burnt today" << endl;
	
	cout << "\nPlease enter your weight in pounds" << endl;
	cin >> weight;

	cout << "Please enter your height in feet" << endl;
	cin >> height;

	cout << "Please enter your age in years" << endl;
	cin >> age;

	cout << "\nPlease input a number that matches your activity level.\n 0 if no excercise \n 1.2 if little to no exercise \n 1.375 if very light exercise\n 1.55 if moderate exercise\n 1.725 if fairly active\n 1.9 if extremely active" << endl; //used \n to split up the activity factor into multiple lines
	cin >> activityFactor;

	bmr = 66 + 6.2 * weight + 154.2 * height - 6.8 * age; //bmr formula

	caloriesBurnt = bmr = bmr * activityFactor;	//calories burnt formula

	cout << "\nAccording to your responses you burn " << caloriesBurnt << " calories in a day" << endl;	//output stating how many calories were burnt

	cout << "\nThank you for using our program.\n" << endl;
	cout << "Here are some simple household activities that burn calories.\nSleeping burns 35 calories.\nRunning burns 870.\nWalking burns 176.\nTalking on the phone burns 70." << endl;	//cout health examples similar to the food calories
}