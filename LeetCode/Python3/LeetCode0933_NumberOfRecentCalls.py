# LeetCode0933_NumberOfRecentCalls.py
class RecentCounter:
	def __init__( self ):
		self.__q = collections.deque()

	def ping( self, t: int ) -> int:
		self.__q.append( t )

		th = t - 3000
		while ( th > self.__q[0]):
			self.__q.popleft()

		return len( self.__q )