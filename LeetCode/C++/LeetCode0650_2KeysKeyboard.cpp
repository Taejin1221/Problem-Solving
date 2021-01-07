// LeetCode0650_2KeysKeyboard.cpp
// https://leetcode.com/problems/2-keys-keyboard/

/*
 * Date
 01/07/2021

 * Solution
 행을 만드려는 'A'의 갯수, 열을 복사되어 있는 'A'의 갯수로 하였다.
 즉 dp[i][j]는 'A'가 i개이고 'A'가 j개 복사되어 있기 위한 operation의 최소 갯수로 하였다.
 그리고 i는 지속적으로 증가하며 j는 i까지 증가한다면 자연스럽게 dp[i][j]는 dp[i - j][j] + 1이 된다.
 다시 말하면, 'A'가 i - j개 있고 j개가 복사 되어있을 때 붙여넣기를 하면 dp[i][j]의 갯수가 된다.
 따라서 반복하면서 최솟값을 찾아준다. 마지막으로 dp[i][i]는 단순히 copy operation을 수행하면 된다.
 그러니 i행의 최솟 값에 1을 더해준다.

 * Dificult Part
 DP 테이블을 만드는 것이 어려웠다. 행으로 해야할 것은 알았는데 열로는 무엇을 해야할지 고민했다.
 하지만 천천히 생각해서 n개의 'A'를 만들기 위해선 n - 1개를 만든 뒤 1개를 paste하거나,
 n - 2개를 만든 뒤 2개를 paste하면 된다는 생각을 하고 paste한 갯수를 열로 만들어 해결하였다.
*/

#define INF  1'000'000'000

class Solution {
public:
	int minSteps( int n ) {
		int dp[1'001][1'001];
		for ( int i = 0; i <= n; i++ )
			fill( dp[i], dp[i] + n + 1, INF );

		dp[1][0] = 0;
		dp[1][1] = 1;

		for ( int i = 2; i <= n; i++ ) {
			int minVal = INF;
			for ( int j = 1; j < i; j++ ) {
				dp[i][j] = min( dp[i][j], dp[i - j][j] + 1 );
				minVal = min( minVal, dp[i][j] );
			}

			dp[i][i] = minVal + 1;
		}

		int ans = INF;
		for ( int i = 0; i <= n; i++ )
			ans = min( ans, dp[n][i] );

		return ans;
	}
};