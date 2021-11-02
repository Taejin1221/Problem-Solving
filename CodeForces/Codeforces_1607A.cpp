// Codeforces_1607A.cpp
#include <iostream>

#include <string>

using namespace std;

void solveTestCase() {
	int position[128] = { 0, };
	for (int i = 0; i < 26; i++) {
		char c;
		cin >> c;

		position[c] = i;
	}

	string str;
	cin >> str;

	int ans = 0, prevPosition = position[str[0]];
	for (int i = 1; i < str.size(); i++) {
		ans += abs(prevPosition - position[str[i]]);
		prevPosition = position[str[i]];
	}

	cout << ans << '\n';
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
