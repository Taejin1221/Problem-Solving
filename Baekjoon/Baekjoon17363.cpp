// Baekjoon17363_IfMilkFall.cpp
// https://www.acmicpc.net/problem/17363
// UCPC 2019 Preliminary B
#include <cstdio>

using namespace std;

int main(void) {
	int n, m;
	scanf("%d %d", &n, &m);

	char str1[101][101], str2[101][101];
	for ( int i = 0; i < n; i++ ) {
		scanf("%s", str1[i]);
		getchar();
	}

	for ( int i = 0; i < n; i++ ) {
		for ( int j = 0; j < m; j++ ) {
			int row = m - j - 1, col = i;
			switch ( str1[i][j] ) {
				case 46:
					str2[row][col] = 46;
					break;
				case 79:
					str2[row][col] = 79;
					break;
				case 45:
					str2[row][col] = 124;
					break;
				case 124:
					str2[row][col] = 45;
					break;
				case 47:
					str2[row][col] = 92;
					break;
				case 92:
					str2[row][col] = 47;
					break;
				case 94:
					str2[row][col] = 60;
					break;
				case 60:
					str2[row][col] = 118;
					break;
				case 118:
					str2[row][col] = 62;
					break;
				case 62:
					str2[row][col] = 94;
					break;
			}
		}
	}

	for ( int i = 0; i < m; i++ ) {
		for ( int j = 0; j < n; j++ )
			printf("%c", str2[i][j]);
		printf("\n");
	}
		
	return 0;
}