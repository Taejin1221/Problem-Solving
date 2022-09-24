// Baekjoon25593.cpp
// https://www.acmicpc.net/problem/25593
#include <iostream>

#include <map>
#include <string>

using namespace std;

int main(void) {
	int n;
	cin >> n;

	const int times[4] = { 4, 6, 4, 10 };

	map<string, int> table;
	while (n--) {
		for (const int& addTime : times) {
			for (int i = 0; i < 7; i++) {
				string name;
				cin >> name;

				if (name != "-") {
					if (table.find(name) == table.end())
						table.insert({ name, 0 });
					table.find(name)->second += addTime;
				}
			}
		}
	}

	int workTime[2'000], size = 0;
	for (auto iter = table.begin(); iter != table.end(); ++iter)
		workTime[size++] = iter->second;

	bool ans = true;
	for (int i = 0; i < size - 1; i++) {
		for (int j = i + 1; j < size; j++) {
			if (abs(workTime[i] - workTime[j]) > 12) {
				ans = false;
				break;
			}
		}
	}

	if (ans)
		cout << "Yes";
	else
		cout << "No";
	cout << '\n';

	return 0;
}