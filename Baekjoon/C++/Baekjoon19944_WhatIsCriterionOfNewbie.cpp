// Baekjoon19944_WhatIsCriterionOfNewbie.cpp
// https://www.acmicpc.net/problem/19944
#include <iostream>

using namespace std;

int main(void) {
	int n, m;
	cin >> n >> m;

	if ( m <= 2 )
		cout << "NEWBIE!";
	else if ( m <= n )
		cout << "OLDBIE!";
	else
		cout << "TLE!";
	cout << '\n';

	return 0;
}