# Baekjoon10870_Fibonacci5.py
def Fibonacci(n: int) -> int:
	if ( n == 0 ): return 0
	elif ( n == 1 ): return 1
	else: return ( Fibonacci( n - 1 ) + Fibonacci( n - 2 ) )

def Fibonacci(n: int) -> int:
	f1 = 0
	f2 = 1
	if ( n == 0 ):
		return f1
	elif ( n == 1 ):
		return f2
	else:
		for i in range( n - 1 ):
			f3 = f1 + f2
			f1 = f2
			f2 = f3
		return f3

n = int( input() )

print( Fibonacci( n ) )