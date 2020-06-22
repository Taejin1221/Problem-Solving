# Prob0094_BinaryTreeInorderTraversal.py
class Solution:
	def inorderTraversal(self, root: TreeNode) -> List[int]:
		nums = []

		def Inorder(root:TreeNode) -> None:
			if (root is not None):
				Inorder(root.left)
				nums.append(root.val)
				Inorder(root.right)

		Inorder(root)

		return nums

	def inorderTraversal(self, root: TreeNode) -> List[int]:
		nums = []
		stck = []

		curr = root
		while curr or stck:
			if curr:
				stck.append(curr)
				curr = curr.left
			else:
				curr = stck.pop()
				nums.append(curr.val)
				curr = curr.right

		return nums
