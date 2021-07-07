# LeetCode0206_ReverseLinkedList.py
class Solution:
	# method 1 (20ms)
	def reverseList( self, head: ListNode ) -> ListNode:
		def helper( prev, curr ):
			if curr.next:
				head = helper( curr, curr.next )
				curr.next = prev
			else:
				curr.next = prev
				head = curr

			return head

		if head:
			return helper( None, head )
		else:
			return None

	# method 2 (44ms)
	def reverseList( self, head: ListNode ) -> ListNode:
		if head.next:
			newHead = self.reverseList( head.next )
			head.next.next = head
			head.next = None

			head = newHead
		
		return head
