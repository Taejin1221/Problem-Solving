// Baekjoon10833_Apple.cpp
// https://www.acmicpc.net/problem/10833
#include <iostream>

using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;

	int restApple = 0;
	for ( int i = 0; i < n; i++ ) {
		int a, b;
		cin >> a >> b;

		restApple += b % a;
	}

	cout << restApple << '\n';

	return 0;
}