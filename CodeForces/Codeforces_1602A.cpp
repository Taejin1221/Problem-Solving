// Codeforces_1602A.cpp
#include <iostream>

#include <string>

using namespace std;

void solveTestCase() {
	string s;
	cin >> s;

	pair<char, int> a = { s[0], 0 };
	for (int i = 1; i < (int)s.size(); i++)
		a = (a.first > s[i]) ? make_pair(s[i], i) : a;

	cout << a.first << ' ';
	for (int i = 0; i < (int)s.size(); i++)
		if (i != a.second)
			cout << s[i];
	cout << '\n';
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int t;
	cin >> t;
	while (t--) {
		solveTestCase();
	}

	return 0;
}
