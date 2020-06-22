# LeetCode1437_CheckIfAll1sAreAtLeastLengthKPlacesAway.py
class Solution:
	def kLengthApart( self, nums: List[int], k: int ) -> bool:
		prevIdx = -1
		for idx, bina in enumerate( nums ):
			if bina:
				if prevIdx < 0:
					prevIdx = idx
				else:
					if idx - prevIdx - 1 < k:
						return False
					else:
						prevIdx = idx

		return True
