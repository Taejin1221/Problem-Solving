// Baekjoon13414.cpp
// https://www.acmicpc.net/problem/13414
#include <iostream>

#include <map>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(pair<string, int>& a, pair<string, int>& b) {
	return a.second < b.second;
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int k, l;
	cin >> k >> l;

	map<string, int> hashTable;
	for (int i = 0; i < l; i++) {
		string temp;
		cin >> temp;

		if (hashTable.find(temp) == hashTable.end()) // 없을 때
			hashTable.insert({temp, i});
		else
			hashTable[temp] = i;
	}

	vector<pair<string, int>> arr;
	for (auto iter = hashTable.begin(); iter != hashTable.end(); ++iter)
		arr.push_back(*iter);

	sort(arr.begin(), arr.end(), compare);

	for (int i = 0; i < min((int)arr.size(), k); i++)
		cout << arr[i].first << '\n';

	return 0;
}