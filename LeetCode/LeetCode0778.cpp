// LeetCode0778_SwimInRisingWater.cpp
// https://leetcode.com/problems/swim-in-rising-water/
struct Node {
	int row, col;
	int time;

	Node(int r, int c, int t): row(r), col(c), time(t) { }

	bool operator<(const Node& n2) const {
		return time > n2.time;
	}
};

class Solution {
	int rowChange[4] = { -1, 0, 1, 0 }, colChange[4] = { 0, 1, 0, -1 };

public:
	int swimInWater(vector<vector<int>>& grid) {
		int maxRow = grid.size(), maxCol = grid[0].size();

		priority_queue<Node> pq;
		bool visited[50][50] = { false, };

		pq.push(Node(0, 0, grid[0][0]));
		visited[0][0] = true;

		int t;
		for (t = 0; t < maxRow * maxCol; t++) {
			Node top = pq.top();
			if (top.time > t)
				continue;

			bool isFind = false;
			while (!pq.empty() && top.time <= t) {
				pq.pop();
				if (top.row == maxRow - 1 && top.col == maxCol - 1) {
					isFind = true;
					break;
				}

				for (int i = 0; i < 4; i++) {
					int newRow = top.row + rowChange[i], newCol = top.col + colChange[i];
					if ((0 <= newRow && newRow < maxRow) && (0 <= newCol && newCol < maxCol)) {
						if (!visited[newRow][newCol]) {
							visited[newRow][newCol] = true;
							pq.push(Node(newRow, newCol, grid[newRow][newCol]));
						}
					}
				}

				if (!pq.empty())
					top = pq.top();
			}

			if (isFind)
				break;
		}

		return t;
	}
};