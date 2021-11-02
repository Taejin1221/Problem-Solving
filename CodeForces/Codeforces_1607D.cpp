// Codeforces_1607D.cpp
#include <iostream>

#include <vector>
#include <algorithm>

using namespace std;

void solveTestCase() {
	int n;
	cin >> n;

	int* arr = new int[n];
	for (int i = 0; i < n; i++)
		cin >> arr[i];

	vector<int> blue, red;
	for (int i = 0; i < n; i++) {
		char color;
		cin >> color;

		color == 'B' ? blue.push_back(arr[i]) : red.push_back(arr[i]);
	}

	sort(blue.begin(), blue.end());
	sort(red.begin(), red.end());

	bool isImpossible = false;
	int num = 1;
	for (int i = 0; i < blue.size(); i++) {
		if (blue[i] < num) {
			isImpossible = true;
			break;
		}
		num++;
	}

	if (isImpossible)
		cout << "NO";
	else {
		for (int i = 0; i < red.size(); i++) {
			if (red[i] > num) {
				isImpossible = true;
				break;
			}
			num++;
		}

		if (isImpossible)
			cout << "NO";
		else
			cout << "YES";
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
