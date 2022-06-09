// Baekjoon01058.cpp
// https://www.acmicpc.net/problem/1058
#include <iostream>

using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;

	char adjMat[50][51];
	for (int i = 0; i < n; i++)
		cin >> adjMat[i];

	int ans = 0;
	for (int i = 0; i < n; i++) {
		int friend_2 = 0;
		for (int j = 0; j < n; j++) {
			if (adjMat[i][j] == 'Y')
				friend_2++;
			else if (i != j) {
				for (int k = 0; k < n; k++) {
					if (adjMat[i][k] == 'Y' && adjMat[k][j] == 'Y') {
						friend_2++;
						break;
					}
				}
			}
		}

		ans = max(ans, friend_2);
	}

	cout << ans << '\n';

	return 0;
}