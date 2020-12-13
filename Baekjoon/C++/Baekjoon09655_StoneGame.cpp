// Baekjoon09655_StoneGame.cpp
// https://www.acmicpc.net/problem/9655
#include <iostream>

using namespace std;

int main(void) {
	int n;
	cin >> n;

	if ( n % 2 )
		cout << "SK";
	else
		cout << "CY";
	cout << '\n';

	return 0;
}
