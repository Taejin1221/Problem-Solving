// Baekjoon01305_Advertisement.cpp
// https://www.acmicpc.net/problem/1305
#include <iostream>
#include <string>

using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;

	string str;
	cin >> str;

	int fail[1'000'000] = { 0, };
	for ( int i = 1, j = 0; i < n; i++ ) {
		while ( j > 0 && str[i] != str[j] )
			j = fail[j - 1];

		if ( str[i] == str[j] )
			fail[i] = ++j;
	}

	cout << n - fail[n - 1] << '\n';

	return 0;
}
