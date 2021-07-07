// Baekjoon09656_StoneGameII.cpp
// https://www.acmicpc.net/problem/9656
#include <iostream>

using namespace std;

int main(void) {
	int n;
	cin >> n;

	if ( n % 2 == 0 )
		cout << "SK";
	else
		cout << "CY";
	cout << '\n';

	return 0;
}
