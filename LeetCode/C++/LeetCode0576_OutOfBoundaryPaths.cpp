// LeetCode0576_OutOfBoundaryPaths.cpp
// https://leetcode.com/problems/out-of-boundary-paths/
#define MOD 1'000'000'007

const int moves[4][2] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

class Solution {
public:
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        if (maxMove == 0)
            return 0;

        vector<vector<vector<int>>> dp(m, vector<vector<int>> (n, vector<int> (maxMove + 1)));

        for (int i = 0; i < n; i++) {
            dp[0][i][1] += 1;
            dp[m - 1][i][1] += 1;
        }

        for (int i = 0; i < m; i++) {
            dp[i][0][1] += 1;
            dp[i][n - 1][1] += 1;
        }

        for (int k = 2; k <= maxMove; k++) {
            for (int i = 0; i < m; i++) {
                for (int j = 0; j < n; j++) {
                    for (int l = 0; l < 4; l++) {
                        int rowNext = i + moves[l][0], colNext = j + moves[l][1];
                        if ((0 <= rowNext && rowNext < m) && (0 <= colNext && colNext < n))
                            dp[i][j][k] = (dp[i][j][k] + dp[rowNext][colNext][k - 1]) % MOD;
                    }
                }
            }
        }

        int ans = 0;
        for (int k = 1; k <= maxMove; k++)
            ans = (ans + dp[startRow][startColumn][k]) % MOD;

        return ans;
    }
};