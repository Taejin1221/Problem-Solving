// Baekjoon01373_BinaryOcta.cpp
// https://www.acmicpc.net/problem/1373
#include <iostream>
#include <string>

using namespace std;

int main(void) {
	string oct;
	cin >> oct;

	for ( int i = 0; i < oct.size() % 3; i++ )
		oct = "0" + oct;

	for ( int i = 0; i < oct.size(); i += 3 ) {
		int ans = 4 * ( oct[i] - '0' );
		ans += 2 * ( oct[i + 1] - '0' );
		ans += (oct[i + 2] - '0' );

		cout << ans;
	}

	cout << '\n';

	return 0;
}
