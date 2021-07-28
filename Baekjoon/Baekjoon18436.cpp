// Baekjoon18436.cpp
// https://www.acmicpc.net/problem/18436
#include <iostream>

using namespace std;

typedef pair<int, int> pii;

class SegmentTree {
	int** tree;
	int minIdx, maxIdx;

	class Range {
	public:
		int start, end;
		Range(int s, int e): start(s), end(e) { }
		int getMid() {
			return (start + end) / 2;
		}
	};

public:
	SegmentTree(int arr[], int size) {
		tree = new int*[2];
		tree[0] = new int[size * 4]();
		tree[1] = new int[size * 4]();

		minIdx = 0, maxIdx = size - 1;

		makeTree(1, Range(minIdx, maxIdx), arr);
	}

	~SegmentTree() {
		delete[] tree[0];
		delete[] tree[1];
		delete[] tree;
	}

	void makeTree(int treeIdx, Range curr, int arr[]) {
		if (curr.start == curr.end) {
			tree[arr[curr.start] % 2][treeIdx] = 1;
		} else {
			int leftIdx = treeIdx * 2, rightIdx = treeIdx * 2 + 1;
			int mid = curr.getMid();
			makeTree(leftIdx, Range(curr.start, mid), arr);
			makeTree(rightIdx, Range(mid + 1, curr.end), arr);

			tree[0][treeIdx] = tree[0][leftIdx] + tree[0][rightIdx];
			tree[1][treeIdx] = tree[1][leftIdx] + tree[1][rightIdx];
		}
	}

	pii getSum(int start, int end) {
		return getSum(1, Range(minIdx, maxIdx), Range(start, end));
	}

	pii getSum(int treeIdx, Range curr, Range target) {
		if (target.start <= curr.start && curr.end <= target.end)
			return make_pair(tree[0][treeIdx], tree[1][treeIdx]);
		else if (curr.end < target.start || target.end < curr.start)
			return make_pair(0, 0);
		else {
			pii leftVal = getSum(treeIdx * 2, Range(curr.start, curr.getMid()), target);
			pii rightVal = getSum(treeIdx * 2 + 1, Range(curr.getMid() + 1, curr.end), target);

			return make_pair(leftVal.first + rightVal.first, leftVal.second + rightVal.second);
		}
	}

	void update(int idx, int val) {
		update(1, Range(minIdx, maxIdx), idx, val);
	}

	void update(int treeIdx, Range curr, int targetIdx, int value) {
		if (curr.start == curr.end && curr.start == targetIdx) {
			tree[0][treeIdx] = value % 2 ? 0 : 1;
			tree[1][treeIdx] = value % 2 ? 1 : 0;
		} else if (curr.start <= targetIdx && targetIdx <= curr.end) {
			int mid = curr.getMid();
			int leftIdx = treeIdx * 2, rightIdx = treeIdx * 2 + 1;

			update(leftIdx, Range(curr.start, mid), targetIdx, value);
			update(rightIdx, Range(mid + 1, curr.end), targetIdx, value);

			tree[0][treeIdx] = tree[0][leftIdx] + tree[0][rightIdx];
			tree[1][treeIdx] = tree[1][leftIdx] + tree[1][rightIdx];
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

	int t;
	cin >> t;
	while (t--) {
		int opr, left, right;
		cin >> opr >> left >> right;

		if (opr == 1)
			st.update(left - 1, right);
		else {
			pii result = st.getSum(left - 1, right - 1);

			if (opr % 2 == 0)
				cout << result.first;
			else
				cout << result.second;
			cout << '\n';
		}
	}

	return 0;
}