// LeetCode0091_DecodeWays.cpp
// https://leetcode.com/problems/decode-ways/
class Solution {
    int dp[100][100];

    bool isValid(char a) {
        if (a == '0')
            return false;
        else
            return true;
    }

    bool isValid(char a, char b) {
        if (a == '0' || b == 0)
            return false;
        else if (a == '1')
            return true;
        else if (a == '2' && b <= '6')
            return true;
        else
            return false;
    }

    int solve(string& s, int start, int end) {
        if (dp[start][end] == -1) {
            if (start == end) {
                if (s[start] == '0')
                    dp[start][end] = 0;
                else
                    dp[start][end] = 1;
            } else {
                dp[start][end] = 0;
                if (isValid(s[start]))
                    dp[start][end] += solve(s, start + 1, end);

                if (isValid(s[start], s[start + 1])) {
                    if (start + 1 == s.size() - 1)
                        dp[start][end] += 1;
                    else
                        dp[start][end] += solve(s, start + 2, end);
                }
            }
        }

        return dp[start][end];
    }

public:
    int numDecodings(string s) {
        int n = s.size();
        for (int i = 0; i < n; i++)
            fill(dp[i], dp[i] + n, -1);

        return solve(s, 0, n - 1);
    }
};