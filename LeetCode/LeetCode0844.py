# LeetCode0844_BackspaceStringCompare.py
class Solution:
	def backspaceCompare( self, S: str, T: str ) -> bool:
		S_stck, T_stck = [ ], [ ]
		for s in S:
			if s is '#':
				if S_stck:
					S_stck.pop()
			else:
				S_stck.append( s )

		for t in T:
			if t is '#':
				if T_stck:
					T_stck.pop()
			else:
				T_stck.append( t )

		if ( ''.join( S_stck ) == ''.join( T_stck ) ):
			return True
		else:
			return False
