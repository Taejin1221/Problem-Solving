# Prob0101_SymmetricTree.py
class Solution:
	def isSymmetric(self, root: TreeNode) -> bool:
		if root == None: return True

		def helper(rootLeft: TreeNode, rootRight: TreeNode) -> bool:
			if (rootLeft == None and rootRight == None): return True
			elif (rootLeft == None or rootRight == None): return False
			else:
				if (rootLeft.val != rootRight.val): return False
				else:
					return helper(rootLeft.left, rootRight.right) and helper(rootLeft.right, rootRight.left)

		return helper(root.left, root.right)