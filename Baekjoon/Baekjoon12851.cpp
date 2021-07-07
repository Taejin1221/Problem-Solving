// Baekjoon12851_HideAndSeek.cpp
// https://www.acmicpc.net/problem/12851
#include <iostream>
#include <vector>
#include <queue>

#define endl '\n'

using namespace std;

struct Node {
	int pos, time;
	Node(): pos(0), time(0) {}
	Node( int p, int t ): pos(p), time(t) {}
};

int main(void) {
	int n, k;
	cin >> n >> k;

	bool visited[100'001] = { false, };
	visited[n] = true;

	int minTime = 0, minNum = 0;
	int currNodesNumber = 1;
	queue<Node> q; q.push( Node( n, 0 ) );
	while ( !q.empty() && !minNum ) {
		int nextNodesNumber = 0;
		vector<int> nextNodes;
		while ( currNodesNumber-- ) {
			Node curr = q.front(); q.pop();

			if ( curr.pos == k ) {
				minTime = curr.time;
				minNum++;
			}

			int nexts[3] = { curr.pos + 1, curr.pos - 1, curr.pos * 2 };
			int nextTime = curr.time + 1;
			for ( int& next : nexts ) {
				if ( 0 <= next && next <= 100'000 ) {
					if ( next == k || !visited[next] ) {
						nextNodes.push_back( next );
						nextNodesNumber++;
						q.push( Node( next, nextTime ) );
					}
				}
			}
		}

		for ( int& nextNode : nextNodes )
			visited[nextNode] = true;
		currNodesNumber = nextNodesNumber;
	}

	cout << minTime << endl;
	cout << minNum << endl;

	return 0;
}