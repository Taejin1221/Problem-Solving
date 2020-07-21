// Baekjoon17362_MathIsPE2.cpp
// https://www.acmicpc.net/problem/17362
// UCPC 2019 Preliminary A
#include <iostream>

using namespace std;

int main(void) {
	int n;
	cin >> n;

	int temp = n % 8;
	if ( temp == 1 )
		cout << 1;
	else if ( temp == 0 || temp == 2 )
		cout << 2;
	else if ( temp == 3 || temp == 7 )
		cout << 3;
	else if ( temp == 4 || temp == 6 )
		cout << 4;
	else
		cout << 5;

	return 0;
}
