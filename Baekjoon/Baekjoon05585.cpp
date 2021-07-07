// Baekjoon05585_Change.cpp
// https://www.acmicpc.net/problem/5585
#include <iostream>

using namespace std;

int main(void) {
	int n;
	cin >> n;

	n = 1000 - n;
	
	int coins = 0;
	coins += n / 500; n %= 500;
	coins += n / 100; n %= 100;
	coins += n / 50; n %= 50;
	coins += n / 10; n %= 10;
	coins += n / 5; n %= 5;
	coins += n / 1;

	cout << coins << '\n';

	return 0;
}