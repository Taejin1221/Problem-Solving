// Codeforces_1607C.cpp
#include <iostream>

#include <algorithm>

#define INF 0x3f3f3f3f

using namespace std;

typedef long long ll;

void solveTestCase() {
	int n;
	cin >> n;

	int* arr = new int[n];
	for (int i = 0; i < n; i++)
		cin >> arr[i];

	sort(arr, arr + n);

	ll acc = 0LL, ans = -INF;
	for (int i = 0; i < n; i++) {
		ll currValue = arr[i] - acc;
		ans = max(ans, currValue);
		acc += currValue;
	}

	cout << ans << '\n';

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
