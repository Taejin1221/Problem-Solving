// Baekjoon17265.cpp
// https://www.acmicpc.net/problem/17265
#include <iostream>

#include <string>
#include <vector>

using namespace std;

int n;
char map[5][5];
vector<string> expressions;

void dfs(int row, int col, string currExp) {
	if (row == n - 1 && col == n - 1)
		expressions.push_back(currExp);

	if (row + 1 < n)
		dfs(row + 1, col, currExp + map[row + 1][col]);

	if (col + 1 < n)
		dfs(row, col + 1, currExp + map[row][col + 1]);
}

int evaluate(string exp) {
	int res = exp[0] - '0';
	char currOperator;
	for (int i = 1; i < exp.size(); i++) {
		char& c = exp[i];
		if ('0' <= c && c <= '5') {
			int currNum = c - '0';
			switch (currOperator) {
				case '+':
					res += currNum;
					break;
				case '-':
					res -= currNum;
					break;
				case '*':
					res *= currNum;
					break;
			}
		} else {
			currOperator = c;
		}
	}

	return res;
}

int main(void) {
	cin >> n;

	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cin >> map[i][j];

	string temp = "";
	temp.push_back(map[0][0]);
	dfs(0, 0, temp);

	pair<int, int> ans = { -0x3f3f3f3f, 0x3f3f3f3f }; // { max, min }
	for (string& exp : expressions) {
		int evalResult = evaluate(exp);

		ans.first = max(ans.first, evalResult);
		ans.second = min(ans.second, evalResult);
	}

	cout << ans.first << ' ' << ans.second << '\n';

	return 0;
}