// Baekjoon02563_ColorPaper.cpp
// https://www.acmicpc.net/problem/2563
#include <iostream>

using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;

	bool paper[100][100] = { 0, };
	for ( int i = 0; i < n; i++ ) {
		int a, b;
		cin >> a >> b;

		for ( int r = a; r < a + 10; r++ )
			for ( int c = b; c < b + 10; c++ )
				paper[r][c] = true;
	}

	int sum = 0;
	for ( int i = 0; i < 100; i++ )
		for ( int j = 0; j < 100; j++ )
			if ( paper[i][j] )
				sum++;

	cout << sum << '\n';

	return 0;
}