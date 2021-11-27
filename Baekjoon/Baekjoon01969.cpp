// Baekjoon01969.cpp
// https://www.acmicpc.net/problem/1969
#include <iostream>

#include <string>

using namespace std;

int getHammingDistance(string& a, string& b) {
	int result = 0;
	for (int i = 0; i < (int)a.size(); i++)
		result += (a[i] != b[i]);

	return result;
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n, m;
	cin >> n >> m;

	string arr[1'000];
	for (int i = 0; i < n; i++)
		cin >> arr[i];

	string s;
	for (int i = 0; i < m; i++) {
		int acgt[4] = { 0, };
		for (int j = 0; j < n; j++) {
			if (arr[j][i] == 'A')
				acgt[0]++;
			else if (arr[j][i] == 'C')
				acgt[1]++;
			else if (arr[j][i] == 'G')
				acgt[2]++;
			else if (arr[j][i] == 'T')
				acgt[3]++;
		}

		int maxIdx = 0;
		for (int i = 0; i < 4; i++)
			if (acgt[maxIdx] < acgt[i])
				maxIdx = i;

		if (maxIdx == 0)
			s.push_back('A');
		else if (maxIdx == 1)
			s.push_back('C');
		else if (maxIdx == 2)
			s.push_back('G');
		else if (maxIdx == 3)
			s.push_back('T');
	}

	int sumHD = 0;
	for (int i = 0; i < n; i++)
		sumHD += getHammingDistance(s, arr[i]);

	cout << s << '\n' << sumHD << '\n';

	return 0;
}