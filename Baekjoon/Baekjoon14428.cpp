// Baekjoon14428.cpp
// https://www.acmicpc.net/problem/14428
#include <iostream>

#define INF 1'234'567'890

using namespace std;

struct Node {
	int val, idx;
	Node(): val(0), idx(0) { }
	Node(int v, int i): val(v), idx(i) { }
	bool operator<(const Node& n2) const {
		return (val != n2.val) ? val < n2.val : idx < n2.idx;
	}
};

Node min(Node& n1, Node& n2) {
	return n1 < n2 ? n1 : n2;
}

class SegmentTree {
	Node* tree;
	int minIdx, maxIdx;

	class Range {
	public:
		int start, end;
		Range(int s, int e): start(s), end(e) { }
		int getMid() {
			return (start + end) / 2;
		}
		bool isLeaf() {
			return start == end;
		}
	};
public:
	SegmentTree(int arr[], int size) {
		minIdx = 0, maxIdx = size - 1;
		tree = new Node[size * 4];

		makeTree(1, Range(minIdx, maxIdx), arr);
	}

	~SegmentTree() {
		delete[] tree;
	}

	void makeTree(int treeIdx, Range curr, int arr[]) {
		if (curr.isLeaf())
			tree[treeIdx] = Node(arr[curr.start], curr.start);
		else {
			int leftChild = treeIdx * 2, rightChild = treeIdx * 2 + 1;
			makeTree(leftChild, Range(curr.start, curr.getMid()), arr);
			makeTree(rightChild, Range(curr.getMid() + 1, curr.end), arr);

			tree[treeIdx] = min(tree[leftChild], tree[rightChild]);
		}
	}

	Node getMinimum(int start, int end) {
		return getMinimum(1, Range(minIdx, maxIdx), Range(start, end));
	}

	Node getMinimum(int treeIdx, Range curr, Range target) {
		if (target.start <= curr.start && curr.end <= target.end)
			return tree[treeIdx];
		else if (target.end < curr.start || curr.end < target.start)
			return Node(INF, 0);
		else
			return min(
				getMinimum(treeIdx * 2, Range(curr.start, curr.getMid()), target),
				getMinimum(treeIdx * 2 + 1, Range(curr.getMid() + 1, curr.end), target)
			);
	}

	void update(int idx, int value) {
		update(1, Range(minIdx, maxIdx), idx, value);
	}

	void update(int treeIdx, Range curr, int targetIdx, int targetValue) {
		if (curr.isLeaf() && curr.start == targetIdx)
			tree[treeIdx] = Node(targetValue, targetIdx);
		else if (curr.start <= targetIdx && targetIdx <= curr.end) {
			int leftChild = treeIdx * 2, rightChild = treeIdx * 2 + 1;
			update(leftChild, Range(curr.start, curr.getMid()), targetIdx, targetValue);
			update(rightChild, Range(curr.getMid() + 1, curr.end), targetIdx, targetValue);

			tree[treeIdx] = min(tree[leftChild], tree[rightChild]);
		}
	}
};

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int n;
	cin >> n;

	int arr[100'000];
	for (int i = 0; i < n; i++)
		cin >> arr[i];

	SegmentTree st(arr, n);

	int q; cin >> q;
	while (q--) {
		int a, b, c;
		cin >> a >> b >> c;
		if (a == 1) {
			b--;
			st.update(b, c);
		} else {
			b--, c--;
			cout << st.getMinimum(b, c).idx + 1 << '\n';
		}
	}

	return 0;
}