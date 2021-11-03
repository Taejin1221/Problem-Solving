// Baekjoon01297.cpp
// https://www.acmicpc.net/problem/1297
#include <iostream>

#include <cmath>

using namespace std;

int main(void) {
	int d, h, w;
	cin >> d >> h >> w;

	int w_a = d * w / (sqrt(h * h + w * w));
	int h_a = d * h / (sqrt(h * h + w * w));

	cout << h_a << ' ' << w_a << '\n';

	return 0;
}