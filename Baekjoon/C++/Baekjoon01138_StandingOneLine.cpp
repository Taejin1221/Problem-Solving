// Baekjoon01138_StandingOneLine.cpp
// https://www.acmicpc.net/problem/1138
#include <iostream>
#include <vector>

using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int n;
	cin >> n;

	int arr[10];
	for ( int i = 0; i < n; i++ )
		cin >> arr[i];

	vector<int> ans;
	ans.push_back( n );

	for ( int i = n - 2; i >= 0; i-- )
		ans.insert( ans.begin() + arr[i], i + 1 );

	for ( int i = 0; i < n; i++ )
		cout << ans[i] << ' ';
	cout << '\n';

	return 0;
}
