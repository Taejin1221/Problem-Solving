// Baekjoon20040_CycleGame.cpp
#include <iostream>

using namespace std;

int parent[1'000'000];

int GetRoot(int a);
void Union(int a, int b);

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n, m;
	cin >> n >> m;

	for ( int i = 0; i < n; i++ )
		parent[i] = i;

	bool isCycle = false;
	int time = 0;
	while ( m-- ) {
		int a, b;
		cin >> a >> b;

		int a_root = GetRoot( a );
		int b_root = GetRoot( b );

		time++;
		if ( a_root == b_root ) {
			isCycle = true;
			break;
		} else
			Union( a_root, b_root );
	}

	if ( !isCycle )
		cout << 0 << '\n';
	else
		cout << time << '\n';

	return 0;
}

int GetRoot( int a ) {
	return ( parent[a] == a ) ? a : GetRoot( parent[a] );
}

void Union( int a, int b ) {
	if ( a < b )
		parent[b] = a;
	else
		parent[a] = b;
}