// LeetCode0295.cpp
class MedianFinder {
	priority_queue<int> small;
	priority_queue<int, vector<int>, greater<int>> big;

public:
	MedianFinder() {
		small = priority_queue<int> ();
		big = priority_queue<int, vector<int>, greater<int>> ();
	}

	void addNum(int num) {
		if (small.size() == big.size()) {
			if (!small.empty() && small.top() > num) {
				big.push(small.top()); small.pop();
				small.push(num);
			} else
				big.push(num);
		}
		else if (small.size() < big.size()) {
			if (big.top() > num)
				small.push(num);
			else {
				small.push(big.top()); big.pop();
				big.push(num);
			}
		}
	}

	double findMedian() {
		if (big.size() > small.size())
			return big.top();
		else
			return (small.top() + big.top()) / 2.0;
	}
};