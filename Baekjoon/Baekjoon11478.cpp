// Baekjoon11478.cpp
// https://www.acmicpc.net/problem/11478
#include <iostream>

#include <set>
#include <deque>
#include <string>

using namespace std;

int main(void) {
	string str;
	cin >> str;

	set<string> hashTable;


	int strSize = str.size();
	for (int i = 0; i < strSize; i++) {
		string temp;
		for (int j = i; j < strSize; j++) {
			temp.push_back(str[j]);
			hashTable.insert(temp);
		}
	}

	cout << hashTable.size() << '\n';

	return 0;
}