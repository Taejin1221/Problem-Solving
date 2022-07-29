// Baekjoon05523.cpp
// https://www.acmicpc.net/problem/5523
#include <iostream>

using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;

	int a = 0, b = 0;
	for (int i = 0; i < n; i++) {
		int s1, s2;
		cin >> s1 >> s2;

		if (s1 > s2)
			a++;
		else if (s1 < s2)
			b++;
	}

	cout << a << ' ' << b << '\n';

	return 0;
}