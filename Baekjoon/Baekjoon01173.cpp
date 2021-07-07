// Baekjoon01173_Workout.cpp
// https://www.acmicpc.net/problem/1173
#include <iostream>

using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int N, m, M, T, R;
	cin >> N >> m >> M >> T >> R;

	if ( M - m < T )
		cout << -1;
	else {
		int currPulse = m;
		int totalTime, exerTime = 0;
		for ( totalTime = 0; exerTime < N ; totalTime++ ) {
			if ( currPulse + T <= M ) {
				currPulse += T;
				exerTime++;
			} else {
				currPulse -= R;
				if ( currPulse < m )
					currPulse = m;
			}
		}

		cout << totalTime;
	}
	cout << '\n';

	return 0;
}