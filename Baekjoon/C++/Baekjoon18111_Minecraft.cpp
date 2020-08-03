// Baekjoon18111_Minecraft.cpp
// https://www.acmicpc.net/problem/18111
#include <iostream>

using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n, m, b;
	cin >> n >> m >> b;

	int minHeight = 256, maxHeight = 0;
	int table[257] = { 0, };
	for ( int i = 0; i < n; i++ ) {
		for ( int j = 0; j < m; j++ ) {
			int temp;
			cin >> temp;

			if ( temp < minHeight )
				minHeight = temp;

			if ( temp > maxHeight )
				maxHeight = temp;

			table[temp]++; 
		}
	}

	int answer[2] = { 1'000'000'000, 0 };
	for ( int i = minHeight; i <= maxHeight; i++ ) {
		int time = 0, tempB = b;

		for ( int j = maxHeight; j > i; j-- ) {
			int num = (j - i) * table[j];
			tempB += num;
			time += 2 * num;
		}

		for ( int j = minHeight; j < i; j++ ) {
			int num = ( i - j ) * table[j];
			tempB -= num;

			if ( tempB < 0 )
				break;
			else
				time += num;
		}

		if ( tempB < 0 )
			continue;
		else {
			if ( time <= answer[0] ) {
				answer[0] = time;
				answer[1] = i;
			}
		}
	}

	cout << answer[0] << ' ' << answer[1] << '\n';

	return 0;	
}