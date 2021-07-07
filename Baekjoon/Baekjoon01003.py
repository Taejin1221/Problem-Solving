# Baekjoon01003_FibonacciFunction.py
import sys
input = sys.stdin.readline

t = int( input() )
nums = [ int( input() ) for _ in range( t ) ]

fibs = [ ( 1, 0 ), ( 0, 1 ) ]
for i in range( 2, max( nums ) + 1 ):
	fib1, fib2 = fibs[ i - 1 ], fibs[ i - 2 ]
	newFib = (fib1[0] + fib2[0], fib1[1] + fib2[1])
	fibs.append( newFib )

for n in nums:
	print( fibs[n][0], fibs[n][1] )
