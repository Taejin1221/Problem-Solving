// Baekjoon06198_DecorateRooftopGarden.cpp
// https://www.acmicpc.net/problem/6198
#include <iostream>

#include <vector>

using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;

	int arr[80'000];
	for ( int i = n - 1; i >= 0; i-- )
		cin >> arr[i];

	long ans = 0l;
	vector<pair<int, long>> stck;
	for ( int i = 0; i < n; i++ ) {
		long currLower = 0l;
		while ( !stck.empty() && stck.back().first < arr[i] ) {
			currLower += stck.back().second + 1l;
			stck.pop_back();
		}

		ans += currLower;
		stck.push_back( { arr[i], currLower } );
	}

	cout << ans << '\n';

	return 0;
}