// Baekjoon13703.cpp
// https://www.acmicpc.net/problem/13703
#include <iostream>

#include <algorithm>

using namespace std;

using ll = long long;

ll n, k, dp[200][64];

ll solve(int depth, int time) {
	if (time == n)
		dp[depth][time] = depth == 0;

	if (depth == 0)
		dp[depth][time] = (1LL << (n - time));

	if (dp[depth][time] == -1) {
		ll result = solve(depth - 1, time + 1);
		result += solve(depth + 1, time + 1);

		dp[depth][time] = result;
	}

	return dp[depth][time];
}

int main(void) {
	cin >> k >> n;

	for (int i = 0; i < 200; i++)
		fill(dp[i], dp[i] + n + 1, -1);

	cout << ((1LL << n) - solve(k, 0)) << '\n';

	return 0;
}