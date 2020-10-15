// Baekjoon13549_Hide-and-Seek3.cpp
// https://www.acmicpc.net/problem/13549
#include <iostream>
#include <queue> /* priority_queue */

#define MAX 100'000
#define MIN 0

using namespace std;

struct Node {
	int pos, time;
	Node(): pos(0), time(0) {}
	Node(int p, int t): pos(p), time(t) {}
	bool operator<(const Node& n2) const {
		return ( time > n2.time );	
	}
};

int main(void) {
	int n, k;
	cin >> n >> k;

	priority_queue<Node> pq;
	pq.push( Node( n, 0 ) );

	bool visited[100'001] = { false, };
	while ( !pq.empty() && pq.top().pos != k ) {
		Node curr = pq.top(); pq.pop();
		if ( !visited[curr.pos] ) {
			visited[curr.pos] = true;

			int nextPos = curr.pos + 1;
			if ( (MIN <= nextPos && nextPos <= MAX) && !visited[nextPos] )
				pq.push( Node( nextPos, curr.time + 1 ) );

			nextPos = curr.pos - 1;
			if ( (MIN <= nextPos && nextPos <= MAX) && !visited[nextPos] )
				pq.push( Node( nextPos, curr.time + 1 ) );

			nextPos = curr.pos * 2;
			if ( (MIN <= nextPos && nextPos <= MAX) && !visited[nextPos] )
				pq.push( Node( nextPos, curr.time ) );
		}
	}

	cout << pq.top().time << '\n';

	return 0;
}