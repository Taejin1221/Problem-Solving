// Prob2441_PringStar4.cpp
#include <iostream>

using namespace std;

int main(void) {
	int num;

	cin >> num;
	for (int i = num; i > 0; i--) {
		for (int j = 0; j < num - i; j++)
			cout << " ";
		for (int j = i; j > 0; j--)
			cout << "*";
		cout << "\n";
	}

	return 0;
}