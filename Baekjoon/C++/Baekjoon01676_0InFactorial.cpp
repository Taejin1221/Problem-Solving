// Baekjoon01676_0InFactorial.cpp
// https://www.acmicpc.net/problem/1676
#include <iostream>

using namespace std;

int main(void) {
	int n;
	cin >> n;

	int answer;
	answer += n / 5;
	answer += n / 25;
	answer += n / 125;

	cout << answer << '\n';

	return 0;
}