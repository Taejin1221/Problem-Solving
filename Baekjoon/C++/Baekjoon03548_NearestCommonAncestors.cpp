// Baekjoon03548_NearestCommonAncestors.cpp
// https://www.acmicpc.net/problem/3584
#include <iostream>
#include <algorithm> /* fill() */
#include <vector>
#include <cmath> /* log2(), ceil() */

#define endl '\n'
#define MAX_NODE_SIZE 10'001

using namespace std;

const int MAX_LEVEL = (int)ceil(log2(MAX_NODE_SIZE));

int depth[MAX_NODE_SIZE];
vector<int> tree[MAX_NODE_SIZE];
int ancestor[MAX_NODE_SIZE][MAX_LEVEL];

void Swap( int& a, int& b );
void MakeTree( int me, int mom );

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int t; cin >> t;
	while ( t-- ) {
		int n;
		cin >> n;

		bool isNotRoot[MAX_NODE_SIZE] = { false, };

		fill( depth, depth + n + 1, 0 );
		for ( int i = 1; i <= n; i++ ) {
			tree[i].clear();
			fill( ancestor[i], ancestor[i] + MAX_LEVEL, 0 );
		}

		for ( int i = 0; i < n - 1; i++ ) {
			int a, b;
			cin >> a >> b;
			isNotRoot[b] = true;

			tree[a].push_back( b );
		}
		int root;
		for ( int i = 1; i <= n; i++)
			if ( !isNotRoot[i] ) {
				root = i;
				break;
			}

		MakeTree( root, 0 );

		int node1, node2;
		cin >> node1 >> node2;

		if ( depth[node1] != depth[node2] ) {
			if ( depth[node1] > depth[node2] )
				Swap( node1, node2 );

			for ( int i = MAX_LEVEL - 1; i >= 0; i-- )
				if ( depth[node1] <= depth[ancestor[node2][i]] )
					node2 = ancestor[node2][i];
		}

		int result = node1;
		if ( node1 != node2 ) {
			for ( int i = MAX_LEVEL - 1; i >= 0; i-- ) {
				if ( ancestor[node1][i] != ancestor[node2][i] ) {
					node1 = ancestor[node1][i];
					node2 = ancestor[node2][i];
				} else
					result = ancestor[node1][i];
			}
		}

		cout << result << endl;
	}

	return 0;
}

void Swap( int& a, int& b ) {
	int temp = a;
	a = b;
	b = temp;
}

void MakeTree( int me, int mom ) {
	depth[me] = depth[mom] + 1;

	ancestor[me][0] = mom;
	for ( int i = 1; i < MAX_LEVEL; i++ )
		ancestor[me][i] = ancestor[ancestor[me][i - 1]][i - 1];

	for ( int son : tree[me] )
		MakeTree( son, me );
}