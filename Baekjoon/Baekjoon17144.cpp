// Baekjoon17144_GoodbyeFindDust.cpp
// https://www.acmicpc.net/problem/17144

/*
Review
 * Date
 01/06/2021

 * 잡담
 문제가 재밌어 보이지만 구현이라 미루고 미루다 푼 문제. 구현이고 어려웠던 부분은 없어 그냥 풀었다.
 Gold 구현은 처음 풀어보는 것 같은데, 어렵진 않은 것 같다. 대신 시간은 다른 알고리즘 문제보다 오래 걸린다.
 구현도 많이 풀어서 푸는 시간을 줄여야 할 것 같다.

 * Solution
 main이 길어지는 것이 싫어 확산 함수인 Spread와 공기청정기 작동 함수인 OperateAirCleaner를 작성하였다.
 Spread는 기존 배열을 그대로 이용하기엔 굉장히 어려워서 2차원 배열을 하나 더 만들어 확산 후의 상황을 표현하였다.
 OperateAirCleaner는 기존 배열을 그대로 이용하였고, 이동은 단순 값 복사로 구현했다.
 미세먼지의 이동(Copy)을 표현하기 위해 공기청정기가 작동하는 반대 방향(바람의 역방향)으로 코드를 진행하였다.
 공기청정기가 작동하는 방향으로 코드를 진행하면 미세먼지가 이동할 공간의 값을 다른데에다 저장하여야 한다.
 이건 복잡하기 때문에 역으로 진행하였다.

 * Idea
 달팽이 배열과 비슷하게 외곽을 순환하는 문제여서, 옛날 생각이 났다.

 * Difficult part
 어려웠던 부분은 구현 문제라 Debugging이었다. 확실히 코드가 길어지다 보니 Compile Error도 많이 났다.
*/

#include <iostream>
#include <iomanip>

using namespace std;

int maxRow, maxCol;
int upperAc, downerAc; // Air Cleaner Position and Index

void CopyMatrix( int src[][50], int dst[][50] );
void Spread( int home[][50] );
int OperateAirCleaner( int home[][50], int totalDust );

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int time;
	cin >> maxRow >> maxCol >> time;

	// acIdx and acTop is for storing position and never use rest of codes;
	int home[50][50], totalDust = 0, acTop[2], acIdx = 0;
	for ( int i = 0; i < maxRow; i++ ) {
		for ( int j = 0; j < maxCol; j++ ) {
			cin >> home[i][j];
			if ( home[i][j] == -1 )
				acTop[acIdx++] = i;
			else
				totalDust += home[i][j];
		}
	}

	upperAc = acTop[0], downerAc = acTop[1];

	while ( time-- ) {
		Spread( home );
		totalDust = OperateAirCleaner( home, totalDust );
	}

	cout << totalDust << '\n';

	return 0;
}

void CopyMatrix( int src[][50], int dst[][50] ) {
	for ( int i = 0; i < maxRow; i++ )
		for ( int j = 0; j < maxCol; j++ )
			dst[i][j] = src[i][j];
}

void Spread( int beforeSpread[][50] ) {
	int afterSpread[50][50] = { 0, };
	afterSpread[upperAc][0] = -1;
	afterSpread[downerAc][0] = -1;

	for ( int i = 0; i < maxRow; i++ ) {
		for ( int j = 0; j < maxCol; j++ ) {
			if ( beforeSpread[i][j] > 0 ) {
				afterSpread[i][j] += beforeSpread[i][j];

				int unitDust = beforeSpread[i][j] / 5;

				int changeRow[4] = { -1, 0, 1, 0 }, changeCol[4] = { 0, 1, 0, -1 };
				for ( int k = 0; k < 4; k++ ) {
					int newRow = i + changeRow[k], newCol = j + changeCol[k];
					if ( ( 0 <= newRow && newRow < maxRow ) && ( 0 <= newCol && newCol < maxCol ) ) {
						if ( beforeSpread[newRow][newCol] != -1 ) {
							afterSpread[newRow][newCol] += unitDust;
							afterSpread[i][j] -= unitDust;
						}
					}
				}
			}
		}
	}

	CopyMatrix( afterSpread, beforeSpread );
}

int OperateAirCleaner( int home[][50], int totalDust ) {
	// Upper Wind
	totalDust -= home[upperAc - 1][0];

	for ( int i = upperAc - 1; i > 0; i-- )
		home[i][0] = home[i - 1][0];

	for ( int i = 0; i < maxCol - 1; i++ )
		home[0][i] = home[0][i + 1];

	for ( int i = 0; i < upperAc; i++ )
		home[i][maxCol - 1] = home[i + 1][maxCol - 1];

	for ( int i = maxCol - 1; i > 1; i-- )
		home[upperAc][i] = home[upperAc][i - 1];
	home[upperAc][1] = 0;

	// Downer Wind
	totalDust -= home[downerAc + 1][0];

	for ( int i = downerAc + 1; i < maxRow - 1; i++ )
		home[i][0] = home[i + 1][0];

	for ( int i = 0; i < maxCol - 1; i++ )
		home[maxRow - 1][i] = home[maxRow - 1][i + 1];

	for ( int i = maxRow - 1; i > downerAc; i-- )
		home[i][maxCol - 1] = home[i - 1][maxCol - 1];

	for ( int i = maxCol - 1; i > 1; i-- )
		home[downerAc][i] = home[downerAc][i - 1];
	home[downerAc][1] = 0;

	return totalDust;
}
