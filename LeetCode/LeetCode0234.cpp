// Baekjoon0234_PaindromeLinkedList.cpp
// https://leetcode.com/problems/palindrome-linked-list/
class Solution {
public:
	bool isPalindrome(ListNode* head) {
		int len = 0;
		for ( ListNode* curr = head; curr; curr = curr->next )
			len++;
		
		int i = 0;
		vector<int> stck;
		for ( ListNode* curr = head; curr; curr = curr->next, i++ ) {
			if ( i < len / 2 )
				stck.push_back( curr->val );
			else if ( len % 2 && i == len / 2 )
				continue;
			else {
				if ( stck.back() != curr->val )
					return false;
				else
					stck.pop_back();
			}
		}
		
		return true;
	}
};