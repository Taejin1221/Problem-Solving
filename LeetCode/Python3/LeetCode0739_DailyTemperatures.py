# LeetCode0739_DailyTemperatures.py
class Solution:
	def dailyTemperatures( self, t: List[int] ) -> List[int]:
		length = len( t )

		rtrnList = []
		hashTable = { }
		for idx in range( length - 1, -1, -1 ):
			hashTable[t[idx]] = idx

			minIdx = False
			for h in hashTable:
				if h > t[idx]:
					if not minIdx or minIdx > hashTable[h]:
						minIdx = hashTable[h]

			if minIdx:
				rtrnList.append( minIdx - idx )
			else:
				rtrnList.append( 0 )

		return reversed( rtrnList )
