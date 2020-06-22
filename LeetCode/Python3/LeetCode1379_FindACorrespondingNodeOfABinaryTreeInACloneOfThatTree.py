# LeetCode1379_FindACorrespondingNodeOfABinaryTreeInACloneOfThatTree.py
class Solution:
	def getTargetCopy( self, original: TreeNode, cloned: TreeNode, target: TreeNode ) -> TreeNode:
		q = [ cloned ]

		while q:
			curr = q.pop(0)
			if curr.val == target.val:
				return curr

			if curr.left:
				q.append( curr.left )
			if curr.right:
				q.append( curr.right )
