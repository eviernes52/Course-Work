#pragma once
#ifndef mathStack_H
#define mathStack_H
#include <iostream> // cout
#include <string> 
#include <cstdlib> // exit function
#include "IntStack.h"

using namespace std;

class mathStack : public IntStack 
{
public:
	//default constructor
	mathStack(int s) : IntStack(s) {}

	//stack operators
	void mult();
	void div();
	void addALL();
	void multALL();
};//end of class
#endif

