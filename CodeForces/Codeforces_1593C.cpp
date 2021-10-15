// Codeforces_1593C.cpp
#include <iostream>

#include <algorithm>

using namespace std;

void solveTestCase( ) {
	int n, k;
	cin >> n >> k;

	int arr[400'000];
	for (int i = 0; i < k; i++)
		cin >> arr[i];

	sort(arr, arr + k);

	int cat = 0, ans = 0;
	for (int i = k - 1; i >= 0; i--) {
		cat += n - arr[i];
		ans++;
		if (i > 0 && cat >= arr[i - 1])
			break;
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
