# LeetCode0022_GenerateParentheses.py
class Solution:
	# Dynamic Programming
	def generateParenthesis( self, n: int ) -> List[str]:
		paren = [ [''] ]
		for i in range( 1, n + 1 ):
			paren.append( [] )
			for j in range( i ):
				for k in paren[j]:
					for l in paren[i - 1 - j]:
						paren[i].append('(' + k + ')' + l )

		return paren[n]

	# Backtracking
	def generateParenthesis( self, n: int) -> List[str]:
		def generate( string, open, close ):
			if ( len( string ) == 2 * n ):
				rtrn.append( string )
			else:
				if open < n:
					generate( string + '(', open + 1, close )
				
				if close < open:
					generate( string + ')', open, close + 1 )

		rtrn = []
		generate( '', 0, 0 )

		return rtrn