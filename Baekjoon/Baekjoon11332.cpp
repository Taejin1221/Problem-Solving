// Baekjoon11332.cpp
// https://www.acmicpc.net/problem/11332
#include <iostream>

#include <string>

using namespace std;

typedef long long ll;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	const ll second = 100'000'000LL;
	const string YES = "May Pass.";
	const string NO = "TLE!";

	int c;
	cin >> c;
	while (c--) {
		string timeComplexity;
		cin >> timeComplexity;

		ll n, t, l;
		cin >> n >> t >> l;

		if (timeComplexity == "O(N)") {
			if (n * t <= second * l)
				cout << YES;
			else
				cout << NO;
		} else if (timeComplexity == "O(N^2)") {
			if (n * n * t <= second * l)
				cout << YES;
			else
				cout << NO;
		} else if (timeComplexity == "O(N^3)") {
			if (n >= 100'000LL)
				cout << NO;
			else {
				if (n * n * n * t <= second * l)
					cout << YES;
				else
					cout << NO;
			}
		} else if (timeComplexity == "O(2^N)") {
			if (n > 30)
				cout << NO;
			else {
				ll totalN = (1LL << n);
				if (totalN * t <= second * l)
					cout << YES;
				else
					cout << NO;
			}
		} else if (timeComplexity == "O(N!)") {
			if (n > 13)
				cout << NO;
			else {
				ll totalN = 1LL;
				for (ll i = 1; i <= n; i++)
					totalN *= i;

				if (totalN * t <= second * l)
					cout << YES;
				else
					cout << NO;
			}
		}

		cout << '\n';
	}

	return 0;
}