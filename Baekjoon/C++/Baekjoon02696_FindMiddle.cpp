// Baekjoon02696_FindMiddle.cpp
// https://www.acmicpc.net/problem/2696
#include <iostream>

#include <queue>
#include <climits>

using namespace std;

void Solve() {
	int n;
	cin >> n;

	priority_queue<int> smallNums;
	priority_queue<int, vector<int>, greater<int>> bigNums;

	smallNums.push( INT_MIN );
	bigNums.push( INT_MAX );

	int midNums[5'000], midIdx = 0;
	for ( int i = 1; i <= n; i++ ) {
		int curr;
		cin >> curr;

		if ( bigNums.top() < curr )
			bigNums.push( curr );
		else
			smallNums.push( curr );

		if ( bigNums.size() > smallNums.size() ) {
			smallNums.push( bigNums.top() );
			bigNums.pop();
		} else if ( smallNums.size() - bigNums.size() > 2 ) {
			bigNums.push( smallNums.top() );
			smallNums.pop();
		}

		if ( i % 2 )
			midNums[midIdx++] = smallNums.top();
	}

	cout << midIdx << '\n';
	for ( int i = 1; i <= midIdx; i++ ) {
		cout << midNums[i - 1] << ' ';
		if ( i % 10 == 0 )
			cout << '\n';
	}
	cout << '\n';
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int t;
	cin >> t;

	while ( t-- ) {
		Solve();
	}

	return 0;
}