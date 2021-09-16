// Baekjoon06549.cpp
// https://www.acmicpc.net/problem/6549
#include <iostream>

#define INF 1'234'567'890

using namespace std;

typedef long long ll;

struct Node {
	int height, idx;

	Node(): height(INF), idx(0) { }
	Node(int v, int i): height(v), idx(i) { }
};

class Range {
public:
	int start, end;

	Range(): start(0), end(0) { }
	Range(int s, int e): start(s), end(e) { }

	int getMid() {
		return (start + end) / 2;
	}

	int getDistance() {
		return (end - start) + 1;
	}
};


Node min(const Node& n1, const Node& n2) {
	return (n1.height < n2.height) ? n1 : n2;
}

// Min Segment Tree
class SegmentTree {
private:
	Node* tree;
	Node trash;
	int minIdx, maxIdx;

public:
	SegmentTree(int size, int arr[]) {
		tree = new Node[size * 4];
		minIdx = 0, maxIdx = size - 1;

		makeTree(1, Range(minIdx, maxIdx), arr);
	}

	~SegmentTree() {
		delete[] tree;
	}

	void makeTree(int treeIdx, Range curr, int arr[]) {
		if (curr.start == curr.end)
			tree[treeIdx] = Node(arr[curr.start], curr.start);
		else {
			int mid = curr.getMid();
			int leftIdx = treeIdx * 2, rightIdx = treeIdx * 2 + 1;
			makeTree(leftIdx, Range(curr.start, mid), arr);
			makeTree(rightIdx, Range(mid + 1, curr.end), arr);

			tree[treeIdx] = min(tree[leftIdx], tree[rightIdx]);
		}
	}

	Node getMin(Range target) {
		return getMin(1, Range(minIdx, maxIdx), target);
	}

	Node getMin(int treeIdx, Range curr, Range target) {
		if (target.start <= curr.start && curr.end <= target.end)
			return tree[treeIdx];
		else if (curr.end < target.start || target.end < curr.start)
			return trash;
		else {
			return min(
				getMin(treeIdx * 2, Range(curr.start, curr.getMid()), target),
				getMin(treeIdx * 2 + 1, Range(curr.getMid() + 1, curr.end), target)
			);
		}
	}
};

int histograms[100'000];
SegmentTree* tree;

ll getLargestHistogram(Range curr) {
	if (curr.start == curr.end)
		return histograms[curr.start];
	else if (curr.end < curr.start)
		return 0ll;

	Node minNode = tree->getMin(curr);

	ll result = max(
		getLargestHistogram(Range(curr.start, minNode.idx - 1)),
		getLargestHistogram(Range(minNode.idx + 1, curr.end))
	);

	return max(result, (long long)curr.getDistance() * minNode.height);
}

void solvedTestCase(int n) {
	for (int i = 0; i < n; i++)
		cin >> histograms[i];

	tree = new SegmentTree(n, histograms);

	cout << getLargestHistogram(Range(0, n - 1)) << '\n';

	delete tree;
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int n;
	cin >> n;
	while (n) {
		solvedTestCase(n);

		cin >> n;
	}

	return 0;
}