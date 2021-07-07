// Baekjoon01766_Workbook.cpp
// https://www.acmicpc.net/problem/1766
#include <iostream>

#include <queue>
#include <vector>

#define SIZE 32'001

using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int n, m;
	cin >> n >> m;

	int indegree[SIZE] = { 0, };

	vector<int> adjList[SIZE];
	for ( int i = 0; i < m; i++ ) {
		int a, b;
		cin >> a >> b;

		adjList[a].push_back( b );
		indegree[b]++;
	}

	priority_queue<int, vector<int>, greater<int>> pq;
	for ( int i = 1; i <= n; i++ )
		if ( !indegree[i] )
			pq.push( i );

	while ( !pq.empty() ) {
		int curr = pq.top(); pq.pop();
		cout << curr << ' ';

		for ( const int& adj : adjList[curr] ) {
			if ( --indegree[adj] == 0 )
				pq.push( adj );
		}
	}

	cout << '\n';

	return 0;
}