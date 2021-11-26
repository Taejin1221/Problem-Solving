// Codeforces_1614B.cpp
#include <iostream>

#include <vector>
#include <algorithm>

using namespace std;

using ll = long long;
using pii = pair<int, int>;

void solveTestCase() {
	int n;
	cin >> n;

	vector<pii> arr(n);
	for (int i = 0; i < n; i++) {
		cin >> arr[i].first;
		arr[i].second = i;
	}
	sort(arr.begin(), arr.end(), greater<pii>());

	int currPosition = 1;
	ll sum = 0LL;
	vector<pii> ans(n);
	for (int i = 0; i < n; i += 2) {
		sum += (ll)arr[i].first * currPosition;
		ans[i].first = arr[i].second;
		ans[i].second = currPosition;

		if (i < n - 1) {
			sum += (ll)arr[i + 1].first * currPosition;
			ans[i + 1].first = arr[i + 1].second;
			ans[i + 1].second = -currPosition;
		}
		currPosition++;
	}

	sort(ans.begin(), ans.end());

	cout << sum * 2 << '\n' << 0 << ' ';
	for (int i = 0; i < n; i++)
		cout << ans[i].second << ' ';
	cout << '\n';
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int t;
	cin >> t;
	while (t--) {
		solveTestCase();
	}

	return 0;
}
