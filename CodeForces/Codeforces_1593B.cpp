// Codeforces_1593B.cpp
#include <iostream>

#include <string>

using namespace std;

typedef long long ll;

int find(string& str, int idx, int target) {
	int ans = 0;
	for (int i = idx - 1; i >= 0; i--) {
		if (str[i] == target + '0')
			return ans;
		ans++;
	}
	return -1;
}

void solveTestCase( ) {
	ll n;
	cin >> n;

	if (n % 25 == 0)
		cout << 0;
	else {
		int ans = 20, basic = 0;
		string str = to_string(n);
		for (int i = str.size() - 1; i >= 0; i--, basic++) {
			if (str[i] == '5') {
				int two = find(str, i, 2);
				int seven = find(str, i, 7);

				if (two != -1)
					ans = min(ans, two + basic);
				
				if (seven != -1)
					ans = min(ans, seven + basic);

			} else if (str[i] == '0') {
				int zero = find(str, i, 0);
				int five = find(str, i, 5);

				if (zero != -1)
					ans = min(ans, zero + basic);
				
				if (five != -1)
					ans = min(ans, five + basic);
			}
		}

		cout << ans;
	}

	cout << '\n';
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int t;
	cin >> t;
	while ( t-- ) {
		solveTestCase( );
	}

	return 0;
}
