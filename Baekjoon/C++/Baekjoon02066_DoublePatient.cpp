// Baekjoon02066_DoublePatient.cpp
// https://www.acmicpc.net/problem/2066
#include <cstdio>

#define ROW 9
#define COL 4

using namespace std;

int main(void) {
	char cards[ROW + 1][COL + 1], temp;
	for ( int i = 1; i <= ROW; i++ )
		for ( int j = COL; j > 0; j-- )
			scanf(" %c %c", &cards[i][j], &temp );

	int idx[10];
	double dp[5][5][5][5][5][5][5][5][5];

	dp[0][0][0][0][0][0][0][0][0] = 1;
	for ( idx[1] = 0; idx[1] <= COL; idx[1]++ ) {
		for ( idx[2] = 0; idx[2] <= COL; idx[2]++ ) {
			for ( idx[3] = 0; idx[3] <= COL; idx[3]++ ) {
				for ( idx[4] = 0; idx[4] <= COL; idx[4]++ ) {
					for ( idx[5] = 0; idx[5] <= COL; idx[5]++ ) {
						for ( idx[6] = 0; idx[6] <= COL; idx[6]++ ) {
							for ( idx[7] = 0; idx[7] <= COL; idx[7]++ ) {
								for ( idx[8] = 0; idx[8] <= COL; idx[8]++ ) {
									for ( idx[9] = 0; idx[9] <= COL; idx[9]++ ) {
										int count = 0;
										for ( int i = 1; i <= ROW - 1; i++ )
											for ( int j = i + 1; j <= ROW; j++ )
												if ( idx[i] != 4 && idx[j] != 4 )
													if ( cards[i][idx[i] + 1] == cards[j][idx[j] + 1] )
														count++;

										for ( int i = 1; i <= ROW - 1; i++ ) {
											for ( int j = i + 1; j <= ROW; j++ ) {
												if ( idx[i] != 4 && idx[j] != 4 ) {
													if ( cards[i][idx[i] + 1] == cards[j][idx[j] + 1] ) {
														int temp[10];
														for ( int k = 1; k <= 9; k++ )
															temp[k] = idx[k];
														temp[i]++; temp[j]++;

														dp[temp[1]][temp[2]][temp[3]][temp[4]][temp[5]][temp[6]][temp[7]][temp[8]][temp[9]] += dp[idx[1]][idx[2]][idx[3]][idx[4]][idx[5]][idx[6]][idx[7]][idx[8]][idx[9]] / (double)count;
													}
												}
											}
										}

									}
								}
							}
						}
					}
				}
			}
		}
	}

	printf("%.6lf\n", dp[COL][COL][COL][COL][COL][COL][COL][COL][COL]);

	return 0;
}