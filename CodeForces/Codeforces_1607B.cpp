// Codeforces_1607B.cpp
#include <iostream>

using namespace std;

typedef long long ll;

void solveTestCase() {
	ll start, endTime;
	cin >> start >> endTime;

	ll quot = endTime / 4;

	ll ans = start;
	for (ll i = quot * 4 + 1; i <= endTime; i++) {
		if (ans % 2)
			ans += i;
		else
			ans -= i;
	}

	cout << ans << '\n';

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
