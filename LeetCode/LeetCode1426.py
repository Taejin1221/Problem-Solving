# LeetCodeDay7_CountingElements.py
class Solution:
	# method 1 (20ms) : Using List Index
	def countElements( self, arr: List[int] ) -> int:
		table = [ False ] * 1002
		for num in arr:
			if table[num]:
				continue
			else:
				table[num] = True

		count = 0
		for num in arr:
			if table[num + 1]:
				count += 1

		return count


	# method 2 (50~60ms) : Using Dictionary
	def countElements( self, arr: List[int] ) -> int:
		table = { }

		for num in arr:
			if num not in table:
				table[num] = True

		count = 0
		for num in arr:
			if num + 1 in table:
				count += 1

		return count
