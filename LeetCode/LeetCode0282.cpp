// LeetCode0282.cpp
// https://leetcode.com/problems/expression-add-operators/
#define IS_OPERATOR(x) ((x) == '+' || (x) == '*' || (x) == '-')

typedef long long ll;
typedef pair<char, int> pci;

class Solution {
	vector<string> ans;

	void backtracking(string& num, int idx, string& currExpression, char prevOperator, ll prevOperand, ll value, int& target) {
		if (idx == num.size()) {
			if (value == target)
				ans.push_back(currExpression);
		} else {
			int currDigit = num[idx] - '0';

			currExpression.push_back('+'); currExpression.push_back(num[idx]);
			backtracking(num, idx + 1, currExpression, '+', currDigit, value + currDigit, target);
			currExpression.pop_back(); currExpression.pop_back();

			currExpression.push_back('-'); currExpression.push_back(num[idx]);
			backtracking(num, idx + 1, currExpression, '-', -currDigit, value - currDigit, target);
			currExpression.pop_back();currExpression.pop_back();

			currExpression.push_back('*'); currExpression.push_back(num[idx]);
			ll currValue = (prevOperator == '+' || prevOperator == '-') ? value - prevOperand + (prevOperand * currDigit) : value * currDigit;
			backtracking(num, idx + 1, currExpression, '*', currDigit, currValue, target);
			currExpression.pop_back(); currExpression.pop_back();

			ll currOperand;
			if (prevOperand < 0)
				currOperand = (prevOperand * 10 - currDigit);
			else if (prevOperand > 0)
				currOperand = (prevOperand * 10 + currDigit);
			else
				return;

			if (prevOperator == '*') {
				currValue = value / prevOperand;
				currValue *= currOperand;
			} else {
				currValue = value - prevOperand;
				currValue += currOperand;
			}

			currExpression.push_back(num[idx]);
			backtracking(num, idx + 1, currExpression, prevOperator, currOperand, currValue, target);
			currExpression.pop_back();
		}
	}

public:
	vector<string> addOperators(string num, int target) {
		string currExpression = { num[0] };
		backtracking(num, 1, currExpression, '\0', num[0] - '0', num[0] - '0', target);

		return ans;
	}
};