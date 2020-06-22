# Prob0147_InsertionSortList.py
class Solution():
	def insertionSortList(self, head: ListNode) -> ListNode:
		if (not head):
			return head
		# copy linked list to list #
		curr = head
		list1 = []
		while ( curr ):
			list1.append(curr)
			curr = curr.next

		# Insertion sort #
		for i in range(1, len(list1)):
			target = list1[i].val
			idx = i - 1
			while ( idx >= 0 and target < list1[idx].val):
				idx -= 1
			list1.insert(idx + 1, list1.pop(i))

		# Reconnect Linkedlist #
		head = list1[0]
		for i in range(len(list1) - 1):
			list1[i].next = list1[i + 1]
		list1[len(list1) - 1].next = None

		return head
