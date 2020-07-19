// Baekjoon03176_TrafficNetwork.cpp
// https://www.acmicpc.net/problem/3176
#include <iostream>
#include <algorithm> /* fill() */
#include <vector>

#define endl '\n'
#define INF 1'000'000
#define MAX_LEVEL 17
#define MAX_NODE_SIZE 100'001

using namespace std;

struct Node {
	int vertex, weight;
	Node( int v, int w ): vertex(v), weight(w) {}
};

int maxVal, minVal;
int depth[MAX_NODE_SIZE];
int maxVals[MAX_NODE_SIZE][MAX_LEVEL];
int minVals[MAX_NODE_SIZE][MAX_LEVEL];
int ancestors[MAX_NODE_SIZE][MAX_LEVEL];
vector<Node> tree[MAX_NODE_SIZE];

void MakeAncestors( int me, int mom );
void GetMaxMin( int a, int b );

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int n;
	cin >> n;

	for ( int i = 0; i < n - 1; i++ ) {
		int a, b, c;
		cin >> a >> b >> c;

		tree[a].push_back( Node( b, c ) );
		tree[b].push_back( Node( a, c ) );
	}

	for ( int i = 0; i <= n; i++ )
		fill( minVals[i], minVals[i] + MAX_LEVEL, INF );
	MakeAncestors( 1, 0 );

	int k;
	cin >> k;
	while ( k-- ) {
		int d, e;
		cin >> d >> e;

		if ( depth[d] > depth[e] ) {
			int temp = d;
			d = e;
			e = temp;
		}

		maxVal = 0, minVal = INF;
		GetMaxMin( d, e );

		cout << minVal << ' ' << maxVal << endl;
	}

	return 0;
}

void MakeAncestors( int me, int mom ) {
	depth[me] = depth[mom] + 1;

	ancestors[me][0] = mom;
	for ( int i = 1; i < MAX_LEVEL; i++ ) {
		int parent = ancestors[me][i - 1];
		ancestors[me][i] = ancestors[parent][i - 1];
		maxVals[me][i] = max( maxVals[me][i - 1], maxVals[parent][i - 1] );
		minVals[me][i] = min( minVals[me][i - 1], minVals[parent][i - 1] );
	}

	for ( Node son : tree[me] ) {
		if ( son.vertex != mom ) {
			maxVals[son.vertex][0] = minVals[son.vertex][0] = son.weight;

			MakeAncestors( son.vertex, me );
		}
	}
}

void GetMaxMin( int a, int b ) {
	if ( depth[a] != depth[b] ) {
		for ( int i = MAX_LEVEL - 1; i >= 0; i-- ) {
			if ( depth[a] <= depth[ancestors[b][i]] ) {
				maxVal = max( maxVal, maxVals[b][i] );
				minVal = min( minVal, minVals[b][i] );

				b = ancestors[b][i];
			}
		}
	}

	if ( a != b ) {
		for ( int i = MAX_LEVEL - 1; i >= 0; i-- ) {
			if ( ancestors[a][i] != ancestors[b][i] ) {
				maxVal = max( maxVal, max( maxVals[a][i], maxVals[b][i] ) );
				minVal = min( minVal, min( minVals[a][i], minVals[b][i] ) );
				a = ancestors[a][i];
				b = ancestors[b][i];
			}
		}

		maxVal = max( maxVal, max( maxVals[a][0], maxVals[b][0] ) );
		minVal = min( minVal, min( minVals[a][0], minVals[b][0] ) );
	}
}