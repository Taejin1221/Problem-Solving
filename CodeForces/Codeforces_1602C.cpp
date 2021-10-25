// Codeforces_1602C.cpp
#include <iostream>

#include <vector>

using namespace std;

void solveTestCase() {
	int n;
	cin >> n;

	int* arr = new int[n];
	for (int i = 0; i < n; i++)
		cin >> arr[i];

	vector<int> counts;
	for (int i = 0; i <= 30; i++) {
		int count = 0;
		for (int j = 0; j < n; j++)
			if (arr[j] & (1 << i))
				count++;

		if (count)
			counts.push_back(count);
	}
	// cout << counts.size() << endl;

	for (int i = 1; i <= n; i++) {
		bool canMake = true;
		for (int j = 0; j < (int)counts.size(); j++) {
			if (counts[j] % i != 0) {
				canMake = false;
				break;
			}
		}

		if (canMake)
			cout << i << ' ';
	}

	cout << '\n';

	delete[] arr;
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int t;
	cin >> t;
	while (t--) {
		solveTestCase();
	}

	return 0;
}
