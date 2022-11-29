// Baekjoon02961.cpp
// https://www.acmicpc.net/problem/2961
#include <iostream>

using namespace std;

using ll = long long;
using pii = pair<ll, ll>;

int n;
ll ans = 0x3f3f3f3f3f3f3f3f;
pii ingredient[10];

ll min(ll a, ll b) { return (b < a) ? b : a; }
ll absolute(ll a) { return (a > 0) ? a : -a; }

void solve(int curr, pii cook, int selected) {
	if (curr == n) {
		if (selected > 0)
			ans = min(ans, abs(cook.first - cook.second));
	} else {
		solve(curr + 1, { cook.first * ingredient[curr].first, cook.second + ingredient[curr].second }, selected + 1);
		solve(curr + 1, cook, selected);
	}
}

int main(void) {
	cin >> n;

	for (int i = 0; i < n; i++)
		cin >> ingredient[i].first >> ingredient[i].second;

	solve(0, { 1, 0 }, 0);

	cout << ans << '\n';

	return 0;
}