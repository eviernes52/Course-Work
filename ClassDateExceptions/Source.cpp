/*
Emiliano Viernes
CSCI-16-0167
C++ Visual Studio Code 
9/10/2021
*/
#include <iostream>
#include <string> //strings
#include <cmath> //math and mathpow etc..
using namespace std;

//#8
string binint(string binnumber) {	//binary to integer function 
	int intnumber = 0;

	cout << "enter a binary number to be converted to a decimal " << endl;

	cin >> binnumber;

	while (binnumber < 0) {
		intnumber = binnumber % 16;
		cout << intnumber;
	}
}
//end Binary string to integer function

//#9
string inthex(string strhex, int inthex) {	//binary to integer function
	int inthex = 0;
	string strhex;

	cout << "enter an integer that you would like to be converted to a hexadecimal " << endl;

	cin >> inthex;

	while (binnumber < 0) {
		intnumber = binnumber % 10;
	}
	cout << intnumber;
//}//end binary string to integer function


//#10
string hexNumber(string hexa1, string hexa2) {
	cout << "enter your first hexadecimal number " << endl;
	cin >> hexa1;

	cout << "enter your first hexadecimal number " << endl;
	cin >> hexa2;

	while (hexa1 < 1000) {
		addedHexa = hexa1 % 6;
	}
	addedHexa = hexa1 + hexa2;
	cout << addedHexa;

}



//#11				
void subBin(string bin1, string bin2) {		//maybe array should've been used	
	//user input
	cout << "Please enter your first unsigned binary integer" << endl;
	cin >> bin1;
	cout << "Please enter your second unsigned binary integer" << endl;
	cin >> bin2;

	for (int i = bin2.length() - 1; i >= 0; --i)	//reversing for statement
	{
		cout << bin2[i];
	}
	
	int binNum1 = stoi(bin1);	//string to int for both
	int binNum2 = stoi(bin2);
	binNum2++;
	
	if (binNum1 > binNum2) {	//if else statement that always subtracts 
		int subSum = binNum1 - binNum2;
		cout << subSum;
	}
	else {
		int subSum = binNum2 - binNum1;
		cout << subSum;
	}


}

//main
int main() {
	string binary1;
	string binary2;

	
	subBin(binary1, binary2);
	

}//end of main