# LeetCode0344_ReverseString.py
class Solution:
	def reverseString( self, s: List[str] ) -> None:
		length = len( s )
		for i in range( length // 2 ):
			j = length - 1 - i
			s[i], s[j] = s[j], s[i]

	def reverseString( self, s: List[str] ) -> None:
		def helper( left, right ):
			if left < right:
				s[left], s[right] = s[right], s[left]
				helper( left + 1, right - 1 )

		helper( 0, len( s ) - 1 )
