// Prob1290_ConvertBinaryNumberInALinkedListToInteger.cpp
typedef struct ListNode ListNode, * ListNodePtr;

class Solution {
public:
	int getDecimalValue(ListNodePtr head) {
		int sum = 0;

		for (ListNodePtr curr = head; curr; curr = curr->next) {
			sum = sum * 2 + curr->val;
		}

		return sum;
	}
};