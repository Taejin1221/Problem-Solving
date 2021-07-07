// Baekjoon01422_GodOfNumber.cpp
// https://www.acmicpc.net/problem/1422
#include <algorithm> /* sort() */
#include <iostream>
#include <string> /* string */

using namespace std;

bool Compare( const string& str1, const string& str2 ) {
	string a = str1 + str2;
	string b = str2 + str1;

	if ( a > b )
		return true;
	else
		return false;
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int k, n;
	cin >> k >> n;

	string nums[1000];

	for ( int i = 0; i < k; i++ )
		cin >> nums[i];

	string maxVal = "";

	sort( nums, nums + k, Compare );

	int idx = 0;
	for ( int i = 0; i < k; i++ )
		if ( nums[idx].size() < nums[i].size() )
			idx = i;

	for ( int i = 0; i < k; i++ ) {
		if ( i == idx ) {
			while ( k < n ) {
				maxVal += nums[i];
				n--;
			}
		}
		maxVal += nums[i];
	}

	cout << maxVal << '\n';

	return 0;
}

