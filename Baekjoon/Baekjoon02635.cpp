// Baekjoon02635.cpp
// https://www.acmicpc.net/problem/2635
#include <iostream>

#include <vector>

using namespace std;

int main(void) {
	int a1;
	cin >> a1;

	vector<int> ans;

	for (int i = 1; i <= a1; i++) {
		vector<int> temp;
		temp.push_back(a1);
		temp.push_back(i);

		while (temp.back() >= 0) {
			int size = temp.size();
			temp.push_back(temp[size - 2] - temp[size - 1]);
		}
		temp.pop_back();

		if (ans.size() < temp.size())
			ans = temp;
	}

	cout << ans.size() << '\n';
	for (int& a : ans)
		cout << a << ' ';
	cout << '\n';

	return 0;
}