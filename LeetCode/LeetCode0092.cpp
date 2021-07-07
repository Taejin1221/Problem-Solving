// LeetCode0092_ReverseLinkedListII.cpp
// https://leetcode.com/problems/reverse-linked-list-ii/
class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        vector<ListNode*> stck;

        ListNode* curr = head, *prev = head;
        for (int i = 1; i <= right; i++, curr = curr->next) {
            if (i >= left)
                stck.push_back(curr);
            else
                prev = curr;
        }

        if (stck.front() == head) {
            head = stck.back(); stck.pop_back();
            prev = head;
        }

        ListNode* next = curr;
        for (int i = stck.size() - 1; i >= 0; i--) {
            prev->next = stck.back();
            stck.pop_back();
            prev = prev->next;
        }

        prev->next = next;

        return head;
    }
};