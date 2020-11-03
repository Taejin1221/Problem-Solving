// Baekjoon02530_AIClock.cpp
// https://www.acmicpc.net/problem/2530
#include <iostream>

using namespace std;

int main(void) {
	int h, m, s;
	cin >> h >> m >> s;

	int ovenSecond;
	cin >> ovenSecond;

	h += ovenSecond / 3600;
	ovenSecond %= 3600;
	m += ovenSecond / 60;
	ovenSecond %= 60;
	s += ovenSecond;

	m += s / 60;
	s %= 60;
	h += m / 60;
	m %= 60;

	cout << h % 24 << ' ';
	cout << m << ' ';
	cout << s << '\n';

	return 0;
}
