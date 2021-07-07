// Baekjoon10266_ClockPictures.cpp
// https://www.acmicpc.net/problem/10266
#include <iostream>

#define POSSIBLE "possible"
#define IMPOSSIBLE "impossible"
#define endl '\n'

using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;

	int num1[720'000] = { 0, }, num2[360'000] = { 0, };
	for ( int i = 0; i < n; i++ ) {
		int temp;
		cin >> temp;

		num1[temp] = 1;
		num1[temp + 360'000] = 1;
	}

	for ( int i = 0; i < n; i++ ) {
		int temp;
		cin >> temp;

		num2[temp] = 1;
	}

	int fail[360'000] = { 0, };
	for ( int i = 1, j = 0; i < 360'000; i++ ) {
		while ( j > 0 && num2[i] != num2[j] )
			j = fail[j - 1];

		if ( num2[i] == num2[j] )
			fail[i] = ++j;
	}

	bool possible = false;
	for ( int i = 0, j = 0; i < 720'000; i++ ) {
		while ( j > 0 && num1[i] != num2[j] )
			j = fail[j - 1];

		if ( num1[i] == num2[j] ) {
			if ( j == 360'000 - 1 ) {
				possible = true;
				break;
			} else
				j++;
		}
	}

	if (possible)
		cout << POSSIBLE << endl;
	else
		cout << IMPOSSIBLE << endl;

	return 0;
}