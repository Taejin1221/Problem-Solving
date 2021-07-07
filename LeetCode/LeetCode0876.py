# LeetCode0876_MiddleOfTheLinkedList.py
class Solution:
	def middleNode( self, head: ListNode ) -> ListNode:
		nodeList = [ ]
		curr = head
		while curr:
			nodeList.append( curr )
			curr = curr.next

		return nodeList[ len( nodeList ) // 2 ]
