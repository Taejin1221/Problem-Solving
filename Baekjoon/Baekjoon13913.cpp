// Baekjoon13913_HideAndSeek4.cpp
// https://www.acmicpc.net/problem/13913
#include <iostream>

#include <queue>
#include <vector>
#include <algorithm>

#define MAX 200'000

using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int n, k;
	cin >> n >> k;

	bool visited[MAX] = { false, };
	int path[MAX];
	fill( path, path + MAX, -1 );

	queue<pair<int, int>> q;

	pair<int, int> ans;
	q.push( { n, 0 } );
	visited[n] = true;
	while ( !q.empty() ) {
		pair<int, int> curr = q.front(); q.pop();
		if ( curr.first == k ) {
			ans = curr;
			break;
		}

		int nextTime = curr.second + 1;
		int nexts[3] = { curr.first + 1, curr.first - 1, curr.first * 2 };
		for ( int i = 0; i < 3; i++ ) {
			int next = nexts[i];
			if ( 0 <= next && next < MAX ) {
				if ( !visited[next] ) {
					visited[next] = true;
					path[next] = curr.first;
					q.push( { next, nextTime } );
				}
			}
		}
	}

	cout << ans.second << '\n';

	vector<int> ansPath;

	int curr = ans.first;
	while ( curr != -1 ) {
		ansPath.push_back( curr );
		curr = path[curr];
	}

	cout << n << ' ';
	for ( int i = ans.second - 1; i >= 0; i-- )
		cout << ansPath[i] << ' ';
	cout << '\n';

	return 0;
}