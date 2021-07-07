// LeetCode0048_RotateImage.cpp
struct Position {
	int row;
	int col;
};

class Solution {
public:
	void rotate(vector<vector<int>>& matrix) {
		const int n = matrix.size();

		int start = 0;
		while ((n / 2) > start) {
			Position prev = { start, start - 1 };

			for (int i = 0; i < (n - 1 - (start	* 2)); i++) {
				prev.col++;

				int prevValue = matrix[prev.row][prev.col];
				for (int j = 0; j < 4; j++) {
					Position next = { prev.col, ((n - 1) - prev.row) };

					int temp = matrix[next.row][next.col];
					matrix[next.row][next.col] = prevValue;
					prevValue = temp;

					prev = next;
				}
			}

			start++;
		}
	}
};
