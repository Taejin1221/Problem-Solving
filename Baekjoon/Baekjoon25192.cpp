// Baekjoon25192.cpp
// https://www.acmicpc.net/problem/25192
#include <iostream>

#include <set>
#include <string>

using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;

	set<string> s;

	int ans = 0;
	while (n--) {
		string user;
		cin >> user;

		if (user == "ENTER")
			s.clear();
		else {
			if (s.find(user) == s.end()) {
				ans++;
				s.insert(user);
			}
		}
	}

	cout << ans << '\n';

	return 0;
}