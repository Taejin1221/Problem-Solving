// Baekjoon02011_CipherCode.cpp
// https://www.acmicpc.net/problem/2011
#include <iostream>
#include <string>

#define MOD 1'000'000

using namespace std;

// 0 -> not Alphabet, 1 -> is Alphabet, -1 -> can not decode
int canDecoded( char c1, char c2 ) {
	if ( c2 == '0' && (c1 >= '3' || c1 == '0') )
		return -1;
	else if ( c1 == '0' )
		return 0;

	int num = (c1 - '0') * 10 + (c2 - '0');
	return ( ( num <= 26 ) ? 1 : 0 );
}

int main(void) {
	string str;
	cin >> str;

	int n = str.size();

	bool decodeFlag = true;
	int dp[5'000] = { 0, };
	if ( str[0] != '0' )
		dp[0] = 1;
	else
		decodeFlag = false;

	if ( n > 1 ) {
		int decodeResult = canDecoded( str[0], str[1] );
		if ( decodeResult == -1 )
			decodeFlag = false;
		else if ( decodeResult == 0 || str[1] == '0' )
			dp[1] = 1;
		else
			dp[1] = 2;

		for ( int i = 2; i < n; i++ ) {
			int decodeResult = canDecoded( str[i - 1], str[i] );
			if ( decodeResult == 1 )
				dp[i] += dp[i - 2];
			else if ( decodeResult == -1 ) {
				decodeFlag = false;
				break;
			}

			if ( str[i] != '0' )
				dp[i] += dp[i - 1];

			dp[i] %= MOD;
		}
	}

	if ( decodeFlag )
		cout << dp[n - 1] << '\n';
	else
		cout << 0 << '\n';

	return 0;
}
