// Hongik_F.cpp
#include <iostream>

#include <string>
#include <algorithm>

#define INF 0x3f3f3f3f

using namespace std;

int main(void) {
	string str;
	cin >> str;

	int n = str.size();
	if (n == 1) {
		cout << (str[0] == '+' ? 10 : 1) << '\n';

		return 0;
	}

	bool isNotValid[200'001] = { false, };
	int dp[200'001];
	fill(dp, dp + n, -INF);

	dp[0] = str[0] == '+' ? 10 : 1;
	if (str[0] == '+' && str[1] == '-')
		dp[1] = 11;
	else {
		dp[1] = 0;
		isNotValid[1] = true;
	}

	for (int i = 2; i < n; i++) {
		int str_i = str[i] == '+' ? 10 : 1;
		bool tempValid = false;
		if (isNotValid[i - 2] == true) {
			tempValid = true;
		} else {
			if (str[i - 1] == '+')
				dp[i] = dp[i - 2] + str_i;
			else
				dp[i] = dp[i - 2] - str_i;
		}

		if (i > 2 && str[i - 1] == '+' && str[i] == '-') {
			if (isNotValid[i - 3] == true && tempValid == true) {
				isNotValid[i] = true;
			} else if (isNotValid[i - 3] == false) {
				int str_i = 11;
				if (str[i - 2] == '+')
					dp[i] = max(dp[i], dp[i - 3] + str_i);
				else
					dp[i] = max(dp[i], dp[i - 3] - str_i);
			}
		}
	}

	cout << dp[n - 1] << '\n';

	return 0;
}