// Baekjoon12837.cpp
// https://www.acmicpc.net/problem/12837
#include <iostream>

#define SIZE 4'000'000

using namespace std;

using ll = long long;

struct Range {
	int start, end;
	Range(): start(0), end(0) { }
	Range(int s, int e): start(s), end(e) { }
	int getMid() { return (start + end) / 2; }
};

ll tree[SIZE];

ll getSum(int treeIdx, Range curr, Range target) {
	if (target.start <= curr.start && curr.end <= target.end)
		return tree[treeIdx];
	else if (curr.end < target.start || target.end < curr.start)
		return 0;
	else
		return (getSum(treeIdx * 2, Range(curr.start, curr.getMid()), target)
			+ getSum(treeIdx * 2 + 1, Range(curr.getMid() + 1, curr.end), target));
}

void update(int treeIdx, Range curr, int targetIdx, ll targetValue) {
	if (curr.start == curr.end && curr.start == targetIdx)
		tree[treeIdx] += targetValue;
	else if (curr.start <= targetIdx && targetIdx <= curr.end) {
		update(treeIdx * 2, Range(curr.start, curr.getMid()), targetIdx, targetValue);
		update(treeIdx * 2 + 1, Range(curr.getMid() + 1, curr.end), targetIdx, targetValue);

		tree[treeIdx] = tree[treeIdx * 2] + tree[treeIdx * 2 + 1];
	}
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int n, q;
	cin >> n >> q;

	while (q--) {
		int query;
		cin >> query;
		if (query == 1) {
			int idx, value;
			cin >> idx >> value;
			idx--;

			update(1, Range(0, n - 1), idx, (ll)value);
		} else {
			int start, end;
			cin >> start >> end;

			start--, end--;
			cout << getSum(1, Range(0, n - 1), Range(start, end)) << '\n';
		}
	}

	return 0;
}