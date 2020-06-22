# LeetCode1387_SortIntegersByThePowerValue.py
class Solution:
	def getKth( self, lo: int, hi: int, k: int ) -> int:
		def interval( val ):
			inter = 0
			while ( val is not 1 ):
				if val % 2:
					val = val * 3 + 1
				else:
					val //= 2
				inter += 1

			return inter

		intervals = [ ( interval( val ), val ) for val in range( lo, hi + 1 ) ]
		intervals.sort()

		return intervals[k - 1][1]
