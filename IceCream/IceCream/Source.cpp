#include <iostream>
#include <iomanip>
#include <string>
#include <cmath>

using namespace std;
//sizes milks and toppings
const double kiddieCone;
const double small;
const double medium;
const double large;
const double extraLarge;
const double regularMilk;
const double organicCow;
const double organicGoat;
const double lychees;
const double gummyBears;
const double strawberry;
const double kiwiFruit;
const double mango;

int main() {
	cout << "Hello Welcome to ELCO's Cream Shop " << endl;
	string first;
	string last;
	cout << "Please enter your first name" << endl;
	cin >> first;
	cout << "Please enter your last name" << endl;
	cin >> last;
	int age;
	cout << "Please enter your age to recieve potential discounts" << endl;
		cin >> age;
		bool age_flag = false;

		if (age > 55) {
			cout << "Congrats you qualify for a senior discount" << endl;
			age_flag = true;
		}
		cout << "Please enter the serving size you would like your ice cream to be\n S for small blah blah blah" << endl;
			char size = ' ';




}