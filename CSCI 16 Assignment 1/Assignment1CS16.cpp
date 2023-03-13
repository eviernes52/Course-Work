#include <iostream>
#include <string> //strings
#include <cmath> //math and mathpow etc..
using namespace std;

string BinInt(string BinNumber, int IntNumber) {	//binary to integer function
	int Intnumber = 0;
	string BinNumber;

	cout << "Enter a binary number to be converted to a decimal " << endl;

	cin >> BinNumber;

	while (BinNumber < 0) {
		Intnumber = BinNumber % 10;
	}
}//end Binary string to integer function


string IntHex(string strHex, int intHex) {	//binary to integer function
	int intHex = 0;
	string strHex;

	cout << "Enter an integer that you would like to be converted to a hexadecimal " << endl;

	cin >> intHex;

	while (BinNumber < 0) {
		Intnumber = BinNumber % 10;
	}
	cout << ""
}//end Binary string to integer function

string HexAdd(string hexa1, string hexa2) {
	string hexa1;
	string hexa2;

	cout << "Enter your first Hexadecimal number " << endl;
	cin >> hexa1;

	cout << "Enter your first Hexadecimal number " << endl;
	cin >> hexa2;
}


int main() {
	BinInt(BinNumber, IntNumber);

	HexAdd(BinNumber, IntNumber);


}//end of main