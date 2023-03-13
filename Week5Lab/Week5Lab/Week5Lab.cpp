/*
Program name: Week5Lab.cpp

Programmer: Emiliano Viernes Orozco

Date: 3-23-21

Version: 3.0

This is a c++ program that was designed to use an abstract base class named student and an inherited class called underGraduate. The student class hold two virtual classes which means they return 0, while the UnderGraduate class inherits them and overides them in the main. This program takes two parameters one for
students employeed and one for students unemployed and. in undergraduate the total student ammount is counted and then at least half of the students attending are considered coming from low income.
*/

#include <iostream>
#include <string>
#include <iomanip>
#include <cmath>
#include <cstdlib>
using namespace std;

//abstract class
//two pure virtual functions
class Student {
protected:
	int lowIncome;
	int employedStudent;
	int unemployedStudent;
	int studentCount;
public:
	void setStudent(int employed, int unemployed)	//no implimitation from these two pure virtual functions
	{
		employedStudent = employed;
		unemployedStudent = unemployed;
	}

	virtual int lowIncomeStudent() { return 0; }	// prints count of low income students

	virtual int totalStudentCount() { return 0; }	//virtual function before end of class
};

class UnderGraduate : public Student {
public:
	int totalStudentCount() {						//poly
		int studentCount;
		return studentCount = employedStudent + unemployedStudent;
	}

	int lowIncomeStudent() {
		lowIncome = (employedStudent + unemployedStudent) / 2;
		return lowIncome;
	}
};

//driver
int main() {
	Student* sPtr;		 //declare pointer variable
	UnderGraduate under; //my object for undergraduate	
	sPtr = &under;		 //sPrt points to undergraduate object

	sPtr->setStudent(130, 50);
	cout << "Welcome to Redondo University" "\nThis program will take account of total students enrolled and calculate the ammount of students that are low income." << endl;
	cout << "The Total student count is " << sPtr->totalStudentCount() << "\nWith 50 percent of the students being low income that comes out to " << fixed << setprecision(3) << sPtr->lowIncomeStudent() << " low income students." << endl;

}