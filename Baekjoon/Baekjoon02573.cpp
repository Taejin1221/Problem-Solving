// Baekjoon02573_Iceberg.cpp
// https://www.acmicpc.net/problem/2573
#include <iostream>

#include <algorithm>

using namespace std;

const int rowChange[4] = { -1, 0, 1, 0 }, colChange[4] = { 0, 1, 0, -1 };

int maxRow, maxCol;
int map[300][300];
bool visited[300][300];

void dfs( int row, int col ) {
	for ( int i = 0; i < 4; i++ ) {
		int newRow = row + rowChange[i], newCol = col + colChange[i];
		if ( ( 0 <= newRow && newRow < maxRow ) && ( 0 <= newCol && newCol < maxCol ) ) {
			if ( !visited[newRow][newCol] && map[newRow][newCol] ) {
				visited[newRow][newCol] = true;
				dfs( newRow, newCol );
			}
		}
	}
}

int CountIceberg( ) {
	for ( int i = 0; i < maxRow; i++ )
		fill( visited[i], visited[i] + maxCol, false );

	int numIce = 0;
	for ( int i = 0; i < maxRow; i++ ) {
		for ( int j = 0; j < maxCol; j++ ) {
			if ( map[i][j] && !visited[i][j] ) {
				visited[i][j] = true;
				dfs( i, j );
				numIce++;
			}
		}
	}

	return numIce;
}

int Melt( ) {
	int temp[300][300], nonZero = 0;
	for ( int row = 0; row < maxRow; row++ ) {
		for ( int col = 0; col < maxCol; col++ ) {
			temp[row][col] = map[row][col];
			if ( map[row][col] ) {
				int ocean = 0;
				for ( int i = 0; i < 4; i++ ) {
					int newRow = row + rowChange[i], newCol = col + colChange[i];
					if ( ( 0 <= newRow && newRow < maxRow ) && ( 0 <= newCol && newCol < maxCol ) ) {
						if ( !map[newRow][newCol] )
							ocean++;
					}
				}

				temp[row][col] = map[row][col] - ocean;
			}

			if ( temp[row][col] <= 0 )
				temp[row][col] = 0;
			else
				nonZero++;
		}
	}

	for ( int i = 0; i < maxRow; i++ )
		for ( int j = 0; j < maxCol; j++ )
			map[i][j] = temp[i][j];

	return nonZero;
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> maxRow >> maxCol;

	int nonZero = 0;
	for ( int i = 0; i < maxRow; i++ ) {
		for ( int j = 0; j < maxCol; j++ ) {
			cin >> map[i][j];
			if ( !map[i][j] )
				nonZero++;
		}
	}

	int time = 0, ans = 0;
	while ( nonZero ) {
		if ( CountIceberg( ) >= 2 ) {
			ans = time;
			break;
		}

		nonZero = Melt( );
		time++;
	}

	cout << ans << '\n';

	return 0;
}