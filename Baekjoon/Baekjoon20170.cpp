// Baekjoon20170.cpp
// https://www.acmicpc.net/problem/20170
#include <iostream>

using namespace std;

int GCD(int a, int b) {
	return b ? GCD(b, a % b) : a;
}

int main(void) {
	int diceA[6];
	for (int i = 0; i < 6; i++)
		cin >> diceA[i];

	int sum = 0;
	for (int i = 0; i < 6; i++) {
		int num;
		cin >> num;
		for (int j = 0; j < 6; j++)
			sum += (num < diceA[j]);
	}

	int gcd = GCD(36, sum);

	cout << sum / gcd << '/' << 36 / gcd << endl;

	return 0;
}