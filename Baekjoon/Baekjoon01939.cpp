// Baekjoon01939_WeightLimit.cpp
// https://www.acmicpc.net/problem/1939
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int start, target;
vector<pair<int, int>> adjList[10001];

bool BFS( int mid ) {
	bool visited[10001] = { false, };

	queue<int> q; q.push( start );
	visited[start] = true;
	while ( !q.empty() ) {
		int curr = q.front(); q.pop();
		if ( curr == target )
			return true;

		for ( int i = 0; i < adjList[curr].size(); i++ ) {
			if ( !visited[adjList[curr][i].first] ) {
				if ( adjList[curr][i].second >= mid ) {
					visited[adjList[curr][i].first] = true;
					q.push( adjList[curr][i].first );
				}
			}
		}
	}

	return false;
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n, m;
	cin >> n >> m;

	int min = 1000000000, max = 0;
	for ( int i = 0; i < m; i++ ) {
		int a, b, c;
		cin >> a >> b >> c;
		adjList[a].push_back( pair<int, int> ( b, c ) );
		adjList[b].push_back( pair<int, int> ( a, c ) );

		min = ( c < min ) ? c : min;
		max = ( c > max ) ? c : max;
	}

	cin >> start >> target;

	int ans;
	int left = min, right = max;
	while ( left <= right ) {
		int mid = ( left + right ) / 2;
		if ( BFS( mid ) ) {
			ans = mid;
			left = mid + 1;
		} else
			right = mid - 1;
	}

	cout << ans << '\n';

	return 0;
}