// Baekjoon03079_Imigration.cpp
// https://www.acmicpc.net/problem/3079
#include <iostream>

typedef unsigned long long ull;

using namespace std;

int n, m;
int times[100000];

bool isPossible( ull mid ) { 
	ull sum = 0;
	for ( int i = 0; i < n; i++ )
		sum += mid / times[i];

	return ( sum >= m );
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin >> n >> m;

	int maxVal = 0;
	for ( int i = 0; i < n; i++ ) {
		cin >> times[i];
		maxVal = ( times[i] < maxVal ) ? maxVal : times[i];
	}

	ull left = 1, right = (ull)m * maxVal;
	while ( left + 1 < right) {
		ull mid = ( left + right ) / 2;
		if ( isPossible( mid ) )
			right = mid;
		else
			left = mid;
	}

	cout << right << '\n';

	return 0;
}