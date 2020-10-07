// Programmers_DP_Thief.cpp
// https://programmers.co.kr/learn/courses/30/lessons/42897
#include <vector>

using namespace std;

int solution( vector<int> money ) {
	int ans = 0;

	int size = money.size();
	vector<int> dp1 ( size );
	vector<int> dp2 ( size );

	dp1[0] = dp1[1] = money[0];
	for ( int i = 2; i < size - 1; i++ )
		dp1[i] = max( money[i] + dp1[i - 2], dp1[i - 1] );

	dp2[1] = money[1];
	for ( int i = 2; i < size; i++ )
		dp2[i] = max( money[i] + dp2[i - 2], dp2[i - 1] );

	ans = max(dp1[size - 2], dp2[size - 1]);

	return ans;
}