// Baekjoon17224.cpp
// https://www.acmicpc.net/problem/17224
#include <iostream>

using namespace std;

using pii = pair<int, int>;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n, l, k;
	cin >> n >> l >> k;

	int solveEasy = 0, solveHard = 0;
	for (int i = 0; i < n; i++) {
		int easy, hard;
		cin >> easy >> hard;

		if (easy <= l)
			solveEasy++;

		if (hard <= l)
			solveHard++;
	}

	int ans = 100 * min(solveEasy, k);
	ans += 40 * min(solveHard, k);

	cout << ans << '\n';

	return 0;
}
