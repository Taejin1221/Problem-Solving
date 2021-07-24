// Baekjoon02309.cpp
// https://www.acmicpc.net/problem/2309
#include <iostream>

#include <vector>

using namespace std;

int currSum;
int height[9];
vector<int> smallPeople;

bool dfs(int start) {
	if (smallPeople.size() == 7 && currSum == 100)
		return true;
	else {
		for (int i = start; i < 9; i++) {
			currSum += height[i];
			smallPeople.push_back(height[i]);
			if (dfs(i + 1))
				return true;
			smallPeople.pop_back();
			currSum -= height[i];
		}

		return false;
	}
}

int main(void) {
	for (int i = 0; i < 9; i++)
		cin >> height[i];

	dfs(0);

	int n = smallPeople.size();
	for (int i = n - 2; i >= 0; i--) {
		for (int j = i; j < n - 1; j++) {
			if (smallPeople[j] > smallPeople[j + 1]) {
				int temp = smallPeople[j + 1];
				smallPeople[j + 1] = smallPeople[j];
				smallPeople[j] = temp;
			}
		}
	}

	for (int i = 0; i < n; i++)
		cout << smallPeople[i] << '\n';

	return 0;
}