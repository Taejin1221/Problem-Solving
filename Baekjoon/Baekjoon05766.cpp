// Baekjoon05766.cpp
// https://www.acmicpc.net/problem/5766
#include <iostream>

using namespace std;

void solve(int n, int m) {
	int score[10'001] = { 0, };

	while (n--) {
		for (int i = 0; i < m; i++) {
			int player;
			cin >> player;

			score[player]++;
		}
	}

	int firstScore = 0;
	for (int i = 1; i < 10'001; i++)
		firstScore = max(firstScore, score[i]);

	int secondScore = 0;
	for (int i = 1; i < 10'001; i++)
		if (score[i] != firstScore)
			secondScore = max(secondScore, score[i]);

	for (int i = 1; i < 10'001; i++)
		if (score[i] == secondScore)
			cout << i << ' ';
	cout << '\n';
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int n, m;
	cin >> n >> m;
	while (n != 0 && m != 0) {
		solve(n, m);

		cin >> n >> m;
	}

	return 0;
}