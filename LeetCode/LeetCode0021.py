# LeetCode0021_MergeTwoSortedList.py
class Solution:
	def mergeTwoLists( self, l1: ListNode, l2: ListNode ) -> ListNode:
		if not l1 and not l2:
			return None
		elif not l1:
			newNode = ListNode( l2.val )
			l2 = l2.next
		elif not l2:
			newNode = ListNode( l1.val )
			l1 = l1.next
		else:
			if l1.val < l2.val:
				newNode = ListNode( l1.val )
				l1 = l1.next
			else:
				newNode = ListNode( l2.val )
				l2 = l2.next

		newNode.next = self.mergeTwoLists( l1, l2 )

		return newNode
