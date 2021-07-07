# Prob0104_MaximumDepthOfBinaryTree.py
class Solution:
	def maxDepth(self, root) -> int:
		if not root:
			return 0

		queue = []
		depth = 1

		queue.append((root, depth))
		while (queue):
			curr = queue.pop(0)

			if curr[0].left:
				queue.append((curr[0].left, curr[1] + 1))
			if curr[0].right:
				queue.append((curr[0].right, curr[1] + 1))

			if (curr[1] > depth): depth = curr[1]

		return depth

	def maxDepth(self, root) -> int:
		def helper(root) -> int:
			if not root:
				return 0

			else:
				return max(helper(root.left), helper(root.right)) + 1

		return helper(root)

	def maxDepth(self, root) -> int:
		if not root:
			return 0
		else:
			return max(self.maxDepth(root.left), self.maxDepth(root.right)) + 1
