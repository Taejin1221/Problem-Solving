// Prob1110_PlusCycle.cpp
#include <iostream>

using namespace std;

int main(void) {
	int n;

	cin >> n;

	int cycle = 0;
	int firstNum, secondNum;
	int firstDigit, secondDigit;
	int result = n;

	do {
		int firstDigit = result % 10;
		int secondDigit = ((result / 10) + firstDigit) % 10;

		result = firstDigit * 10 + secondDigit;
		cycle++;
	} while (result != n);

	cout << cycle;

	return 0;
}