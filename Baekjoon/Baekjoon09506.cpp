// Baekjoon09506.cpp
// https://www.acmicpc.net/problem/9506
#include <iostream>

#include <vector>

using namespace std;

void solve(int n) {
	int sum = 0;
	vector<int> divisors;
	for (int i = 1; i < n; i++) {
		if (n % i == 0) {
			divisors.push_back(i);
			sum += i;
		}
	}

	if (sum == n) {
		cout << n << " = ";
		for (int i = 0; i < divisors.size() - 1; i++)
			cout << divisors[i] << " + ";
		cout << divisors.back();
	} else {
		cout << n << " is NOT perfect.";
	}

	cout << '\n';
}

int main(void) {
	int n;
	cin >> n;

	while (n != -1) {
		solve(n);

		cin >> n;
	}

	return 0;
}