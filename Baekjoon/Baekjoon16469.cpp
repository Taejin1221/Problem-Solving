// Baekjoon16469.cpp
// https://www.acmicpc.net/problem/16469
#include <iostream>

#include <queue>

using namespace std;

using pii = pair<int, int>;

const int moves[4][2] = { { -1, 0 }, { 0, 1 }, { 1, 0 }, { 0, -1 } };

struct Node {
	int row, col, time;
	Node(): row(0), col(0), time(0) { }
	Node(int r, int c, int t): row(r), col(c), time(t) { }
};

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int maxRow, maxCol;
	cin >> maxRow >> maxCol;

	// F: road, T: wall
	char map[101][101] = { { 0, }, };
	for (int i = 1; i <= maxRow; i++)
			cin >> &map[i][1];

	pii villains[3];
	cin >> villains[0].first >> villains[0].second;
	cin >> villains[1].first >> villains[1].second;
	cin >> villains[2].first >> villains[2].second;


	// first: number of villains, second: max time
	pii maxShortestTime[101][101];

	for (int i = 0; i < 3; i++) {
		queue<Node> q;
		bool visited[101][101] = { { false, } }; 

		q.push(Node(villains[i].first, villains[i].second, 0));
		visited[villains[i].first][villains[i].second] = true;

		while (!q.empty()) {
			Node curr = q.front(); q.pop();

			pii& currAns = maxShortestTime[curr.row][curr.col];

			currAns.first++;
			currAns.second = max(currAns.second, curr.time);

			for (int j = 0; j < 4; j++) {
				int newRow = curr.row + moves[j][0], newCol = curr.col + moves[j][1];
				if ((0 < newRow && newRow <= maxRow) && (0 < newCol && newCol <= maxCol)) {
					if (map[newRow][newCol] == '0' && !visited[newRow][newCol]) {
						visited[newRow][newCol] = true;

						q.push(Node(newRow, newCol, curr.time + 1));
					}
				}
			}
		}
	}

	// { number, time }
	pii ans = { 0, 0x3f3f3f3f };
	for (int i = 1; i <= maxRow; i++) {
		for (int j = 1; j <= maxCol; j++) {
			if (maxShortestTime[i][j].first == 3) {
				if (maxShortestTime[i][j].second == ans.second) {
					ans.first++;
				} else if (maxShortestTime[i][j].second < ans.second) {
					ans.second = maxShortestTime[i][j].second;
					ans.first = 1;
				}
			}
		}
	}

	if (ans.first == 0) {
		cout << -1 << '\n';
	} else {
		cout << ans.second << '\n';
		cout << ans.first << '\n';
	}

	return 0;
}