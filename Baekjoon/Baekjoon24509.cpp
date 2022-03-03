// Baekjoon24509.cpp
// https://www.acmicpc.net/problem/24509
#include <iostream>

#include <vector>
#include <algorithm>

#define MAX 200'000

using namespace std;

using pii = pair<int, int>;

bool compare(pii a, pii b) {
	return (a.first != b.first ? a.first > b.first : a.second < b.second);
}

bool isIn(vector<int>& winner, int student) {
	for (int& w : winner)
		if (w == student)
			return true;
	return false;
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;

	pii score[4][MAX];
	for (int i = 0; i < n; i++) {
		int number;
		cin >> number;

		for (int j = 0; j < 4; j++) {
			cin >> score[j][i].first;
			score[j][i].second = number;
		}
	}

	for (int i = 0; i < 4; i++)
		sort(score[i], score[i] + n, compare);

	vector<int> winner;
	for (int i = 0; i < 4; i++) {
		int j;
		for (j = 0; j < n && isIn(winner, score[i][j].second); j++);
		cout << score[i][j].second << ' ';
		winner.push_back(score[i][j].second);
	}
	cout << '\n';

	return 0;
}