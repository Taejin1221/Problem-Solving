// Baekjoon14697_AllocatingRoom.cpp
// https://www.acmicpc.net/problem/14697
// KOI 2017 초등부 2
#include <iostream>

using namespace std;

int main(void) {
	int a, b, c, target;
	cin >> a >> b >> c >> target;

	int isPossible = 0;
	for ( int i = 0; i <= target / a; i++ )
		for ( int j = 0; j <= target / b; j++ )
			for ( int k = 0; k <= target / c; k++ )
				if ( a * i + b * j + c * k == target )
					isPossible = 1;

	cout << isPossible << '\n';

	return 0;
}