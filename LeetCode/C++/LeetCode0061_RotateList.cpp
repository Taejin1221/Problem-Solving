// LeetCode0061_RotateList.cpp
typedef ListNode * ListNodePtr;

class Solution {
public:
	ListNodePtr rotateRight(ListNodePtr head, int k) {
		if (!head) return NULL;
		vector<ListNodePtr> table;

		for ( ListNodePtr temp = head; temp; temp = temp->next )
			table.push_back( temp );

		for (int i = 0; i < ( k % table.size() ); i++) {
			table.insert( table.begin(), table.back() );
			table.pop_back();
		}

		head = table[0];
		for (int i = 0; i < table.size() - 1; i++)
			table[i]->next = table[i + 1];
		table[table.size() - 1]->next = NULL;

		return head;
	}
};
