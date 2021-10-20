// Baekjoon13334.cpp
// https://www.acmicpc.net/problem/13334
#include <iostream>

#include <queue>
#include <algorithm>

using namespace std;

typedef pair<int, int> pii;
typedef long long ll;

struct Node {
	int start, end;

	Node(): start(0), end(0) { }
	Node(int v, int n): start(v), end(n) { }
	bool operator<(const Node& n2) const {
		return start > n2.start;
	}
};

bool compare(pii& p1, pii& p2) {
	return p1.second < p2.second;
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;

	pii arr[100'000];
	for (int i = 0; i < n; i++) {
		int h, o;
		cin >> h >> o;

		if (h < o) {
			arr[i].first = h;
			arr[i].second = o;
		} else {
			arr[i].first = o;
			arr[i].second = h;
		}
	}

	sort(arr, arr + n, compare);

	ll l;
	cin >> l;

	int ans = 0;
	priority_queue<Node> pq;
	for (int i = 0; i < n; i++) {
		int curr = arr[i].second;
		pq.push(Node(arr[i].first, arr[i].second));
		while (!pq.empty() && pq.top().start < curr - l)
			pq.pop();

		ans = max(ans, (int)pq.size());
	}

	cout << ans << '\n';

	return 0;
}