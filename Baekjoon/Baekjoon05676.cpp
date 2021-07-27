// Baekjoon05676_AlcoholCoding.cpp
// https://www.acmicpc.net/problem/5676
#include <iostream>

using namespace std;

class SegmentTree {
private:
	char* tree;
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
	SegmentTree(int* arr, int size) {
		tree = new char[size * 4];
		minIdx = 0, maxIdx = size - 1;

		makeTree(1, Range(minIdx, maxIdx), arr);
	}

	~SegmentTree() {
		delete[] tree;
	}

	void makeTree(int treeIdx, Range curr, int* arr) {
		if (curr.start == curr.end) {
			if (arr[curr.start] < 0 )
				tree[treeIdx] = '-';
			else if (arr[curr.start] > 0)
				tree[treeIdx] = '+';
			else
				tree[treeIdx] = '0';
		} else {
			int left = treeIdx * 2, right = treeIdx * 2 + 1;
			makeTree(left, Range(curr.start, curr.getMid()), arr);
			makeTree(right, Range(curr.getMid() + 1, curr.end), arr);

			if (tree[left] == '0' || tree[right] == '0')
				tree[treeIdx] = '0';
			else if (tree[left] != tree[right])
				tree[treeIdx] = '-';
			else
				tree[treeIdx] = '+';
		}
	}

	char getResult(int start, int end) {
		return getResult(1, Range(minIdx, maxIdx), Range(start, end));
	}

	char getResult(int treeIdx, Range curr, Range target) {
		if (target.start <= curr.start && curr.end <= target.end)
			return tree[treeIdx];
		else if (curr.end < target.start || target.end < curr.start)
			return '=';
		else {
			int sign1 = getResult(treeIdx * 2, Range(curr.start, curr.getMid()), target);
			int sign2 = getResult(treeIdx * 2 + 1, Range(curr.getMid() + 1, curr.end), target);

			if (sign1 == '=' || sign2 == '=')
				return (sign1 == '=' ? sign2 : sign1);
			else {
				if (sign1 == '0' || sign2 == '0')
					return '0';
				else if (sign1 != sign2)
					return '-';
				else
					return '+';
			}
		}
	}

	void update(int idx, int val) {
		update(1, Range(minIdx, maxIdx), idx, val);
	}

	void update(int treeIdx, Range curr, int target, int value) {
		if (curr.start == curr.end && curr.start == target) {
			char sign;
			if (value > 0)
				sign = '+';
			else if (value < 0)
				sign = '-';
			else
				sign = '0';

			tree[treeIdx] = sign;
		} else if (curr.start <= target && target <= curr.end) {
			int left = treeIdx * 2, right = treeIdx * 2 + 1;
			update(left, Range(curr.start ,curr.getMid()), target, value);
			update(right, Range(curr.getMid() + 1, curr.end), target, value);

			if (tree[left] == '0' || tree[right] == '0')
				tree[treeIdx] = '0';
			else if (tree[left] != tree[right])
				tree[treeIdx] = '-';
			else
				tree[treeIdx] = '+';
		}
	}
};

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int arr[100'000];
	int n, k;
	while (cin >> n >> k) {
		for (int i = 0; i < n; i++)
			cin >> arr[i];

		SegmentTree segTree(arr, n);
		while (k--) {
			char opr; int a, b;
			cin >> opr >> a >> b;

			if (opr == 'P')
				cout << segTree.getResult(a - 1, b - 1);
			else
				segTree.update(a - 1, b);
		}

		cout << '\n';
	}

	return 0;
}