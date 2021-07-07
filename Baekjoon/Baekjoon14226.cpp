// Baekjoon14226_Emoticon.cpp
// https://www.acmicpc.net/problem/14226
#include <iostream>

#include <queue>

using namespace std;

struct Node {
	int emoticon, clip, time;
	Node( int e, int c, int t ): emoticon(e), clip(c), time(t) { }
};

int main(void) {
	int n;
	cin >> n;

	queue<Node> q;
	int visited[1'002][1'002] = { false, };

	visited[1][0] = true;
	q.push( Node( 1, 0, 0 ) );

	int ans;
	while ( !q.empty() ) {
		Node curr = q.front(); q.pop();
		if ( curr.emoticon == n ) {
			ans = curr.time;
			break;
		}
		
		Node newNodes[3] = {
			Node( curr.emoticon, curr.emoticon, curr.time + 1 ),
			Node( curr.emoticon + curr.clip, curr.clip, curr.time + 1 ),
			Node( curr.emoticon - 1, curr.clip, curr.time + 1 )
		};

		for ( int i = 0; i < 3; i++ ) {
			if ( 1 <= newNodes[i].emoticon && newNodes[i].emoticon <= 1'001) {
				if ( !visited[newNodes[i].emoticon][newNodes[i].clip] ) {
					visited[newNodes[i].emoticon][newNodes[i].clip] = true;
					q.push( newNodes[i] );
				}
			}
		}
	}

	cout << ans << '\n';

	return 0;
}