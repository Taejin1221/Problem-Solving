// Baekjoon01380.cpp
// https://www.acmicpc.net/problem/1380
#include <iostream>

#include <string>

using namespace std;

void solve(int n) {
	string name[100];
	for (int i = 0; i < n; i++)
		getline(cin, name[i]);

	bool isFind[100] = { false, };
	for (int i = 0; i < 2 * n - 1; i++) {
		int num; char _;
		cin >> num >> _;

		num--;
		isFind[num] = !isFind[num];
	}

	for (int i = 0; i < n; i++) {
		if (isFind[i]) {
			cout << name[i] << '\n';
			return;
		}
	}
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int n;
	cin >> n;
	for (int time = 1; n; time++) {
		cin.ignore();
		cout << time << ' ';
		solve(n);

		cin >> n;
	}

	return 0;
}