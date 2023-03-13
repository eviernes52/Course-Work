/*
Program name: doSomething.cpp

Programmer: Emiliano Viernes Orozco

Date: 2-24-21

Version: 3.0

This is a c++ program that was designed to demonstate a function that uses pointers as parameters instead of reference.
*/

#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

int doSomething(int*, int*);

int main()
{
    int w,
        * x = &w,
        * y = &w;

    cout << "Enter any digit" << endl;  //user inputs any digit
    cin >> w;                           //store digit


    w = doSomething(x, y);               //function call

    cout << "Your new digit " << w << " was multiplied by 10 and then added to itself" << endl;   //outputs new digit
}

int doSomething(int* x, int* y) {    //mostly just formating substitution amd usning * to changing values
    int temp = *x;

    *x = *y * 10;   // changing value of x to = y * 10

    *y = temp * 10;

    return *x + *y; // adds the newly changed x and y variables
}