# Baekjoon10872_Factorial.py

# Recursion
def Factorial(n: int) -> int:
	if ( n == 0 ):
		return 1
	else:
		return ( n * Factorial( n - 1 ) )

# Iteration
def Factorial_Iter(n: int) -> int:
	fac = 1
	for i in range( 1, n + 1 ):
		fac *= i

	return fac

N = int( input() )

print( Factorial_Iter( N ) )