// Baekjoon2562_Max.cpp
#include <iostream>

using namespace std;

int main(void) {
	int arr[9];
	int maxNum, maxIdx = 0;

	cin >> arr[0];
	maxNum = arr[0];
	for (int i = 1; i < 9; i++) {
		cin >> arr[i];
		if ( maxNum < arr[i] ) {
			maxNum = arr[i];
			maxIdx = i;
		}
	}

	cout << maxNum << "\n";
	cout << maxIdx + 1 << endl;

	return 0;
}