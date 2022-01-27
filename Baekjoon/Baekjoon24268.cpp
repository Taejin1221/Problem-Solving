// Baekjoon24268.cpp
// https://www.acmicpc.net/problem/24268
#include <iostream>

#include <vector>

using namespace std;

using ll = long long;

int n, d;
bool visited[10];
vector<int> nums;

ll myPow(int x, int y) {
	ll result = 1LL;
	for (int i = 0; i < y; i++)
		result *= x;

	return result;
}

ll evaluate() {
	ll result = 0LL;
	for (int i = d - 1; i >= 0; i--) {
		result += nums[i] * myPow(d, d - i - 1);
	}

	return result;
}

bool backtracking() {
	if (nums.size() == d) {
		if (nums[0] != 0 && evaluate() > n)
			return true;
	} else {
		for (int i = 0; i < d; i++) {
			if (!visited[i]) {
				visited[i] = true;
				nums.push_back(i);
				if (backtracking())
					return true;
				visited[i] = false;
				nums.pop_back();
			}
		}
	}

	return false;
}

int main(void) {
	cin >> n >> d;

	if (backtracking())
		cout << evaluate();
	else
		cout << -1;
	cout << '\n';

	return 0;
}