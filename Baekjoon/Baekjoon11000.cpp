// Baekjoon11000_AllocateClassroom.cpp
// https://www.acmicpc.net/problem/11000
#include <iostream>

#include <queue>
#include <algorithm>

using namespace std;

struct Node {
	int start, end;
	Node( ): start( 0 ), end( 0 ) { }
	Node( int s, int e ): start( s ), end( e ) { }
	bool operator<( const Node& n2 ) const {
		return end > n2.end;
	}
};

bool compare( const Node& n1, const Node& n2 ) {
	return n1.start < n2.start;
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int n;
	cin >> n;

	Node lectures[200'000];
	for ( int i = 0; i < n; i++ )
		cin >> lectures[i].start >> lectures[i].end;

	sort( lectures, lectures + n, compare );

	priority_queue<Node> pq;
	pq.push( lectures[0] );
	for ( int i = 1; i < n; i++ ) {
		if ( pq.top().end <= lectures[i].start )
			pq.pop();
		pq.push( lectures[i] );
	}

	cout << pq.size() << '\n';

	return 0;
}