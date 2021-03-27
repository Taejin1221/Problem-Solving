// LeetCode0086_PartitionList.cpp
// https://leetcode.com/problems/partition-list/
class Solution {
public:
	ListNode* partition( ListNode* head, int x ) {
		if ( head == NULL )
			return NULL;

		int part1Idx = 0, part2Idx = 0;
		ListNode* part1[200], * part2[200] = { NULL, };

		for ( ListNode* curr = head; curr; curr = curr->next ) {
			if ( curr->val < x )
				part1[part1Idx++] = curr;
			else
				part2[part2Idx++] = curr;
		}

		ListNode* newHead, * prev;
		if ( part1Idx != 0 ) {
			newHead = part1[0];

			prev = newHead;
			for ( int i = 1; i < part1Idx; i++, prev = prev->next )
				prev->next = part1[i];

			for ( int i = 0; i < part2Idx; i++, prev = prev->next )
				prev->next = part2[i];
		} else {
			newHead = part2[0];

			prev = newHead;
			for ( int i = 1; i < part2Idx; i++, prev = prev->next )
				prev->next = part2[i];
		}

		prev->next = NULL;

		return newHead;
	}
};