// Baekjoon01145_AlmostMultiple.cpp
// https://www.acmicpc.net/problem/1145
#include <iostream>

using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int nums[5];
	for ( int i = 0; i < 5; i++ )
		cin >> nums[i];

	for ( int i = 1; i <= 1'000'000; i++ ) {
		int multiple = 0;
		for ( int j = 0; j < 5; j++ )
			multiple += ( i % nums[j] ) ? 0 : 1;

		if ( multiple >= 3 ) {
			cout << i << '\n';

			break;
		}
	}

	return 0;
}