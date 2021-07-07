// Baekjoon02965_ThreeKangaroo.cpp
// https://www.acmicpc.net/problem/2965
#include <iostream>

using namespace std;

int main(void) {
	int a, b, c;
	cin >> a >> b >> c;

	cout << ( max( b - a, c - b ) - 1 ) << '\n';

	return 0;
}