// Prob2442_PrintStar5.cpp
#include <iostream>

using namespace std;

int main(void) {
	int num;

	cin >> num;
	for (int i = 0; i < num; i++) {
		for (int j = 1; j < num - i; j++)
			cout << " ";
		for (int j = 0; j < i * 2 + 1; j++)
			cout << "*";
		cout << "\n";
	}

	return 0;
}