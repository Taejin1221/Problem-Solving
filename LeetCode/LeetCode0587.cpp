// LeetCode0587.cpp
// https://leetcode.com/problems/erect-the-fence/
typedef vector<int> vi;

vi bottomLeft;

int getCCW(vi& a, vi& b, vi& c) {
	return (b[0] - a[0]) * (c[1] - a[1]) - (c[0] - a[0]) * (b[1] - a[1]);
}

int getDistance(vi& v1, vi& v2) {
	return (v1[0] - v2[0]) * (v1[0] - v2[0]) + (v1[1] - v2[1]) * (v1[1] - v2[1]);
}

bool compare(vi& v1, vi&v2) {
	int ccw = getCCW(bottomLeft, v1, v2);
	if (ccw != 0)
		return 0 < ccw;
	else
		return getDistance(bottomLeft, v1) < getDistance(bottomLeft, v2);
}

class Solution {
public:
	vector<vector<int>> outerTrees(vector<vector<int>>& trees) {
		int n = trees.size();
		if (n <= 2)
			return trees;

		bottomLeft = trees[0];
		for (int i = 1; i < n; i++)
			if (trees[i][1] < bottomLeft[1])
				bottomLeft = trees[i];

		sort(trees.begin(), trees.end(), compare);

		int i = n - 1;
		while (0 <= i && getCCW(bottomLeft, trees[n - 1], trees[i]) == 0)
			i--;

		for (int start = i + 1, end = n - 1; start <= end; start++, end--) {
			vi temp = trees[start];
			trees[start] = trees[end];
			trees[end] = temp;
		}

		vi stck;
		stck.push_back(0);
		stck.push_back(1);

		// cout << trees[0][0] << ' ' << trees[0][1] << endl;
		// cout << trees[1][0] << ' ' << trees[1][1] << endl;
		for (int i = 2; i < n; i++) {
			// cout << trees[i][0] << ' ' << trees[i][1] << endl;
			while (stck.size() >= 2) {
				int prev = stck.back(); stck.pop_back();
				int prevprev = stck.back();
				// cout << "prev: " << prev << ' ' << prevprev << endl;

				int ccw = getCCW(trees[prevprev], trees[prev], trees[i]);
				// cout << ccw << endl;
				if (getCCW(trees[prevprev], trees[prev], trees[i]) >= 0) {
					stck.push_back(prev);
					break;
				}
			}

			stck.push_back(i);
		}

		vector<vector<int>> ans;
		for (int i = 0; i < stck.size(); i++)
			ans.push_back(trees[stck[i]]);

		return ans;
	}
};