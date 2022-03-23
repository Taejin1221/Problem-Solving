// Baekjoon24416.cpp
// https://www.acmicpc.net/problem/24416
#include <iostream>

using namespace std;

using ll = long long;

int main(){
	int n;
	cin >> n;

	ll dp[41] = { 0, 1, 1, };
	for (int i = 3; i <= n; i++)
		dp[i] = dp[i - 1] + dp[i - 2];

	cout << dp[n] << ' ' << n - 2 << '\n';

	return 0;
}
