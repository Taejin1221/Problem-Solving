# LeetCode0024_SwapNodesInPairs.py
class Solution:
	# method1
	def swapPairs( self, head: ListNode ) -> ListNode:
		if head is None:
			return None
			
		prev, curr = head, head
		if curr.next:
			next = curr.next
		else:
			return head

		while True:
			if prev is head:
				head = next
			else:
				prev.next = next
			curr.next = next.next
			next.next = curr

			prev = curr
			if curr.next:
				curr = curr.next
			else:
				break

			if curr.next:
				next = curr.next
			else:
				break

		return head

	# method 2 Recursion
	def swapPairs( self, head: ListNode ) -> ListNode:
		if head and head.next:
			currNode, nextNode = head, head.next

			currNode.next = self.swapPairs( nextNode.next )
			nextNode.next = currNode

			head = nextNode
		
		return head
