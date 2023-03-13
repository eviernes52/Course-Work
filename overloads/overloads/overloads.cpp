/*

 Programmer: Emiliano Viernes Orozco
Program name: ProductionWorker.cpp


Date: 3-28-21

Version: 1.2

This is a c++ program that was designed to overloads fractions arithmetic operations for division. And it includes the overloading operators like multiplication, comparison, insertion, and extraction operators.
*/


#include <iostream>
using namespace std;
class Fraction
{
private:
	string name;
	int num1;	 //number 1
	double num2; //number 2
public:
	Fraction()
	{
		num1 = 0.0, num2 = 1.0;	// can't both = 0
		name;
	}
	Fraction(int n1, double n2, string nm)
	{
		name = nm,num1 = n1, num2 = n2;
	}

	void setFraction() {
		double n1, n2;
		cout << "Enter the numerator like this X" << endl;
		cin >> n1;
		cout << "\nNow enter the denomerator like this X.X " << endl;
		cin >> n2;

		num1 = n1;
		num2 = n2;
		name = nm;
	}

	void setFractionInput()
	{
		string nm;
		cout << "Enter a name:" << endl;
		cin >> nm;
	
	}

		int getNum1()	//numerator
		{
			return num1;
		}

		double getNum2()	//denomerator
		{
			return num2;
		}

		string getName() {
			return name;
		}

	//func prototype
	friend Fraction operator *(Fraction n1, Fraction n2);

	//we overload the insertion operator "<<"
	friend ostream & operator << (ostream & o, const Fraction & f);

	//we overload the instream operator ">>" 
	friend istream& operator >> (istream& i, const Fraction& f);

};//end Fraction

	Fraction operator * (Fraction f1, Fraction f2) 
	{
		Fraction temp;
		temp.num1 = f1.num1 * f2.num1;
		temp.num2 = f1.num2 * f2.num2;
		return temp;
	}

	ostream& operator << (ostream& o, Fraction& f)
	{
		o << f.getNum1() << "/" << f.getNum2();
		return o; 
	}

	istream& operator >> (istream& i, Fraction& f) 
	{
		i >> f.getName;
		return i;
	}

//Driver
int main()
{
	Fraction frac1;
	Fraction frac2;
	Fraction Nme;
	Fraction solution;

	cout << "Please enter fraction 1" << endl;
	frac1.setFraction();
	cout << "Please enter fraction 2" << endl;
	frac2.setFraction();


	solution = frac1 * frac2;

	cout << " The solution is " << solution << endl;
}			

