// Baekjoon02623_MusicProgram.cpp
// https://www.acmicpc.net/problem/2623

/* Review
 * Date
 01/09/2021

 * Comment
 기본적인 위상정렬 문제이며, 위상정렬 할 수 있을 땐 위상정렬을 출력, 없을 땐 0을 출력하는 문제이다. 

 * Solution
 1. 가수들의 순서를 선발 가수가 후발 가수를 가리키는 유향 그래프로 만든다.
 2. 위상정렬을 수행한다.
 3. 위상정렬을 할 수 있으면 결과를 출력, 없으면 0을 출력한다.
*/

#include <iostream>

#include <queue>
#include <vector>

using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int n, m;
	cin >> n >> m;

	vector<int> adjList[1'001];
	int indegree[1'001] = { 0, };
	for ( int i = 0; i < m; i++ ) {
		int t;
		cin >> t;

		int a, b;
		cin >> a; t--;
		while ( t-- ) {
			cin >> b;

			adjList[a].push_back( b );
			indegree[b]++;

			a = b;
		}
	}

	queue<int> q;
	for ( int i = 1; i <= n; i++ )
		if ( !indegree[i] )
			q.push( i );

	vector<int> topol;
	while ( !q.empty() ) {
		int curr = q.front(); q.pop();
		topol.push_back( curr );

		for ( int& adjV : adjList[curr] ) {
			if ( --indegree[adjV] == 0 )
				q.push( adjV );
		}
	}

	if ( topol.size() != n )
		cout << 0 << '\n';
	else {
		for ( int& value : topol )
			cout << value << '\n';
	}

	return 0;
}