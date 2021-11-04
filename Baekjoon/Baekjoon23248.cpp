// Baekjoon23248.cpp
// https://www.acmicpc.net/problem/23248
#include <iostream>

#include <set>

#define SIZE 100'001

using namespace std;

struct Treasure {
	int row, col;
	Treasure(): row(0), col(0) { }
	Treasure(int r, int c): row(r), col(c) { }
	bool operator<(const Treasure& t2) const {
		return (row != t2.row) ? row < t2.row : col < t2.col;
	}
};

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n, m, k;
	cin >> n >> m >> k;

	set<Treasure> st;
	for (int i = 0; i < k; i++) {
		Treasure temp;
		cin >> temp.row >> temp.col;

		st.insert(temp);
	}

	int ans = 0;
	while (st.size()) {
		Treasure prev = *st.begin();
		st.erase(st.begin());

		auto iter = st.begin();
		while (iter != st.end()) {
			if (prev.row <= iter->row && prev.col <= iter->col) {
				prev = *iter;
				auto prevIter = iter;
				iter++;
				st.erase(prevIter);
			} else {
				++iter;
			}
		}

		ans++;
	}

	cout << ans << '\n';

	return 0;
}