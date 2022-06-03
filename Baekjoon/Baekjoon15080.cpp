// Baekjoon15080.cpp
#include <iostream>

using namespace std;

int main(void) {
	char colon;
	int h1, m1, s1;
	cin >> h1 >> colon >> m1 >> colon >> s1;

	int h2, m2, s2;
	cin >> h2 >> colon >> m2 >> colon >> s2;

	int ans = 0;
	if (s2 < s1) {
		s2 += 60;
		m2 -= 1;
	}
	ans += s2 - s1;

	if (m2 < m1) {
		m2 += 60;
		h2 -= 1;
	}
	ans += (m2 - m1) * 60;

	if (h2 < h1)
		h2 += 24;
	ans += (h2 - h1) * 3600;

	cout << ans << '\n';

	return 0;
}