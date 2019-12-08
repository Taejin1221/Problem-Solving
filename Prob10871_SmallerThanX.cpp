// Prob10871_SmallerThanX.cpp
#include <iostream>

using namespace std;

int main(void) {
	int n, x;

	cin >> n >> x;

	for (int i = 0; i < n; i++) {
		int temp;

		cin >> temp;

		if (temp < x)
			cout << temp << " ";
	}
	cout << "\n";

	return 0;
}