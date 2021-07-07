// LeetCode0658_FindKClosestElements.cpp
class Node {
public:
	int x;
	int value;

	Node(int value, int x): value(value), x(x) { }

	bool operator<(const Node& n2) const {
		if (abs(value - x) == abs(n2.value - x))
			return value >= n2.value;
		else
			return abs(value - x) >= abs(n2.value - x);
	}
};

class Solution {
public:
	vector<int> findClosestElements(vector<int>& arr, int k, int x) {
		priority_queue<Node> pq;
		for (int i = 0; i < arr.size(); i++)
			pq.push(Node(arr[i], x));

		vector<int> ans;
		for (int i = 0; i < k; i++) {
			ans.push_back(pq.top().value);
			pq.pop();
		}

		sort(ans.begin(), ans.end());

		return ans;
	}
};