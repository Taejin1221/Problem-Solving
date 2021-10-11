// Codeforces_.cpp
#include <iostream>

using namespace std;

typedef long long ll;

void solveTestCase() {
	ll n;
	cin >> n;

	cout << -(n - 1) << ' ' << n << '\n';
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
