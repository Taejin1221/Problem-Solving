// Programmers_DP_IntegerTriangle.cpp
// https://programmers.co.kr/learn/courses/30/lessons/43105
#include <vector>

using namespace std;

int solution( vector<vector<int>> triangle ) {
	int answer = 0;

	int size = triangle.size();

	vector<vector<int>> dp;
	dp.push_back( vector<int> ( 1 ) );
	dp[0][0] = triangle[0][0];

	for ( int i = 1; i < size; i++ ) {
		dp.push_back( vector<int> ( i + 1 ) );

		dp[i][0] = dp[i - 1][0] + triangle[i][0];
		dp[i][i] = dp[i - 1][i - 1] + triangle[i][i];
		for ( int j = 1; j < i; j++ )
			dp[i][j] = max( dp[i - 1][j], dp[i - 1][j - 1] ) + triangle[i][j];
	}

	for ( int i  = 0; i < size; i++ )
		answer = max( dp[size - 1][i], answer );

	return answer;
}