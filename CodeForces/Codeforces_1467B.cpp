// Codeforces_1467B.cpp
#include <iostream>

using namespace std;

int n;
int arr[300'000];

bool isHill( int idx ) {
	if ( 0 < idx && idx < n - 1 )
		if ( arr[idx - 1] < arr[idx] && arr[idx] > arr[idx + 1] )
			return true;
	return false;
}

bool isValley( int idx ) {
	if ( 0 < idx && idx < n - 1 )
		if ( arr[idx - 1] > arr[idx] && arr[idx] < arr[idx + 1] )
			return true;
	return false;
}

void solveTestCase( ) {
	cin >> n;

	for ( int i = 0; i < n; i++ )
		cin >> arr[i];

	int intimidation = 0;
	bool vh[300'000] = { false, }; // number of valleys and hills at index i
	for ( int i = 1; i < n - 1; i++ ) {
		if ( isHill( i ) || isValley( i ) ) {
			vh[i] = true;
			intimidation++;
		}
	}

	int ans = intimidation;
	for ( int i = 1; i < n - 1; i++ ) {
		int temp = arr[i];

		arr[i] = arr[i - 1];
		ans = min( ans, intimidation - ( vh[i - 1] + vh[i] + vh[i + 1] )
			+ ( isHill( i - 1 ) + isHill( i ) + isHill( i + 1 ) )
			+ ( isValley( i - 1 ) + isValley( i ) + isValley( i + 1 ) )
		);

		arr[i] = arr[i + 1];
		ans = min( ans, intimidation - ( vh[i - 1] + vh[i] + vh[i + 1] )
			+ ( isHill( i - 1 ) + isHill( i ) + isHill( i + 1 ) )
			+ ( isValley( i - 1 ) + isValley( i ) + isValley( i + 1 ) )
		);

		arr[i] = temp;
	}

	cout << ans << '\n';
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int t;
	cin >> t;
	while ( t-- ) {
		solveTestCase();
	}

	return 0;
}
