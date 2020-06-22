# LeetCode1385_FindTheDistanceValueBetweenTwoArrays.py
class Solution:
	def findTheDistanceValue( self, arr1: List[int], arr2: List[int], d: int ) -> int:
		count = 0
		for val1 in arr1:
			flag = True
			for val2 in arr2:
				if ( abs( val1 - val2 ) <= d ):
					flag = False
					break
			if flag:
				count += 1

		return count
