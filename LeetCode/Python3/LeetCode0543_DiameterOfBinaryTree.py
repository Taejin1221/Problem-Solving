# LeetCode0543_DiameterOfBinaryTree.py
class Solution:
	lengthTable = { }
	maxLen = 0
	def getLength( self, root: TreeNode ) -> int:
		if root:
			if root in self.lengthTable:
				return self.lengthTable[root]
			else:
				length = max( self.getLength( root.left ), self.getLength( root.right ) ) + 1

				self.lengthTable[root] = length

				return length
		else:
			return 0

	def diameterOfBinaryTree( self, root: TreeNode ) -> int:
		if root:
			tempMaxLen = max( self.diameterOfBinaryTree( root.left ), self.diameterOfBinaryTree( root.right ) )
			self.maxLen = max( tempMaxLen, self.getLength( root.left ) + self.getLength( root.right ) )

			return self.maxLen
		else:
			return 0
