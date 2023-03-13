/*
Programmer: Emiliano Viernes Orozco

Assignment 8

Visual Studio 2019 version 16.9.6

Windows 10 19042

11:50 pm 6/1/2021
*/
#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
using namespace std;

const int MAX = 20;// the 20 questions / answers in the test

struct Quiz {
	string question;	//stores questions
	char key{};			//stores answer keys needs to be initilized apperantly
	char response{};		//stores user responses needs to be initilized apperantly
};

//function protypes
void openInputFile(ifstream& input, const string& message);	//done well
int fillQuestions(Quiz qz[], ifstream& in);					//done well
int fillAnswerKeys(Quiz qz[], ifstream& inA);				//done well
void fillResponses(Quiz qz[], int len);						//done
int gradeResponses(const Quiz qz[], int len);				//done
void printAnswersAndResponses(const Quiz qz[], int len);	//done

int main() {
	cout << fixed << showpoint << setprecision(2);
	cout << "Welcome,This online driving test will instantly grade your responses and display the correct and incorrect answers.\n" << endl;
	ifstream in;
	openInputFile(in, "questions");
	Quiz qz[MAX];
	int len = fillQuestions(qz, in);
	in.close();
	openInputFile(in, "answers");
	int lenAnswers = fillAnswerKeys(qz, in);
	in.close();

	if (len != lenAnswers) {
		cout << "The ammount of questions do not match up with the answer key responses" << endl;
		return 0;
	}
	cout << "Please enter either your answers exactly as 'A' , 'B', 'C' , 'D' for each answer in uppercase" << endl;
	fillResponses(qz, len);
	int points = gradeResponses(qz, len);
	cout << ".\n.\n.\n." << endl;
	cout << "Total questions answered correctly: " << points << endl;
	cout << "Total questions answered incorrectly: " << MAX - points << endl;
	if (points >= 12) {
			cout << "Congratulations you passed, you scored " << points << " points out of " << MAX << ". Please review your answers. \n" << endl;
		}

	else {
			cout << "Sadly you failed, you scored " << points << " points out of " << MAX  << ". Please review your answers. \n" << endl;
		}

	printAnswersAndResponses(qz, len);
	return 0;
}//end main

void openInputFile(ifstream& input, const string& message) // done
{
	bool done = false;
	string In_File = "";

	while (!done)
	{
		cout << "Please enter the name of the data file with " << message << " to be read: ";
		getline(cin, In_File);
		cout << "The file name you entered is : " << In_File << endl;
		input.open(In_File.c_str());

		if (input.fail()) {
			cout << "The file " << In_File << " does not exist. \n";
			done = false;
		}

		else
		{
			input.peek();

			if (input.eof())
			{
				cout << " The file has nothing in it ";
				done = false;
				input.close();
			}
			else
			{
				done = true;
			}
		}
	} // ends while loop
	cout << "File " << In_File << " opened and has data stored inside of it " << endl;
} //end open file

int fillQuestions(Quiz qz[], ifstream& in) {
	char ch = ' ';
	int count = 0;

	while ((ch = in.peek()) != EOF && count < MAX) {
		string temp = "";
		getline(in, temp, '$');
		qz[count].question = temp;
		count++;
	}
	return count;
}//end fill questions array

int fillAnswerKeys(Quiz qz[], ifstream& inA) {
	int i = 0;
	while (inA.peek() != EOF && i < MAX) {
		inA >> qz[i].key;
		i++;
	}
	return i;
}//end fill answer key array

void fillResponses(Quiz qz[], int len) {
	cout << "Please choose your answers for each question bellow\n " << endl; //user greetings
	cout << "Enter your answer: " << endl;
	for (int i = 0; i < len; i++) {					//algorithim
		cout << qz[i].question << " : ";
		cin >> qz[i].response;
	}
}//end fill response array

int gradeResponses(const Quiz qz[], int len) {
	int score = 0;
	for (int i = 0; i < len; i++) {
		if (qz[i].key == qz[i].response) {
			score++;
		}
	}
	return score;
}//end grade responses

void printAnswersAndResponses(const Quiz qz[], int len) {
	cout << "*********************************************************************************************************" << endl;
	cout << "Thank you for properly taking the test. \n Now we will give an evaluation of your answers and responses " << endl;
	cout << "---------------------------------------------------------------------------------------------------------" << endl;
	cout << setw(55) << left << "Question " << setfill(' ') << setw(18) << left << " Correct Answer " << setfill(' ') << left << setw(15) << "Your answer " << endl;

	for (int i = 0; i < len; i++) {
		cout << setw(55) << left << qz[i].question << setfill(' ') << setw(18) << left << qz[i].key << setfill(' ')
			<< left << setw(15) << qz[i].response << endl;
		if (qz[i].response == qz[i].key) {
			cout << "This questions was answered correctly\n";
			cout << "-----------------------------------------------------" << endl;
		}
																	// if statement print's out after to give user idea on which questions were right or wrong
		else {
			cout << "This questions was answered incorrectly\n";
			cout << "-----------------------------------------------------" << endl;
		}
	}//ends for loop
}//end print answers and responses 
