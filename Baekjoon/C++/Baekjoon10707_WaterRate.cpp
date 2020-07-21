// Baekjoon10707_WaterRate.cpp
// https://www.acmicpc.net/problem/10707
#include <iostream>

using namespace std;

int main(void) {
	int a, b, c, d, p;
	cin >> a >> b >> c >> d >> p;

	int x = a * p;
	int y = (( c > p ) ? b : (b + ( p - c ) * d));

	cout << (( x < y ) ? x : y) << '\n';

	return 0;
}