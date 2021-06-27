// LeetCode1914_CyclicallyRotatingAGrid.cpp
// https://leetcode.com/problems/cyclically-rotating-a-grid/
class Solution {
public:
    vector<vector<int>> rotateGrid(vector<vector<int>>& grid, int num) {
        int m = grid.size(), n = grid[0].size();

        vector<vector<int>> ans(m, vector<int>(n));
        for (int start = 0; start < min(m, n) / 2; start++) {
            int currM = m - 2 * start, currN = n - 2 * start;

            int cellNum = currM * 2 + currN * 2 - 4;
            int currNum = num % (cellNum);
            
            deque<int> oneLayer;

            int startRow = start, endRow = m - start, startCol = start, endCol = n - start;
            for (int i = startRow; i < endRow - 1; i++) oneLayer.push_back(grid[i][startCol]);
            for (int i = startCol; i < endCol - 1; i++) oneLayer.push_back(grid[endRow - 1][i]);
            for (int i = endRow - 1; i > startRow; i--) oneLayer.push_back(grid[i][endCol - 1]);
            for (int i = endCol - 1; i > startCol; i--) oneLayer.push_back(grid[startRow][i]);

            for (int k = 0; k < currNum; k++) {
                int first = oneLayer.back(); oneLayer.pop_back();
                oneLayer.push_front(first);
            }
            
            for (int i = startRow; i < endRow - 1; i++) {
                ans[i][startCol] = oneLayer.front(); oneLayer.pop_front();
            }
            
            for (int i = startCol; i < endCol - 1; i++) {
                ans[endRow - 1][i] = oneLayer.front(); oneLayer.pop_front();
            }
            
            for (int i = endRow - 1; i > startRow; i--) {
                ans[i][endCol - 1] = oneLayer.front(); oneLayer.pop_front();
            }
            
            for (int i = endCol - 1; i > startCol; i--) {
                ans[startRow][i] = oneLayer.front(); oneLayer.pop_front();
            }
            
        }
        
        return ans;
    }
};