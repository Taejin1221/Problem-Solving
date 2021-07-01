// LeetCode0089_GrayCode.cpp
// https://leetcode.com/problems/gray-code/
class Solution {
public:
    vector<int> grayCode(int n) {
        vector<int> temp[2];
        
        int totalNum = 1 << n;
        int table[65537] = { false, };
        temp[0].push_back(0);
        temp[1].push_back(1);
        table[0] = table[1] = true;
        
        for (int i = 0; i < totalNum / 2; i++) {
            for (int j = 0; j < 2; j++) {
                int curr = temp[j].back();
                for (int k = 0; k < n; k++) {
                    int flipNum = curr ^ (1 << k);
                    if (!table[flipNum]) {
                        table[flipNum] = true;
                        temp[j].push_back(flipNum);
                        break;
                    }
                }
            }
        }
        
        for (int i = temp[1].size() - 1; i >= 0; i--)
            temp[0].push_back(temp[1][i]);
        
        return temp[0];
    }
};