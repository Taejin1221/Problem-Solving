# Prob0110_BalancedBinaryTree.py
class Solution:
	def isBalanced(self, root: TreeNode) -> bool:
		if not root:
			return True

		def getLength(root):
			if root:
				return 1 + max(getLength(root.left) , getLength(root.right))
			else:
				return 0

		if (abs(getLength(root.left) - getLength(root.right)) > 1):
			return False
		else:
			return self.isBalanced(root.left) and self.isBalanced(root.right)
