# LeetCode0155_MinStack.py
class MinStack:
	def __init__( self ):
		self.__stck = [ ]
		self.__minVal = float( 'inf' )

	def push( self, x: int ) -> None:
		self.__stck.append( x )
		if x < self.__minVal:
			self.__minVal = x

	def pop( self ) -> None:
		minChange = False
		if self.__minVal == self.__stck[-1]:
			minChange = True

		self.__stck.pop()
		if not self.__stck:
			self.__minVal = float( 'inf' )

		else:
			if minChange:
				self.__minVal = min( self.__stck )


	def top( self ) -> int:
		if not self.__stck:
			return None
		else:
			return self.__stck[-1]

	def getMin( self ) -> int:
		if not self.__stck:
			return None
		else:
			return self.__minVal
