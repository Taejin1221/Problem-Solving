// Baekjoon02750_Sort1.cpp
#include <iostream>

#define SWAP( a, b ) { int temp = ( a ); ( a ) = ( b ); ( b ) = temp; }

using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int n;
	cin >> n;

	int arr[1'000];
	for ( int i = 0; i < n; i++ )
		cin >> arr[i];

	for ( int i = n - 1; i > 0; i-- ) {
		for ( int j = 0; j < i; j++ )
			if ( arr[j] > arr[j + 1] )
				SWAP( arr[j], arr[j + 1] );
	}

	for ( int i = 0; i < n; i++ )
		cout << arr[i] << '\n';

	return 0;
}