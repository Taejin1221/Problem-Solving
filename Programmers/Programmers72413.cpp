// Programmers72413.cpp
// https://programmers.co.kr/learn/courses/30/lessons/72413
#include <vector>

#define INF 0x3f3f3f3f

using namespace std;

int solution(int n, int s, int a, int b, vector<vector<int>> fares) {
	vector<vector<int>> shortest(n + 1, vector<int> (n + 1, INF));
	for (int i = 0; i < fares.size(); i++) {
		shortest[fares[i][0]][fares[i][1]] = fares[i][2];
		shortest[fares[i][1]][fares[i][0]] = fares[i][2];
	}

	for (int i = 1; i <= n; i++)
		shortest[i][i] = 0;

	for (int k = 1; k <= n; k++)
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= n; j++)
				if (shortest[i][j] > shortest[i][k] + shortest[k][j])
					shortest[i][j] = shortest[i][k] + shortest[k][j];

	int ans = INF;
	for (int i = 1; i <= n; i++)
		if (shortest[s][i] != INF && shortest[i][a] != INF && shortest[i][b] != INF)
			ans = min(ans, shortest[s][i] + shortest[i][a] + shortest[i][b]);

	return ans;
}