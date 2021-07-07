# Prob0102_BinaryTreeLevelOrderTraversal.py
class Solution:
	def levelOrder(self, root: TreeNode) -> List[List[int]]:
		rtrnList = []

		if (root is not None):
			queue = [ root ]

			while (queue):
				currLevels = []
				for _ in range(len(queue)):
					curr = queue[0]
					if (curr.left): queue.append(curr.left)
					if (curr.right): queue.append(curr.right)
					currLevels.append(curr.val)
					queue.pop(0)
				rtrnList.append(currLevels)

		return rtrnList
