//specification file for the Mortgage class
//file has a constructor
#pragma once 
#ifndef Mortgage_H
#define Mortgage_H
#include <iostream> // cout
#include <string>
#include <cmath> // for the math computation
#include <cstdlib> // exit function seen in textbook

using namespace std;

class Mortgage {
private:
    double principal, rate;
    int term;
public:
    //constructor
    Mortgage() {
        principal = 0.0;
        rate = 0.0;
        term = 0;
    }

    //setter functions
    void setTotalLoan() {
        double prin;
        cout << "Please enter the original total loan ammount. For example xxxxx " << endl;
        cin >> prin;

        if (prin >= 0)
            principal = prin;
        else {
            cout << "\nPlease enter only positive numbers\n";
            exit(EXIT_FAILURE);		// to exit program if number is not positive 
        }
    }

    void setRate() {
        double rte;
        cout << "\nPlease enter the rate. For example x " << endl;
        cin >> rte;

        if (rte >= 0)
            rate = rte;
        else {
            cout << "Please enter only positive numbers\n";
            exit(EXIT_FAILURE);		// to exit program if number is not positive 
        }
    }

    void setTerm() {
        int trm;
        cout << "\nPlease enter the ammount of years. For example xx " << endl;
        cin >> trm;

        if (trm >= 0)
            term = trm;
        else {
            cout << "Please enter only positive numbers\n";
            exit(EXIT_FAILURE);		// to exit program if number is not positive 
        }
    }


    //getter functions
    double getTerm() const {
        return term * 12.0;
    }
    double getPrincipal() const {
        return principal;
    }

    double getRate() const {
        return rate / 1200.0;
    }

    double getMonthlyPayment() const {
        double monthlyPaid;
        monthlyPaid = principal * rate / (1.0 - pow(rate + 1, -term));
        return monthlyPaid;
    }

    double getAmmountPaid() const {
        double paid;
        paid = (12.0 * term) * getMonthlyPayment();
        return paid;
    }

    //display function to return monthly and total paid
    void display() {
        cout  <<  "The Monthly Payment with interest compounded is $" << getMonthlyPayment() << endl;

        cout  << "The total ammount paid on the loan is $" << getAmmountPaid() << endl;
    }
};

#endif
