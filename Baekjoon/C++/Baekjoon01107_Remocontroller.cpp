// Baekjoon01107_Remocontroller.cpp
// https://www.acmicpc.net/problem/1107
#include <iostream>
#include <string>

#define abs( x ) ( ( ( x ) > 0 ) ? ( x ) : ( -( x ) ) )

using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	string target;
	cin >> target;

	int n;
	cin >> n;

	bool remocon[10] = { true, true, true, true, true, true, true, true, true, true };
	for ( int i = 0; i < n; i++ ) {
		int temp;
		cin >> temp;

		remocon[temp] = false;
	}

	int click = 500'001;
	if ( n != 10 ) {
		click = 0;
		for ( char s : target ) {
			int minDiff = -100;
			for ( int i = 0; i < 10; i++)
				if ( remocon[i] )
					if ( abs( s - '0' - i ) < abs( s - '0' - minDiff ) )
						minDiff = i;

			click += minDiff;
			click *= 10;
		}
		click /= 10;
	}

	int a = abs( stoi( target ) - click ) + target.size(), b = abs( stoi( target ) - 100 );
	cout << ( a < b ? a : b ) << '\n';

	return 0;
}