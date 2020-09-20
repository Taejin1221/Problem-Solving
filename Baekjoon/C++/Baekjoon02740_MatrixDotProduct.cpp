// Baekjoon02740_MatrixDotProduct.cpp
// https://www.acmicpc.net/problem/2740
#include <iostream>

using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int N, M, K;
	int A[100][100], B[100][100];

	cin >> N >> M;

	for ( int i = 0; i < N; i++ )
		for ( int j = 0; j < M; j++ )
			cin >> A[i][j];

	cin >> M >> K;
	for ( int i = 0; i < M; i++ )
		for ( int j = 0; j < K; j++ )
			cin >> B[i][j];

	int C[100][100] = { 0, };
	for ( int i = 0; i < N; i++ )
		for ( int j = 0; j < K; j++ )
			for ( int k = 0; k < M; k++ )
				C[i][j] += A[i][k] * B[k][j];

	for ( int i = 0; i < N; i++ ) {
		for ( int j = 0; j < K; j++ )
			cout << C[i][j] << ' ';
		cout << '\n';
	}

	return 0;
}