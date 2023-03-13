/*
Programmer: Emiliano Viernes Orozco

Assignment 9

Visual Studio 2019 version 16.9.6

Windows 10 19042

11:17 pm 6/7/2021
*/
#include <iostream>
#include <string>
#include <iomanip>
using namespace std;
// Global Constant
const double CREDIT_LIMIT = 1500.00;
// Struct
struct CreditCard
{
    string FirstName;
    string LastName;
    string CCN;
    double balance;
};
//Function prototypes
//See description of all functions before blank body of each function after the //body of main function.
void ChargeToCard(CreditCard& CC, double money);
void print(const CreditCard& CC);
void bubbleSort(CreditCard ccArr[], int flag, int len);
int LinearSearch(const CreditCard ccArr[], const CreditCard& CC, int flag, int len);
void print(const CreditCard arr[], int len);
void makePaymentToCard(CreditCard& CC, double money);
//Array Capacity
const int MAX = 100;

//Codes To Be Completed

//1. Item 1: Main Function: Read main function tasks to be completed. 
//You must not change code in line numbers 119  to 162 and else if lines. 
//Fill code in portions where you are asked to write code.

// Main function
int main()
{
    CreditCard CC1 = { "JIM", "JONES", "56738", 0.0 };
    ChargeToCard(CC1, 200.99);
    CreditCard CC2 = { "ADAM", "ASHLEY", "12345", 0.0 };
    ChargeToCard(CC2, 2000.00);
    CreditCard CC3 = { "BERTHA", "MAPOS", "34567", 0.0 };
    ChargeToCard(CC3, 800.91);
    CreditCard CC4 = { "LISA", "BRAVE", "98765", 0.0 };
    ChargeToCard(CC4, 1001.23);
    CreditCard CC5 = { "WILLY", "NILLY", "23413", 0.0 };
    ChargeToCard(CC5, 700.00);
    CreditCard CC6 = { "JILL", "QUIRK", "67895", 0.0 };
    ChargeToCard(CC6, 1400.91);

    CreditCard CardArray[MAX];

    CardArray[0] = CC1;
    CardArray[1] = CC2;
    CardArray[2] = CC3;
    CardArray[3] = CC4;
    CardArray[4] = CC5;
    CardArray[5] = CC6;
    bool done = false;


    while (!done)
    {
        cout << "Enter the menu item number below and then press enter key." << endl
            << "1. Print credit card list in its current state.\n"
            << "2. Sort based on last name.\n"
            << "3. Sort based on credit card number\n"
            << "4. Sort based on balance.\n"
            << "5. Search based on last name.\n"
            << "6. Search based on credit card number.\n"
            << "7. Exit.\n";
        int choice;
        cin >> choice;

        if (choice == 7)
        {
            done = true;
        }
        else if (choice == 1)
        {
            print(CardArray, 6);
        }
        else if (choice == 2)
        {
            bubbleSort(CardArray, 1, 6);
        }
        else if (choice == 3)
        {
            bubbleSort(CardArray, 2, 6);
        }
        else if (choice == 4)
        {
            bubbleSort(CardArray, 3, 6);
        }
        else if (choice == 5)
        {
            cout << "Enter the last name of card holder in all capitals\n For example please enter paul as 'PAUL' " << endl;
            string LastName;
            cin >> LastName;
            CreditCard Last = {"", LastName,""};
            int index = LinearSearch(CardArray, Last, 1, 6);
        
            if (index >=0) 
            {
                cout << "The record was found. Details lie bellow." << endl;
                print(CardArray[index]);
            }
            else {
                cout << "The credit card record with last name " << LastName << " could not be found" << endl;
                 }
        }
        else if (choice == 6)
        {
            cout << "Enter Credit card number: " << endl;
            string CCN;
            cin >> CCN;
            CreditCard Number = { "","" , CCN};
            int index = LinearSearch(CardArray, Number, 2, 6);

            if (index >= 0)
            {
                cout << "The record was found. Details lie bellow." << endl;
                print(CardArray[index]);
            }
            else {
                cout << "The credit card record with the number " << CCN << " could not be found" << endl;
            }
        }
        else
        {
            cout << "This menu item is not yet implemented.\n" << endl;
        }
    }// while loop
}// Main function

// Function definitions

/*
Item 2: print function prints the CreditCard CC to console, so that output format looks like below:
Credit Card Number: 56738
Name: JIM ASHLEY
Amount owed: $200.99
*/
void print(const CreditCard& CC)
{
    cout << showpoint << setprecision(2);
    cout << "Credit Card Number: " << CC.CCN << endl;
    cout << "Name: " << CC.FirstName << " " << CC.LastName << endl;
    cout << "Amount owed: $" << CC.balance << "\n" << endl;
}


/*
Item 3: The overloaded print function below takes the credit Card array arr and it’s logical length as argument and prints
to console the entire array arr up to its logical length len. This Function MUST call Item 2 print function.
No credit will be given for item 3 if that is not done.
*/
void print(const CreditCard arr[], int len)
{
    for (size_t i = 0; i < len; i++)
    {
        print(arr[i]);
        cout << "---------------------------------\n";
    }
    cout << "---------------------------------------\n";
}

/*
Item 4: Function searches for CC in ccArr (see function header). The possible flag values decide the search basis, which are:
if flag == 1 search based on last name
If flag == 1 then it's caller function’s responsibility that last name field of object CC is populated.
if flag == 2 search based on credit card number.
if flag == 2 then it's caller's responsibility that credit card number field of CC object is populated.
Additional function duties:
Function returns -1 if CC is not found in ccArr, otherwise return index in the array, where CC is found in ccArr,
*/
int LinearSearch(const CreditCard ccArr[], const CreditCard& CC, int flag, int len)
{
    int index;
    for (size_t i = 0; i < len; i++) {
        if (flag == 1) {
            if (ccArr[i].LastName == CC.LastName) {
                index = static_cast<int>(i);
                return index;
            }                                               //looped if function to check on last name field if populated
            else {
                cout << "Record with name " << CC.LastName << " not found\n" << endl;
                return -1;
            }
           
        }

        else if (flag == 2) {
            if (ccArr[i].CCN == CC.CCN) {
                index = static_cast<int>(i);
                return index;
            }
            else {
                cout << "Card with number " << CC.CCN << " not found\n" << endl;
                return -1;
            }
        }
    }
}

/*

Item 5: Write a bubbleSort function, which sorts the array ccArr passed to it based on the flag value it gets. l
en is the logical length or length of interest. flag values determine the sorting basis as follows:
flag = 1 sort based on last name
flag = 2 sort based on CCN
flag = 3 sort based on balance
*/
    void bubbleSort(CreditCard ccArr[], int flag, int len)
    {
        for (size_t i = 0; i < len ; i++)
        {
            for (size_t j = 0; j < len - i - 1; j++) {
                if (flag == 1)
                {        //sort based on last name              
                    if (ccArr[j].LastName > ccArr[j + 1].LastName)    //swap whole structure not just element ID
                    {
                        CreditCard Temp;
                        Temp = ccArr[j];
                        ccArr[j] = ccArr[j + 1];
                        ccArr[j + 1] = Temp;
                    }


                }

                else if (flag == 2)
                {               //sort based on credit card number
                    if (ccArr[j].CCN > ccArr[j + 1].CCN)
                    {
                        CreditCard Temp;
                        Temp = ccArr[j];
                        ccArr[j] = ccArr[j + 1];
                        ccArr[j + 1] = Temp;
                    }


                }

                else if (flag == 3)
                {                //sort based on balance
                    if (ccArr[j].balance > ccArr[j + 1].balance)
                    {
                        CreditCard Temp;
                        Temp = ccArr[j];
                        ccArr[j] = ccArr[j + 1];
                        ccArr[j + 1] = Temp;
                    }

                }
        }
    }
}//end bubbleSorty

/*
Item 6: Write the body of function ChargeToCard, which takes money as argument. money is the amount of
money the credit card holder wishes to charge in a purchase transaction. This function MUST do a conditional
check to ascertain that adding the charge of money would not exceed global constant CREDIT_LIMIT.
Another way of saying this is that argument money must be less than or equal to available credit to authorize the purchase,
else the transaction must be declined. One Sample output from the program shown (at the end of this document) may give some
clue as how this function may be working.
*/

void ChargeToCard(CreditCard& CC, double money)
{
    cout << showpoint << setprecision(5);
    if (CREDIT_LIMIT - CC.balance <= money) {
        CC.balance += money;
    }

    else {
    cout << "Hello " << CC.FirstName << " " << CC.LastName << endl;
    cout << "Charging $ " << CC.balance << " will exceed credit limit. Transaction declined." << endl;
    cout << "-------------------------------------------------------------" << endl;
    }
}
/*
Item 7: Write a function called makePaymentToCard which takes credit card CC by reference, and amount of money that is a payment
against outstanding balance or advance payment on the credit. Function adjusts down the balance data member
 by the function argument money. Works just like making a payment on credit card or paying a portion of any monthly bill.
 */
void makePaymentToCard(CreditCard& CC, double money)
{
    cout << showpoint << setprecision(5);
    CC.balance = CC.balance - money;
}