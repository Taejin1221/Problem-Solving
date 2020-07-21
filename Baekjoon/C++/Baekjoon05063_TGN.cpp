// Baekjoon05063_TGN.cpp
// https://www.acmicpc.net/problem/5063
#include <iostream>

using namespace std;

int main(void) {
	int t;
	cin >> t;

	while ( t-- ) {
		int r, e, c;
		cin >> r >> e >> c;

		if ( r < e - c )
			cout << "advertise\n";
		else if ( r > e - c )
			cout << "do not advertise\n";
		else
			cout << "does not matter\n";
	}

	return 0;
}