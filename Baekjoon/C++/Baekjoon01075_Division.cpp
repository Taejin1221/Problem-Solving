// Baekjoon01075_Division.cpp
// https://www.acmicpc.net/problem/1075
#include <iostream>

using namespace std;

int main(void) {
	int n, f;
	cin >> n >> f;

	int front = n / 100, ans = 0;
	while ( ans < 100 ) {
		if ( ( front * 100 + ans ) % f == 0 )
			break;
		ans++;
	}

	if ( ans < 10 )
		cout << '0' << ans;
	else
		cout << ans;
	cout << '\n';

	return 0;
}
