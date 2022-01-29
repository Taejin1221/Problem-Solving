// Baekjoon17869.cpp
// https://www.acmicpc.net/problem/17869
#include <iostream>

using namespace std;

int main(void) {
	long long n;
	cin >> n;

	int ans = 0;
	while (n != 1) {
		if (n % 2)
			n += 1;
		else
			n /= 2;

		ans++;
	}

	cout << ans << '\n';

	return 0;
}
