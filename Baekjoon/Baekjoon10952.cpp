// Prob10952_A+B-5.cpp
#include <iostream>

using namespace std;

int main(void) {
	int a, b;

	cin >> a >> b;
	while (a || b ) {
		cout << a + b << "\n";

		cin >> a >> b;
	}

	return 0;
}