// Baekjoon01517_BubbleSort.cpp
// https://www.acmicpc.net/problem/1517
#include <iostream>

#include <vector>
#include <algorithm>

using namespace std;

struct Range {
	int start, end;
	Range(int s, int e): start(s), end(e) { }

	int getMid() {
		return (start + end) / 2;
	}
};

class SegmentTree {
	long* tree;
	int minIdx, maxIdx;

public:
	SegmentTree(int n) {
		minIdx = 0, maxIdx = n - 1;
		tree = new long[4 * n];
		fill(tree, tree + 4 * n, 0);
	}

	~SegmentTree() {
		delete[] tree;
	}

	long getSum(int start, int end) {
		return getSum(1, Range(start, end), Range(minIdx, maxIdx));
	}

	long getSum(int treeIdx, Range target, Range curr) {
		if (target.start <= curr.start && curr.end <= target.end)
			return tree[treeIdx];
		else if (curr.end < target.start || target.end < curr.start)
			return 0;
		else {
			int mid = curr.getMid();
			return (getSum(treeIdx * 2, target, Range(curr.start, mid))
				+ getSum(treeIdx * 2 + 1, target, Range(mid + 1, curr.end)));
		}
	}

	void add1(int idx) {
		add(1, idx, Range(minIdx, maxIdx), 1);
	}

	void add(int treeIdx, int target, Range curr, int val) {
		if (curr.start == curr.end && curr.start == target)
			tree[treeIdx] += val;
		else if (curr.start <= target && target <= curr.end) {
			int mid = curr.getMid();
			add(treeIdx * 2, target, Range(curr.start, mid), val);
			add(treeIdx * 2 + 1, target, Range(mid + 1, curr.end), val);

			tree[treeIdx] = tree[treeIdx * 2] + tree[treeIdx * 2 + 1];
		}
	}
};

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;

	int arr[500'000];
	vector<int> coords(n);
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
		coords[i] = arr[i];
	}

	sort(coords.begin(), coords.end());
	coords.erase(unique(coords.begin(), coords.end()), coords.end());

	long ans = 0;
	SegmentTree st(n);
	for (int i = n - 1; i >= 0; i--) {
		int idx = lower_bound(coords.begin(), coords.end(), arr[i]) - coords.begin();
		ans += st.getSum(0, idx - 1);
		st.add1(idx);
	}

	cout << ans << '\n';

	return 0;
}