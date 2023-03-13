#include <iostream>
#include <string>
#include <iomanip>
#include <cmath>
using namespace std;

struct Foo {
	string phrase;
};
int main() {
	Foo F1;
	Foo F2;
	F1.phrase = "wow ton not now";
	F2 = F1;;
	cout << F2.phrase << endl;
}

