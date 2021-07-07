// Baekjoon20410_EarnLotteryPrize.cpp
// https://www.acmicpc.net/problem/20410
#include <iostream>

using namespace std;

int main(void) {
	int m, seed, x1, x2;
	cin >> m >> seed >> x1 >> x2;

	bool isFind = false;
	for ( int i = 0; i < m; i++ ) {
		for ( int j = 0; j < m; j++ ) {
			bool first = ((i * seed + j) % m == x1);
			bool second = ((i * x1 + j) % m == x2);

			if ( first && second ) {
				isFind = true;
				cout << i << ' ' << j << '\n';
				break;
			}
		}

		if ( isFind )
			break;
	}

	return 0;
}