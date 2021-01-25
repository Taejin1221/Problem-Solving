// Baekjoon12015_LIS2.cpp
// https://www.acmicpc.net/problem/12015
#include <iostream>

#include <vector>
#include <algorithm>

using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;

	int arr[1'000'000];
	for ( int i = 0; i < n; i++ )
		cin >> arr[i];

	vector<int> lis;
	for ( int i = 0; i < n; i++ ) {
		auto idx = lower_bound( lis.begin(), lis.end(), arr[i] );
		if ( idx == lis.end() )
			lis.push_back( arr[i] );
		else
			*idx = arr[i];
	}

	cout << lis.size() << '\n';

	return 0;
}