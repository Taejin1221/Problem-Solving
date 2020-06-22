# LeetCode0122_BestTimeToBuySellStock2.py
class Solution:
	def maxProfit( self, prices: List[int] ) -> int:
		profit = 0
		buy, sell, nextDay = 0, 1, 2
		while nextDay < len( prices ):
			if prices[buy] > prices[sell]:
				buy = sell
				sell = nextDay
			else:
				if prices[sell] > prices[nextDay]:
					profit += prices[sell] - prices[buy]
					buy = nextDay
					sell = nextDay + 1
					nextDay = nextDay + 1
				else:
					sell = nextDay

			nextDay += 1

		if sell < len( prices ) and prices[sell] > prices[buy]:
			profit += prices[sell] - prices[buy]

		return profit
