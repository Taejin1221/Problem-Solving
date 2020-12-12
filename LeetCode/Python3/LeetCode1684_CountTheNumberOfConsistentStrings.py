# LeetCode1684_CountTheNumberOfConsistentStrings.py
# https://leetcode.com/problems/count-the-number-of-consistent-strings/
# LeetCode Biweekly Contest 41
class Solution:
	def countConsistentStrings( self, allowed: str, words: List[str] ) -> int:
		count = 0
		for word in words:
			for w in word:
				if ( w not in allowed ):
					break
			else:
				count += 1

		return count
