// Baekjoon15688_Sort5.cpp
// https://www.acmicpc.net/problem/15688
#include <iostream>
#include <algorithm>

using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int n;
	cin >> n;

	int arr[1'000'000];
	for ( int i = 0; i < n; i++ )
		cin >> arr[i];

	sort( arr, arr + n );

	for ( int i = 0; i < n; i++ )
		cout << arr[i] << '\n';

	return 0;
}
