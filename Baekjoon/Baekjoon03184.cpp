// Baekjoon03184.cpp
// https://www.acmicpc.net/problem/3184
#include <iostream>

using namespace std;

typedef pair<int, int> pii;

const int delta[4][2] = { { -1, 0 }, { 0, 1 }, { 1, 0 }, { 0, -1 } };

int maxRow, maxCol;
char garden[250][251];
bool visited[250][251];

pii dfs(int currRow, int currCol ) {
	pii animals = { 0, 0 };
	for (int i = 0; i < 4; i++) {
		int newRow = currRow + delta[i][0], newCol = currCol + delta[i][1];
		if ((0 <= newRow && newRow < maxRow) && (0 <= newCol && newCol < maxCol)) {
			if (garden[newRow][newCol] != '#' && !visited[newRow][newCol]) {
				visited[newRow][newCol] = true;
				pii temp = dfs(newRow, newCol);

				animals.first += temp.first;
				animals.second += temp.second;
				if (garden[newRow][newCol] == 'o')
					animals.first++;
				else if (garden[newRow][newCol] == 'v')
					animals.second++;
			}
		}
	}

	return animals;
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> maxRow >> maxCol;

	for (int i = 0; i < maxRow; i++)
		cin >> garden[i];

	// { sheep, wolf }
	pii ans = { 0, 0 };
	for (int i = 0; i < maxRow; i++) {
		for (int j = 0; j < maxCol; j++) {
			if (garden[i][j] != '#' && !visited[i][j]) {
				visited[i][j] = true;

				pii animals = dfs(i, j);
				if (garden[i][j] == 'o')
					animals.first++;
				else if (garden[i][j] == 'v')
					animals.second++;

				if (animals.first > animals.second)
					animals = { animals.first, 0 };
				else
					animals = { 0, animals.second};

				ans.first += animals.first;
				ans.second += animals.second;
			}
		}
	}

	cout << ans.first << ' ' << ans.second << '\n';

	return 0;
}
