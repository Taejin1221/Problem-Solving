// Baekjoon14003_LIS5.cpp
// https://www.acmicpc.net/problem/14003
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

	int indexes[1'000'000];
	vector<int> lis;
	for ( int i = 0; i < n; i++ ) {
		int idx = lower_bound( lis.begin(), lis.end(), arr[i] ) - lis.begin();
		if ( idx == lis.size() )
			lis.push_back( arr[i] );
		else
			lis[idx] = arr[i];
		indexes[i] = idx;
	}

	int lisSize = lis.size();

	int findIdx = lisSize - 1;
	vector<int> ans ( lisSize );
	for ( int i = n - 1; i >= 0; i-- )
		if ( indexes[i] == findIdx )
			ans[findIdx--] = arr[i];

	cout << lisSize << '\n';
	for ( int i = 0; i < lisSize; i++ )
		cout << ans[i] << ' ';
	cout << '\n';

	return 0;
}