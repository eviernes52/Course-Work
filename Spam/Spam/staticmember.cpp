#include <iostream>
using namespace std;

	class Farm
{
private:	// static in private
	static int sick;
	int totalAnimals;
public:

	static int getSick() {	// can only access static
		return sick;
	}
};
//initialization
int Farm::sick = 0;

int main()
{
		cout << Farm::getSick() << endl; // since member is in private only function can be called to get static int indirectly
}				// or if static int sick is public we can use Farm::sick
