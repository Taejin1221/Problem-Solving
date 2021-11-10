// Baekjoon17370.cpp
// https://www.acmicpc.net/problem/17370
#include <iostream>

using namespace std;

using pii = pair<int, int>;

const int moves[2][3][2] = {
	{ { -1, 1 }, { 1, 1 }, { 0, -1 } },
	{ { 0, 1 }, { -1, -1 }, { 1, -1 } }
};

int n, ans;
bool visited[1'000][1'000];

void dfs(pii curr, int prev, int type, int moveNum) {
	if (moveNum > n)
		return;

	if (visited[curr.first][curr.second]) {
		if (moveNum == n)
			ans++;
	} else {
		visited[curr.first][curr.second] = true;
		for (int i = 0; i < 3; i++) {
			if ((i == 2 && prev == 0) || (i == 0 && prev == 2) || (i == 1 && prev == 1))
				continue;
			pii next = { curr.first + moves[type][i][0], curr.second + moves[type][i][1] };
			dfs(next, i, !type, moveNum + 1);
		}
		visited[curr.first][curr.second] = false;
	}
}

int main(void) {
	cin >> n;

	visited[100][100] = true;
	dfs({ 100, 101 }, 0, 0, 0);

	cout << ans << '\n';

	return 0;
}
