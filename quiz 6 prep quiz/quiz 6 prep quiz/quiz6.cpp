#include <iostream>
using namespace std;
void Test(int & s, int T);
int main() 
{
	int d{ 12 }, e{ 14 };

	Test(d, e);
	cout << "main func " << d << e << endl;

	d = 15;
	e = 18;
	Test(e, d);

	cout << "Main test func" << d << e << endl;
	return 0;
}

void Test(int& s, int T) {
	s = 3;
	s += 2;
	T = 4*s;
		cout << "In the function test "<< s << T << endl;
		return;

}