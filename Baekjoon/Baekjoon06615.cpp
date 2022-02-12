// Baekjoon06615.cpp
// https://www.acmicpc.net/problem/6615
#include <iostream>

#include <vector>

using namespace std;

using ll = long long;

void getCollatzSequence(ll n, vector<int>& sequence) {
	sequence.push_back(n);
	while (n != 1) {
		if (n % 2)
			n = n * 3 + 1;
		else
			n = n / 2;
		sequence.push_back(n);
	}
}

void printAnswer(int n, int m, int sa, int sb, ll c) {
	cout << n << " needs " << sa << " steps, " << m << " needs " << sb << " steps, they meet at " << c << '\n';
}

void solveTestCase(int n, int m) {
	vector<int> sequence1, sequence2;
	getCollatzSequence(n, sequence1);
	getCollatzSequence(m, sequence2);

	bool isFind = false;
	for (int i = 0; i < sequence1.size(); i++) {
		for (int j = 0; j < sequence2.size(); j++) {
			if (sequence1[i] == sequence2[j]) {
				printAnswer(n, m, i, j, sequence1[i]);
				isFind = true;
				break;
			}
		}

		if (isFind)
			break;
	}
}

int main(void) {
	int n, m;
	cin >> n >> m;

	while (n != 0 && m != 0) {
		solveTestCase(n, m);

		cin >> n >> m;
	}

	return 0;
}