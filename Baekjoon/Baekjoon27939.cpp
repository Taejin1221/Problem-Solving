// Baekjoon27939.cpp
// https://www.acmicpc.net/problem/27939
#include <iostream>

using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;

	char kind[1'001];
	for (int i = 1; i <= n; i++)
		cin >> kind[i];

	int m, k;
	cin >> m >> k;

	bool canBeWhite = false;
	for (int i = 0; i < m; i++) {
		bool isAllWhite = true;
		for (int j = 0; j < k; j++) {
			int idx;
			cin >> idx;

			if (kind[idx] == 'P')
				isAllWhite = false;
		}

		if (isAllWhite)
			canBeWhite = true;
	}

	cout << (canBeWhite ? 'W' : 'P') << '\n';

	return 0;
}