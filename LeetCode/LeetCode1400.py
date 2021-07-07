# LeetCode1400_ConstructKPalindromeStrings.py
class Solution:
	# method 1 ( 104ms )
	def canConstruct( self, string: str, k: int ) -> bool:
		length = len( string )
		if k > length:
			return False

		char = { }
		for s in string:
			if s in char:
				char[s] += 1
			else:
				char[s] = 1

		numChar = len( char )
		odd, even = 0, 0
		for c in char:
			if char[c] % 2:
				odd += 1
			else:
				even += 1

		if numChar <= k:
			return True
		else:
			if odd <= k:
				return True
			else:
				return False

	# method 2 ( 72ms )
	def canConstruct( self, string: str, k: int ) -> bool:
		if k > len( string ):
			return False

		char = collections.Counter( string )
		odd = sum( c % 2 for c in char.values() )

		numChar = len( char )

		if numChar <= k:
			return True
		else:
			if odd <= k:
				return True
			else:
				return False
