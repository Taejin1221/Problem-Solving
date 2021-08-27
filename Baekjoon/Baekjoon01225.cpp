// Baekjoon01225.cpp
// https://www.acmicpc.net/problem/1225
#include <iostream>
#include <string>

using namespace std;

int main(void) {
	string a, b;
	cin >> a >> b;

	long long result = 0ll;
	for (int i = 0; i < a.size(); i++)
		for (int j = 0; j < b.size(); j++)
			result += (long long)(a[i] - '0') * (b[j] - '0');

	cout << result << '\n';

	return 0;
}