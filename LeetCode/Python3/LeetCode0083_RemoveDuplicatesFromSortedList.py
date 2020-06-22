# Prob0083_RemoveDuplicatesFromSortedList.py
class Solution:
	def deleteDuplicates(self, head: ListNode) -> ListNode:
		if head is None: return None
		
		curr = head.next
		prev = head
		target = head.val

		while curr:
			if target == curr.val:
				prev.next = curr.next
			else:
				target = curr.val
				prev = curr
			curr = curr.next

		return head

	def deleteDuplicates(self, head: ListNode) -> ListNode:
		curr = head

		while curr:
			while curr.next and curr.val == curr.next.val:
				curr.next = curr.next.next
			curr = curr.next

		return head