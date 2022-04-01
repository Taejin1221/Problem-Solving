// Baekjoon20299.cpp
// https://www.acmicpc.net/problem/20299
#include <iostream>

#include <vector>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int n, k, l;
	cin >> n >> k >> l;

	int stats[500000][3];
	vector<int> ans;
	for (int i = 0; i < n; i++) {
		int sum = 0;
		bool allOver = true;

		for (int j = 0; j < 3; j++) {
			cin >> stats[i][j];

			sum += stats[i][j];
			if (stats[i][j] < l)
				allOver = false;
		}

		if (allOver && sum >= k)
			ans.push_back(i);
	}

	cout << ans.size() << '\n';
	for (int i = 0; i < ans.size(); i++)
		for (int j = 0; j < 3; j++)
			cout << stats[ans[i]][j] << ' ';

	return 0;
}
