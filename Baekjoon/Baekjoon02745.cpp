// Baekjoon02745_ConvertNumberSystem.cpp
// https://www.acmicpc.net/problem/2745
#include <iostream>

#include <string>

using namespace std;

int myPow( int a, int b ) {
	int result = 1;
	for ( int i = 0; i < b; i++ )
		result *= a;
	return result;
}

int main(void) {
	int B;
	string number;
	cin >> number >> B;

	int ans = 0;
	int len = number.size();
	for ( int i = 0; i < number.size(); i++ ) {
		char currChar = number[len - (i + 1)];
		if ( '0' <= currChar && currChar <= '9' )
			ans += ( currChar - '0' ) * myPow( B, i );
		else
			ans += ( currChar - 'A' + 10 ) * myPow( B, i );
	}

	cout << ans << '\n';

	return 0;
}