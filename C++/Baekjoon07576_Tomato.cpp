// Baekjoon07576_Tomato.cpp
// https://www.acmicpc.net/problem/7576
#include <cstdio>
#include <queue>
#include <vector>

using namespace std;

struct Position {
	int r, c;
	Position(int x, int y): r(x), c(y) {};
};

int main(void) {
	int n, m;
	scanf("%d %d", &m, &n);

	int repeat = 0, zeros = 0;
	vector<Position> v;
	int tomatoes[1000][1000];
	for ( int i = 0; i < n; i++ ) {
		for ( int j = 0; j < m; j++ ) {
			scanf("%d", &tomatoes[i][j]);
			if ( tomatoes[i][j] == 1 ) {
				v.push_back( Position( i, j ) );
				repeat++;
			} else if ( tomatoes[i][j] == 0 ) {
				zeros++;
			}
		}
	}

	queue<Position> q;

	for ( int i = 0; i < (int)v.size(); i++ )
		q.push( v[i] );

	int count = -1;
	while ( !q.empty() ) {
		int tempRepeat = 0;
		while ( repeat-- ) {
			Position curr = q.front(); q.pop();

			Position surr[4] = {
				{ curr.r - 1, curr.c },
				{ curr.r, curr.c - 1 },
				{ curr.r, curr.c + 1 },
				{ curr.r + 1, curr.c },
			};

			for ( int i = 0; i < 4; i++ ) {
				Position next = surr[i];
				if ( 0 <= next.r && next.r < n && 0 <= next.c && next.c < m ) {
					if ( tomatoes[next.r][next.c] == 0 ) {
						zeros--;
						tomatoes[next.r][next.c] = 1;
						q.push( Position( next.r, next.c ) );
						tempRepeat++;
					}
				}
			}
		}
		count++;
		repeat = tempRepeat;
	}

	if ( zeros )
		puts("-1");
	else
		printf("%d\n", count);

	return 0;
}