// Baekjoon26069.cpp
// https://www.acmicpc.net/problem/26069
#include <iostream>

#include <set>
#include <string>

using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int t;
	cin >> t;

	bool dance = false;
	set<string> dancing;
	while (t--) {
		string a, b;
		cin >> a >> b;

		if (!dance) {
			if (a == "ChongChong" || b == "ChongChong") {
				dancing.insert(a);
				dancing.insert(b);

				dance = true;
			}
		} else {
			if (dancing.find(a) != dancing.end() || dancing.find(b) != dancing.end()) {
				dancing.insert(a);
				dancing.insert(b);
			}
		}
	}

	cout << dancing.size() << '\n';

	return 0;
}