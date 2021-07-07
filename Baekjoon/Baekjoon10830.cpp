// Baekjoon10830_MatrixPower.cpp
// https://www.acmicpc.net/problem/10830
#include <iostream>

#define MOD 1'000

using namespace std;

struct Matrix {
	int n;
	int matrix[5][5];

	Matrix( ) {
		n = 0;
		for ( int i = 0; i < 5; i++ )
			for ( int j = 0; j < 5; j++ )
				matrix[i][j] = 0;
	}

	void SetMatrix( int n ) {
		this->n = n;
		for ( int i = 0; i < n; i++ )
			for ( int j = 0; j < n; j++ )
				cin >> matrix[i][j];
	}

	void PrintMatrix( ) {
		for ( int i = 0; i < n; i++ ) {
			for ( int j = 0; j < n; j++ ) {
				matrix[i][j] %= MOD;
				cout << matrix[i][j] << ' ';
			}
			cout << '\n';
		}
	}

	Matrix operator*( const Matrix& operand ) const {
		Matrix ans;
		for ( int i = 0; i < n; i++ ) {
			for ( int j = 0; j < n; j++ ) {
				for ( int k = 0; k < n; k++ ) {
					ans.matrix[i][j] += (matrix[i][k] * operand.matrix[k][j]) % MOD;
					ans.matrix[i][j] %= MOD;
				}
			}
		}

		ans.n = n;
		return ans;
	}
};

Matrix MatrixPower( Matrix mat, long long b ) {
	if ( b == 1LL )
		return mat;
	else if ( b == 2LL )
		return mat * mat;
	else {
		Matrix half = MatrixPower( mat, b / 2LL );
		half = half * half;
		if ( b % 2LL )
			half = half * mat;

		return half;
	}
}

int main(void) {
	int n;
	long long b;
	cin >> n >> b;

	Matrix mat;
	mat.SetMatrix( n );

	Matrix ans = MatrixPower( mat, b );
	ans.PrintMatrix();

	return 0;
}
