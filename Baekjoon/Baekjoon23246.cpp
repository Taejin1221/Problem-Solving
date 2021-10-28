// Baekjoon23246.cpp
// https://www.acmicpc.net/problem/23246
#include <iostream>

#include <algorithm>

using namespace std;

struct Node {
	int prod, sum, num;
	Node(): prod(0), sum(0), num(0) { }
	bool operator<(const Node& n2) const {
		if (prod == n2.prod) {
			if (sum == n2.sum)
				return num < n2.num;
			else
				return sum < n2.sum;
		} else
			return prod < n2.prod;
	}
};

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;

	Node players[100];
	for (int i = 0; i < n; i++) {
		cin >> players[i].num;

		int p, q, r;
		cin >> p >> q >> r;

		players[i].prod = p * q * r;
		players[i].sum = p + q + r;
	}

	sort(players, players + n);

	cout << players[0].num << ' ';
	cout << players[1].num << ' ';
	cout << players[2].num << '\n';

	return 0;
}