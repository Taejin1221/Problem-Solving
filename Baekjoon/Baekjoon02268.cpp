// Baekjoon02268.cpp
// https://www.acmicpc.net/problem/2268
#include <iostream>

using namespace std;

using ll = long long;

struct Range {
	int start, end;
	Range(): start(0), end(0) { }
	Range(int s, int e): start(s), end(e) { }

	int getMid() { return (start + end) / 2; }
};

ll tree[4'000'000];

void swap(int& a, int& b) { int temp = a; a = b; b = temp; }
ll getSum(int treeIdx, Range curr, Range target);
void update(int treeIdx, Range curr, int targetIdx, int val);

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int n, m;
	cin >> n >> m;

	for (int i = 0; i < m; i++) {
		int q, a, b;
		cin >> q >> a >> b;
		a--;

		if (q == 0) {
			b--;
			if (a > b)
				swap(a, b);
			cout << getSum(1, Range(0, n - 1), Range(a, b)) << '\n';
		} else {
			update(1, Range(0, n - 1), a, b);
		}
	}

	return 0;
}

ll getSum(int treeIdx, Range curr, Range target) {
	if (target.start <= curr.start && curr.end <= target.end)
		return tree[treeIdx];
	else if (curr.end < target.start || target.end < curr.start)
		return 0;
	else {
		return (getSum(treeIdx * 2, Range(curr.start, curr.getMid()), target)
			+ getSum(treeIdx * 2 + 1, Range(curr.getMid() + 1, curr.end), target));
	}
}

void update(int treeIdx, Range curr, int targetIdx, int val) {
	if (curr.start == curr.end && curr.start == targetIdx)
		tree[treeIdx] = val;
	else if (curr.start <= targetIdx && targetIdx <= curr.end) {
		update(treeIdx * 2, Range(curr.start, curr.getMid()), targetIdx, val);
		update(treeIdx * 2 + 1, Range(curr.getMid() + 1, curr.end), targetIdx, val);
		tree[treeIdx] = tree[treeIdx * 2] + tree[treeIdx * 2 + 1];
	}
}