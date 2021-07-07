// Baekjoon05625_Pastries.cpp
// https://www.acmicpc.net/problem/5625
#include <iostream>
#include <string>

#define MAX_ARR_SIZE 1'000'002
#define endl '\n'

using namespace std;

int max( int a, int b, int c );
int min( int a, int b, int c );

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int n;
	cin >> n;

	int xPreprocess[MAX_ARR_SIZE] = { 0, };
	int yPreprocess[MAX_ARR_SIZE] = { 0, };
	for ( int i = 0; i < n; i++ ) {
		int x1, y1, x2, y2, x3, y3;
		cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;

		xPreprocess[min( x1, x2, x3 ) + 1] += 1; xPreprocess[max( x1, x2, x3 )] -= 1;
		yPreprocess[min( y1, y2, y3 ) + 1] += 1; yPreprocess[max( y1, y2, y3 )] -= 1;
	}

	for ( int i = 1; i < MAX_ARR_SIZE; i++ ) {
		xPreprocess[i] += xPreprocess[i - 1];
		yPreprocess[i] += yPreprocess[i - 1];
	}

	int m;
	cin >> m;

	int val;
	char inst, equal;
	for ( int i = 0; i < m; i++ ) {
		cin >> inst >> equal >> val;
		if ( inst == 'x' )
			cout << xPreprocess[val];
		else
			cout << yPreprocess[val];
		cout << endl;
	}

	return 0;
}

int max( int a, int b, int c ) {
	if ( a >= b && a >= c )
		return a;
	else if ( b >= a && b >= c )
		return b;
	else
		return c;
}

int min( int a, int b, int c ) {
	if ( a <= b && a <= c )
		return a;
	else if ( b <= a && b <= c )
		return b;
	else
		return c;
}