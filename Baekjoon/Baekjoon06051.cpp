// Baekjoon06051.cpp
// https://www.acmicpc.net/problem/6051
#include <iostream>

using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int t;
	cin >> t;

	// { value, prevState };
	int state[80'000][2] = { { -1, 0 }, };
	for (int i = 1; i <= t; i++) {
		char query;
		cin >> query;
		if (query == 'a') {
			int k; cin >> k;

			state[i][0] = k;
			state[i][1] = i - 1;
		} else if (query == 's') {
			state[i][0] = state[state[i - 1][1]][0];
			state[i][1] = state[state[i - 1][1]][1];
		} else if (query == 't') {
			int k; cin >> k;

			state[i][0] = state[k - 1][0];
			state[i][1] = state[k - 1][1];
		}

		cout << state[i][0] << '\n';
	}

	return 0;
}