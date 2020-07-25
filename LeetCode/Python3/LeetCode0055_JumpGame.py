# LeetCode0055_JumpGame.py
# https://leetcode.com/problems/jump-game/
class Solution:
	def canJump( self, nums: List[int] ) -> bool:
		numsLen = len( nums )
		canQ = [ True ] + [ False ] * (numsLen - 1)

		for idx, n in enumerate( nums ):
			if canQ[idx]:
				for i in range( n, 0, -1 ):
					if (idx + i < numsLen and not canQ[idx + i]):
						canQ[idx + i] = True
						if idx + i == numsLen - 1:
							return True
					elif ( idx + i < numsLen and canQ[idx + i] == True ):
						break

		return canQ[numsLen - 1]
