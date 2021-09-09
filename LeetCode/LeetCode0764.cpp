// LeetCode0764.cpp
// https://leetcode.com/problems/largest-plus-sign/
class Solution {
public:
	int orderOfLargestPlusSign(int n, vector<vector<int>>& mines) {
		bool zero[500][500] = { false, };
		for (int i = 0; i < mines.size(); i++)
			zero[mines[i][0]][mines[i][1]] = true;

		// up, left, down, right
		int dp[4][500][500] = { 0, };
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (i != 0 && !zero[i - 1][j])
					dp[0][i][j] = dp[0][i - 1][j] + 1;

				if (j != 0 && !zero[i][j - 1] != 0)
					dp[1][i][j] = dp[1][i][j - 1] + 1;
			}
		}

		for (int i = n - 1; i >= 0; i--) {
			for (int j = n - 1; j >= 0; j--) {
				if (i != n - 1 && !zero[i + 1][j])
					dp[2][i][j] = dp[2][i + 1][j] + 1;

				if (j != n - 1 && !zero[i][j + 1])
					dp[3][i][j] = dp[3][i][j + 1] + 1;
			}
		}

		int ans = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (!zero[i][j]) {
					int value = 500;
					for (int k = 0; k < 4; k++)
						value = min(value, dp[k][i][j]);

					ans = max(ans, value + 1);
				}
			}
		}

		return ans;
	}
};