// Codeforces_1594C.cpp
#include <iostream>

#include <string>

using namespace std;

void solveTestCase() {
	int n; char c;
	cin >> n >> c;

	string str;
	cin >> str;

	int cNum = 0;
	for (int i = 0; i < str.size(); i++)
		if (str[i] == c)
			cNum++;

	if (cNum == n)
		cout << 0;
	else {
		if (str[n - 1] == c) {
			cout << 1 << '\n';
			cout << n;
		} else if (cNum == n - 1) {
			cout << 1 << '\n';
			cout << n - 1;
		} else {
			cout << 2 << '\n';
			cout << n << ' ' << n - 1;
		}
	}
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
