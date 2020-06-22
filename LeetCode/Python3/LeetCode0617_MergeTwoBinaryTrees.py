# LeetCode0617_MergeTwoBinaryTrees.py
class Solution:
	def mergeTrees( self, t1: TreeNode, t2: TreeNode ) -> TreeNode:
		def helper( root1, root2 ) -> TreeNode:
			# if both are not None
			if root1 and root2:
				newNode = TreeNode( root1.val + root2.val )
				newNode.left = helper( root1.left, root2.left )
				newNode.right = helper( root1.right, root2.right )

				return newNode
			elif root1:
				return root1
			else:
				return root2

		return helper( t1, t2 )

	def mergeTrees( self, t1: TreeNode, t2: TreeNode ) -> TreeNode:
		if t1 and t2:
			newNode = TreeNode( t1.val + t2.val )
			newNode.left = self.mergeTrees( t1.left, t2.left )
			newNode.right = self.mergeTrees( t1.right, t2.right )

			return newNode
		elif t1:
			return t1
		else:
			return t2
