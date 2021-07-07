// Baekjoon02166_AreaOfPolygon.cpp
// https://www.acmicpc.net/problem/2166
#include <cstdio>
#include <cmath>

using namespace std;

struct Coord {
	double x, y;
	Coord( ): x(0), y(0) { }
};

double CCW( Coord pos1, Coord pos2, Coord pos3 ) {
	return ( ( pos1.x * pos2.y + pos2.x * pos3.y + pos3.x * pos1.y )
		- ( pos1.y * pos2.x + pos2.y * pos3.x + pos3.y * pos1.x ) );
}

int main(void) {
	int n;
	scanf("%d", &n);

	Coord coordinates[10'000];
	for ( int i = 0; i < n; i++ )
		scanf("%lf %lf", &coordinates[i].x, &coordinates[i].y);

	double area = 0.0;
	for ( int i = 2; i < n; i++ )
		area += CCW( coordinates[0], coordinates[i - 1], coordinates[i] ) / 2.0;

	printf("%.1lf\n", fabs( area ) );

	return 0;
}
