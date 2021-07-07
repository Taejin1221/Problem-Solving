// Baekjoon17611_Rightpolygon.cpp
// https://www.acmicpc.net/problem/17611
#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

struct Range {
	int s, e;
};

bool compare( const Range& r1, const Range& r2 );
int Solve( Range ranges[], int size );

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;

	int vIdx = 0, hIdx = 0;
	Range verticals[50001];
	Range horizontals[50001];

	int initX, initY;
	cin >> initX >> initY;

	int prevX = initX, prevY = initY;
	for ( int i = 1; i < n; i++ ) {
		int x, y;
		cin >> x >> y;

		if ( prevX == x ) {
			if ( prevY < y ) {
				verticals[vIdx].s = prevY;
				verticals[vIdx].e = y;
			} else {
				verticals[vIdx].s = y;
				verticals[vIdx].e = prevY;
			}
			vIdx++;
		}
		else {
			if ( prevX < x ) {
				horizontals[hIdx].s = prevX;
				horizontals[hIdx].e = x;
			} else {
				horizontals[hIdx].s = x;
				horizontals[hIdx].e = prevX;
			}
			hIdx++;
		}

		prevX = x; prevY = y;
	}

	if ( prevX == initX ) {
		if ( prevY < initY ) {
			verticals[vIdx].s = prevY;
			verticals[vIdx].e = initY;
		} else {
			verticals[vIdx].s = initY;
			verticals[vIdx].e = prevY;
		}
		vIdx++;
	}
	else {
		if ( prevX < initX ) {
			horizontals[hIdx].s = prevX;
			horizontals[hIdx].e = initX;
		} else {
			horizontals[hIdx].s = initX;
			horizontals[hIdx].e = prevX;
		}
		hIdx++;
	}

	int v = Solve( horizontals, hIdx ), h = Solve( verticals, vIdx );

	cout << max( h, v ) << '\n';

	return 0;
}

bool compare( const Range& r1, const Range& r2 ) {
	if ( r1.s != r2.s )
		return r1.s < r2.s;
	else
		return r1.e < r2.e;
}

int Solve( Range ranges[], int size ) {
	int maxVal = 0;
	sort( ranges, ranges + size, compare );
	priority_queue<int, vector<int>, greater<int>> pq;
	for ( int i = 0; i < size; i++ ) {
		Range currRange = ranges[i];

		while ( !pq.empty() && (pq.top() <= currRange.s) )
			pq.pop();
		pq.push( currRange.e );

		maxVal = ( maxVal < pq.size() ) ? pq.size() : maxVal;
	}

	return maxVal;
}