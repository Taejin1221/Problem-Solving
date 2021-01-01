// Baekjoon02467_Liquid.cpp
// https://www.acmicpc.net/problem/2467
#include <iostream>

#define ABS( a ) ( ( a ) > 0 ? ( a ) : -( a ) )

using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;

	int liquids[100'000];
	for ( int i = 0; i < n; i++ )
		cin >> liquids[i];

	int left = 0, right = n - 1;
	int ans = 2'000'000'000, leftVal, rightVal;
	while ( left < right ) {
		int currVal = liquids[left] + liquids[right];
		if ( ABS( currVal ) < ans ) {
			ans = ABS( currVal );
			leftVal = liquids[left];
			rightVal = liquids[right];
		}

		if ( ABS( liquids[left] ) < ABS( liquids[right] ) )
			right--;
		else
			left++;
	}

	cout << leftVal << ' ' << rightVal << '\n';

	return 0;
}
