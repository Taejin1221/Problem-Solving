// Baekjoon03273_SumOfTwoNumber.cpp
// https://www.acmicpc.net/problem/3273
#include <iostream>

#include <algorithm>

using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;

	int arr[100'000];
	for ( int i = 0; i < n; i++ )
		cin >> arr[i];
	sort( arr, arr + n );

	int x;
	cin >> x;

	int ans = 0;
	int i = 0, j = n - 1;
	while ( i < j ) {
		if ( arr[i] + arr[j] > x )
			j--;
		else if ( arr[i] + arr[j] < x )
			i++;
		else
			ans++, i++;
	}

	cout << ans << '\n';

	return 0;
}