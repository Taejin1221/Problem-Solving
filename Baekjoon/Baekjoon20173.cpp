// Baekjoon20173.cpp
// https://www.acmicpc.net/problem/20173
#include <iostream>

using namespace std;

using pii = pair<int, int>;

pii getIndegree(int direction, bool isPrev) {
	if (isPrev) {
		if (direction == 0)
			direction = 3;
		else if (direction == 1)
			direction = 2;
		else if (direction == 2)
			direction = 1;
		else
			direction = 0;
	}

	pii result;
	if (direction == 0)
		result = { 0, 0 };
	else if (direction == 1)
		result = { 0, 1 };
	else if (direction == 2)
		result = { 1, 0 };
	else
		result = { 1, 1 };

	return result;
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;

	int diff[1'000'000];
	for (int i = 0; i < n; i++)
		cin >> diff[i];

	bool dp[4][1'000'000] = { false, };
	if (diff[0] == 1) {
		dp[0][0] = false;
		dp[1][0] = true;
		dp[2][0] = true;
		dp[3][0] = false;
	} else if (diff[0] == 0) {
		dp[0][0] = true;
		dp[1][0] = false;
		dp[2][0] = false;
		dp[3][0] = true;
	}

	for (int i = 1; i < n - 1; i++) {
		for (int j = 0; j < 4; j++) {
			pii curr = getIndegree(j, false);
			for (int k = 0; k < 4; k++) {
				if (dp[k][i - 1]) {
					pii prev = getIndegree(k, true);
					if (abs((curr.first + prev.first) - (curr.second + prev.second)) == diff[i])
						dp[j][i] = true;
				}
			}
		}
	}

	bool ans = false;
	if (diff[n - 1] == 0) {
		if (dp[0][n - 2] || dp[3][n - 2])
			ans = true;
	} else if (diff[n - 1] == 1) {
		if (dp[1][n - 2] || dp[2][n - 2])
			ans = true;
	}

	if (ans)
		cout << "YES";
	else
		cout << "NO";
	cout << '\n';

	return 0;
}