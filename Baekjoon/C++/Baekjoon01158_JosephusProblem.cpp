// Baekjoon01158_JosephusProblem.cpp
// https://www.acmicpc.net/problem/1158
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int n, k;
	cin >> n >> k;

	queue<int> q;
	for ( int i = 1; i <= n; i++ )
		q.push( i );

	vector<int> joseph;
	for ( int i = 0; i < n; i++ ) {
		for ( int j = 0; j < k - 1; j++ ) {
			q.push( q.front() );
			q.pop();
		}

		joseph.push_back( q.front() );
		q.pop();
	}

	cout << "<";
	for ( int i = 0; i < n; i++ ) {
		cout << joseph[i];
		if ( i != n - 1 )
			cout << ", ";
	}
	cout << ">\n";

	return 0;
}
