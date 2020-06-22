# LeetCode0700_SearchInABinarySearchTree.py
class Solution:
	# method 1 (recursion) 80ms
	def searchBST( self, root: TreeNode, val: int ) -> TreeNode:
		if not root or root.val == val:
			return root
		elif root.val < val:
			return self.searchBST( root.right, val )
		else:
			return self.searchBST( root.left, val )

	# method 2 (iteration) 80ms
	def searchBST( self, root: TreeNode, val: int ) -> TreeNode:
		if root:
			curr = root

			while curr:
				if curr.val == val:
					return curr
				elif curr.val < val:
					curr = curr.right
				else:
					curr = curr.left

		return None
