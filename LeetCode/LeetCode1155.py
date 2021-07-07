# LeetCode1155_NubmerOfDiceRollsWithTargetSum.py
# https://leetcode.com/problems/number-of-dice-rolls-with-target-sum/
class Solution:
	def numRollsToTarget( self, dice: int, face: int, target: int ) -> int:
		'''
		dp[i][j] : j개의 주사위로 i를 만들 수 있는 경우의 수
		i를 j개로 만드려면 1개로 1 ~ face를 만들고 j - 1개로 나머지 만듬
		따라서 dp[i][j] = dp[i - k][j - 1];
		'''
		dp = [ [ 0 for _ in range( dice + 1 ) ] for _ in range( target + 1 ) ]

		# 기본적으로 1개의 주사위로 만들 수 있는 경우의 수는 1개, f가 target보다 크면 indexOutOfBound기 때문에 min( face + 1, target + 1 )로 설정
		for i in range( 1, min( face + 1, target + 1 ) ):
			dp[i][1] = 1

		for i in range( 1, target + 1 ):
			for j in range( 2, dice + 1 ):
				for k in range( 1, min( face + 1, target + 1 ) ): # 주사위 눈
					if ( k < i ):
						dp[i][j] = ( dp[i][j] + dp[i - k][j - 1] ) % 1_000_000_007

		return dp[target][dice]