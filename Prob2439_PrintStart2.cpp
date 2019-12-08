// Prob2439_PrintStart2.cpp
#include <iostream>

using namespace std;

int main(void) {
	int num;
	cin >> num;

	for (int i = 1; i <= num; i++) {
		for (int j = num - i; j > 0; j--)
			cout << " ";
		for (int j = 0; j < i; j++)
			cout << "*";
		cout << "\n";
	}

	return 0;
}