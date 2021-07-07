// Baekjoon10797_10thDayNoDriving.cpp
// https://www.acmicpc.net/problem/10797
#include <iostream>

using namespace std;

int main(void) {
	int n;
	cin >> n;

	int count = 0;
	for ( int i = 0; i < 5; i++ ) {
		int temp;
		cin >> temp;

		if ( temp == n )
			count++;
	}

	cout << count << '\n';

	return 0;
}