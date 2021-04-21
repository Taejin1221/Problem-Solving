// Codeforces_1516A.cpp
#include <iostream>

using namespace std;

void solveTestCase( ) {
	int n, k;
	cin >> n >> k;

	int arr[100];
	for ( int i = 0; i < n; i++ )
		cin >> arr[i];

	int idx = 0;
	while ( k-- ) {
		while ( idx < n && arr[idx] == 0 )
			idx++;

		if ( idx == n - 1 || idx == n )
			break;
		else {
			arr[idx]--;
			arr[n - 1]++;
		}
	}

	for ( int i = 0; i < n; i++ )
		cout << arr[i] << ' ';
	cout << '\n';
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
