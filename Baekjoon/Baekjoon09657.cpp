// Baekjoon09657_StoneGame3.cpp
// https://www.acmicpc.net/problem/9657
#include <iostream>

using namespace std;

int main(void) {
	int n;
	cin >> n;

	bool canWin[1'001] = { true, true, false, true, true, };
	for ( int i = 5; i <= n; i++ )
		canWin[i] = !( canWin[i - 1] && canWin[i - 3] && canWin[i - 4] );

	if ( canWin[n] )
		cout << "SK";
	else
		cout << "CY";
	cout << '\n';

	return 0;
}