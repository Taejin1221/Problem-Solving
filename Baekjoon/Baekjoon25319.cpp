// Baekjoon25319.cpp
// https://www.acmicpc.net/problem/25319
#include <iostream>

#include <queue>
#include <string>

#define ROW first
#define COL second

using namespace std;

using pii = pair<int, int>;

const char OFFSET = 'a';

void goTarget(pii curr, pii target, pair<int, string>& ans) {
	int rowDiff = target.ROW - curr.ROW, colDiff = target.COL - curr.COL;

	char inst;
	if (rowDiff > 0)
		inst = 'D';
	else if (rowDiff < 0)
		inst = 'U';
	else
		inst = '\0';

	if (inst)
		for (int j = 0; j < abs(rowDiff); j++)
			ans.second.push_back(inst);

	if (colDiff > 0)
		inst = 'R';
	else if (colDiff < 0)
		inst = 'L';
	else
		inst = '\0';

	if (inst)
		for (int j = 0; j < abs(colDiff); j++)
			ans.second.push_back(inst);
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n, m, s;
	cin >> n >> m >> s;

	string dungeon[50];
	queue<pii> q[26];
	for (int i = 0; i < n; i++) {
		cin >> dungeon[i];
		for (int j = 0; j < m; j++) {
			q[dungeon[i][j] - OFFSET].push({ i, j });
		}
	}

	string id;
	cin >> id;
	int idTable[26] = { 0, };
	for (int i = 0; i < s; i++)
		idTable[id[i] - OFFSET]++;

	pair<int, string> ans = { 0x3f3f3f3f, "" };
	for (int i = 0; i < 26; i++)
		if (idTable[i])
			ans.first = min(ans.first, (int)q[i].size() / idTable[i]);

	pii curr = { 0, 0 };
	for (int time = 0; time < ans.first; time++) {
		for (int i = 0; i < s; i++) {
			pii target = q[id[i] - OFFSET].front(); q[id[i] - OFFSET].pop();

			goTarget(curr, target, ans);
			ans.second.push_back('P');
			curr = target;
		}
	}

	goTarget(curr, { (n - 1), (m - 1) }, ans);

	cout << ans.first << ' ' << ans.second.size() << '\n';
	cout << ans.second << '\n';

	return 0;
}