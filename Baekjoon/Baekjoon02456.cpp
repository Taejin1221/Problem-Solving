// Baekjoon02456.cpp
// https://www.acmicpc.net/problem/2456
#include <iostream>

#include <vector>

using namespace std;

int main(void) {
	int n;
	cin >> n;

	int candidate[3][4] = { { 0, } };
	for (int i = 0; i < n; i++) {
		int scores[3];
		cin >> scores[0] >> scores[1] >> scores[2];

		for (int j = 0; j < 3; j++) {
			candidate[j][0] += scores[j];

			candidate[j][scores[j]]++;
		}
	}

	int maxIdx = 0;
	for (int i = 1; i < 3; i++)
		if (candidate[maxIdx][0] < candidate[i][0])
			maxIdx = i;

	vector<int> sameWithMax;
	for (int i = 0; i < 3; i++)
		if (i != maxIdx && candidate[i][0] == candidate[maxIdx][0])
			sameWithMax.push_back(i);

	if (sameWithMax.size() == 0)
		cout << maxIdx + 1 << ' ' << candidate[maxIdx][0];
	else if (sameWithMax.size() == 1) {
		int maxIdx2 = sameWithMax[0];

		if (candidate[maxIdx][3] > candidate[maxIdx2][3])
			cout << maxIdx + 1 << ' ' << candidate[maxIdx][0];
		else if (candidate[maxIdx][3] < candidate[maxIdx2][3])
			cout << maxIdx2 + 1 << ' ' << candidate[maxIdx2][0];
		else {
			if (candidate[maxIdx][2] > candidate[maxIdx2][2])
				cout << maxIdx + 1 << ' ' << candidate[maxIdx][0];
			else if (candidate[maxIdx][2] < candidate[maxIdx2][2])
				cout << maxIdx2 + 1 << ' ' << candidate[maxIdx2][0];
			else
				cout << 0 << ' ' << candidate[maxIdx][0];
		}
	} else {
		int maxIdx3 = 0;
		for (int i = 1; i < 3; i++)
			if (candidate[maxIdx3][3] < candidate[i][3])
				maxIdx3 = i;

		vector<int> max3;
		for (int i = 0; i < 3; i++)
			if (candidate[maxIdx3][3] == candidate[i][3])
				max3.push_back(i);

		if (max3.size() == 1)
			cout << max3[0] + 1 << ' ' << candidate[max3[0]][0];
		else if (max3.size() == 2) {
			if (candidate[max3[1]][2] < candidate[max3[0]][2])
				cout << max3[0] + 1 << ' ' << candidate[max3[0]][0];
			else if (candidate[max3[0]][2] < candidate[max3[1]][2])
				cout << max3[1] + 1 << ' ' << candidate[max3[1]][0];
			else
				cout << 0 << ' ' << candidate[max3[0]][0];
		} else {
			cout << 0 << ' ' << candidate[0][0];
		}
	}

	return 0;
}