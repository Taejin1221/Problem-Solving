// Baekjoon12867.cpp
// https://www.acmicpc.net/problem/12867
#include <iostream>

#include <map>
#include <vector>
#include <string>

using namespace std;

int pow(int x, int y) {
	int result = 1;
	for (int i = 0; i < y; i++)
		result *= x;

	return result;
}

string toString(int value) {
	string result = "";
	if (value < 0) {
		result.push_back('-');
		value *= -1;
	}

	int temp = value, digit = 0;
	while (temp >= 10) {
		temp /= 10;
		digit++;
	}

	for (int i = digit; i >= 0; i--) {
		result.push_back((char)(value / pow(10, i) + '0'));
		value %= pow(10, i);
	}

	return result;
}

int main(void) {
	int n, m;
	cin >> n >> m;

	// cout << toString(n) << ' ' << toString(m) << endl;

	int arr[50];
	for (int i = 0; i < m; i++)
		cin >> arr[i];

	string direction;
	cin >> direction;

	vector<string> visited;
	visited.push_back("");

	bool ans = true;
	map<int, int> position;
	for (int i = 0; i < m; i++) {
		if (position.find(arr[i]) == position.end())
			position.insert({ arr[i], (direction[i] == '+' ? 1 : -1) });
		else
			position[arr[i]] += 1 * (direction[i] == '+' ? 1 : -1);

		string currPosition = "";
		for (auto iter = position.begin(); iter != position.end(); ++iter) {
			if (iter->second) {
				currPosition.append(toString(iter->first));
				currPosition.push_back(',');
				currPosition.append(toString(iter->second));
				currPosition.push_back(',');
			}
		}

		bool isVisited = false;
		for (string& str : visited) {
			if (str == currPosition) {
				isVisited = true;
				break;
			}
		}

		if (isVisited) {
			ans = false;
			break;
		} else {
			visited.push_back(currPosition);
		}
	}

	if (ans)
		cout << 1 << '\n';
	else
		cout << 0 << '\n';

	return 0;
}