// Baekjoon16673.cpp
// https://www.acmicpc.net/problem/16673
#include <iostream>

using namespace std;

int main(){
	int c, k, p;
	cin >> c >> k >> p;

	int ans = 0;
	for (int i = 1; i <= c; i++) {
		ans += k * i + p * i * i;
	}

	cout << ans << '\n';

	return 0;
}
