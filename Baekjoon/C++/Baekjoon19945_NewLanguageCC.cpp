// Baekjoon19945_NewLanguageCC.cpp
// https://www.acmicpc.net/problem/19945
#include <iostream>

using namespace std;

int main(void) {
	int n;
	cin >> n;

	if ( n < 0 )
		cout << 32 << '\n';
	else if ( n == 0 )
		cout << 1 << '\n';
	else {
		int ans, num = 1;
		for ( ans = 1; n > num; ans++ )
			num = num << 1;
	
		if ( n == num )
			cout << ans << '\n';
		else
			cout << ans - 1 << '\n';
	}

	return 0;
}