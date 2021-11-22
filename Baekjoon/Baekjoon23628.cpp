// Baekjoon23628.cpp
// https://www.acmicpc.net/problem/23628
#include <iostream>

using namespace std;

int main(void) {
	int year, month, day;

	cin >> year >> month >> day;
	int day1 = year * 12 * 30 + month * 30 + day;

	cin >> year >> month >> day;
	int day2 = year * 12 * 30 + month * 30 + day;

	int period = day2 - day1;
	int currRest = 15 * (period / 360);
	for (int i = 1; i <= period / 360; i++)
		currRest += (i - 1) / 2;
	cout << currRest << ' ';
	cout << min(36, period / 30) << '\n';

	cout << period << "days" << '\n';

	return 0;
}