// Baekjkoon01068_Tree.cpp
// https://www.acmicpc.net/problem/1068
#include <iostream>
#include <vector>

using namespace std;

int removeNode;
vector<int> adjList[50];

int dfs( int curr ) {
	int currSize = adjList[curr].size();
	if ( currSize == 0 )
		return 1;
	else if ( currSize == 1 && adjList[curr][0] == removeNode )
		return 1;
	else {
		int leaf = 0;
		for ( int& next : adjList[curr] ) {
			if ( next != removeNode )
				leaf += dfs( next );
		}

		return leaf;
	}
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;

	int root;
	for ( int i = 0; i < n; i++ ) {
		int parent;
		cin >> parent;

		if ( parent == -1 )
			root = i;
		else
			adjList[parent].push_back( i );
	}

	cin >> removeNode;

	if ( root == removeNode )
		cout << 0;
	else {
		int ans = dfs( root );

		cout << ans;
	}
	cout << '\n';

	return 0;
}