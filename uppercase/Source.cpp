#include <iostream>
#include <string>
#include <iostream>
#include <iomanip>
#include <fstream>

using namespace std;

const int MAX = 20;

void openFile(ifstream& input, const string& message);
int filltestQuest(string testQuest[], ifstream& inQ);
int fillansKey(bool ansKey[], ifstream& inA);
void fillstuAns(const string testQuest[], bool stuAns[], int lenQ);
int grade(const bool ansKey[], const bool stuAns[], int len);
void printansKeyAndstuAns(const string testQuest[], const bool ansKey[], const bool stuAns[], int len);

int main(int argc, char* argv[])
{
    cout << "Welcome to the Driving Test Program" << endl;
    ifstream in;
    openFile(in, "testQuest");
    string testQuest[MAX] = {};
    int lenQ = filltestQuest(testQuest, in);
    in.close();
    openFile(in, "ansKey");
    bool ansKey[MAX];
    int lenA = fillansKey(ansKey, in);

    if (lenQ != lenA)
    {
        cout << "Number of testQuest and ansKey are Different. Exiting the Program" << endl;
        exit(0);
    }
    bool stuAns[MAX] = {};
    fillstuAns(testQuest, stuAns, lenQ);
    int score = 0;
    score = grade(ansKey, stuAns, lenQ);
    cout << "You Scored " << score << "Points, out of a Maximum of " << lenQ << "Points" << endl;
    double percent = (double(score) / lenQ) * 100;

    if (percent > 60)
    {
        cout << "You Scored " << percent << "% in the Quiz" << endl;
        cout << "You Passed the Quiz" << endl;
    }
    else
    {
        cout << "You Scored " << percent << "% in the Quiz" << endl;
        cout << "You Failed the Quiz. Please Try Again" << endl;
    }
    in.close();
    cout << "--------------------------------------------------------------------------------" << endl;
    return 0;
}

void openFile(ifstream& input, const string& message) //Does not Register Multiple Answer Test due to Array lengths not the same. Possible sentinel value needing to be inserted.
{
    bool done = false;
    string In_File = "";
    while (!done)
    {
        input.clear();
        cout << "Please Input the File Location: " << endl;
        getline(cin, In_File);
        input.open(In_File.c_str());

        if (input.fail())
        {
            cout << "The File " << In_File << "does NOT Exist" << endl;
            done = false;
        }
        else
        {

            input.peek();
            if (input.eof())
            {
                cout << "The File Was EMPTY" << endl;
                done = false;
                input.close();
            }
            else
            {
                done = true;
            }
        }
    }//end while
    cout << "The File " << In_File << "opened and contains data" << endl;
}

int filltestQuest(string testQuest[], ifstream& inQ)
{
    char ch = ' ';
    int i = 0;

    while ((ch = inQ.peek()) != EOF && i < MAX)
    {
        getline(inQ, testQuest[i], '$');
        i++;
    }

    return i;
}

int fillansKey(bool ansKey[], ifstream& inA)
{
    char ch = ' ';
    int i = 0;

    while ((ch = inA.peek()) != EOF && i < MAX)
    {
        inA >> ansKey[i];
        i++;
    }

    return i;
}

void fillstuAns(const string testQuest[], bool stuAns[], int lenQ)
{
    cout << "Enter Test Questions with Cooresponding Character" << endl;
    for (int i = 0; i < lenQ; i++)
    {
        cout << testQuest[i];//does not allow user inputted answer after the posting of the question
        cin >> stuAns[i];
    }
}

int grade(const bool ansKey[], const bool stuAns[], int len)
{
    int score = 0;
    for (int i = 0; i < len; i++)
    {
        if (ansKey[i] == stuAns[i])
        {
            score++;
        }
    }

    return score;
}

void printansKeyAndstuAns(const string testQuest[], const bool ansKey[], const bool stuAns[], int len)
{
    cout << "*******************************************************" << endl;
    cout << "Here are the Correct ansKey and Your Inputted ansKey" << endl;
    cout << "*******************************************************" << endl;

    cout << boolalpha;
    cout << setw(55) << left << "testQuest" << setfill(' ') << setw(18) << left << "Correct ansKey" << setfill(' ') << setw(18) << left << "Your ansKey" << setfill(' ') << endl;
    cout << "------------------------------------------------------------------------------------------------------------------------" << endl;

    for (int i = 0; i < len; i++)
    {
        cout << setw(55) << left << testQuest[i] << setfill(' ') << setw(18) << left << stuAns[i] << setfill(' ') << setw(18) << left << ansKey[i] << setfill(' ') << endl;
        cout << "------------------------------------------------------------------------------------------------------------------------" << endl;
    }
    cout << "------------------------------------------------------------------------------------------------------------------------" << endl;
}

