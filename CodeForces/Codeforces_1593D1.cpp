// Codeforces_1593D1.cpp
#include <iostream>

#include <set>

using namespace std;

int GCD(int a, int b) {
	return (a % b == 0) ? b : GCD(b, a % b);
}

void solveTestCase( ) {
	int n;
	cin >> n;

	int arr[40], minVal = 1'234'567'890;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
		minVal = min(minVal, arr[i]);
	}

	int ans = -1;
	for (int i = 0; i < n; i++) {
		int diff = arr[i] - minVal;
		if (diff != 0) {
			if (ans == -1)
				ans = diff;
			else
				ans = (ans < diff) ? GCD(diff, ans) : GCD(ans, diff);
		}
	}

	cout << ans << '\n';
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int t;
	cin >> t;
	while ( t-- ) {
		solveTestCase( );
	}

	return 0;
}
