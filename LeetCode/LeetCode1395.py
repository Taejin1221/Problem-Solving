# LeetCode1395_CountNumberOfTeams.py
class Solution:
	def numTeams( self, rating: List[int] ) -> int:
		global teams
		teams = 0

		length = len( rating )

		def DFS1( prev, size, idx ):
			if size == 3:
				global teams
				teams += 1
			else:
				for i in range( idx, length ):
					if ( ( not prev ) or ( prev[-1] < rating[i] ) ):
						DFS1( prev + [ rating[i] ], size + 1, i + 1 )

		def DFS2( prev, size, idx ):
			if size == 3:
				global teams
				teams += 1
			else:
				for i in range( idx, length ):
					if ( ( not prev ) or ( prev[-1] > rating[i] ) ):
						DFS2( prev + [ rating[i] ], size + 1, i + 1 )

		DFS1( [], 0, 0 ); DFS2( [], 0, 0 )

		return teams
