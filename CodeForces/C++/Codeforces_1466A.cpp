// Codeforces_1466A.cpp
#include <iostream>

using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int t;
	cin >> t;
	while ( t-- ) {
		int n;
		cin >> n;

		bool diff[51] = { false, };
		int arr[50];
		for ( int i = 0; i < n; i++ )
			cin >> arr[i];

		for ( int i = 0; i < n - 1; i++ )
			for ( int j = i + 1; j < n; j++ )
				diff[arr[j] - arr[i]] = true;

		int ans = 0;
		for ( int i = 1; i <= 50; i++ )
			if ( diff[i] )
				ans++;

		cout << ans << '\n';
	}

	return 0;
}
