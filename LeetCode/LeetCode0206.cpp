// LeetCode0206.cpp
// https://leetcode.com/problems/reverse-linked-list/
class Solution {
public:
	ListNode* reverseList(ListNode* head) {
		if (head == nullptr)
			return head;

		stack<ListNode*> stck;

		ListNode* curr;
		for (curr = head; curr != nullptr; curr = curr->next)
			stck.push(curr);

		ListNode* ans = stck.top(); stck.pop();

		for (curr = ans; !stck.empty(); curr = curr->next) {
			curr->next = stck.top(); stck.pop();
		}
		curr->next = nullptr;

		return ans;
	}
};