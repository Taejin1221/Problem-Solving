// Baekjoon21610_WizardSharkAndRainDance.cpp
// https://www.acmicpc.net/problem/21610
#include <iostream>

#include <vector>
#include <algorithm>

using namespace std;

typedef pair<int, int> pii;

const int rowChange[9] = { 0, 0, -1, -1, -1, 0, 1, 1, 1 };
const int colChange[9] = { 0, -1, -1, 0, 1, 1, 1, 0, -1 };

int rowSize, colSize, grid[51][51];
vector<pii> clouds;
bool prevClouds[51][51];

void MoveClouds( int dir, int move );
void RainDance( );
void WaterCopy( );
void RemoveClouds( );
void GenerateClouds( );

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int moveCommand;
	cin >> rowSize >> moveCommand;
	colSize = rowSize;

	for ( int i = 0; i < rowSize; i++ )
		for ( int j = 0; j < colSize; j++ )
			cin >> grid[i][j];

	clouds.push_back( { rowSize - 2, 0 } );
	clouds.push_back( { rowSize - 2, 1 } );
	clouds.push_back( { rowSize - 1, 0 } );
	clouds.push_back( { rowSize - 1, 1 } );

	while ( moveCommand-- ) {
		int dir, move;
		cin >> dir >> move;
		MoveClouds( dir, move );
		RainDance( );
		WaterCopy( );
		RemoveClouds( );
		GenerateClouds( );
	}

	int ans = 0;
	for ( int i = 0; i < rowSize; i++ )
		for ( int j = 0; j < colSize; j++ )
			ans += grid[i][j];

	cout << ans << '\n';

	return 0;
}

void MoveClouds( int dir, int move ) {
	for ( int i = 0; i < move; i++ ) {
		for ( pii& clo : clouds ) {
			clo.first = (clo.first + rowChange[dir] + rowSize) % rowSize;
			clo.second = (clo.second + colChange[dir] + colSize) % colSize;
		}
	}
}

void RainDance( ) {
	for ( pii& clo : clouds ) {
		grid[clo.first][clo.second]++;
	}
}

void WaterCopy( ) {
	for ( pii& clo : clouds ) {
		int currRow = clo.first, currCol = clo.second;

		int copyPlus = 0;
		for ( int i = 2; i <= 8; i += 2 ) {
			int newRow = currRow + rowChange[i], newCol = currCol + colChange[i];
			if ( ( 0 <= newRow ) && ( newRow < rowSize ) && ( 0 <= newCol ) && ( newCol < colSize ) ) {
				if ( grid[newRow][newCol] )
					copyPlus++;
			}
		}

		grid[currRow][currCol] += copyPlus;
	}
}

void RemoveClouds( ) {
	for ( int i = 0; i < rowSize; i++ )
		fill( prevClouds[i], prevClouds[i] + colSize, false );

	while ( clouds.size() ) {
		pii clo = clouds.back( ); clouds.pop_back( );
		prevClouds[clo.first][clo.second] = true;
	}
}

void GenerateClouds( ) {
	for ( int i = 0; i < rowSize; i++ ) {
		for ( int j = 0; j < colSize; j++ ) {
			if ( grid[i][j] >= 2 && !prevClouds[i][j] ) {
				clouds.push_back( { i, j } );
				grid[i][j] -= 2;
			}
		}
	}
}
