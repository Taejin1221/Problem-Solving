// Baekjoon02010_Plug.cpp
// https://www.acmicpc.net/problem/2010
#include <iostream>

using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;

	int sum = 0;
	for ( int i = 0; i < n; i++ ) {
		int temp;
		cin >> temp;

		sum += temp;
	}

	int ans = sum - n + 1;

	cout << ans << '\n';

	return 0;
}