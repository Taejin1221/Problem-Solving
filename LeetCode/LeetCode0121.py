# LeetCode0121_BestTimeToBuySellStock.py
class Solution:
	def maxProfit( self, prices: List[int] ) -> int:
		profit, small = 0, float( 'inf' )
		for currPrice in prices:
			if small > currPrice:
				small = currPrice
			else:
				if currPrice - small > profit:
					profit = currPrice - small

		return profit
