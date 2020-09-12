// Codeforces1385_A.cpp
#include <iostream>

using namespace std;

int firstMax( int arr[] ) {
	int idx = 0;
	for ( int i = 1; i < 3; i++ )
		if ( arr[idx] < arr[i] )
			idx = i;
	return idx;
}

int secondMax( int arr[], int idx ) {
	int idx2;
	if ( idx == 0 )
		idx2 = 1;
	else
		idx2 = 0;
	
	for ( int i = 0; i < 3; i++ ) {
		if ( i == idx )
			continue;
		else
			if ( arr[idx2] < arr[i] )
				idx2 = i;
	}

	return idx2;
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int t;
	cin >> t;

	while ( t-- ) {
		int arr[3];
		cin >> arr[0] >> arr[1] >> arr[2];

		int idx1 = firstMax( arr );
		int idx2 = secondMax( arr, idx1 );

		// cout << idx1 << ' ' << idx2 << '\n';

		if ( arr[idx1] != arr[idx2] )
			cout << "NO" << '\n';
		else {
			cout << "YES" << '\n';
			int idx3;
			for ( int i = 0; i < 3; i++ ) {
				if ( i != idx1 && i != idx2 ) {
					idx3 = i;
					break;
				}
			}

			cout << arr[idx1] << ' ';
			cout << arr[idx3] << ' ' << arr[idx3];
			cout << '\n';
		}
	}

	return 0;
}