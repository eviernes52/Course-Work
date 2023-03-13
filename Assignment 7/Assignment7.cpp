/*
Programmer: Emiliano Viernes Orozco

Assignment 7

Visual Studio 2019 version 16.9.6

Windows 10 19042

11:40 pm 5/20/2021
*/
#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>

using namespace std;

//function protypes
const int MAX = 20; // the 20 questions / answers in the test
void openFile(ifstream& input, const string& message);
int fillQuestionsArray(string questions[], ifstream& in);
int fillAnswerKeyArray(char ans[], ifstream& in);
int fillResponseArray(const string questions[], char response[], int len);
int GradeResponses(const char answers[], const char response[], int len);
void printAnswersAndResponses(const string questions[], const char answers[], const char response[], int len);

int main(){
	cout << "Welcome to your online driving test." << endl;
	ifstream in;
	openFile(in, "questions");
	string questions[MAX] = {};
	int questionsLen = fillQuestionsArray(questions,in);
	in.close();
	openFile(in, "answers");
	char answers[MAX];
	int answersLen = fillAnswerKeyArray(answers,in);

	if (questionsLen != answersLen) {
		cout << "The ammount of questions answered doesn't match with the ammount of questions" << endl;
		exit (0);
	}

	else
	{
		char response[MAX] = {};
		fillResponseArray(questions, response, questionsLen);
		int score = 0;
		score = GradeResponses(answers, response, questionsLen);
		printAnswersAndResponses(questions, answers, response, answersLen);

		cout << "Your total score was " << score << " points correct out of a total of " << questionsLen << " points" << endl;
		if (score >= 12) {
			cout << "You passed. Please review your answers. " << endl;
		}

		else {
			cout << "You failed. Please review your answers. " << endl;
		}

		cout << "Total answered correctly: " << score << endl;
		cout << "Total answered incorrectly: " << questionsLen - score << endl;
	}
	in.close();
	return 0;
}//end main

void openFile(ifstream& input, const string& message)
{
	bool done = false;
	string In_File = "";

	while (!done)
	{
		cout << "Please enter the name of the data file with " << message << " to be read: ";
		getline(cin,In_File);
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
	}
	cout << "File " << In_File << " opened and has data stored inside of it " << endl;
} //end open file

int fillQuestionsArray(string questions[], ifstream& in) {
	char ch = ' ';
	int i = 0;

	while ((ch = in.peek()) != EOF && i < MAX){
	string temp;
	getline(in, temp, '$');
	questions[i] = temp;
	i++;
	getline(in, questions[i]);
	i++;
	}
	return i;
}//end fill questions array

int fillAnswerKeyArray(char ans[], ifstream& in) {
	int i = 0;
	while (in.peek() != EOF && i < MAX) {
		in >> ans[i];
		i++;
	}
	return i;
}//end fill answer key array

int fillResponseArray(const string questions[], char response[], int len) {
	cout << "Please choose your answer: " << endl;
	for (int i = 0; i < len; i++) {
		cout << questions[i] << " : ";
		return response[i];
	}
}//end fill response array

int GradeResponses(const char answers[], const char response[], int len) {
	int score = 0;
	for (int i = 0; i < len; i++) {
		if (answers[i] == response[i]) {
			score++;
		}
	}
	return score;
}//end grade responses

void printAnswersAndResponses(const string questions[], const char answers[], const char response[], int len) {
	cout << "Thank you for properly taking the test. \n Now we will give an evaluation of your answers and responses " << endl;
	cout << setw(50) << left << "Question " << setfill(' ') << setw(30) << left << " Correct Answer " << setfill(' ')
		<< left << setw(15) << "Your answer " << endl;

	for (int i = 0; i < len; i++) {
		cout << setw(50) << left << questions[i] << setfill(' ') << setw(30) << left << answers[i] << setfill(' ')
			<< left << setw(15) << response[i] << endl;
	}
}//end print answeres and responses
