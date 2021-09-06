// LeetCode1629.cpp
// https://leetcode.com/problems/slowest-key/
class Solution {
public:
    char slowestKey(vector<int>& releaseTimes, string keysPressed) {
        int n = keysPressed.size();
        pair<char, int> ans = { keysPressed[0], releaseTimes[0] };
        
        for (int i = 1; i < n; i++) {
            int delay = releaseTimes[i] - releaseTimes[i - 1];
            if (delay > ans.second)
                ans = { keysPressed[i], delay };
            else if (delay == ans.second)
                if (ans.first < keysPressed[i])
                    ans.first = keysPressed[i];
        }
        
        return ans.first;
    }
};