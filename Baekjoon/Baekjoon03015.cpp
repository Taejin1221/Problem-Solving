// Baekjoon03015.cpp
#include <iostream>

#include <stack>

#define MAX 500'000

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;

	ll ans = 0ll;
	stack<pii> stck;

	int temp;
	cin >> temp;
	stck.push({ temp, 1 });

	for (int i = 1; i < n; i++) {
		int curr, currAcc = 1;
		cin >> curr;

		while (!stck.empty() && stck.top().first <= curr) {
			pii top = stck.top();

			ans += (ll)top.second; // {top, curr} 쌍으로 본경우
			if (top.first == curr)
				currAcc += top.second;
			stck.pop();

			if (!stck.empty())
				ans++; // {stck[-2], stck[-1]} 쌍으로 본경우
		}
		stck.push({ curr, currAcc });
	}

	ans += (ll)stck.size() - 1;

	cout << ans << '\n';

	return 0;
}