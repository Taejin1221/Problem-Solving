// Baekjoon01422_GodOfNumber.cpp
// https://www.acmicpc.net/problem/1422
#include <algorithm> /* sort() */
#include <iostream>
#include <string> /* string */

using namespace std;

bool Compare( string str1, string str2 ) {
	if ( str1.compare( str2 ) >= 0 )
		return true;
	else
		return false;
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n, m;
	cin >> n >> m;

	string nums[1000];

	for ( int i = 0; i < n; i++ )
		cin >> nums[i];

	sort( nums, nums + n, Compare );

	string maxVal = "";
	while ( m > n ) {
		maxVal += nums[0];
		m--;
	}

	for ( int i = 0; i < n; i++ ) {
		maxVal += nums[i];
	}

	cout << maxVal << '\n';

	return 0;
}

