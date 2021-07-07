// Baekjoon11437_LCA.cpp
// https://www.acmicpc.net/problem/11437
#include <iostream>
#include <vector>
#include <cmath> /* log2(), ceil() */

#define endl '\n'
#define MAX_NODE_SIZE 100'001

using namespace std;

const int MAX_LEVEL = (int)ceil(log2(MAX_NODE_SIZE));

int depth[MAX_NODE_SIZE];
int ancestor[MAX_NODE_SIZE][MAX_LEVEL];
vector<int> tree[MAX_NODE_SIZE];

void Swap( int& a, int& b );
void MakeTree( int me, int mom );
int GetLCA( int node1, int node2 );

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int n;
	cin >> n;

	for ( int i = 0; i < n - 1 ; i++ ) {
		int n1, n2;
		cin >> n1 >> n2;

		tree[n1].push_back( n2 );
		tree[n2].push_back( n1 );
	}

	MakeTree( 1, 0 );

	int m;
	cin >> m;
	while ( m-- ) {
		int a, b;
		cin >> a >> b;
		cout << GetLCA( a, b ) << endl;
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
		if ( son != mom )
			MakeTree( son, me );
}

int GetLCA( int node1, int node2 ) {
	if ( depth[node1] > depth[node2] ) 
		Swap( node1, node2 );

	if ( depth[node1] != depth[node2] )
		for ( int i = MAX_LEVEL - 1; i >= 0; i-- )
			if ( depth[node1] <= depth[ancestor[node2][i]] )
				node2 = ancestor[node2][i];

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

	return result;
}