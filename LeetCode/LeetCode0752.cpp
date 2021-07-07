// LeetCode0752_OpenTheLock.cpp
// https://leetcode.com/problems/open-the-lock/
class Solution {
public:
	int openLock(vector<string>& deadends, string target) {
		set<string> deadTable;
		for (string& s : deadends) {
			if (s == "0000")
				return -1;
			else
				deadTable.insert(s);
		}

		set<string> visited;
		queue<pair<string, int>> q;
		visited.insert("0000");
		q.push({"0000", 0});

		int ans = -1;
		while (!q.empty()) {
			pair<string, int> curr = q.front(); q.pop();

			if (curr.first == target) {
				ans = curr.second;
				break;
			}

			for (int i = 0; i < 4; i++) {
				string next[2] = { curr.first, curr.first };
				if (curr.first[i] == '0') {
					next[0][i] = '9';
					next[1][i] = '1';
				} else if (curr.first[i] == '9') {
					next[0][i] = '8';
					next[1][i] = '0';
				} else {
					next[0][i]--;
					next[1][i]++;
				}

				if (deadTable.find(next[0]) == deadTable.end() && visited.find(next[0]) == visited.end()) {
					visited.insert(next[0]);
					q.push({next[0], curr.second + 1});
				}

				if (deadTable.find(next[1]) == deadTable.end() && visited.find(next[1]) == visited.end()) {
					visited.insert(next[1]);
					q.push({next[1], curr.second + 1});
				}
			}
		}

		return ans;
	}
};