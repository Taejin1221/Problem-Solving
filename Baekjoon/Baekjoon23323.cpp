// Hongik_D.cpp
#include <iostream>

using namespace std;

typedef long long ll;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int t;
	cin >> t;
	while (t--) {
		ll n, m;
		cin >> n >> m;

		ll ans = 0;
		while (n > 1)
			n /= 2, ans++;

		ans += m + 1;

		cout << ans << '\n';
	}

	return 0;
}