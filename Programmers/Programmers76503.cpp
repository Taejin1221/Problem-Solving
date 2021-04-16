// Programmers76503.cpp
// https://programmers.co.kr/learn/courses/30/lessons/76503
// Programmers Monthly Programming Challenge 2 (April) Prob 3
#include <queue>
#include <vector>

#define MAX 300'000
#define ABS( x ) ( ( x ) > 0 ) ? ( x ) : ( -( x ) )

using namespace std;

typedef long long ll;

ll solution( vector<int> a, vector<vector<int>> edges ) {
	ll ans = 0ll;

	int n = a.size();

	int degree[MAX] = { 0, };
	vector<int> adjList[MAX];
	for ( int i = 0; i < edges.size(); i++ ) {
		int u = edges[i][0], v = edges[i][1];

		adjList[u].push_back( v );
		adjList[v].push_back( u );

		degree[u]++, degree[v]++;
	}

	ll weights[MAX];
	queue<int> leafNodes;
	for ( int i = 0; i < n; i++ ) {
		if ( degree[i] == 1 )
			leafNodes.push( i );

		weights[i] = (ll)a[i];
	}

	while ( !leafNodes.empty() ) {
		int curr = leafNodes.front(); leafNodes.pop();
		degree[curr]--;

		for ( int& adj : adjList[curr] ) {
			if ( degree[adj] >= 1 ) {
				degree[adj]--;
				ans += ABS( weights[curr] );
				weights[adj] += weights[curr];
				weights[curr] = 0;

				if ( degree[adj] == 1 )
					leafNodes.push( adj );
			}
		}
	}

	bool isPossible = true;
	for ( int i = 0; i < n; i++ ) {
		if ( weights[i] ) {
			isPossible = false;
			break;
		}
	}

	if ( !isPossible )
		return -1;
	else
		return ans;
}