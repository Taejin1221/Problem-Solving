// LeetCode0023_Merge-k-Sorted-Lists.cpp
// https://leetcode.com/problems/merge-k-sorted-lists/
struct Node {
	ListNode* head;
	Node( ListNode* list ): head( list ) { }
	bool operator<( Node head2 ) const {
		return head->val > head2.head->val;
	}
};

class Solution {
public:
	ListNode* mergeKLists( vector<ListNode*>& lists ) {
		if ( lists.size() == 0 )
			return NULL;

		priority_queue<Node> pq;
		for ( int i = 0; i < lists.size(); i++ ) {
			if ( lists[i] )
				pq.push( Node( lists[i] ) );
		}

		if ( pq.size() > 0 ) {
			ListNode* topHead = pq.top().head; pq.pop();
			if ( topHead->next )
				pq.push( Node( topHead->next ) );
			ListNode* head = new ListNode( topHead->val );

			ListNode* curr = head;
			while ( !pq.empty() ) {
				topHead = pq.top().head; pq.pop();
				if ( topHead->next )
					pq.push( Node( topHead->next ) );
				curr->next = new ListNode( topHead->val );
				curr = curr->next;
			}
			curr->next = NULL;

			return head;
		} else
			return NULL;
	}
};