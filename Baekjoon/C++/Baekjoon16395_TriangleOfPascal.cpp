// Baekjoon16395_TriangleOfPascal.cpp
// https://www.acmicpc.net/problem/16395
#include <iostream>

using namespace std;

int main(void) {
	int n, k;
	cin >> n >> k;

	int pascal[31][31] = { 0, };
	pascal[1][1] = 1;

	for ( int i = 2; i <= n; i++ )
		for ( int j = 1; j <= i; j++ )
			pascal[i][j] = pascal[i - 1][j - 1] + pascal[i - 1][j];

	cout << pascal[n][k] << '\n';

	return 0;
}