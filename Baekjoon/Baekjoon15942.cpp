// Baekjoon15942_ThinkingHeap.cpp
// https://www.acmicpc.net/problem/15942
#include <iostream>
#include <queue> /* queue */
#include <cmath> /* floor(), log2() */

#define MAX_ARR_SIZE 200'001

using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int n, k, p;
	cin >> n >> k >> p;

	int parents = (int)floor( log2( p ) );
	int childs = -1;

	bool table[MAX_ARR_SIZE] = { false, };

	int arr[MAX_ARR_SIZE] = { 0, };
	arr[p] = k;
	table[k] = true;

	int next = k + 1;
	queue<int> q; q.push( p );
	while ( !q.empty() ) {
		int curr = q.front(); q.pop();
		childs++;

		int left = curr * 2, right = curr * 2 + 1;
		if ( left <= n ) {
			q.push( left );
			arr[left] = next;
			table[next++] = true;
		}

		if ( right <= n ) {
			q.push( right );
			arr[right] = next;
			table[next++] = true;
		}
	}

	if ( parents < k && childs <= (n - k) ) {
		int idx = p / 2;
		for ( int i = parents; i >= 1; i-- ) {
			arr[idx] = i;
			table[i] = true;
			idx /= 2;
		}

		int prev = 1;
		for ( int i = 1; i <= n; i++ ) {
			while ( prev <= n && table[prev] )
				prev++;

			if ( prev > n )
				break;

			if ( arr[i] == 0 )
				arr[i] = prev++;
		}

		for ( int i = 1; i <= n; i++ )
			cout << arr[i] << '\n';
	} else
		cout << -1 << '\n';

	return 0;
}