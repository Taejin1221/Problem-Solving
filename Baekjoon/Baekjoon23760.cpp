// Baekjoon23760.cpp
// https://www.acmicpc.net/problem/23760
// KCPC 2021 Div. 2 E
#include <iostream>

using namespace std;

struct Range {
	int start, end;
	Range(int s, int e): start(s), end(e) { }
	Range getLeft() {
		return Range(start, (start + end) / 2);
	}

	Range getRight() {
		return Range((start + end) / 2 + 1, end);
	}
};

int tree[400'000];

void makeTree(int treeIdx, Range curr, int arr[]) {
	if (curr.start == curr.end)
		tree[treeIdx] = arr[curr.start];
	else {
		makeTree(treeIdx * 2, curr.getLeft(), arr);
		makeTree(treeIdx * 2 + 1, curr.getRight(), arr);

		tree[treeIdx] = tree[treeIdx * 2] + tree[treeIdx * 2 + 1];
	}
}

int get_i_th_element(int treeIdx, Range curr, int target) {
	if (curr.start == curr.end)
		return curr.start;
	else {
		if (target <= tree[treeIdx * 2])
			return get_i_th_element(treeIdx * 2, curr.getLeft(), target);
		else
			return get_i_th_element(treeIdx * 2 + 1, curr.getRight(), target - tree[treeIdx * 2]);
	}
}

void addTo(int treeIdx, Range curr, int target, int add) {
	if (curr.start == curr.end && curr.start == target)
		tree[treeIdx] += add;
	else if (curr.start <= target && target <= curr.end) {
		addTo(treeIdx * 2, curr.getLeft(), target, add);
		addTo(treeIdx * 2 + 1, curr.getRight(), target, add);

		tree[treeIdx] = tree[treeIdx * 2] + tree[treeIdx * 2 + 1];
	}
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n, m;
	cin >> n >> m;

	int arr[100'001] = { 0, };
	for (int i = 0; i < n; i++) {
		int temp;
		cin >> temp;
		arr[temp]++;
	}

	makeTree(1, Range(0, 100'000), arr);

	int want[100'000];
	for (int i = 0; i < m; i++)
		cin >> want[i];

	int mercy[100'000];
	for (int i = 0; i < m; i++)
		cin >> mercy[i];

	bool disappoint = false;
	for (int i = 0; i < m; i++) {
		int gift = get_i_th_element(1, Range(0, 100'000), n - mercy[i] + 1);
		if (gift >= want[i]) {
			addTo(1, Range(0, 100'000), gift, -1);
			addTo(1, Range(0, 100'000), gift - want[i], 1);
		} else {
			disappoint = true;
			break;
		}
	}

	cout << !disappoint << '\n';

	return 0;
}