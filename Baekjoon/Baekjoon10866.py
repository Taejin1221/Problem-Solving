# Baekjoon10866_Deque.py
class Deque:
	def __init__( self ):
		self.__deque = [ ]

	def push_front( self, X ):
		self.__deque = [ X ] + self.__deque

	def push_back( self, X ):
		self.__deque.append( X )

	def pop_front( self ) -> int:
		if self.empty():
			return -1
		else:
			val = self.__deque[0]
			self.__deque = self.__deque[1 : ]

			return val

	def pop_back( self ) -> int:
		return ( -1 if self.empty() else self.__deque.pop() )

	def size( self ) -> int:
		return len( self.__deque )

	def empty( self ) -> int:
		return ( 0 if self.__deque else 1 )

	def front( self ) -> int:
		return ( -1 if self.empty() else self.__deque[0] )

	def back( self ) -> int:
		return ( -1 if self.empty() else self.__deque[-1] )

import sys
input = sys.stdin.readline

deque = Deque()
for _ in range( int( input() ) ):
	inst = input().split()

	if ( inst[0] == 'push_front' ):
		deque.push_front( int( inst[1] ) )
	elif ( inst[0] == 'push_back' ):
		deque.push_back( int( inst[1] ) )
	elif ( inst[0] == 'pop_front' ):
		print( deque.pop_front() )
	elif ( inst[0] == 'pop_back' ):
		print( deque.pop_back() )
	elif ( inst[0] == 'size' ):
		print( deque.size() )
	elif ( inst[0] == 'empty' ):
		print( deque.empty() )
	elif ( inst[0] == 'front' ):
		print( deque.front() )
	elif ( inst[0] == 'back' ):
		print( deque.back() )
