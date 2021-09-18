// Baekjoon02243.cpp
// https://www.acmicpc.net/problem/2243
#include <iostream>

#include <algorithm>

#define TREE_MAX 4'000'000
#define MAX 1'000'000

using namespace std;

class SegmentTree {
	int tree[TREE_MAX];
	int minIdx, maxIdx;

	class Range {
	public:
		int start, end;

		Range(): start(0), end(0) { }
		Range(int s, int e): start(s), end(e) { };

		int getMid() {
			return (start + end) / 2;
		}
	};

public:
	SegmentTree() {
		fill(tree, tree + TREE_MAX, 0);

		minIdx = 0, maxIdx = MAX - 1;
	}

	int search(int target) {
		return search(1, Range(minIdx, maxIdx), target) + 1;
	}

	int search(int treeIdx, Range curr, int target) {
		if (curr.start == curr.end) {
			return curr.start;
		} else {
			int leftIdx = treeIdx * 2, rightIdx = treeIdx * 2 + 1;
			if (tree[leftIdx] < target)
				return search(rightIdx, Range(curr.getMid() + 1, curr.end), target - tree[leftIdx]);
			else
				return search(leftIdx, Range(curr.start, curr.getMid()), target);
		}
	}

	void update(int target, int value) {
		update(1, Range(minIdx, maxIdx), target - 1, value);
	}

	void update(int treeIdx, Range curr, int target, int value) {
		if (curr.start == curr.end && curr.start == target)
			tree[treeIdx] += value;
		else if (curr.start <= target && target <= curr.end) {
			int leftIdx = treeIdx * 2, rightIdx = treeIdx * 2 + 1;
			update(leftIdx, Range(curr.start, curr.getMid()), target, value);
			update(rightIdx, Range(curr.getMid() + 1, curr.end), target, value);

			tree[treeIdx] = tree[leftIdx] + tree[rightIdx];
		}
	}
};

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	SegmentTree tree;

	int t;
	cin >> t;
	while (t--) {
		int a;
		cin >> a;
		if (a == 1) {
			int b;
			cin >> b;

			int candy = tree.search(b);
			cout << candy << '\n';
			tree.update(candy, -1);
		} else {
			int b, c;
			cin >> b >> c;

			tree.update(b, c);
		}
	}

	return 0;
}