// Baekjoon13140.cpp
// https://www.acmicpc.net/problem/13140
#include <iostream>

using namespace std;

const int helloIndexes[5] = { 2, 1, 3, 3, 4 };
const int worldIndexes[5] = { 6, 4, 5, 3, 0 };

int numbers[7], n;
bool visited[10] = { false, };

int makeNumber(const int indexes[]) {
	int ans = 0;
	for (int i = 0; i < 5; i++) {
		ans *= 10;
		ans += numbers[indexes[i]];
	}

	return ans;
}

int evaluate() {
	int hello = makeNumber(helloIndexes);
	int world = makeNumber(worldIndexes);

	return hello + world;
}

bool backtracking(int idx) {
	if (idx == 7 && numbers[2] != 0 && numbers[6] != 0)
		return (n == evaluate()) ? true : false;
	else {
		for (int i = 0; i < 10; i++) {
			if (!visited[i]) {
				visited[i] = true;
				numbers[idx] = i;
				if (backtracking(idx + 1))
					return true;
				visited[i] = false;
			}
		}

		return false;
	}
}

int main(void) {
	cin >> n;

	if (backtracking(0)) {
		cout << "  ";
		for (int i = 0; numbers[helloIndexes[i]] == 0; i++)
			cout << " ";
		cout << makeNumber(helloIndexes) << '\n';

		cout << "+ ";
		for (int i = 0; numbers[worldIndexes[i]] == 0; i++)
			cout << " ";
		cout << makeNumber(worldIndexes) << '\n';

		cout << "-------" << '\n';
		if (n / 100000)
			cout << " ";
		else
			cout << "  ";
		cout << n << '\n';
	} else
		cout << "No Answer\n";

	return 0;
}