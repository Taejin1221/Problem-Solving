// Codeforces_1604B.cpp
#include <iostream>

using namespace std;

void solveTestCase() {
	int n;
	cin >> n;

	int arr[100'000];
	for (int i = 0; i < n; i++)
		cin >> arr[i];

	if (n % 2 == 0)
		cout << "YES";
	else {
		bool canMake = false;
		for (int i = 0; i < n - 1; i++) {
			if (arr[i] >= arr[i + 1]) {
				canMake	= true;
				break;
			}
		}

		if (canMake)
			cout << "YES";
		else
			cout << "NO";
	}
	cout << '\n';
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
