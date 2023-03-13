#include <iostream>
#include <iostream>
#include <string>
#include <cmath>
using namespace std;

int main() {
	int index;
	int nums = {5,4,6,7,8};
	for (index = 0; index < 4; index++) 
	{
		cout << max(nums[index], nums[index + 1]);
		cout <<" ";
	}

	cout << endl;

}