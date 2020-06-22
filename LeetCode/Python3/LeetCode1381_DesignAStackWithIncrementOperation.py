# LeetCode1381_DesignAStackWithIncrementOperation.py
class CustomStack:
	def __init__( self, maxSize: int ):
		self.__stack = []
		self.maxSize = maxSize


	def push( self, x: int ) -> None:
		if ( self.maxSize > len( self.__stack ) ):
			self.__stack.append( x )


	def pop( self ) -> int:
		if self.__stack:
			return self.__stack.pop()
		else:
			return -1


	def increment( self, k: int, val: int ) -> None:
		if ( ( k >= len( self.__stack ) ) ):
			self.__stack = [ x + val for x in self.__stack ]
		else:
			for i in range(k):
				self.__stack[i] = self.__stack[i] + val
