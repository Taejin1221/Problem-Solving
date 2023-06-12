// Baekjoon20529.cpp
// https://www.acmicpc.net/problem/20529
#include <iostream>

#include <map>
#include <vector>
#include <string>

using namespace std;

int getDistance(string a, string b, string c) {
	int result = 0;
	for (int i = 0; i < 4; i++) {
		if (a[i] != b[i])
			result++;
		if (b[i] != c[i])
			result++;
		if (a[i] != c[i])
			result++;
	}

	return result;
}

void solve() {
	int n;
	cin >> n;

	map<string, int> table;
	for (int i = 0; i < n; i++) {
		string mbti;
		cin >> mbti;

		if (table.find(mbti) == table.end())
			table.insert({ mbti, 1 });
		else
			table.find(mbti)->second++;
	}

	vector<string> mbti;
	for (auto iter = table.begin(); iter != table.end(); ++iter) {
		for (int i = 0; i < min(3, iter->second); i++)
			mbti.push_back(iter->first);
	}

	int ans = 1'234'567'890;
	int size = (int)mbti.size();
	for (int i = 0; i < size - 2; i++) {
		for (int j = i + 1; j < size - 1; j++) {
			for (int k = j + 1; k < size; k++) {
				ans = min(ans, getDistance(mbti[i], mbti[j], mbti[k]));
			}
		}
	}

	cout << ans << '\n';
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int t;
	cin >> t;

	while (t--) {
		solve();
	}

	return 0;
}