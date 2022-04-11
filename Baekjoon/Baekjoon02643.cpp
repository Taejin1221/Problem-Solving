// Baekjoon02643.cpp
// https://www.acmicpc.net/problem/2643
#include <iostream>

#include <algorithm>

using namespace std;

using pii = pair<int, int>;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;

	pii papers[100];
	for (int i = 0; i < n; i++) {
		cin >> papers[i].first >> papers[i].second;
		if (papers[i].first > papers[i].second) {
			int temp = papers[i].first;
			papers[i].first = papers[i].second;
			papers[i].second = temp;
		}
	}

	sort(papers, papers + n);

	int dp[100] = { 0, };
	dp[n - 1] = 1;

	int ans = 1;
	for (int i = n - 2; i >= 0; i--) {
		for (int j = i + 1; j < n 
		; j++) {
			if ((papers[i].first <= papers[j].first && papers[i].second <= papers[j].second) || (papers[i].first <= papers[j].second && papers[i].second <= papers[j].first)) {
				dp[i] = max(dp[i], dp[j]);
			}
		}

		dp[i] += 1;

		ans = max(ans, dp[i]);
	}

	cout << ans << '\n';

	return 0;
}
