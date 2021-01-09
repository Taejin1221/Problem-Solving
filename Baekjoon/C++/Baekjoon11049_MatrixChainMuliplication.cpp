// Baekjoon11049_MatrixChainMuliplication.cpp
// https://www.acmicpc.net/problem/11049

/* Review
 * Date
 01/09/2021

 * Comment
 1년 전 알고리즘 수업 시간에 배웠던 행렬 곱셈 순서이다. 행렬 곱셈 순서를 왜인지 모르겠지만 O(n^2)으로 알고있었다.
 그래서 여러번 틀렸고, 책을 참고하여 맞게 O(n^3)으로 풀었다.

 * Solution
 dp[i][j] = (i부터 j까지의 행렬을 곱했을 때 곱셈 연산의 최솟값)
 dp[i][j]를 구하기 위해선 (i, i + 1)(i + 2, j)로 묶어보고, (i, i + 2)(i + 3, j)로 묶어보고... 모든 경우의 수를 구해야한다.
 그러기 위해선 일단 2개의 행렬을 묶는 경우를 더하고, 3개의 행렬을 묶는 경우등을 구해야한다.
 1. dp[i][i]는 모두 0으로 초기화한다.
 (자기 자신과 자기 자신의 곱은 0이다.)
 2. interval을 1로 두어 2개의 행렬을 계산하고, 3개의 행렬... 을 계산한다.
 3. 각 interval만큼의 i부터 j까지 여러 경우로 묶어보며 최솟값을 구한다.
*/

#include <iostream>
#include <climits>

using namespace std;

struct Matrix {
	int row, col;
};

int main(void) {
	int n;
	cin >> n;

	Matrix matrix[500];
	for ( int i = 0; i < n; i++ )
		cin >> matrix[i].row >> matrix[i].col;

	int dp[500][500] = { 0, };
	for ( int i = 0; i < n; i++ ) {
		fill( dp[i], dp[i] + n, INT_MAX );
		dp[i][i] = 0;
	}

	for ( int interval = 1; interval < n; interval++ ) {
		for ( int i = 0; i < n - interval; i++ ) {
			int j = i + interval;
			for ( int k = i; k < j; k++ )
				dp[i][j] = min( dp[i][j], dp[i][k] + dp[k + 1][j] + matrix[i].row * matrix[k].col * matrix[j].col );
		}
	}

	cout << dp[0][n - 1] << '\n';

	return 0;
}
