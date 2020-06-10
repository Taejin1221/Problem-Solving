// Baekjoon01697_HideAndSeek.cpp
// https://www.acmicpc.net/problem/1697
#include <iostream>
#include <queue>

#define MAX_POS 100001

using namespace std;

int main(void) {
	bool visited[MAX_POS] = { false,  };

	int n, k, count = 0;
	cin >> n >> k;

	queue<pair<int, int>> pos;

	visited[n] = true;
	pos.push( { n, 0 } );
	while ( true ) {
		pair<int, int> curr = pos.front(); pos.pop();

		int currPos = curr.first, currCount = curr.second;
		if ( currPos == k ) {
			cout << currCount << '\n';
			break;
		}

		int nextCount = currCount + 1;
		int nextPositions[3] = { currPos - 1, currPos + 1, currPos * 2 };
		if ( nextPositions[0] >= 0 && !visited[nextPositions[0]] ) {
			visited[nextPositions[0]] = true;
			pos.push( { nextPositions[0], nextCount } );
		}

		if ( (nextPositions[1] < MAX_POS) && !visited[nextPositions[1]] ) {
			visited[nextPositions[1]] = true;
			pos.push( { nextPositions[1], nextCount } );
		}

		if ( ( nextPositions[2] < MAX_POS ) && !visited[nextPositions[2]] ) {
			visited[nextPositions[2]] = true;
			pos.push( { nextPositions[2], nextCount } );
		}
	}

	return 0;
}
