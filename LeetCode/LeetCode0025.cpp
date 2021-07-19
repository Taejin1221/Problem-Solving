// LeetCode0025.cpp
// https://leetcode.com/problems/reverse-nodes-in-k-group/
class Solution {
public:
	ListNode* reverseKGroup(ListNode* head, int k) {
		if (head == nullptr)
			return head;

		vector<ListNode*> stck;

		ListNode* curr = head;
		for (int i = 0; curr != nullptr && i < k; i++, curr = curr->next) {
			stck.push_back(curr);
		}

		if (stck.size() < k)
			return head;
		else {
			ListNode* nextNode = stck.back()->next;
			ListNode* prev = stck.back(); stck.pop_back();
			head = prev;
			while (stck.size()) {
				prev->next = stck.back();
				prev = stck.back(); stck.pop_back();
			}

			prev->next = reverseKGroup(nextNode, k);

			return head;
		}
	}
};