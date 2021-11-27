// Baekjoon02636_2.cpp
// https://www.acmicpc.net/problem/2636
#include <iostream>

#include <queue>

#define AIR -2
#define MELT -1
#define CHEESE 1

using namespace std;

using pii = pair<int, int>;

const int moves[4][2] = { { -1, 0 }, { 0, 1 }, { 1, 0 }, { 0, -1 } };

int n, m;
int table[100][100];

void airCheck() {
	bool visited[100][100] = { false, };

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (!visited[i][j] && table[i][j] == AIR) {
				visited[i][j] = true;


				queue<pii> q;
				q.push({ i, j });
				while (!q.empty()) {
					pii curr = q.front(); q.pop();

					for (int i = 0; i < 4; i++) {
						pii next = { curr.first + moves[i][0], curr.second + moves[i][1] };
						if ((0 <= next.first && next.first < n) && (0 <= next.second && next.second < m)) {
							if (!visited[next.first][next.second] && (table[next.first][next.second] == 0 || table[next.first][next.second] == AIR)) {
								visited[next.first][next.second] = true;
								table[next.first][next.second] = AIR;

								q.push(next);
							}
						}
					}
				}
			}
		}
	}
}

void meltCheck() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (table[i][j] != CHEESE)
				continue;

			bool isMelt = false;
			for (int k = 0; k < 4; k++) {
				pii next = { i + moves[k][0], j + moves[k][1] };
				if ((0 <= next.first && next.first < n) && (0 <= next.second && next.second < m)) {
					if (table[next.first][next.second] == AIR) {
						isMelt = true;
						break;
					}
				}
			}

			if (isMelt)
				table[i][j] = MELT;
		}
	}
}

int melting() {
	int result = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (table[i][j] == MELT) {
				table[i][j] = AIR;
				result++;
			}
		}
	}

	return result;
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> m;

	int cheeseNum = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> table[i][j];
			if (table[i][j] == CHEESE)
				cheeseNum++;
		}
	}
	table[0][0] = AIR;

	int time = 0;
	while (true) {
		airCheck();
		meltCheck();
		int meltedCheese = melting();
		time++;
		if (meltedCheese == cheeseNum)
			break;
		cheeseNum -= meltedCheese;
	}

	cout << time << '\n' << cheeseNum << '\n';

	return 0;
}