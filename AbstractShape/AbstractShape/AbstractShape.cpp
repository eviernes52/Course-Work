/*
Program name: ProductionWorker.cpp

Programmer: Emiliano Viernes Orozco

Date: 3-20-21

Version: 1.0

This is a c++ program that was designed to use an abstract base class named Shape  to pass of inheritence to a class called ProductionWOrker in order to set up the shift and hourly
pay rate for a company that analysis's the employees,name,number, and the date that they were hired
*/

#include <iostream>
#include <string>
#include <iomanip>
#include <cmath>
#include <cstdlib>
using namespace std;

//two pure virtual functions
class Shape {
private:

public:
	void printShape();

	void printShapeName();

};

class Point : public Shape {
private:

public:
	void side() {
		

	}
};

class Circle : public Point {


};

class Cylinder : public Circle {



};

//driver
int main() {




}