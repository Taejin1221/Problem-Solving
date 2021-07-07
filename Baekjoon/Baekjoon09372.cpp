// Baekjoon09372_FlyingSafely.cpp
// https://www.acmicpc.net/problem/9372
#include <iostream>

using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int t;
	cin >> t;
	while (t--) {
		int n, m;
		cin >> n >> m;

		int a, b;
		while (m--)
			cin >> a >> b;

		cout << n - 1 << '\n';
	}

	return 0;
}