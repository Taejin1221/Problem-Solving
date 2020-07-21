// Baekjoon05532_VacationHomework.cpp
// https://www.acmicpc.net/problem/5532
#include <iostream>
#include <cmath>

using namespace std;

int main(void) {
	int l, a, b, c, d;
	cin >> l >> a >> b >> c >> d;

	int korean = (int)ceil( (double)a / c );
	int math = (int)ceil( (double)b / d );

	l -= ( korean < math ) ? math : korean;

	cout << l << '\n';

	return 0;
}