# LeetCode1598_CrawlerLogFolder.py
# https://leetcode.com/problems/crawler-log-folder/
class Solution:
	def minOperations( self, logs: List[str] ) -> int:
		ans = 0
		for log in logs:
			if ( log == './' ):
				continue
			elif ( log == '../' ):
				if ( ans > 0 ):
					ans -= 1
			else:
				ans += 1

		return ans
