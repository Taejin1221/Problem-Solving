// Baekjoon23757.cpp
// https://www.acmicpc.net/problem/23757
// KCPC 2021 Div. 2 B
#include <iostream>

#include <queue>

using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n, m;
	cin >> n >> m;

	priority_queue<int> pq;
	for (int i = 0; i < n; i++) {
		int present;
		cin >> present;

		pq.push(present);
	}

	bool disappoint = false;
	for (int i = 0; i < m; i++) {
		int want;
		cin >> want;

		int gift = pq.top(); pq.pop();
		if (gift > want)
			pq.push(gift - want);
		else if (gift < want) {
			disappoint = true;
			break;
		}
	}

	cout << !disappoint << '\n';

	return 0;
}