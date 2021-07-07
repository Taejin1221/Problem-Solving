// Baekjoon05014_Startlink.cpp
// https://www.acmicpc.net/problem/5014
#include <iostream>

#include <queue>

using namespace std;

int main(void) {
	int limit, start, target, up, down;
	cin >> limit >> start >> target >> up >> down;

	queue<pair<int, int>> q;
	bool visited[1'000'001] = { false, };

	q.push( { start, 0 } );
	visited[start] = true;

	int ans = -1;
	while ( !q.empty() ) {
		pair<int, int> curr = q.front(); q.pop();
		if ( curr.first == target ) {
			ans = curr.second;
			break;
		}

		int upFloor = curr.first + up;
		if ( upFloor <= limit && !visited[upFloor] ) {
			visited[upFloor] = true;
			q.push( { upFloor, curr.second + 1 } );
		}

		int downFloor = curr.first - down;
		if ( downFloor >= 1 && !visited[downFloor] ) {
			visited[downFloor] = true;
			q.push( { downFloor, curr.second + 1 } );
		}
	}

	if ( ans == -1 )
		cout << "use the stairs";
	else
		cout << ans;
	cout << '\n';

	return 0;
}