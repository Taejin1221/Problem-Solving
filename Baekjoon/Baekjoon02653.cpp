// Baekjoon02653.cpp
// https://www.acmicpc.net/problem/2653
#include <iostream>

#include <vector>

#define LIKE false

using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int n;
	cin >> n;

	bool adjMat[101][101];
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			cin >> adjMat[i][j];

	bool hasAnswer = true;
	vector<vector<int>> ans;
	bool hasSmallGroup[101] = { false, };
	for (int i = 1; i <= n; i++) {
		if (hasSmallGroup[i])
			continue;

		for (int j = 1; j <= n; j++) {
			if (i != j && adjMat[i][j] == LIKE) {
				for (int k = j + 1; k <= n; k++) {
					if (adjMat[i][k] == LIKE) {
						if (adjMat[j][k] != LIKE) {
							hasAnswer = false;
							break;
						}
					}
				}
			}

			if (!hasAnswer)
				break;
		}

		if (!hasAnswer)
			break;
		else {
			ans.push_back(vector<int> ());

			for (int j = 1; j <= n; j++) {
				if (adjMat[i][j] == LIKE) {
					hasSmallGroup[j] = true;

					ans.back().push_back(j);
				}
			}
		}
	}

	bool allComplete = true;
	for (int i = 1; i <= n; i++)
		allComplete &= hasSmallGroup[i];

	for (int i = 0; i < (int)ans.size(); i++) {
		if (ans[i].size() == 1) {
			allComplete = false;
			break;
		}
	}

	if (!allComplete)
			cout << 0 << '\n';
	else {
		cout << ans.size() << '\n';
		for (vector<int>& curr : ans) {
			for (int& i : curr)
				cout << i << ' ';
			cout << '\n';
		}
	}
	return 0;
}