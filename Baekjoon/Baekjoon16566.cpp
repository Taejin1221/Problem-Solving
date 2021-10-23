// Baekjoon16566.cpp
// https://www.acmicpc.net/problem/16566
#include <iostream>

#define INF 1'234'567'890

using namespace std;

class SegmentTree {
	int* tree;
	int minIdx, maxIdx;

	class Range {
	public:
		int start, end;
		Range(int s, int e): start(s), end(e) { }
		int getMid() { return (start + end) / 2; }
	};

public:
	SegmentTree(int size, bool* arr) {
		tree = new int[size * 4];
		minIdx = 0, maxIdx = size - 1;

		makeTree(1, Range(minIdx, maxIdx), arr);
	}

	~SegmentTree() {
		delete[] tree;
	}

	void makeTree(int treeIdx, Range curr, bool* arr) {
		if (curr.start == curr.end)
			tree[treeIdx] = arr[curr.start] ? curr.start : INF;
		else {
			makeTree(treeIdx * 2, Range(curr.start, curr.getMid()), arr);
			makeTree(treeIdx * 2 + 1, Range(curr.getMid() + 1, curr.end), arr);

			tree[treeIdx] = min(tree[treeIdx * 2], tree[treeIdx * 2 + 1]);
		}
	}

	int getMinValue(int target) {
		return getMinValue(1, Range(minIdx, maxIdx), Range(target + 1, maxIdx));
	}

	int getMinValue(int treeIdx, Range curr, Range target) {
		if (target.start <= curr.start && curr.end <= target.end)
			return tree[treeIdx];
		else if (curr.end < target.start || target.end < curr.start)
			return INF;
		else {
			return min(getMinValue(treeIdx * 2, Range(curr.start, curr.getMid()), target),
				getMinValue(treeIdx * 2 + 1, Range(curr.getMid() + 1, curr.end), target));
		}
	}

	void update(int target) {
		update(1, Range(minIdx, maxIdx), target);
	}

	void update(int treeIdx, Range curr, int target) {
		if (curr.start == curr.end && curr.start == target)
			tree[treeIdx] = INF;
		else if (curr.start <= target && target <= curr.end) {
			update(treeIdx * 2, Range(curr.start, curr.getMid()), target);
			update(treeIdx * 2 + 1, Range(curr.getMid() + 1, curr.end), target);

			tree[treeIdx] = min(tree[treeIdx * 2], tree[treeIdx * 2 + 1]);
		}
	}
};

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int n, m, k;
	cin >> n >> m >> k;

	bool* arr = new bool[n + 1];
	for (int i = 0; i < m; i++) {
		int temp; cin >> temp;
		arr[temp] = true;
	}

	SegmentTree st(n + 1, arr);
	while (k--) {
		int target;
		cin >> target;

		int ans = st.getMinValue(target);
		cout << ans << '\n';
		st.update(ans);
	}

	delete[] arr;

	return 0;
}