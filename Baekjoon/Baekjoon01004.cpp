// Baekjoon01004_LittlePrince.cpp
// https://www.acmicpc.net/problem/1004
#include <iostream>

using namespace std;

struct Coordinate {
	int x, y;
	Coordinate( ): x(0), y(0) { }
	Coordinate( int x, int y ): x(x), y(y) { }
};

bool isIn( Coordinate& point, Coordinate& center, int radius ) {
	int xDistance = point.x - center.x, yDistance = point.y - center.y;
	int squaredDistnace = (xDistance * xDistance) + (yDistance * yDistance);

	if ( squaredDistnace < radius * radius )
		return true;
	else
		return false;
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int t;
	cin >> t;
	while ( t-- ) {
		Coordinate start, end;
		cin >> start.x >> start.y >> end.x >> end.y;

		int n;
		cin >> n;

		int ans = 0;
		for ( int i = 0; i < n; i++ ) {
			int radius;
			Coordinate curr;
			cin >> curr.x >> curr.y >> radius;

			bool startIn = isIn( start, curr, radius );
			bool endIn = isIn( end, curr, radius );

			if ( startIn ^ endIn )
				ans++;
		}

		cout << ans << '\n';
	}

	return 0;
}