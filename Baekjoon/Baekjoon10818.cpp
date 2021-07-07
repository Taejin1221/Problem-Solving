// Baekjun10818_MinMax.cpp
#include <iostream>
#include <climits>
#include <vector>

using namespace std;

int main(void) {
	int time;
	int max = INT_MIN, min = INT_MAX;
	vector<int> arr;

	cin >> time;

	for (int i = 0; i < time; i++) {
		int temp;

		cin >> temp;
		arr.push_back(temp);

		if (temp < min) min = temp;
		if (temp > max) max = temp;
	}

	cout << min << " " << max << "\n";

	return 0;
}