// Baekjoon20047.cpp
// https://www.acmicpc.net/problem/20047
#include <iostream>

#define SIZE 10'001

using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;

	char strS[SIZE], strT[SIZE];
	cin >> strS >> strT;

	int c1Idx, c2Idx;
	cin >> c1Idx >> c2Idx;

	char coin1 = strS[c1Idx], coin2 = strS[c2Idx];

	char s1[SIZE] = { 0, }, s2[SIZE] = { 0, }, s3[SIZE] = { 0, };

	int s1Idx = 0, s2Idx = 1, s3Idx = 2;
	for (int i = 0; i < n; i++) {
		if (i != c1Idx && i != c2Idx)
			s1[s1Idx++] = strS[i], s2[s2Idx++] = strS[i], s3[s3Idx++] = strS[i];
	}

	bool dp[2][SIZE];
	dp[0][n - 1] = (s3[n - 1] == strT[n - 1]);
	dp[1][n - 1] = (coin2 == strT[n - 1]);
	for (int i = n - 2; i > 0; i--) {
		dp[0][i] = dp[0][i + 1] & (strT[i] == s3[i]);
		dp[1][i] = ((strT[i] == coin2) & dp[0][i + 1]) | ((strT[i] == s2[i]) & dp[1][i + 1]);
	}

	bool ans = false;
	bool prefix = (strT[0] == s1[0]);
	for (int i = 1; i <= n - 1; i++) {
		if (coin1 == strT[i]) {
			if (prefix & dp[1][i + 1]) {
				ans = true;
				break;
			}
		}

		prefix = prefix & (s1[i] == strT[i]);
	}

	if (ans || ((strT[0] == coin1) & dp[1][1]))
		cout << "YES";
	else
		cout << "NO";
	cout << '\n';

	return 0;
}