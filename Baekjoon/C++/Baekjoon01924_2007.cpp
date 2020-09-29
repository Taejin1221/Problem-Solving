// Baekjoon01924_2007.cpp
// https://www.acmicpc.net/problem/1924
#include <iostream>

using namespace std;

bool is31( int n ) {
	if ( n == 1 || n == 3 || n == 5 || n == 7 || n == 8 || n == 10 || n == 12 )
		return true;
	else
		return false;
}

bool is30( int n ) {
	if ( n == 4 || n == 6 || n == 9 || n == 11 )
		return true;
	else
		return false;
}

int main(void) {
	int x, y;
	cin >> x >> y;

	int m = 1, d = 1, num = 0;
	while ( m != x || d != y ) {
		if ( d == 28 && m == 2 )
			m++, d = 1;
		else if ( d == 31 && is31(m) )
			m++, d = 1;
		else if ( d== 30 && is30(m) )
			m++, d = 1;
		else
			d++;
		num++;
	}

	const char* day[7] = { "MON", "TUE", "WED", "THU", "FRI", "SAT", "SUN" };
	cout << day[num % 7] << '\n';

	return 0;
}