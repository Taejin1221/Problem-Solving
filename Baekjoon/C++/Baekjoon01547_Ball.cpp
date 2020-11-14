// Baekjoon01547_Ball.cpp
// https://www.acmicpc.net/problem/1547
#include <iostream>

using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int ball = 1;

	int m;
	cin >> m;
	for ( int i = 0; i < m; i++ ) {
		int a, b;
		cin >> a >> b;

		if ( a == ball )
			ball = b;
		else if ( b == ball )
			ball = a;
	}

	cout << ball << '\n';

	return 0;
}