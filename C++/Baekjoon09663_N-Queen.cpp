// Baekjoon09633_N-Queen.cpp
#include <iostream>
#include <vector>

using namespace std;

typedef struct {
	int row, col;
} Position;

int count = 0;
int n;

bool isValid( vector<Position>& queens, Position curr ) {
	for ( Position pos : queens )
		if ( ( pos.col == curr.col ) || ( pos.row - pos.col == curr.row - curr.col ) ||
			( pos.col + pos.row == curr.col + curr.row ) )
			return false;

	return true;
}

void dfs( vector<Position>& queens, int size ) {
	if ( size == n )
		count++;
	else
		for ( int j = 0; j < n; j++ ) {
			Position curr = { size, j };
			if ( isValid( queens, curr ) ) {
				queens.push_back( curr );
				dfs( queens, size + 1 );
				queens.pop_back();
			}
		}
}

int main( void ) {
	cin >> n;
	
	vector<Position> queens;
	for ( int j = 0; j < n; j++ ) {
		queens.push_back( { 0, j } );
		dfs( queens, 1 );
		queens.pop_back();
	}

	cout << count << "\n";

	return 0;
}
