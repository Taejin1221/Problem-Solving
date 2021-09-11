// Baekjoon09328.cpp
// https://www.acmicpc.net/problem/9328
#include <iostream>

#include <queue>
#include <vector>

#define IS_CAPITAL(x) (('A' <= x) && (x <= 'Z'))
#define IS_SMALL(x) (('a' <= x) && (x <= 'z'))
#define IS_IN(x, y) ((0 <= x) && (x < y))

using namespace std;

typedef pair<int, int> pii;

const int moves[4][2] = { { -1, 0 }, { 0, 1 }, { 1, 0 }, { 0, -1 } };

// 0: can't go, 1: enqueue, 2: key, 3: door and no key, 4: document
void judgeState(char building[][101], int row, int col, queue<pii>& q, bool hasKey[], vector<pii> door[], int& ans) {
	char ch = building[row][col];
	if (ch == '.')
		q.push({ row, col });
	else if (IS_CAPITAL(ch)) {
		int idx = ch - 'A';
		if (hasKey[idx])
			q.push({ row, col });
		else
			door[idx].push_back({ row, col });
	} else if (IS_SMALL(ch)) {
		int idx = ch - 'a';
		hasKey[idx] = true;
		for (pii& curr : door[idx])
			q.push(curr);
		door[idx].clear();
		q.push({ row, col });
	} else if (ch == '$') {
		ans++;
		q.push({ row, col });
	} else if (ch == '*')
		return;
}

void solveTestCase() {
	int n, m;
	cin >> n >> m;

	char building[100][101];
	for (int i = 0; i < n; i++)
		cin >> building[i];

	bool hasKey[26] = { 0, };

	string key;
	cin >> key;

	if (key != "0")
		for (int i = 0; i < key.size(); i++)
			hasKey[key[i] - 'a'] = true;

	int ans = 0;
	queue<pii> q;
	vector<pii> door[26];
	bool visited[100][100] = { false, };

	for (int i = 0; i < m; i++) {
		visited[0][i] = true;
		judgeState(building, 0, i, q, hasKey, door, ans);

		visited[n - 1][i] = true;
		judgeState(building, n - 1, i, q, hasKey, door, ans);
	}

	for (int i = 1; i < n - 1; i++) {
		visited[i][0] = true;
		judgeState(building, i, 0, q, hasKey, door, ans);

		visited[i][m - 1] = true;
		judgeState(building, i, m - 1, q, hasKey, door, ans);
	}

	while (!q.empty()) {
		pii curr = q.front(); q.pop();

		for (int i = 0; i < 4; i++) {
			int newRow = curr.first + moves[i][0], newCol = curr.second + moves[i][1];
			if (IS_IN(newRow, n) && IS_IN(newCol, m)) {
				if (!visited[newRow][newCol]) {
					visited[newRow][newCol] = true;

					judgeState(building, newRow, newCol, q, hasKey, door, ans);
				}
			}
		}
	}

	cout << ans << '\n';
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int t;
	cin >> t;
	while (t--) {
		solveTestCase();
	}

	return 0;
}