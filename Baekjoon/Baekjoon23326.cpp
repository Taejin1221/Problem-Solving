// Hongik_G.cpp
#include <iostream>

#include <algorithm>

using namespace std;

typedef pair<int, int> pii;

pii min(pii a, pii b) {
	if (a.first == b.first)
		return (a.second < b.second) ? a : b;
	else
		return (a.first < b.first) ? a : b;
}

class SegmentTree {
	pii* tree;
	int minIdx, maxIdx;

	class Range {
	public:
		int start, end;
		Range(): start(0), end(0) { }
		Range(int s, int e): start(s), end(e) { }
		int getMid() {
			return (start + end) / 2;
		}
	};

public:
	SegmentTree(bool arr[], int size) {
		tree = new pii[size * 4];

		minIdx = 0, maxIdx = size - 1;
		makeTree(1, Range(minIdx, maxIdx), arr);
	}

	~SegmentTree() {
		delete[] tree;
	}

	void makeTree(int treeIdx, Range curr, bool arr[]) {
		if (curr.start == curr.end) {
			if (arr[curr.start])
				tree[treeIdx] = { -1, curr.start };
			else
				tree[treeIdx] = { 1, curr.start };
		} else {
			int left = treeIdx * 2, right = treeIdx * 2 + 1;
			makeTree(left, Range(curr.start, curr.getMid()), arr);
			makeTree(right, Range(curr.getMid() + 1, curr.end), arr);

			tree[treeIdx] = min(tree[left], tree[right]);
		}
	}

	pii findShortest(int start, int end) {
		return findShortest(1, Range(minIdx, maxIdx), Range(start, end));
	}

	pii findShortest(int treeIdx, Range curr, Range target) {
		if (target.start <= curr.start && curr.end <= target.end)
			return tree[treeIdx];
		else if (curr.end < target.start || target.end < curr.start)
			return make_pair(1, 0x3f3f3f3f);
		else {
			return min(findShortest(treeIdx * 2, Range(curr.start, curr.getMid()), target),
				findShortest(treeIdx * 2 + 1, Range(curr.getMid() + 1, curr.end), target));
		}
	}

	void update(int targetIdx) {
		update(1, Range(minIdx, maxIdx), targetIdx);
	}

	void update(int treeIdx, Range curr, int targetIdx) {
		if (curr.start == curr.end && curr.start == targetIdx)
			tree[treeIdx].first *= -1;
		else if (curr.start <= targetIdx && targetIdx <= curr.end) {
			update(treeIdx * 2, Range(curr.start, curr.getMid()), targetIdx);
			update(treeIdx * 2 + 1, Range(curr.getMid() + 1, curr.end), targetIdx);

			tree[treeIdx] = min(tree[treeIdx * 2], tree[treeIdx * 2 + 1]);
		}
	}
};

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int n, q;
	cin >> n >> q;

	bool* arr = new bool[n];
	for (int i = 0; i < n; i++)
		cin >> arr[i];

	int currPos = 0;
	SegmentTree st(arr, n);
	while (q--) {
		int query;
		cin >> query;

		if (query == 1) {
			int x;
			cin >> x;
			x--;

			arr[x] = !arr[x];
			st.update(x);
		} else if (query == 2) {
			int x;
			cin >> x;

			currPos = (currPos + x) % n;
		} else {
			if (arr[currPos])
				cout << 0;
			else {
				pii value1 = st.findShortest(currPos + 1, n - 1);
				pii value2 = st.findShortest(0, currPos - 1);

				if (value1.first == -1)
					cout << value1.second - currPos;
				else if (value2.first == -1)
					cout << n - currPos + value2.second;
				else
					cout << -1;
			}
			cout << '\n';
		}
	}

	delete[] arr;

	return 0;
}