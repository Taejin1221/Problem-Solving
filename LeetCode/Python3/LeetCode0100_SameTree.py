# Prob0100_SameTree.py
class Solution:
	def isSameTree(self, p: TreeNode, q: TreeNode) -> bool:
		if (not p and not q):
			return True
		elif ((not p or not q) or (p.val != q.val)):
			return False
		else:
			return (self.isSameTree(p.left, q.left) and self.isSameTree(p.right, q.right))

	def isSameTree(self, p: TreeNode, q: TreeNode) -> bool:
		if (not p and not q):
			return True
		elif (not p or not q):
			return False
		else:
			if (p.val != q.val):
				return False
			else:
				return (self.isSameTree(p.left, q.left) and self.isSameTree(p.right, q.right))