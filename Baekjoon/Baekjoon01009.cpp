// Baekjoon01009_DistributedComputing.cpp
// https://www.acmicpc.net/problem/1009
#include <iostream>

using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int t;
	cin >> t;

	while ( t-- ) {
		int a, b;
		cin >> a >> b;
		
		int digit = 1;
		for ( int i = 0; i < b; i++ )
			digit = digit * a % 10;

		digit %= 10;
		if ( !digit )
			digit = 10;

		cout << digit << '\n';
	}

	return 0;
}