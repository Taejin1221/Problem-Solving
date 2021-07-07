# LeetCode1394_FindLuckyIntegerInAnArray.py
class Solution:
	def findLucky( self, arr: List[int] ) -> int:
		hashtable = { }
		for num in arr:
			if num in hashtable:
				hashtable[num] += 1
			else:
				hashtable[num] = 1

		luckys = [ lucky for lucky in hashtable if lucky == hashtable[lucky] ]

		if luckys:
			return max( luckys )
		else:
			return -1
