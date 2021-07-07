// Baekjoon02448_PrintStar11.cpp
// https://www.acmicpc.net/problem/2448

/* Review
 * Date
 01/07/2021

 * Solution
 재귀를 이용한 별찍기 문제이다. 현재 찍으려는 행의 갯수가 3개면 가작 작은 삼각형이니 찍어준다.
 아니라면 3개의 파트로 나뉘어 재귀가 반복되기 때문에 3개의 파트로 나눠 똑같은 재귀함수를 돌려주면 된다.
 인덱스를 기준으로 전달을 해줘야하기 때문에 코드가 좀 더러워졌다.
*/

#include <iostream>
#include <algorithm>

using namespace std;

struct Range {
	int start, end;
	Range( int s, int e ): start( s ), end( e ) { }
	int currRange( ) {
		return end - start + 1;
	};
};

char star[3072][6144];

void PrintStar( Range rowRange, Range colRange );

int main(void) {
	int n;
	cin >> n;

	int maxCol = n * 2 - 1;
	for ( int i = 0; i < n; i++ )
		fill( star[i], star[i] + maxCol, ' ' );

	PrintStar( Range( 0, n - 1 ), Range( 0, maxCol - 1 ) );

	for ( int i = 0; i < n; i++ ) {
		for ( int j = 0; j < maxCol; j++ )
			cout << star[i][j];
		cout << '\n';
	}

	return 0;
}

void PrintStar( Range rowRange, Range colRange ) {
	if ( rowRange.currRange() == 3 ) {
		star[rowRange.start][colRange.start + 2] = '*';

		star[rowRange.start + 1][colRange.start + 1] = '*';
		star[rowRange.start + 1][colRange.end - 1] = '*';

		for ( int i = colRange.start; i <= colRange.end; i++ )
			star[rowRange.end][i] = '*';
	} else {
		int rowSize = rowRange.currRange(), colSize = colRange.currRange();

		int halfRow = rowSize / 2, halfCol = (colSize - 1) / 2;
		int quarter = halfCol / 2;

		PrintStar( Range( rowRange.start, rowRange.start + halfRow - 1 ),
			Range( colRange.start + quarter + 1, colRange.end - (quarter + 1) ) );

		PrintStar( Range( rowRange.start + halfRow, rowRange.end ),
			Range( colRange.start, colRange.start + halfCol - 1 ) );

		PrintStar( Range( rowRange.start + halfRow, rowRange.end ),
			Range( colRange.start + halfCol + 1, colRange.end ) );
	}
}