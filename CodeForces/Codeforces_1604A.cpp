// Codeforces_1604A.cpp
#include <iostream>

using namespace std;

void solveTestCase() {
	int n;
	cin >> n;

	int ans = 0;
	int arr[100];
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
		ans = max(ans, arr[i] - (i + 1));
	}

	cout << ans << '\n';
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
