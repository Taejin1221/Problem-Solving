# LeetCode1415_Thek-thLexicographicalStringOfAllHappyStringsOfLengthN.py
class Solution:
	def getHappyString( self, n: int, k: int ) -> str:
		strings = [ 'a', 'b', 'c' ]

		happy = [ ]

		def dfs( size, prev ):
			if size == n:
				happy.append( prev )
			else:
				for s in strings:
					if prev[-1] != s:
						dfs( size + 1, prev + s )

		dfs( 1, 'a' )
		dfs( 1, 'b' )
		dfs( 1, 'c' )

		if len( happy ) < k:
			return ''
		else:
			return happy[k - 1]
