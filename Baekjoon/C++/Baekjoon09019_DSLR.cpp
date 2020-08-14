// Baekjoon09019_DSLR.cpp
// https://www.acmicpc.net/problem/9019
#include <iostream>
#include <string>
#include <queue>

using namespace std;

int D( int n );
int S( int n );
int L( int n );
int R( int n );

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int t;
	cin >> t;
	while ( t-- ) {
		int a, b;
		cin >> a >> b;

		queue<pair<int, string>> q;
		q.push( { a, string() } );
		while ( !q.empty() ) {
			pair<int, string> curr = q.front();
			if ( curr.first == b )
				break;
			q.pop();

			q.push( { D( curr.first ), curr.second + 'D' } );
			q.push( { S( curr.first ), curr.second + 'S' } );
			q.push( { L( curr.first ), curr.second + 'L' } );
			q.push( { R( curr.first ), curr.second + 'R' } );
		}

		cout << q.front().second << '\n';
	}

	return 0;
}

int D( int n ) {
	return ( n * 2 ) % 10'000;
}

int S( int n ) {
	return ( ( --n < 0 ) ? 9999 : n );
}

int L( int n ) {
	return ( ( n % 1000 ) * 10 + n / 1000 );
}

int R( int n ) {
	return ( ( n % 10 ) * 1000 + ( n / 10 ) );
}