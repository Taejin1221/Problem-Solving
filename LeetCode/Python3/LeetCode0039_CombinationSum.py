# LeetCode0039_CombinationSum.py
class Solution:
	def combinationSum( self, candidates: List[int], target: int ) -> List[List[int]]:
		def dfs( prev, target ):
			if target == 0:
				rtrnList.append( prev )
			elif target < 0:
				return
			else:
				for candidate in candidates:
					if not prev or candidate <= prev[-1]:
						dfs( prev + [ candidate ], target - candidate )
	
		rtrnList = [ ]
		dfs( [ ], target )

		return rtrnList			