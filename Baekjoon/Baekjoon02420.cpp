// Baekjoon02420_SafariWorld.cpp
// https://www.acmicpc.net/problem/2420
#include <iostream>

using namespace std;

int main(void) {
	long long n, m;
	cin >> n >> m;

	long long ans;
	if ( n < m )
		ans = m - n;
	else
		ans = n - m;

	cout << ans;

	return 0;
}